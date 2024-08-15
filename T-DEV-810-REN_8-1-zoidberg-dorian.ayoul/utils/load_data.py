import torch
from torchvision import transforms
from torchvision.datasets import ImageFolder
from torch.utils.data import DataLoader, SubsetRandomSampler, Subset
from torchvision.transforms import functional as F
import numpy as np
import cv2
from PIL import ImageFilter

class Denoise:
    def __call__(self, img):
        img = img.filter(ImageFilter.GaussianBlur(radius=1))
        return img

class HistogramEqualization:
    def __call__(self, img):
        img = np.array(img)
        if len(img.shape) == 3 and img.shape[2] == 3:
            img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
        img = cv2.equalizeHist(img)
        return F.to_pil_image(img)


def load_data(path, subset_size=624, batch_size=64):
    transform = transforms.Compose([
        HistogramEqualization(),
        Denoise(),
        transforms.Resize((224, 224)),
        transforms.ToTensor(),
        # to one channel
        # transforms.Grayscale(num_output_channels=1),
        # transforms.Normalize(mean=[0.485], std=[0.229])
    ])

    dataset_folder = ImageFolder(root=path, transform=transform)
    # subset = Subset(dataset_folder, range(subset_size))
    dataset = DataLoader(dataset_folder, batch_size=batch_size)

    print('Dataset\t', 'Train\t', dataset_folder.classes[0], '', dataset_folder.classes[1])
    print('Total:\t', len(dataset_folder), '\t', dataset_folder.targets.count(0), '\t', dataset_folder.targets.count(1))

    return dataset
