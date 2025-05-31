import torch
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
import numpy as np

# 定义数据预处理：转换为张量 + 中心裁剪为统一尺寸
target_size = 32
transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Resize(target_size + 4),       # 先放大尺寸
    transforms.CenterCrop(target_size)      # 再中心裁剪
])

# 下载并加载CIFAR10数据集
trainset = torchvision.datasets.CIFAR10(
    root='./data',
    train=True,
    download=True,
    transform=transform
)
trainloader = torch.utils.data.DataLoader(
    trainset,
    batch_size=64,
    shuffle=True
)

# 获取一个批次数据
dataiter = iter(trainloader)
#images, labels = dataiter.next()
images, labels = next(dataiter)
# 选择前10张图片并生成网格
selected_images = images[:10]
grid = torchvision.utils.make_grid(selected_images, nrow=10, padding=2)

# 转换为Matplotlib可显示格式
grid_np = grid.numpy().transpose((1, 2, 0))

# 绘制图像
plt.imshow(np.clip(grid_np, 0, 1))
plt.axis('off')
plt.title('CIFAR10 Sample Images')
plt.savefig('cifar10_sample.png', bbox_inches='tight', dpi=200)
plt.show()

# 定义数据预处理：转换为张量 + 中心裁剪为统一尺寸
target_size = 32  # 可修改为目标尺寸（如24或64）
transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Resize(target_size + 4),       # 先放大尺寸
    transforms.CenterCrop(target_size),      # 再中心裁剪
    #transforms.RandomCrop(target_size)      # 若需要随机裁剪可取消注释
])

# 下载并加载CIFAR10数据集
trainset = torchvision.datasets.CIFAR10(
    root='./data',
    train=True,
    download=True,
    transform=transform
)
trainloader = torch.utils.data.DataLoader(
    trainset,
    batch_size=64,
    shuffle=True
)

# 获取一个批次数据
dataiter = iter(trainloader)
#images, labels = dataiter.next()
images, labels = next(dataiter)
# 选择前10张图片并生成网格
selected_images = images[:10]
grid = torchvision.utils.make_grid(selected_images, nrow=10, padding=2)

# 转换为Matplotlib可显示格式
grid_np = grid.numpy().transpose((1, 2, 0))

means = []
stds = []
for images, _ in trainloader:
    for c in range(images.shape[1]):
        if len(means) <= c:
            means.append([])
            stds.append([])
        means[c].append(images[:, c, :, :].mean().item())
        stds[c].append(images[:, c, :, :].std().item())

channel_means = [np.mean(m) for m in means]
channel_stds = [np.mean(s) for s in stds]

# 定义包含归一化的新转换
transform_with_normalization = transforms.Compose([
    transforms.ToTensor(),
    transforms.Resize(target_size + 4),
    transforms.CenterCrop(target_size),
    transforms.Normalize(mean=channel_means, std=channel_stds)
])

# 重新加载数据集，使用包含归一化的转换
trainset_normalized = torchvision.datasets.CIFAR10(
    root='./data',
    train=True,
    download=False,
    transform=transform_with_normalization
)
trainloader_normalized = torch.utils.data.DataLoader(
    trainset_normalized,
    batch_size=64,
    # shuffle=True
    shuffle=False
)

# 获取归一化后的一个批次数据
dataiter_normalized = iter(trainloader_normalized)
images_normalized, labels_normalized = next(dataiter_normalized)

# 选择归一化后的前10张图片并生成网格
selected_images_normalized = images_normalized[:10]
grid_normalized = torchvision.utils.make_grid(selected_images_normalized, nrow=10, padding=2)

# 转换为Matplotlib可显示格式
grid_np_normalized = grid_normalized.numpy().transpose((1, 2, 0))

# 计算减去均值后的数据
channel_means_tensor = torch.tensor(channel_means).view(3, 1, 1)
images_minus_mean = selected_images - channel_means_tensor
grid_minus_mean = torchvision.utils.make_grid(images_minus_mean, nrow=10, padding=2)
grid_np_minus_mean = grid_minus_mean.numpy().transpose((1, 2, 0))

# 绘制图像
plt.figure(figsize=(15, 7.5))

# 原数据
plt.subplot(3, 1, 1)
plt.imshow(grid_np)
plt.axis('off')
plt.title('CIFAR10 Sample Images (Original)')

# 减去均值后的数据
plt.subplot(3, 1, 2)
plt.imshow(np.clip(grid_np_minus_mean, 0, 1))
#plt.imshow(grid_np_minus_mean)
plt.axis('off')
plt.title('CIFAR10 Sample Images (After Subtracting Mean)')

# 归一化之后的数据
plt.subplot(3, 1, 3)
plt.imshow(np.clip(grid_np_normalized, 0, 1))
plt.axis('off')
plt.title('CIFAR10 Sample Images (After Normalization)')

plt.savefig('cifar10_samples.png', bbox_inches='tight', dpi=200)
plt.show()