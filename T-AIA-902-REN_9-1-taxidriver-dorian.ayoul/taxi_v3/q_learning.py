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
        # Training iterations, higher value improves convergence/stabilization of the Q-values
        'episodes': 1000,
        # Max steps per episode, limits how long the agent can take to reach a goal
        'max_steps': 100,
        # How much new information overrides the old one (0=no learning, 1=full update)
        'learning_rate': 0.8,
        # How much future rewards are considered important compared to immediate ones (0=greedy, 1=far-sighted)
        'discount_factor': 0.95,
        # Probability of choosing a random action instead of the best-known one (0=exploitation,1=exploration).
        'epsilon': 1.0,
        # Rate at which epsilon decreases per episode to reduce exploration/increase exploitation over time.
        'epsilon_decay': 0.995,
        # Minimum value of epsilon to maintain some level of exploration even after decay.
        'min_epsilon': 0.01
    }
    episodes = get_input("Number of episodes (higher = convergence/stabilization of the Q-values)", defaults['episodes'], int)
    max_steps = get_input("Max steps per episode (limits how long the agent can take to reach a goal)", defaults['max_steps'], int)
    learning_rate = get_input("Learning rate (how much new information overrides the old one)", defaults['learning_rate'], float)
    discount_factor = get_input("Discount factor (how much future rewards are considered important compared to immediate ones)", defaults['discount_factor'], float)
    epsilon = get_input("Epsilon (probability of choosing a random action instead of the best-known one)", defaults['epsilon'], float)
    epsilon_decay = get_input("Epsilon decay (reduce exploration/increase exploitation over time)", defaults['epsilon_decay'], float)
    min_epsilon = get_input("Minimum epsilon (maintain some level of exploration even after decay)", defaults['min_epsilon'], float)
    env = gym.make('Taxi-v3')
    # Rows=states(500), Columns=actions(6), init to 0=all state-action pairs have no expected reward/penalty
    q_table = np.zeros([env.observation_space.n, env.action_space.n])
    steps_per_episode = []
    colors = []
    for episode in range(episodes):
        state = env.reset()[0]
        done = False
        steps = 0
        while not done and steps < max_steps:
            # epsilon-greedy: reduces epsilon over time to favor exploitation as the policy improves
            if rd.uniform(0, 1) < epsilon:
                action = env.action_space.sample()
            else:
                action = np.argmax(q_table[state])
            # rewards: deliver passenger=+20, bad pickup or dropoff=-10, move a square=-1(to encourage finding the shortest path)
            next_state, reward, done, _, _ = env.step(action)
            # Calculate the best predicted future reward, lessened so that it's considered but weighted less than immediate reward
            future_reward = discount_factor * np.max(q_table[next_state])
            # Calculate the Temporal Difference (TD) error
            # current reward + best future reward - current Q-value estimate = how much better or worse the new experience is compared to the current expectation
            td_error = reward + future_reward - q_table[state, action]
            # Update the Q-value for the current state-action pair at a certain learning rate using the TD error
            q_table[state, action] += learning_rate * td_error
            state = next_state
            steps += 1
        epsilon = max(min_epsilon, epsilon * epsilon_decay)
        steps_per_episode.append(steps)
        colors.append('blue' if reward > 0 else 'red')
        if episode % 1000 == 0:
            print(f"Episode {episode}/{episodes} completed.")

    timestamp = np.datetime64('now', 's')
    np.save(f"taxi_qn_{timestamp}.npy", q_table)
    print(f"Model saved as taxi_qn_{timestamp}.npy")

    env.close()

def run(model_path):
    q_table = np.load(model_path)
    env = gym.make('Taxi-v3')
    state = env.reset()[0]
    done = False
    steps = 0
    total_reward = 0
    while not done:
        action = np.argmax(q_table[state])
        next_state, reward, done, _, _ = env.step(action)
        total_reward += reward
        state = next_state
        steps += 1
    print(f"Total steps: {steps}, Total reward: {total_reward}")
    env.close()

def taxiQN():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train() if training else f"models/{models[id - 1]}")
