import gymnasium as gym
import numpy as np
import random as rd
import matplotlib.pyplot as plt
from collections import defaultdict
import os

def get_input(prompt, default, cast_type, example=None, effect=None):
    try:
        full_prompt = f"{prompt} (default: {default}" + (f", e.g. {example}" if example else "") + (f". {effect}" if effect else "") + ")\n> "
        user_input = input(full_prompt)
        if user_input == '':
            return default
        return cast_type(user_input)
    except ValueError:
        print(f"Invalid input, using default value {default}.")
        return default

def evaluate_model(model_path, episodes=100, max_steps=100, is_slippery=False):
    env = gym.make("FrozenLake-v1", map_name="4x4", is_slippery=is_slippery)
    q_table = np.load(model_path)
    steps_list = []
    rewards_list = []
    success_count = 0
    for _ in range(episodes):
        state = env.reset()[0]
        done = False
        steps = 0
        total_reward = 0
        while not done and steps < max_steps:
            action = np.argmax(q_table[state])
            state, reward, done, _, _ = env.step(action)
            total_reward += reward
            steps += 1
        steps_list.append(steps)
        rewards_list.append(total_reward)
        if total_reward > 0:
            success_count += 1
    env.close()
    # Plot evaluation performance
    plt.figure(figsize=(10, 6))
    plt.scatter(range(episodes), steps_list, c=['blue' if r > 0 else 'red' for r in rewards_list], marker='o', alpha=0.5)
    plt.xlabel('Evaluation Episode')
    plt.ylabel('Steps Taken')
    plt.title('Monte Carlo FrozenLake-v1 Evaluation Performance')
    plt.grid()
    plt.savefig('monte_carlo_frozenlake_eval.png')
    plt.close()
    print(f"Evaluation: Success rate = {success_count}/{episodes} ({success_count/episodes:.2%})")
    return steps_list, rewards_list

def train():
    defaults = {
        'episodes': 10000,
        'max_steps': 100,
        'gamma': 0.9,
        'epsilon': 1.0,
        'epsilon_decay': 0.995,
        'min_epsilon': 0.01,
        'is_slippery': False
    }
    episodes = get_input(
        "Number of episodes",
        defaults['episodes'],
        int,
        example="10000, 20000, 50000",
        effect="Higher = more stable Q-values, but longer training. Lower = faster, less stable."
    )
    max_steps = get_input(
        "Max steps per episode",
        defaults['max_steps'],
        int,
        example="100, 200, 500",
        effect="Higher = agent can take longer to reach goal. Lower = shorter episodes, may not reach goal."
    )
    gamma = get_input(
        "Discount factor",
        defaults['gamma'],
        float,
        example="0.9, 0.99, 0.5",
        effect="Higher = future rewards matter more. Lower = focus on immediate rewards."
    )
    epsilon = get_input(
        "Epsilon (exploration rate)",
        defaults['epsilon'],
        float,
        example="1.0, 0.5, 0.1",
        effect="Higher = more random actions. Lower = more greedy actions."
    )
    epsilon_decay = get_input(
        "Epsilon decay",
        defaults['epsilon_decay'],
        float,
        example="0.995, 0.99, 0.9",
        effect="Higher = slower decay, more exploration. Lower = faster decay, less exploration."
    )
    min_epsilon = get_input(
        "Minimum epsilon",
        defaults['min_epsilon'],
        float,
        example="0.01, 0.05, 0.1",
        effect="Higher = always some exploration. Lower = almost always greedy at end."
    )
    is_slippery = get_input(
        "Is slippery (True/False)",
        defaults['is_slippery'],
        bool,
        example="True, False",
        effect="True = environment is stochastic. False = deterministic."
    )

    env = gym.make("FrozenLake-v1", map_name="4x4", is_slippery=is_slippery)

    # Initialize Q-table and returns storage
    q_table = np.zeros([env.observation_space.n, env.action_space.n])
    returns = defaultdict(list)

    # Lists for visualization
    steps_per_episode = []
    colors = []
    epsilon_values = []

    for episode in range(episodes):
        state = env.reset()[0]
        episode_history = []
        done = False
        steps = 0

        # Generate one complete episode
        while not done and steps < max_steps:
            if rd.uniform(0, 1) < epsilon:
                action = env.action_space.sample()
            else:
                action = np.argmax(q_table[state])

            next_state, reward, done, _, _ = env.step(action)
            episode_history.append((state, action, reward))
            state = next_state
            steps += 1

        # Monte Carlo return computation
        G = 0
        visited_state_actions = set()

        for t in reversed(range(len(episode_history))):
            state, action, reward = episode_history[t]
            G = gamma * G + reward

            # First-visit MC update
            if (state, action) not in visited_state_actions:
                visited_state_actions.add((state, action))
                returns[(state, action)].append(G)
                q_table[state, action] = np.mean(returns[(state, action)])

        # Decay epsilon
        epsilon = max(min_epsilon, epsilon * epsilon_decay)
        epsilon_values.append(epsilon)

        # Tracking
        steps_per_episode.append(steps)
        episode_rewards = [r for (_, _, r) in episode_history]
        is_success = 1 in episode_rewards
        colors.append('blue' if is_success else 'red')
        print(f"Episode {episode+1}: episode_rewards={episode_rewards}, is_success={is_success}")

        if episode % 1000 == 0:
            print(f"Episode {episode}/{episodes} completed.")

    # save the Q-table in the models folder
    os.makedirs("models", exist_ok=True)
    timestamp = np.datetime64('now', 's')
    filename = f"models/frozenlake_mc_{timestamp}.npy"
    np.save(filename, q_table)
    print(f"Model saved as {filename}")

    # Plot training performance with epsilon
    fig, ax1 = plt.subplots(figsize=(12, 6))

    ax1.set_xlabel('Episode')
    ax1.set_ylabel('Steps Taken', color='blue')
    ax1.scatter(range(episodes), steps_per_episode, c=colors, marker='o', alpha=0.5, label='Steps')
    ax1.tick_params(axis='y', labelcolor='blue')

    ax2 = ax1.twinx()  # Second Y-axis
    ax2.set_ylabel('Epsilon', color='green')
    ax2.plot(range(episodes), epsilon_values, color='green', linewidth=2, label='Epsilon')
    ax2.tick_params(axis='y', labelcolor='green')

    success_patch = plt.Line2D([0], [0], marker='o', color='w', label='Success', markerfacecolor='blue', markersize=10)
    fail_patch = plt.Line2D([0], [0], marker='o', color='w', label='Failure', markerfacecolor='red', markersize=10)
    ax1.legend(handles=[success_patch, fail_patch])


    plt.title('Training Performance and Epsilon Decay')
    fig.tight_layout()
    plt.grid()
    plt.savefig('monte_carlo_frozenlake_performance.png')
    plt.close()


    env.close()

    # Evaluate and plot evaluation performance
    evaluate_model(filename, episodes=100, max_steps=max_steps, is_slippery=is_slippery)
    return filename

def run(model):
    # Try to infer is_slippery from filename (not perfect, but helps for comparison)
    is_slippery = False
    if "slippery" in model:
        is_slippery = True
    evaluate_model(model, episodes=100, max_steps=100, is_slippery=is_slippery)
    env = gym.make("FrozenLake-v1", map_name="4x4", is_slippery=is_slippery, render_mode="human")
    q_table = np.load(model)

    state = env.reset()[0]
    done = False
    steps = 0

    while not done and steps < 100:
        action = np.argmax(q_table[state])
        state, _, done, _, _ = env.step(action)
        steps += 1

    print(f"Test completed in {steps} steps.")
    env.close()

def frozenlakeMC():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if f.endswith('.npy')]
    if not training:
        if not models:
            print("No models available in the 'models' folder.")
            return
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
        run(f"models/{models[id - 1]}")
    else:
        model_path = train()
        run(model_path)