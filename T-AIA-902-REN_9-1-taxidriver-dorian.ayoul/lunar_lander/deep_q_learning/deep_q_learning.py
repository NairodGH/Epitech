import numpy as np
import gymnasium as gym
import random
import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from collections import deque, namedtuple
import matplotlib.pyplot as plt
import os

BUFFER_SIZE = int(1e5)  # Taille du replay buffer
BATCH_SIZE = 64  # Taille du mini-batch
GAMMA = 0.99  # Facteur de discount
TAU = 1e-3  # Pour la mise à jour douce du target network
LR = 5e-4  # Taux d'apprentissage
UPDATE_EVERY = 4  # Fréquence de mise à jour du réseau
TARGET_UPDATE_EVERY = (
    100  # Fréquence de mise à jour du réseau cible (en termes de pas d'apprentissage)
)


def save_training(agent):
    os.makedirs("lunar_lander/deep_q_learning/train", exist_ok=True)
    torch.save(
        {
            "qnetwork_local": agent.qnetwork_local.state_dict(),
            "qnetwork_target": agent.qnetwork_target.state_dict(),
            "optimizer": agent.optimizer.state_dict(),
        },
        "lunar_lander/deep_q_learning/train/lunar_lander_final.pth",
    )


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")


class QNetwork(nn.Module):
    """Modèle de réseau neuronal pour approximer Q(s,a)."""

    def __init__(self, state_size, action_size, seed, fc1_units=64, fc2_units=64):
        """Initialise les paramètres et construit le modèle.
        Params
        ======
            state_size (int): Dimension de chaque état
            action_size (int): Dimension de chaque action
            seed (int): Graine aléatoire
            fc1_units (int): Nombre de nœuds dans la première couche cachée
            fc2_units (int): Nombre de nœuds dans la deuxième couche cachée
        """
        super(QNetwork, self).__init__()
        self.seed = torch.manual_seed(seed)
        self.fc1 = nn.Linear(state_size, fc1_units)
        self.fc2 = nn.Linear(fc1_units, fc2_units)
        self.fc3 = nn.Linear(fc2_units, action_size)

    def forward(self, state):
        x = F.relu(self.fc1(state))
        x = F.relu(self.fc2(x))
        return self.fc3(x)


class ReplayBuffer:
    """Buffer de taille fixe pour stocker les tuples d'expérience."""

    def __init__(self, action_size, buffer_size, batch_size, seed):
        self.action_size = action_size
        self.memory = deque(maxlen=buffer_size)
        self.batch_size = batch_size
        self.experience = namedtuple(
            "Experience",
            field_names=["state", "action", "reward", "next_state", "done"],
        )
        self.seed = random.seed(seed)
        np.random.seed(seed)  # Aussi pour numpy utilisé dans sample()

    def add(self, state, action, reward, next_state, done):
        """Ajoute une nouvelle expérience à la mémoire."""
        e = self.experience(state, action, reward, next_state, done)
        self.memory.append(e)

    def sample(self):
        """Échantillonne aléatoirement un batch d'expériences depuis la mémoire."""
        experiences = random.sample(self.memory, k=self.batch_size)

        # Convertit le batch d'expériences en tenseurs PyTorch
        states = (
            torch.from_numpy(np.vstack([e.state for e in experiences if e is not None]))
            .float()
            .to(device)
        )
        actions = (
            torch.from_numpy(
                np.vstack([e.action for e in experiences if e is not None])
            )
            .long()
            .to(device)
        )
        rewards = (
            torch.from_numpy(
                np.vstack([e.reward for e in experiences if e is not None])
            )
            .float()
            .to(device)
        )
        next_states = (
            torch.from_numpy(
                np.vstack([e.next_state for e in experiences if e is not None])
            )
            .float()
            .to(device)
        )
        # Convertit done (bool) en float (0.0 ou 1.0) puis en tenseur
        dones = (
            torch.from_numpy(
                np.vstack([e.done for e in experiences if e is not None]).astype(
                    np.uint8
                )
            )
            .float()
            .to(device)
        )

        return (states, actions, rewards, next_states, dones)

    def __len__(self):
        return len(self.memory)


class DQNAgent:
    """Interagit avec et apprend de l'environnement."""

    def __init__(self, state_size, action_size, seed):
        self.state_size = state_size
        self.action_size = action_size
        self.seed = random.seed(seed)
        torch.manual_seed(seed)  # Graine PyTorch

        self.qnetwork_local = QNetwork(state_size, action_size, seed).to(device)
        self.qnetwork_target = QNetwork(state_size, action_size, seed).to(device)
        self.qnetwork_target.load_state_dict(self.qnetwork_local.state_dict())
        self.qnetwork_target.eval()  # Mettre le réseau cible en mode évaluation

        self.optimizer = optim.Adam(self.qnetwork_local.parameters(), lr=LR)

        # Mémoire de Replay
        self.memory = ReplayBuffer(action_size, BUFFER_SIZE, BATCH_SIZE, seed)
        self.t_step = 0
        self.target_update_count = 0

    def step(self, state, action, reward, next_state, done):
        self.memory.add(state, action, reward, next_state, done)

        # Apprend toutes les UPDATE_EVERY étapes.
        self.t_step = (self.t_step + 1) % UPDATE_EVERY
        if self.t_step == 0:
            # S'il y a assez d'échantillons dans la mémoire, prend un sous-ensemble aléatoire et apprend
            if len(self.memory) > BATCH_SIZE:
                experiences = self.memory.sample()
                self.learn(experiences, GAMMA)
                self.target_update_count = (
                    self.target_update_count + 1
                ) % TARGET_UPDATE_EVERY
                if self.target_update_count == 0:
                    self.hard_update(self.qnetwork_local, self.qnetwork_target)

    def act(self, state, eps=0.0):
        """Retourne les actions pour un état donné selon la politique actuelle."""
        state = torch.from_numpy(state).float().unsqueeze(0).to(device)
        self.qnetwork_local.eval()  # Mettre en mode évaluation pour l'inférence
        with torch.no_grad():  # Pas besoin de calculer les gradients ici
            action_values = self.qnetwork_local(state)
        self.qnetwork_local.train()  # Remettre en mode entraînement

        if random.random() > eps:
            # Choisir l'action avec la Q-valeur maximale
            return np.argmax(action_values.cpu().data.numpy()).item()
        else:
            # Choisir une action aléatoire
            return random.choice(np.arange(self.action_size))

    def learn(self, experiences, gamma):
        """Met à jour les paramètres de valeur en utilisant un batch d'expériences donné."""
        states, actions, rewards, next_states, dones = experiences

        # On regarde ce que le réseau pense être le meilleur choix à faire ensuite, sans lui faire apprendre à ce moment-là
        Q_targets_next = (
            self.qnetwork_target(next_states).detach().max(1)[0].unsqueeze(1)
        )

        # calcule combien valait vraiment l’action, en prenant la récompense et ce qu’on pense pouvoir encore gagner ensuite
        Q_targets = rewards + (gamma * Q_targets_next * (1 - dones))

        # récupère la valeur que le réseau pense que chaque action prise vaut, pour pouvoir ensuite la corriger
        Q_expected = self.qnetwork_local(states).gather(1, actions)

        loss = F.mse_loss(Q_expected, Q_targets)

        self.optimizer.zero_grad()  # Remettre les gradients à zéro
        loss.backward()  # Calculer les gradients
        self.optimizer.step()  # Mettre à jour les poids du réseau local

    def soft_update(self, local_model, target_model, tau):
        """Mise à jour douce des paramètres du modèle cible.
        θ_target = τ*θ_local + (1 - τ)*θ_target
        Params
        ======
            local_model (PyTorch model): poids à copier depuis
            target_model (PyTorch model): poids à copier vers
            tau (float): paramètre d'interpolation
        """
        for target_param, local_param in zip(
            target_model.parameters(), local_model.parameters()
        ):
            target_param.data.copy_(
                tau * local_param.data + (1.0 - tau) * target_param.data
            )

    def hard_update(self, local_model, target_model):
        """Copie directe des poids du modèle local vers le modèle cible."""
        target_model.load_state_dict(local_model.state_dict())


# --- Fonction d'entraînement DQN ---
def dqn_train(
    n_episodes: int, max_t: int, eps_start: float, eps_end: float, eps_decay: float
):
    env = gym.make("LunarLander-v3")
    state_size = env.observation_space.shape[0]  # type: ignore
    action_size = env.action_space.n  # type: ignore
    agent = DQNAgent(state_size=state_size, action_size=action_size, seed=0)

    scores = []  # liste contenant les scores de chaque épisode
    scores_window = deque(maxlen=100)  # 100 derniers scores
    eps = eps_start  # initialiser epsilon
    eps_vals = []  # Pour le graphique d'epsilon
    steps_per_episode = []

    for i_episode in range(1, n_episodes + 1):
        state, _ = env.reset(seed=i_episode)
        score = 0
        steps = 0
        for t in range(max_t):
            action = agent.act(state, eps)
            next_state, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated
            agent.step(state, action, reward, next_state, done)
            state = next_state
            score += reward  # type: ignore
            steps += 1
            if done:
                break

        scores_window.append(score)  # enregistrer le score le plus récent
        steps_per_episode.append(steps)
        scores.append(score)  # enregistrer le score le plus récent
        eps = max(eps_end, eps_decay * eps)  # diminuer epsilon
        eps_vals.append(eps)  # enregistrer epsilon

        print(
            f"\rEpisode {i_episode}\tScore Moyen (100 ép.): {np.mean(scores_window):.2f}\tEpsilon: {eps:.3f}",
            end="",
        )
        if i_episode % 100 == 0:
            print(
                f"\rEpisode {i_episode}\tScore Moyen (100 ép.): {np.mean(scores_window):.2f}\tEpsilon: {eps:.3f}"
            )
    env.close()

    # A décommenter pour enregister l'entrainement
    # save_training(agent)

    # Affichage des résultats
    plt.figure(figsize=(12, 4))
    plt.subplot(1, 2, 1)
    plt.plot(np.arange(len(scores)), scores)
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

    return agent  # Retourner l'agent entraîné pour le test


def test_agent(agent, episodes=5, max_steps=1000):
    """Teste l'agent entraîné avec rendu visuel."""
    env = gym.make("LunarLander-v3", render_mode="human")
    total_rewards = []
    for i in range(episodes):
        state, _ = env.reset()
        episode_reward = 0
        steps = 0
        done = False
        while not done and steps < max_steps:
            # Choisir l'action de manière gourmande (epsilon=0)
            action = agent.act(state, eps=0.0)
            state, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated
            episode_reward += reward  # type: ignore
            steps += 1

        print(
            f"Test Episode {i+1} - Steps: {steps}, Total Reward: {episode_reward:.2f}"
        )
        total_rewards.append(episode_reward)

    print(
        f"\nScore moyen sur {episodes} épisodes de test: {np.mean(total_rewards):.2f}"
    )
    env.close()


def save_agent(agent, filename="lunar_lander_agent.pth"):
    torch.save(
        {
            "qnetwork_local": agent.qnetwork_local.state_dict(),
            "qnetwork_target": agent.qnetwork_target.state_dict(),
            "optimizer": agent.optimizer.state_dict(),
        },
        filename,
    )
    print(f"Agent sauvegardé dans {filename}")


def load_agent(state_size, action_size, filename):
    agent = DQNAgent(state_size=state_size, action_size=action_size, seed=0)
    checkpoint = torch.load(filename, weights_only=True)
    agent.qnetwork_local.load_state_dict(checkpoint["qnetwork_local"])
    agent.qnetwork_target.load_state_dict(checkpoint["qnetwork_target"])
    agent.optimizer.load_state_dict(checkpoint["optimizer"])
    print(f"Agent chargé depuis {filename}")
    return agent


def training_entrypoint(
    n_episodes: int,
    max_t: int,
    eps_start: float,
    eps_end: float,
    eps_decay: float,
):
    agent = dqn_train(n_episodes, max_t, eps_start, eps_end, eps_decay)
    save_agent(agent)
    if agent:
        test_agent(agent, episodes=10)


def load_model_entrypoint(model_path: str):
    env = gym.make("LunarLander-v3")
    state_size = env.observation_space.shape[0]  # type: ignore
    action_size = env.action_space.n  # type: ignore

    try:
        agent = load_agent(state_size, action_size, model_path)
        if agent:
            test_agent(agent, episodes=10)
    except FileNotFoundError:
        print("Aucun modèle sauvegardé trouvé")
        return None
