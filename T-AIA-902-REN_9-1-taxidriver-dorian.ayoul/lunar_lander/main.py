from lunar_lander.q_learning import q_learning
from lunar_lander.deep_q_learning import deep_q_learning

algo_list = ["1: q learning", "2: deep q learning"]
parameter_list = ["1: light", "2: strong", "3: extra-strong"]


def ask_for_algo(algo_list):
    print("Quelle algorythme voulez vous utiliser ? :")
    for algo in algo_list:
        print(algo)
    return input("Votre choix :")


def ask_for_parameter(parameters):
    print("Quelle niveau de parametre voulez vous utiliser :")
    for param in parameters:
        print(param)
    return input("Votre choix :")


def ask_for_load_model():
    print("Voulez-vous charger un modèle existant ? (o/n)")
    return input("Votre choix :").lower()


def run_with_model(path: str, parameters: str):
    if path == "deep_q_learning":
        deep_q_learning.load_model_entrypoint(
            model_path=f"lunar_lander/deep_q_learning/train/lunar_lander_{parameters}.pth"
        )
    elif path == "q_learning":
        q_learning.load_model_entrypoint(
            model_path=f"lunar_lander/q_learning/train/lunar_lander_{parameters}.pth"
        )


def entrypoint(algo: int):
    if algo == 1:  # Q Learning
        param = ask_for_parameter(parameter_list)
        load_model = ask_for_load_model()
        if load_model == "o":
            model = run_with_model("q_learning", param)
        else:
            if param == "1":
                q_learning.training_entrypoint(
                    n_episodes=300,
                    max_t=1500,
                    eps_start=1.0,
                    eps_end=0.01,
                    eps_decay=0.997,
                )
            elif param == "2":
                q_learning.training_entrypoint(
                    n_episodes=700,
                    max_t=1500,
                    eps_start=1.0,
                    eps_end=0.01,
                    eps_decay=0.997,
                )
            elif param == "3":
                q_learning.training_entrypoint(
                    n_episodes=1500,
                    max_t=1500,
                    eps_start=1.0,
                    eps_end=0.01,
                    eps_decay=0.997,
                )

    elif algo == 2:  # Deep Q Learning
        param = ask_for_parameter(parameter_list)
        load_model = ask_for_load_model()
        if load_model == "o":
            model = run_with_model("deep_q_learning", param)
        else:
            if param == "1":
                deep_q_learning.training_entrypoint(
                    n_episodes=300,
                    max_t=1500,
                    eps_start=1.0,
                    eps_end=0.01,
                    eps_decay=0.997,
                )
            elif param == "2":
                deep_q_learning.training_entrypoint(
                    n_episodes=700,
                    max_t=1500,
                    eps_start=1.0,
                    eps_end=0.01,
                    eps_decay=0.997,
                )
            elif param == "3":
                deep_q_learning.training_entrypoint(
                    n_episodes=1500,
                    max_t=1500,
                    eps_start=1.0,
                    eps_end=0.01,
                    eps_decay=0.997,
                )
