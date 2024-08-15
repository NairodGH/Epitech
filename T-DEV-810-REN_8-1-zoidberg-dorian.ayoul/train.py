import torch
from tqdm import tqdm
import sys

from utils.network import CNN
from utils.load_data import load_data

def train_model(dataset, model, num_epochs=20):
    # Define the loss function and optimizer
    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.001)

    model.train()
    accuracy_total_train = []

    for epoch in range(num_epochs):
        running_loss = 0.0
        progress_bar = tqdm(total=len(dataset), desc='Epoch {}/{}'.format(epoch+1, num_epochs), position=0, leave=True)

        for inputs, labels in dataset:
            optimizer.zero_grad()  # Zero the parameter gradients
            outputs = model(inputs)  # Forward pass
            loss = criterion(outputs, labels)  # Compute the loss
            loss.backward()  # Backward pass
            optimizer.step()  # Update the weights
            running_loss += loss.item() * inputs.size(0)

            outputs = torch.nn.functional.softmax(outputs, dim=1)
            _, preds = torch.max(outputs, 1)
            accuracy_total_train.append(torch.sum(preds == labels.data).item() / float(inputs.size(0)))

            progress_bar.update(1)

        epoch_loss = running_loss / len(dataset)
        progress_bar.close()
        print('Loss: {:.4f}'.format(epoch_loss), 'Accuracy: {:.4f}'.format(sum(accuracy_total_train) / len(accuracy_total_train)))

    print('Finished Training')
    return model

model_name = 'model.pth'
if len(sys.argv) > 1:
    model_name = sys.argv[1]

# Load datasets
dataset = load_data('datasets/train_transformed', subset_size=5216, batch_size=128)

# Define the device
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print('Device:', device, '\n')

# Create an instance of the model
num_classes = len(dataset.dataset.classes)
model = CNN(num_classes=num_classes).to(device)

# Training loop
model = train_model(dataset, model, num_epochs=5)

print('Saving the model...')
torch.save(model.state_dict(), model_name)
print('Model saved as', model_name)
