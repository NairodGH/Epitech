import gymnasium as gym

def run():
    env = gym.make('Taxi-v3', render_mode="human")
    env.reset()
    for steps in range(100):
        state, reward, done, _, _ = env.step(env.action_space.sample())
        steps += 1
        print(f'Step {steps}: State={state}, Reward={reward}, Done={done}')
        if done:
            print(f'Random policy somehow succeeded in {steps} steps (it\'s just a fluke, try again :D)')
            break
        elif steps == 100:
            print(f'Random policy took all {steps} steps without (big surprise ? nope) succeeding')
    env.close()

def taxiRANDOM():
    print("Running Random Policy for 100 steps...")
    run()
