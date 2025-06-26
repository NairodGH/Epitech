import gymnasium as gym
import numpy as np
import random as rd
import matplotlib.pyplot as plt
import os

def train():
    def get_input(prompt, default, cast_type):
        try:
            user_input = input(f"{prompt}: ")
            if user_input == '':
                return default
            return cast_type(user_input)
        except ValueError:
            print(f"Invalid input, using default value {default}.")
            return default
    defaults = {
        'episodes': 1000,
        'max_steps': 100,
        'learning_rate': 0.8,
        'discount_factor': 0.95,
        'epsilon': 1.0,
        'epsilon_decay': 0.995,
        'min_epsilon': 0.01,
        'is_slippery': False
    }
    episodes = get_input("Number of episodes (higher = convergence/stabilization of the Q-values)", defaults['episodes'], int)
    max_steps = get_input("Max steps per episode (limits how long the agent can take to reach a goal)", defaults['max_steps'], int)
    learning_rate = get_input("Learning rate (how much new information overrides the old one)", defaults['learning_rate'], float)
    discount_factor = get_input("Discount factor (how much future rewards are considered important compared to immediate ones)", defaults['discount_factor'], float)
    epsilon = get_input("Epsilon (probability of choosing a random action instead of the best-known one)", defaults['epsilon'], float)
    epsilon_decay = get_input("Epsilon decay (reduce exploration/increase exploitation over time)", defaults['epsilon_decay'], float)
    min_epsilon = get_input("Minimum epsilon (maintain some level of exploration even after decay)", defaults['min_epsilon'], float)
    is_slippery = get_input("Is slippery (has a chance of taking the wrong direction at random)", defaults['is_slippery'], bool)
    env = gym.make("FrozenLake-v1", desc=None, map_name="4x4", is_slippery=is_slippery)
    q_table = np.zeros([env.observation_space.n, env.action_space.n])
    steps_per_episode = []
    colors = []
    for episode in range(episodes):
        state = env.reset()[0]
        done = False
        steps = 0
        while not done and steps < max_steps:
            if rd.uniform(0, 1) < epsilon:
                action = env.action_space.sample()
            else:
                action = np.argmax(q_table[state])
            next_state, reward, done, _, _ = env.step(action)
            reward = 20 if reward == 1 else -10 if done else -1
            q_table[state, action] = q_table[state, action] + learning_rate * (
                reward + discount_factor * np.max(q_table[next_state]) - q_table[state, action]
            )
            state = next_state
            steps += 1
        epsilon = max(epsilon * epsilon_decay, min_epsilon)
        steps_per_episode.append(steps)
        colors.append('blue' if reward > 0 else 'red')
        if episode % 1000 == 0:
            print(f"Episode {episode}/{episodes} completed.")
    env.close()

    timestamp = np.datetime64('now', 's')
    np.save(f"frozenlake_qn_{timestamp}.npy", q_table)
    print(f"Model saved as frozenlake_qn_{timestamp}.npy")

    # plt.scatter(range(episodes), steps_per_episode, c=colors, marker='o')
    # plt.xlabel('Episode')
    # plt.ylabel('Steps Taken')
    # plt.title('Q-Learning frozen lake')
    # plt.grid()
    # plt.show()

def run(model):
    env = gym.make("FrozenLake-v1", desc=None, map_name="4x4", render_mode="human", is_slippery=True)
    state = env.reset()[0]
    max_steps = 100
    done = False
    steps = 0
    while not done and steps < max_steps:
        state, _, done, _, _ = env.step(np.argmax(model[state]))
        steps += 1
    print(f"Frozen lake Q-learning completed in {steps} steps.")
    env.close()

def frozenlakeQN():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train() if training else f"models/{models[id - 1]}")
