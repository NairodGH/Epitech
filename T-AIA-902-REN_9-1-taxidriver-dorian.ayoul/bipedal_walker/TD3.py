import gymnasium as gym
import numpy as np
import os
from datetime import datetime
from stable_baselines3 import TD3
from stable_baselines3.common.noise import NormalActionNoise
from stable_baselines3.common.env_util import make_vec_env
from stable_baselines3.common.vec_env import SubprocVecEnv, DummyVecEnv # Subproc has multiprocessing, dummy doesnt
from stable_baselines3.common.evaluation import evaluate_policy
from stable_baselines3.common.callbacks import EvalCallback
from stable_baselines3.common.monitor import Monitor
import multiprocessing

# max number of steps to train for, also impacts other training parameters
steps = 10_000_000
learning_rate = 5e-5
gamma = 0.999
tau = 0.005
learning_starts = steps / 100
buffer_size = steps
start_noise = 0.3
end_noise = 0.1
decay_steps = steps / 10
eval_freq = steps / 100

# handles the noise decay and rename the best_model.zip to custom name
class CustomEvalCallback(EvalCallback):
    def __init__(
        self,
        eval_env,
        name,
        **kwargs
    ):
        super().__init__(eval_env, **kwargs)
        self.name = name
        self.start_noise = start_noise
        self.end_noise = end_noise
        self.decay_steps = decay_steps

    def _on_step(self):
        # decay start_noise to end_noise over decay_steps
        if self.model.action_noise is not None:
            progress = min(1.0, self.num_timesteps / self.decay_steps)
            current_noise = self.start_noise - progress * (self.start_noise - self.end_noise)
            self.model.action_noise.sigma = current_noise
        result = super()._on_step() # is what saves the best_model
        if self.n_calls % self.eval_freq == 0 and os.path.exists("models/best_model.zip"): # if we just saved
            if os.path.exists(f"models/{self.name}.zip"): # remove existing renamed files
                os.remove(f"models/{self.name}.zip")
            os.rename("models/best_model.zip", f"models/{self.name}.zip")
        return result

# trains on cpu_count envs at once with multiprocessing, every eval_freq steps save the best_model
def train(model, hardcore):
    name = f"td3_{'hardcore' if hardcore else 'normal'}_{datetime.now().strftime('%d_%m_%Y')}"
    print("If you see lots of cuda related warnings since we use SubprocVecEnv, ignore as it works :)")
    # envs are run on cpu not gpu so get highest number of cores, don't care about torch
    env = make_vec_env(
        lambda: gym.make("BipedalWalker-v3", hardcore=hardcore),
        n_envs=multiprocessing.cpu_count(),
        vec_env_cls=SubprocVecEnv
    )
    reset = model == None
    if model:
        model = TD3.load(model, env)
    else:
        model = TD3(
            "MlpPolicy",
            env,
            # 4 actions, noise encourages exploration, will decay in CustomEvalCallback
            action_noise=NormalActionNoise(np.zeros(4), 0.3*np.ones(4)),
            train_freq=1,
            gradient_steps=-1,
            verbose=1,
            learning_rate=learning_rate,
            gamma=gamma,
            tau=tau,
            learning_starts=learning_starts,
            buffer_size=buffer_size,
            # both actor (pi) and critic (qf) feedforward networks have 2 hidden layers with 400 and 300 neurons each
            # as finetuned in the original TD3 paper https://arxiv.org/pdf/1802.09477
            policy_kwargs=dict(net_arch=dict(pi=[400, 300], qf=[400, 300])),
        )
    # if model is provided, dont reset_num_timesteps (start from chosen model's steps)
    model.learn(total_timesteps=steps, reset_num_timesteps=reset, callback=CustomEvalCallback(
        DummyVecEnv([lambda: Monitor(gym.make("BipedalWalker-v3", hardcore=hardcore), None)]),
        best_model_save_path="models",
        name=name,
        eval_freq=eval_freq,
        deterministic=True,
        render=False
    ))
    return f"models/{name}"

# load the chosen model to get stats and run the pygame visualization on loop
def run(model, hardcore):
    model = TD3.load(model)
    mean_reward, _ = evaluate_policy(model, DummyVecEnv([lambda: gym.make("BipedalWalker-v3", hardcore=hardcore)]), n_eval_episodes=5)
    print(f"Model average reward: {mean_reward:.2f}")
    env = gym.make("BipedalWalker-v3", render_mode="human", hardcore=hardcore)
    observation, _ = env.reset()
    while True:
        action, _ = model.predict(observation, deterministic=True)
        observation, _, terminated, truncated, _ = env.step(action)
        if terminated or truncated:
            observation, _ = env.reset()

def get_override(var_name, cast_type):
    try:
        user_input = input(f"{var_name} (current={globals()[var_name]}): ")
        if user_input == '':
            return  # keep existing
        globals()[var_name] = cast_type(user_input)
    except ValueError:
        print(f"Invalid input for {var_name}, keeping current value: {globals()[var_name]}")
    except KeyError:
        print(f"Unknown variable {var_name}")

def configure_hyperparameters():
    hyperparams = {
        "steps": int,
        "learning_rate": float,
        "gamma": float,
        "tau": float,
        "learning_starts": float,
        "buffer_size": int,
        "start_noise": float,
        "end_noise": float,
        "decay_steps": float,
        "eval_freq": float
    }
    for var_name, cast_type in hyperparams.items():
        get_override(var_name, cast_type)

# choose mode and call the appropriate function
def bipedalTD3():
    configure_hyperparameters()
    hardcore = int(input("1. Normal (flat terrain)\n2. Hardcore (holes & obstacles)\nChoose mode (1/2): ")) == 2
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "td3" in f]
    if training:
        print("0. Start training from scratch")
    id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train(None if id == 0 else f"models/{models[id-1]}", hardcore) if training else f"models/{models[id - 1]}", hardcore)