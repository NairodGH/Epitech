import torch
from tqdm import tqdm
import sys

from utils.load_data import load_data
from utils.network import CNN

model_name = 'model.pth'
if len(sys.argv) > 1:
    model_name = sys.argv[1]

dataset = load_data(path='datasets/test', batch_size=64)

# Define the device
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print('Device:', device, '\n')

# Create an instance of the model
num_classes = len(dataset.dataset.classes)
model = CNN(num_classes=num_classes).to(device)

print('Loading the model', model_name + '...')
model.load_state_dict(torch.load(model_name))
model.eval()

# Test the model
correct = 0
total = 0

progress_bar = tqdm(total=len(dataset), desc='Testing', position=0, leave=True)

with torch.no_grad():
    for inputs, labels in dataset:
        logits = model.forward(inputs)
        _, predicted = torch.max(logits, 1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

        progress_bar.update(1)

progress_bar.close()

print('Accuracy of the network on the test images: %d %%' % (100 * correct / total))
