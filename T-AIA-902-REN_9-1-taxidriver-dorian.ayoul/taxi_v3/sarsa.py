from time import sleep
import gymnasium as gym
import numpy as np
import random as rd
import matplotlib.pyplot as plt
import os

def train():
    env = gym.make("Taxi-v3")
    q_table = np.zeros([env.observation_space.n, env.action_space.n])

    episodes = 10000
    max_steps = 100
    learning_rate = 0.8
    discount_factor = 0.95
    epsilon = 1.0
    epsilon_decay = 0.995
    min_epsilon = 0.01

    steps_per_episode = []
    colors = []

    for episode in range(episodes):
        state = env.reset()[0]
        done = False
        steps = 0

        action = (
            env.action_space.sample()
            if rd.uniform(0, 1) < epsilon
            else np.argmax(q_table[state])
        )

        while not done and steps < max_steps:
            next_state, reward, done, _, _ = env.step(action)
            reward = 20 if reward == 20 else -10 if reward == -10 else -1

            next_action = (
                env.action_space.sample()
                if rd.uniform(0, 1) < epsilon
                else np.argmax(q_table[next_state])
            )

            q_table[state, action] += learning_rate * (
                reward
                + discount_factor * q_table[next_state, next_action]
                - q_table[state, action]
            )

            state = next_state
            action = next_action
            steps += 1

        epsilon = max(min_epsilon, epsilon * epsilon_decay)

        steps_per_episode.append(steps)
        colors.append("blue" if reward > 0 else "red")

        if episode % 1000 == 0:
            print(f"Episode {episode}/{episodes} completed.")

    timestamp = np.datetime64('now', 's')
    np.save(f"taxi_sarsa_{timestamp}.npy", q_table)
    print(f"Model saved as taxi_sarsa_{timestamp}.npy")

    env.close()
    # plt.scatter(range(episodes), steps_per_episode, c=colors, marker="o", s=1)
    # plt.xlabel("Episode")
    # plt.ylabel("Steps Taken")
    # plt.title("SARSA Taxi-v3")
    # plt.grid()
    # plt.show()

def run(model_path):
    q_table = np.load(model_path)

    env = gym.make("Taxi-v3", render_mode="human")
    state = env.reset()[0]
    done = False
    steps = 0

    while not done and steps < 100:
        action = np.argmax(q_table[state])
        state, _, done, _, _ = env.step(action)
        steps += 1
        sleep(0.5)

    print(f"Test completed in {steps} steps.")
    env.close()

def taxiSARSA():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train() if training else f"models/{models[id - 1]}")
