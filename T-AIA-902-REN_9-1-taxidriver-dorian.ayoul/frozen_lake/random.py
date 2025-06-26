import gymnasium as gym
import matplotlib.pyplot as plt

def run():
    env = gym.make("FrozenLake-v1", desc=None, map_name="4x4", render_mode="human", is_slippery=False)
    episodes, steps_per_episode, colors = 10, [], []
    for episode in range(episodes):
        env.reset()
        done, steps = False, 0
        while not done and steps < 100:
            _, _, done, _, _ = env.step(env.action_space.sample())
            steps += 1
        steps_per_episode.append(steps)
        colors.append('blue' if done > 0 else 'red')
        print(f'random episode {episode} took {steps} steps')
    env.close()
    # plt.scatter(range(episodes), steps_per_episode, c=colors, marker='o')
    # plt.xlabel('Episode')
    # plt.ylabel('Steps Taken')
    # plt.title('Random Policy Performance')
    # plt.grid()
    # plt.show()

def frozenlakeRANDOM():
    print("Running Random Policy for 10 episodes...")
    run()
