import gymnasium as gym
import random as rd
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from collections import deque
import os
import numpy as np

class DQN(nn.Module):
    def __init__(self, state_size, action_size):
        super(DQN, self).__init__()
        self.fc1 = nn.Linear(state_size, 128)
        self.fc2 = nn.Linear(128, 128)
        self.fc3 = nn.Linear(128, action_size)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        return self.fc3(x)

def train():
    env = gym.make('Taxi-v3')
    state_size = env.observation_space.n
    action_size = env.action_space.n

    model = DQN(state_size, action_size)
    optimizer = optim.Adam(model.parameters(), lr=0.001)
    criterion = nn.MSELoss()

    episodes = 6000
    max_steps = 120
    gamma = 0.95
    epsilon = 1.0
    epsilon_decay = 0.995
    min_epsilon = 0.01
    memory = deque(maxlen=2000)
    batch_size = 64

    steps_per_episode = []
    colors = []

    for episode in range(episodes):
        state = env.reset()[0]
        state = torch.eye(state_size)[state]
        done = False
        steps = 0

        while not done and steps < max_steps:
            if rd.uniform(0, 1) < epsilon:
                action = env.action_space.sample()
            else:
                with torch.no_grad():
                    action = torch.argmax(model(state)).item()

            next_state, reward, done, _, _ = env.step(action)
            next_state = torch.eye(state_size)[next_state]

            memory.append((state, action, reward, next_state, done))
            state = next_state
            steps += 1

            if len(memory) > batch_size:
                minibatch = rd.sample(memory, batch_size)

                states, actions, rewards, next_states, dones = zip(*minibatch)
                states = torch.stack(states)
                actions = torch.tensor(actions, dtype=torch.long)
                rewards = torch.tensor(rewards, dtype=torch.float)
                next_states = torch.stack(next_states)
                dones = torch.tensor(dones, dtype=torch.bool)

                q_values = model(states).gather(1, actions.unsqueeze(1)).squeeze(1)
                next_q_values = model(next_states).max(1)[0]
                target_q_values = rewards + gamma * next_q_values * (~dones)

                loss = criterion(q_values, target_q_values.detach())
                optimizer.zero_grad()
                loss.backward()
                optimizer.step()

        epsilon = max(min_epsilon, epsilon * epsilon_decay)
        steps_per_episode.append(steps)
        colors.append('blue' if reward > 0 else 'red')

        if episode % 1000 == 0:
            print(f"Episode {episode}/{episodes} completed.")

    timestamp = np.datetime64('now', 's')
    torch.save(model.state_dict(), f"taxi_dqn_{timestamp}.pth")
    print(f"Model saved as taxi_dqn_{timestamp}.pth")

    env.close()

def run(model):
    env = gym.make('Taxi-v3', render_mode="human")
    state_size = env.observation_space.n
    max_steps = 120

    state = env.reset()[0]
    state = torch.eye(state_size)[state]
    done = False
    steps = 0
    while not done and steps < max_steps:
        with torch.no_grad():
            action = torch.argmax(model(state)).item()
        state, reward, done, _, _ = env.step(action)
        state = torch.eye(state_size)[state]
        steps += 1
    print(f'Visual run completed in {steps} steps.')
    env.close()

    # plt.scatter(range(episodes), steps_per_episode, c=colors, marker='o')
    # plt.xlabel('Episode')
    # plt.ylabel('Steps Taken')
    # plt.title('Deep Q-learning Performance in Taxi-v3')
    # plt.grid()
    # plt.show()


def taxiDQN():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train() if training else f"models/{models[id - 1]}")
