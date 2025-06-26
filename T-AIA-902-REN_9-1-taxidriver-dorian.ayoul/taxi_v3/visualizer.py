import torch
import gymnasium as gym
import torch.nn as nn
import torch.nn.functional as F

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

def run_trained_model(model_path="dqn_taxi_model.pth"):
    env = gym.make('Taxi-v3', render_mode="human")
    state_size = env.observation_space.n
    action_size = env.action_space.n

    model = DQN(state_size, action_size)
    model.load_state_dict(torch.load(model_path))
    model.eval()

    state = env.reset()[0]
    state = torch.eye(state_size)[state]
    done = False
    steps = 0
    max_steps = 100

    for _ in range(100):
        while not done and steps < max_steps:
            with torch.no_grad():
                action = torch.argmax(model(state)).item()
            state, reward, done, _, _ = env.step(action)
            state = torch.eye(state_size)[state]
            steps += 1

        print(f'Visual run completed in {steps} steps.')
        env.reset()
        done = False
        steps = 0
    env.close()

if __name__ == "__main__":
    run_trained_model()
