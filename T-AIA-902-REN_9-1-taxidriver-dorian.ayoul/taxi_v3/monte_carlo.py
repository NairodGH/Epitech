import gymnasium as gym
import numpy as np
import random as rd
import matplotlib.pyplot as plt
from collections import defaultdict
import os

def train():
    episodes=30000
    max_steps=100
    gamma=0.9
    epsilon=1.0
    epsilon_decay=0.995
    min_epsilon=0.01

    env = gym.make('Taxi-v3')

    # Initialize Q-table: state-action values (all initially 0)
    q_table = np.zeros([env.observation_space.n, env.action_space.n])

    # Dictionary to store returns for each (state, action) pair
    returns = defaultdict(list)

    # Lists for tracking progress (used for visualization)
    steps_per_episode = []
    colors = []  # Blue for successful episodes, red otherwise

    # Training loop over episodes
    for episode in range(episodes):
        state = env.reset()[0]  # Reset environment and get initial state
        episode_history = []    # To store (state, action, reward) tuples for this episode
        done = False
        steps = 0

        # Generate one full episode
        while not done and steps < max_steps:
            # ε-greedy action selection
            if rd.uniform(0, 1) < epsilon:
                action = env.action_space.sample()  # Explore
            else:
                action = np.argmax(q_table[state])  # Exploit best known action

            next_state, reward, done, _, _ = env.step(action)  # Take action
            episode_history.append((state, action, reward))    # Store experience
            state = next_state
            steps += 1

        # Monte Carlo return computation and Q-value update
        G = 0  # Return
        visited_states_actions = set()  # Track first visits

        # Process episode in reverse to calculate returns
        for t in reversed(range(len(episode_history))):
            state, action, reward = episode_history[t]
            G = gamma * G + reward  # Accumulate discounted return

            # First-visit check: only update the first time (state, action) appears in the episode
            if (state, action) not in visited_states_actions:
                visited_states_actions.add((state, action))
                returns[(state, action)].append(G)  # Store return
                q_table[state, action] = np.mean(returns[(state, action)])  # Update Q-value

        # Decay epsilon to reduce exploration over time
        epsilon = max(min_epsilon, epsilon * epsilon_decay)

        # Track steps and color for visualization
        steps_per_episode.append(steps)
        colors.append('blue' if reward > 0 else 'red')  # Blue for successful (positive reward), red otherwise

        # Progress logging
        if episode % 1000 == 0:
            print(f"Episode {episode}/{episodes} completed.")

    timestamp = np.datetime64('now', 's')
    np.save(f"taxi_mc_{timestamp}.npy", q_table)
    print(f"Model saved as taxi_mc_{timestamp}.npy")

    env.close()

def run(model_path):
    q_table = np.load(model_path)

    env = gym.make('Taxi-v3', render_mode="human")
    state = env.reset()[0]
    done = False
    steps = 0

    while not done:
        action = np.argmax(q_table[state])
        next_state, reward, done, _, _ = env.step(action)
        state = next_state
        steps += 1

    print(f"Total steps: {steps}, Total reward: {reward}")
    env.close()

    # plt.figure(figsize=(10, 6))
    # plt.scatter(range(episodes), steps_per_episode, c=colors, marker='o', alpha=0.5)
    # plt.xlabel('Episode')
    # plt.ylabel('Steps Taken')
    # plt.title('Monte Carlo Taxi-v3 Performance')
    # plt.grid()
    # plt.savefig('monte_carlo_performance.png')  # Save performance plot
    # plt.close()

def taxiMC():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train() if training else f"models/{models[id - 1]}")
