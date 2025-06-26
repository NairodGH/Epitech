import sys
from q_learning import q_learning
from deep_q_learning import deep_q_learning
from monte_carlo import monte_carlo_taxi
from taxi_v3.random import random_policy

def print_algorithm_options():
    print("\nAvailable algorithms:")
    print("1. Q-Learning")
    print("   - Model-free, off-policy RL algorithm")
    print("   - Learns action-value function Q(s,a)")
    print("   - Uses exploration-exploitation tradeoff")

    print("\n2. Deep Q-Learning")
    print("   - Uses neural network to approximate Q-values")
    print("   - Handles high-dimensional state spaces")
    print("   - Requires more computational resources")

    print("\n3. Monte Carlo")
    print("   - Learns from complete episodes")
    print("   - No bootstrapping (uses actual returns)")
    print("   - Good for environments with clear terminal states")

    print("\n4. Random Policy")
    print("   - Takes completely random actions")
    print("   - No learning involved")
    print("   - Useful as a baseline for comparison")

if __name__ == "__main__":
    print_algorithm_options()

    choice = input("\nSelect an algorithm by number or name: ").lower()

    algorithm_map = {
        '1': 'q_learning',
        '2': 'deep_q_learning',
        '3': 'monte_carlo',
        '4': 'random'
    }

    if choice in algorithm_map:
        choice = algorithm_map[choice]

    if choice == "q_learning":
        q_learning()
    elif choice == "random":
        random_policy()
    elif choice == "deep_q_learning":
        deep_q_learning()
    elif choice == "monte_carlo":
        print("\n--- Monte Carlo Hyperparameters ---")

        try:
            episodes = int(input("Number of episodes (e.g. 10000 to 100000): "))
            max_steps = int(input("Max steps per episode (e.g. 100 to 500): "))
            gamma = float(input("Discount factor γ (0.5 to 0.99): "))
            epsilon = float(input("Initial epsilon (exploration rate, 0.1 to 1.0): "))
            epsilon_decay = float(input("Epsilon decay rate (e.g. 0.9 to 0.9999): "))
            min_epsilon = float(input("Minimum epsilon (e.g. 0.01): "))
        except ValueError:
            print("Invalid input. Using default hyperparameters.")
            episodes = 30000
            max_steps = 100
            gamma = 0.9
            epsilon = 1.0
            epsilon_decay = 0.995
            min_epsilon = 0.01

        monte_carlo_taxi(
            episodes=episodes,
            max_steps=max_steps,
            gamma=gamma,
            epsilon=epsilon,
            epsilon_decay=epsilon_decay,
            min_epsilon=min_epsilon
        )

    else:
        print("\nInvalid choice. Please select one of the following:")
        print("By number: 1 (Q-Learning), 2 (Deep Q-Learning), 3 (Monte Carlo), 4 (Random)")
        print("By name: q_learning, deep_q_learning, monte_carlo, random")
        sys.exit(1)
