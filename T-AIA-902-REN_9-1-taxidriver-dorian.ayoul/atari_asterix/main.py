import gymnasium as gym
import ale_py
import time
import importlib
import numpy as np

class AsterixGame:
    def __init__(self, render_mode="human"):
        self.env = gym.make("ALE/Asterix-v5", obs_type="ram", render_mode=render_mode)
        self.obs, self.info = self.env.reset()
        self.prev_obs = self.obs
        self.lives = self.info.get('lives', 3)
        self.step_count = 0
        self.freeze_frame_count = 0
        self.freeze_threshold = 5
        self.agent_position_index = 42

    def is_probably_frozen(self):
        current_position = self.obs[self.agent_position_index]
        previous_position = self.prev_obs[self.agent_position_index]

        print(f"[DEBUG] Current position: {current_position} | Previous position: {previous_position} | freeze_frame_count: {self.freeze_frame_count}")

        if current_position == previous_position:
            self.freeze_frame_count += 1
        else:
            self.freeze_frame_count = 0

        return self.freeze_frame_count >= self.freeze_threshold

    def play(self, num_steps, action_strategy_module):
        try:
            while self.step_count < num_steps:
                is_frozen = self.is_probably_frozen()

                if is_frozen:
                    print(f"Step {self.step_count + 1} | Detected freeze. Stepping with NOOP.")
                    action = action_strategy_module.take_action(self.env)
                else:
                    action = action_strategy_module.take_action(self.env)

                self.prev_obs = self.obs
                self.obs, reward, terminated, truncated, self.info = self.env.step(action)

                if 'lives' in self.info and self.info['lives'] < self.lives:
                    print(f"Step {self.step_count + 1} | Lost a life! Lives remaining: {self.info['lives']}")
                    self.lives = self.info['lives']

                self.process_reward(reward, num_steps)

                print(f"Step {self.step_count + 1}/{num_steps} | Action: {action}, Reward: {reward}, Lives: {self.lives}")
                time.sleep(0.3)

                if not is_frozen:
                    self.step_count += 1

                if terminated or truncated:
                    print("Game Over! Resetting...")
                    self.reset()

        except KeyboardInterrupt:
            print("\nGame closed by user.")
        finally:
            self.env.close()
            print("Environment closed successfully.")

    def process_reward(self, reward, num_steps):
        reward_messages = {
            50.0: "Picked up a cauldron!",
            100.0: "Picked up a helmet!",
            200.0: "Picked up a shield!",
            300.0: "Picked up a lamp!",
            400.0: "Picked up an apple!",
            500.0: "Picked up a fish, wild boar leg, or mug!"
        }
        if reward in reward_messages:
            print(f"Step {self.step_count + 1}/{num_steps} | {reward_messages[reward]} Reward: {reward}")

    def reset(self):
        self.obs, self.info = self.env.reset()
        self.prev_obs = self.obs
        self.lives = self.info.get('lives', 3)
        self.freeze_frame_count = 0

if __name__ == "__main__":
    game = AsterixGame()
    num_steps = 100

    print("Available strategies: random_policy, monte_carlo, q_learning, deep_q_learning")
    strategy_module_name = input("Enter the strategy module name: ")

    try:
        action_strategy_module = importlib.import_module(strategy_module_name)
        game.play(num_steps, action_strategy_module)
    except ModuleNotFoundError:
        print(f"Error: The strategy module '{strategy_module_name}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")
