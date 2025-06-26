import gymnasium as gym
import numpy as np
import torch
import torch.nn as nn
from torch.distributions import Normal
import os

ENV_ID = "Ant-v5"
LR = 3e-4
GAMMA = 0.99
GAE_LAMBDA = 0.95
CLIP_EPS = 0.2
ENTROPY_COEF = 0.01
VALUE_COEF = 0.5
BATCH_SIZE = 2048
MINI_BATCH_SIZE = 64
EPOCHS = 10
MAX_STEPS = 1000000
DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")


class ActorCritic(nn.Module):
    def __init__(self, obs_dim, act_dim):
        super().__init__()
        self.actor = nn.Sequential(
            nn.Linear(obs_dim, 64),
            nn.Tanh(),
            nn.Linear(64, 64),
            nn.Tanh(),
            nn.Linear(64, act_dim)
        )
        self.critic = nn.Sequential(
            nn.Linear(obs_dim, 64),
            nn.Tanh(),
            nn.Linear(64, 64),
            nn.Tanh(),
            nn.Linear(64, 1)
        )
        self.log_std = nn.Parameter(torch.zeros(act_dim))

    def get_action(self, obs):
        mu = self.actor(obs)
        std = self.log_std.exp()
        dist = Normal(mu, std)
        action = dist.sample()
        return action, dist.log_prob(action).sum(axis=-1), dist.entropy().sum(axis=-1)

    def get_value(self, obs):
        return self.critic(obs)

    def evaluate(self, obs, action):
        mu = self.actor(obs)
        std = self.log_std.exp()
        dist = Normal(mu, std)
        log_prob = dist.log_prob(action).sum(axis=-1)
        entropy = dist.entropy().sum(axis=-1)
        value = self.critic(obs).squeeze(-1)
        return log_prob, entropy, value


def compute_gae(rewards, values, dones, gamma=GAMMA, lam=GAE_LAMBDA):
    adv = np.zeros_like(rewards)
    last_adv = 0
    for t in reversed(range(len(rewards))):
        delta = rewards[t] + gamma * values[t + 1] * (1 - dones[t]) - values[t]
        adv[t] = last_adv = delta + gamma * lam * (1 - dones[t]) * last_adv
    returns = adv + values[:-1]
    return adv, returns


def train():
    env = gym.make(ENV_ID)
    obs_dim = env.observation_space.shape[0]
    act_dim = env.action_space.shape[0]
    model = ActorCritic(obs_dim, act_dim).to(DEVICE)
    optimizer = torch.optim.Adam(model.parameters(), lr=LR)

    obs, _ = env.reset()
    obs = torch.tensor(obs, dtype=torch.float32, device=DEVICE)
    total_steps = 0

    while total_steps < MAX_STEPS:
        obs_buf, act_buf, logp_buf, rew_buf, done_buf, val_buf = [], [], [], [], [], []

        for _ in range(BATCH_SIZE):
            with torch.no_grad():
                value = model.get_value(obs).item()
                action, logp, _ = model.get_action(obs)
            next_obs, reward, done, trunc, _ = env.step(action.cpu().numpy())
            next_obs = torch.tensor(next_obs, dtype=torch.float32, device=DEVICE)

            obs_buf.append(obs.cpu().numpy())
            act_buf.append(action.cpu().numpy())
            logp_buf.append(logp.cpu().numpy())
            rew_buf.append(reward)
            done_buf.append(done or trunc)
            val_buf.append(value)

            obs = next_obs
            total_steps += 1

            if done or trunc:
                obs, _ = env.reset()
                obs = torch.tensor(obs, dtype=torch.float32, device=DEVICE)

        val_buf.append(model.get_value(obs).item())
        adv_buf, ret_buf = compute_gae(rew_buf, val_buf, done_buf)

        obs_t = torch.tensor(np.array(obs_buf), dtype=torch.float32, device=DEVICE)
        act_t = torch.tensor(np.array(act_buf), dtype=torch.float32, device=DEVICE)
        logp_old_t = torch.tensor(np.array(logp_buf), dtype=torch.float32, device=DEVICE)
        adv_t = torch.tensor(adv_buf, dtype=torch.float32, device=DEVICE)
        ret_t = torch.tensor(ret_buf, dtype=torch.float32, device=DEVICE)
        adv_t = (adv_t - adv_t.mean()) / (adv_t.std() + 1e-8)

        for _ in range(EPOCHS):
            idxs = np.arange(BATCH_SIZE)
            np.random.shuffle(idxs)
            for i in range(0, BATCH_SIZE, MINI_BATCH_SIZE):
                batch_idx = idxs[i:i + MINI_BATCH_SIZE]
                b_obs = obs_t[batch_idx]
                b_act = act_t[batch_idx]
                b_logp_old = logp_old_t[batch_idx]
                b_adv = adv_t[batch_idx]
                b_ret = ret_t[batch_idx]

                logp, entropy, value = model.evaluate(b_obs, b_act)
                ratio = torch.exp(logp - b_logp_old)
                clipped = torch.clamp(ratio, 1 - CLIP_EPS, 1 + CLIP_EPS) * b_adv
                policy_loss = -torch.min(ratio * b_adv, clipped).mean()
                value_loss = ((value - b_ret) ** 2).mean()
                entropy_bonus = entropy.mean()

                loss = policy_loss + VALUE_COEF * value_loss - ENTROPY_COEF * entropy_bonus

                optimizer.zero_grad()
                loss.backward()
                optimizer.step()

        print(f"Steps: {total_steps}, Loss: {loss.item():.3f}")

    timestamp = np.datetime64('now', 's')
    torch.save(model.state_dict(), f"ant_ppo_{timestamp}.pt")
    print(f"Model saved as ant_ppo_{timestamp}.pt")
    env.close()

def run(model):
    env = gym.make("Ant-v5", render_mode="human")
    obs_dim = env.observation_space.shape[0]
    act_dim = env.action_space.shape[0]

    model = ActorCritic(obs_dim, act_dim).to(DEVICE)
    model.load_state_dict(torch.load(model, map_location=DEVICE))
    model.eval()

    obs, _ = env.reset()
    obs = torch.tensor(obs, dtype=torch.float32, device=DEVICE)

    for _ in range(1000):
        with torch.no_grad():
            action, _, _ = model.get_action(obs)
        obs, _, done, trunc, _ = env.step(action.cpu().numpy())
        obs = torch.tensor(obs, dtype=torch.float32, device=DEVICE)

        if done or trunc:
            obs, _ = env.reset()
            obs = torch.tensor(obs, dtype=torch.float32, device=DEVICE)

    env.close()

def antPPO():
    training = int(input("1. Train\n2. Load\nChoose action (1/2): ")) == 1
    os.makedirs("models", exist_ok=True)
    models = [f for f in os.listdir("models") if "dqn" in f]
    if not training:
        id = int(input("\n".join(f"{i}. {m}" for i, m in enumerate(models,1)) + "\nSelect model: "))
    run(train() if training else f"models/{models[id - 1]}")
