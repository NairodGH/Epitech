import sys
import os
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def plot_and_save_graph(df, title_str, output_filename):
    if df.empty or not all(col in df.columns for col in ['episode', 'reward']):
        sys.stderr.write(f"Warning: No valid data for '{title_str}' or missing columns. Not saving {output_filename}.\n")
        return
    
    fig = plt.figure(figsize=(12, 7))
    plt.plot(df['episode'], df['reward'], linestyle='-')
    plt.title(f"Rewards per episodes: {title_str}", fontsize=16)
    plt.xlabel("Episode", fontsize=14)
    plt.ylabel("Reward", fontsize=14)
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.tight_layout()
    
    try:
        plt.savefig(output_filename)
    except Exception as e:
        sys.stderr.write(f"Error saving plot to {output_filename}: {e}\n")
    finally:
        plt.close(fig)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.stderr.write("Usage: python your_script_name.py <filename.csv_or_keyword>\n")
        sys.exit(1)
    
    param = sys.argv[1]
    
    if os.path.isfile(param) and param.endswith('.csv'):
        base_name = os.path.splitext(param)[0]
        output_png_filename = f"{base_name}.png"
        try:
            data_df = pd.read_csv(param)
            plot_and_save_graph(data_df, os.path.basename(param), output_png_filename)
        except Exception as e:
            sys.stderr.write(f"Error processing file {param}: {e}\n")
    else:
        keyword = param
        output_png_filename = f"{keyword}.png"
        aggregated_dfs = []
        matched_files = []
        
        for fname in sorted(os.listdir('.')):
            if keyword in fname and fname.endswith('.csv'):
                try:
                    temp_df = pd.read_csv(fname)
                    if 'episode' in temp_df.columns and 'reward' in temp_df.columns:
                        aggregated_dfs.append(temp_df[['episode', 'reward']])
                        matched_files.append(fname)
                    else:
                        sys.stderr.write(f"Warning: Skipping {fname} (missing required columns).\n")
                except Exception as e:
                    sys.stderr.write(f"Error reading/processing {fname}: {e}\n")
        
        if aggregated_dfs:
            combined_df = pd.concat(aggregated_dfs, ignore_index=True)
            combined_df = combined_df.sort_values(by='episode').reset_index(drop=True)
            
            plot_title = keyword
            plot_and_save_graph(combined_df, plot_title, output_png_filename)
        else:
            sys.stderr.write(f"No CSV files found containing keyword '{keyword}' or no valid data. Not saving {output_png_filename}.\n")