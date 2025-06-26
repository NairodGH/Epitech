import numpy as np
import random
from collections import defaultdict

# Initialize the state-action value estimates (Q-values)
Q = defaultdict(lambda: np.zeros(18))  # Assuming 18 possible actions for Asterix

# Initialize the number of visits to each state-action pair (N-values)
N = defaultdict(lambda: np.zeros(18))  # Assuming 18 possible actions for Asterix

# Epsilon for epsilon-greedy action selection
epsilon = 0.1

# Discount factor
gamma = 0.99

def get_q_value(state, action):
    return Q[state][action]

def update_q_value(state, action, reward, next_state):
    N[state][action] += 1

    # Calculate the sample return
    sample_return = reward + gamma * np.max(Q[next_state])

    # Update the Q-value using the incremental update rule
    Q[state][action] += (sample_return - Q[state][action]) / N[state][action]

def take_action(env):
    state = tuple(env.unwrapped.ale.getRAM())  # Convert RAM state to a tuple
    if random.random() < epsilon:
        # Explore: take a random action
        return env.action_space.sample()
    else:
        # Exploit: take the action with the highest Q-value
        return np.argmax(Q[state])

def update_policy(env, state, action, reward, next_state):
    update_q_value(state, action, reward, next_state)
