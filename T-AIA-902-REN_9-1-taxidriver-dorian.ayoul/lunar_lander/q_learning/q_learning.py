import numpy as np
import gymnasium as gym
import random as rd
import matplotlib.pyplot as plt
import os
import torch


def save_q_table(q_table, filename):
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    q_table = q_table.astype(np.float32)
    torch.save(q_table, filename)


def load_q_table(filename):
    try:
        if os.path.exists(filename):
            return torch.load(filename, weights_only=False)
        else:
            print(f"Aucun fichier trouvé : {filename}")
            return None
    except Exception as e:
        print(f"Erreur lors du chargement du modèle: {e}")
        return None


def discretize(state, bins):
    indices = []
    for i in range(len(state)):
        idx = np.digitize(state[i], bins[i])
        idx = max(0, min(19, idx - 1))
        indices.append(idx)
    return tuple(indices)


def q_learning(n_episodes, max_t, eps_start, eps_end, eps_decay):
    gamma = 0.99  # facteur discount, les recompense future sont de plus en plus faible
    alpha = 0.1  # Taux d'apprentissage
    epsilon = eps_start  # exploration
    epsilon_min = eps_end
    epsilon_decay = eps_decay

    env = gym.make("LunarLander-v3")
    n_actions = 4  # actions possibles
    n_states = 8  # prochaines states possible

    bins = [np.linspace(-1, 1, 10) for _ in range(n_states)]  # Réduit de 20 à 10 bins

    q_table = np.zeros((10,) * n_states + (n_actions,), dtype=np.float32)

    def choose_action(state):
        if rd.uniform(0, 1) < epsilon:
            return env.action_space.sample()
        return np.argmax(q_table[state])

    # Entraînement
    rewards_per_episode = []
    steps_per_episode = []
    epsilon_vals = []

    for episode in range(n_episodes):
        state, _ = env.reset()
        state = discretize(state, bins)
        done = False
        total_reward = 0
        steps = 0

        while not done and steps < max_t:
            action = choose_action(state)
            next_state, reward, terminated, truncated, _ = env.step(action)
            next_state = discretize(next_state, bins)
            done = terminated or truncated

            # MAJ q-table
            current_q = q_table[state + (action,)]
            next_max_q = np.max(q_table[next_state])
            new_q = current_q + alpha * (float(reward) + gamma * next_max_q - current_q)
            q_table[state + (action,)] = new_q

            state = next_state
            total_reward += float(reward)
            steps += 1

        # decroissance exploration
        epsilon = max(epsilon_min, epsilon * epsilon_decay)
        epsilon_vals.append(epsilon)
        rewards_per_episode.append(total_reward)
        steps_per_episode.append(steps)

        if episode % 100 == 0:
            print(
                f"Épisode {episode}/{n_episodes}, Reward: {total_reward:.2f}, Epsilon: {epsilon:.2f}, Steps: {steps}"
            )

    env.close()

    # A décommenter pour enregistrer l'entrainement
    # save_q_table(q_table, f"lunar_lander/q_learning/train/lunar_lander_final.pth")

    # Affichage des graphiques
    plt.figure(figsize=(12, 4))
    plt.subplot(1, 2, 1)
    plt.plot(rewards_per_episode)
    plt.xlabel("Episode")
    plt.ylabel("Total Reward")
    plt.title("Récompenses par Épisode")
    plt.grid(True)

    plt.subplot(1, 2, 2)
    plt.plot(steps_per_episode)
    plt.xlabel("Episode")
    plt.ylabel("Steps")
    plt.title("Pas par Épisode")
    plt.grid(True)

    plt.tight_layout()
    plt.show()

    return q_table, bins


def test_q_table(q_table, bins, episodes=5, max_steps=1000):
    # Environnement avec rendu pour le test
    env = gym.make("LunarLander-v3", render_mode="human")

    for episode in range(episodes):
        state, _ = env.reset()
        state = discretize(state, bins)
        done = False
        steps = 0
        total_reward = 0

        while not done and steps < max_steps:
            action = np.argmax(q_table[state])
            next_state, reward, terminated, truncated, _ = env.step(action)
            state = discretize(next_state, bins)
            done = terminated or truncated
            total_reward += float(reward)
            steps += 1

        print(
            f"Épisode {episode + 1} - Steps: {steps}, Total Reward: {total_reward:.2f}"
        )

    env.close()


def training_entrypoint(n_episodes, max_t, eps_start, eps_end, eps_decay):
    q_table, bins = q_learning(n_episodes, max_t, eps_start, eps_end, eps_decay)
    if q_table is not None:
        test_q_table(q_table, bins=bins, episodes=10)


def load_model_entrypoint(model_path):
    print(model_path)
    try:
        n_states = 8
        bins = [
            np.linspace(-1, 1, 10) for _ in range(n_states)
        ]  # Même nombre de bins que dans q_learning
        q_table = load_q_table(model_path)
        if q_table is not None:
            test_q_table(q_table, episodes=10, bins=bins)
    except FileNotFoundError:
        print("Aucun modèle sauvegardé trouvé")
        return None
