import gymnasium as gym
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
import random
import os
from collections import deque

episodes = 3000
max_steps = 800
batch_size = 32
# Represents the maximum number of experiences (state, action, reward, next_state, done) the agent can store
# This is for experience replay, a technique where the agent learns from past experiences randomly sampled from this buffer
# Helps break correlations between consecutive experiences and improves learning stability
buffer_size = 100000
learning_rate = 1e-03 # (alpha)
starting_exp_rate = 1.
min_exp_rate = .05
discount_factor = .99
sync_every = 1000
render_every = 50
device = torch.device('cuda')

class Buffer:
    def __init__(self, buffer_size):
        self.memory = deque(maxlen=buffer_size)
    # Stores experiences (state, action, next_state, reward, done) in memory
    def save(self, state, action, next_state, reward, done):
        # pytorch tensors are multidimensional arrays but can run on GPU, track gradient and other deep learning features
        state = torch.tensor(state, dtype=torch.float32).to(device)
        action = torch.tensor(action, dtype=torch.int64).to(device)
        next_state = torch.tensor(next_state, dtype=torch.float32).to(device)
        reward = torch.tensor(reward, dtype=torch.float32).to(device)
        done = torch.tensor(done, dtype=torch.float32).to(device)
        self.memory.append((state, action, next_state, reward, done))
    # Randomly selects a batch of experiences for training
    def sample(self, batch_size):
        batch = random.sample(self.memory, batch_size)
        states, actions, next_states, rewards, dones = zip(*batch)
        states = torch.stack(states).to(device)
        actions = torch.stack(actions).to(device)
        next_states = torch.stack(next_states).to(device)
        rewards = torch.stack(rewards).to(device)
        dones = torch.stack(dones).to(device)
        return states, actions, next_states, rewards, dones
    def clear(self):
        self.memory.clear()

buffer = Buffer(buffer_size)

class DQN(nn.Module):
    #create dense layers from n_observation to n_actions to expand the representation (extract features, +100% then roughly +33%)
    def __init__(self, n_observation, n_actions):
        super().__init__()
        self.layer1 = nn.Linear(n_observation,48)
        self.layer2 = nn.Linear(48,64)
        self.layer3 = nn.Linear(64,n_actions)
    # feed observations and return actions out of the layers
    def forward(self, observations):
        x = F.relu(self.layer1(observations))
        x = F.relu(self.layer2(x))
        x = self.layer3(x)
        return x.view(-1,3,4) #-1=batch dimension, 3=actions per joint, 4=nb of joints

class DQNAgent:
    # self.net: The active network used for action selection and is updated through training
    # self.target: A separate network used for calculating target Q-values
    # This separation stabilizes training by preventing the "moving target" problem
    # The target network gets updated every sync_every steps with the weights from the main network through load_state_dict
    def __init__(self, n_observation, n_actions):
        self.net = DQN(n_observation, n_actions).to(device)
        self.opt = torch.optim.Adam(params=self.net.parameters(), lr=learning_rate)
        self.target = DQN(n_observation, n_actions).to(device)
        self.target.load_state_dict(self.net.state_dict())
        self.exploration_rate = starting_exp_rate
        self.min_exp_rate = min_exp_rate
        self.discount_factor = discount_factor # (gamma)
        self.sync_every = sync_every
        self.total_steps = 0
        self.episodes = episodes
        self.max_steps = max_steps
        self.batch_size = batch_size

    # A decorator that disables gradient calculation during the decorated function
    # Used for inference-only operations like selecting actions
    # Improves performance and reduces memory usage when backpropagation isn't needed
    @torch.no_grad()
    # Selects actions based on the current state and exploration strategy
    # Updates the target network every sync_every steps
    # Implements epsilon-greedy exploration:
    #  With probability exploration_rate: Choose random action
    #  Otherwise or validation_mode (model given): Choose action with highest Q-value
    # Gradually reduces exploration rate from starting_exp_rate to min_exp_rate

    # unsqueeze the tensor across a given dimension, squeeze is the opposite
    # see https://i.sstatic.net/9AJJA.png
    def act(self, state, validation_mode=False):
        self.total_steps += 1
        if self.total_steps % self.sync_every == 0:
            self.target.load_state_dict(self.net.state_dict())
        if random.random() < self.exploration_rate and not validation_mode:
            action = np.random.randint(0,3,size=4)
        else :
            state = torch.tensor(state, dtype=torch.float32).to(device).unsqueeze(0)
            action = self.net(state).squeeze(0).argmax(dim=0).cpu().numpy()
        self.exploration_rate = max(min_exp_rate, self.exploration_rate - 1/(self.episodes * self.max_steps/2))
        return action

    # Performs one step of gradient descent to update the network
    # Gradient Descent is the overall strategy: "Always move downhill to find the lowest valley"
    # Backpropagation is how we determine which direction is downhill:
    # The climber (net) makes a prediction based on current position
    # We measure how wrong that prediction was (the loss)
    # Backpropagation calculates how much each step in different directions would reduce error
    # It "propagates" this error information backward through the network
    # Gradient descent then uses this information to decide which way to step

    # Gets current Q-values from the main network
    # Calculates target Q-values using the Bellman equation (succinct q-value function): reward + discount_factor * max(Q(s',a'))
    # Uses the target network for more stable target Q-value estimates

    # Computes loss using Smooth L1 Loss (for small errors: Behaves like MSE (quadratic), for large errors: Behaves like MAE (linear))
    # Less sensitive to outliers than pure MSE
    # More stable gradients for large errors
    # Still differentiable everywhere (unlike pure MAE)
    # Prevents exploding gradients on large prediction errors
    
    # Applies gradient clipping to prevent exploding gradients (very large values)
    # Stabilizes training, especially in deep networks or RNNs
    # Reduces the risk of taking too large steps during optimization
    # Helps with convergence when rewards or errors can be large
    def optimize(self, states, actions, next_states, rewards, dones):
        current_values = self.net(states).gather(1,actions.unsqueeze(1)).squeeze(1)
        with torch.no_grad():
            expected_values = rewards.unsqueeze(-1) + self.discount_factor * (1 - dones.unsqueeze(-1)) * self.target(next_states).max(1).values
        loss=nn.SmoothL1Loss()(current_values, expected_values)
        self.opt.zero_grad()
        loss.backward()
        torch.nn.utils.clip_grad_value_(self.net.parameters(), 100)
        self.opt.step()
    def save(self, path):
        torch.save(self.net.state_dict(), path)
    def load(self, path):
        data = torch.load(path, map_location=device)
        self.net.load_state_dict(data)

# Observation space: 24
# Hull angle: 1 (The tilt of the main body in radians, 0=horizontal, 0.1=tilted clockwise (leaning right), -0.1=tilted counterclockwise (leaning left))
# Angular velocity: 1 (How fast the hull is rotating, 0=Not rotating, 0.1=rotating clockwise, -0.1=rotating counterclockwise)
# Horizontal speed: 1 (Forward/backward movement speed, 0=Not moving horizontally, 0.1=forward, -0.1=backward)
# Vertical speed: 1 (Up/down movement speed, 0=Not moving vertically, 0.1=jump, -0.1=fall)
# Position of joints (joint angles): 4 (hip: 0.0=straight down, 0.1=forward, -0.1=backward | knee: 0.0=straight, 0.1=bent forward, -0.1=bent backward)
# Angular speed of joints: 4 (0.0=Joint not rotating, 0.1=Joint rotating forward, -0.1=Joint rotating backward)
# Legs contact with ground: 2 (0=in the air, 1=touch ground)
# Lidar rangefinder measurements: 10 (raytracing in 10 directions ahead, each from 0 to 1 where 0=obstacle close and 1=no obstacle)

# Action space (discretized instead of default continuous, from infinitely decimal "-1 to 1" to strictly "-1, 0 or 1" (counterclockwise, none or clockwise rotation))
# Motor speed of joints: 12 (4 joints * 3 discretized actions)
def train(hardcore):
    env = gym.make("BipedalWalker-v3", hardcore=hardcore, render_mode='rgb_array_list')
    agent = DQNAgent(24,12)
    total_rewards = []
    for episode in range(episodes):
        episode_rewards = []
        state, _ = env.reset()
        for step in range(max_steps):
            action = agent.act(state)
            next_state, reward, terminated, truncated, _ = env.step(action  - np.array([1.,1.,1.,1.]))
            done = terminated or truncated
            buffer.save(state, action, next_state, reward, done)
            episode_rewards.append(reward)
            state = next_state
            if episode > 5:
                states, actions, next_states, rewards, dones = buffer.sample(batch_size)
                agent.optimize(states, actions, next_states, rewards, dones)
            if done or step == max_steps - 1:
                break
        total_reward = sum(episode_rewards)
        if total_reward > 5:
            path = f"models/dqn_{'hardcore' if hardcore else 'normal'}_{episode}.pt"
            agent.save(path)
        if (episode + 1) % 10 == 0 or total_reward > 0:
            print(f'Episode {episode+1}/{episodes} | total reward = {total_reward} | exp rate = {agent.exploration_rate}', '\n')
        total_rewards.append(total_reward)
    print('Mean reward :')
    print(np.mean(total_rewards))
    print('Max reward :')
    print(np.max(total_rewards))
    return path

import imageio
def run(model, hardcore):
    agent = DQNAgent(24, 12)
    agent.load(model)
    env = gym.make("BipedalWalker-v3", hardcore=hardcore, render_mode='rgb_array')
    
    # Setup for GIF recording
    frames = []
    fps = 30
    max_frames = 10 * fps
    
    state, _ = env.reset()
    episode_rewards = []
    actions = []
    
    for step in range(max_steps * 2):
        frame = env.render()
        if len(frames) < max_frames:
            frames.append(frame)
        
        action = agent.act(state, validation_mode=True)
        next_state, reward, terminated, truncated, _ = env.step(action - np.array([1.,1.,1.,1.]))
        state = next_state
        actions.append(action)
        episode_rewards.append(reward)
        
        if terminated or truncated:
            break
    
    # Save using imageio
    if frames:
        output_path = 'bipedalwalker_first_5s.gif'
        imageio.mimsave(output_path, frames, fps=fps)
        print(f"Saved first 5 seconds as {output_path}")
    
    print(f'reward = {sum(episode_rewards)}', '\n')
    env.close()

def get_override(var_name, cast_type):
    try:
        user_input = input(f"{var_name} (current={globals()[var_name]}): ")
        if user_input == '':
            return
        globals()[var_name] = cast_type(user_input)
    except ValueError:
        print(f"Invalid input for {var_name}, keeping current value: {globals()[var_name]}")
    except KeyError:
        print(f"Unknown variable {var_name}")

def configure_hyperparameters():
    hyperparams = {
        "episodes": int,
        "max_steps": int,
        "batch_size": int,
        "buffer_size": int,
        "learning_rate": float,
        "starting_exp_rate": float,
        "min_exp_rate": float,
        "discount_factor": float,
        "sync_every": int,
        "render_every": int
    }
    for var_name, cast_type in hyperparams.items():
        get_override(var_name, cast_type)

def bipedalDQN():
    configure_hyperparameters()
    hardcore = int(input("1. Normal (flat terrain)\n2. Hardcore (holes & obstacles)\nChoose mode (1/2): ")) == 2
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train(hardcore) if training else f"models/{models[id - 1]}", hardcore)