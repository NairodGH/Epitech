import sys

from bipedal_walker.DQN import bipedalDQN
from bipedal_walker.TD3 import bipedalTD3
from ant_v5.PPO import antPPO
from frozen_lake.random import frozenlakeRANDOM
from frozen_lake.q_learning import frozenlakeQN
from frozen_lake.deep_q_learning import frozenlakeDQN
from frozen_lake.monte_carlo import frozenlakeMC
from taxi_v3.q_learning import taxiQN
from taxi_v3.deep_q_learning import taxiDQN
from taxi_v3.monte_carlo import taxiMC
from taxi_v3.sarsa import taxiSARSA
from taxi_v3.random import taxiRANDOM

from lunar_lander import main

games = {
    "BipedalWalker": {"DQN": bipedalDQN, "TD3": bipedalTD3},
    "LunarLander": {
        "QLearning": lambda: main.entrypoint(1),
        "Deep Q Learning": lambda: main.entrypoint(2),
    },
    "FrozenLake": {
        "QLearning": frozenlakeQN,
        "DeepQLearning": frozenlakeDQN,
        "Montecarlo": frozenlakeMC,
        "Random": frozenlakeRANDOM,
    },
    "TaxiDriver": {
        "QLearning": taxiQN,
        "DeepQLearning": taxiDQN,
        "Montecarlo": taxiMC,
        "Sarsa": taxiSARSA,
        "Random": taxiRANDOM,
    },
    "Ant": {
        "PPO": antPPO,
    },
}


def select_option(options, prompt):
    options = list(options)
    for idx, option in enumerate(options, 1):
        print(f"{idx}. {option}")
    try:
        choice = int(input(f"{prompt} (1-{len(options)}): "))
        if 1 <= choice <= len(options):
            return options[choice - 1]
    except ValueError:
        pass
    print("Invalid selection.")
    sys.exit(1)


if __name__ == "__main__":
    selected_game = select_option(games.keys(), "Select game")
    games[selected_game][select_option(games[selected_game].keys(), "Select algorithm")]()
