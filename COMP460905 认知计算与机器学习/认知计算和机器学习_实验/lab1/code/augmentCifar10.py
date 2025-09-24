import torch
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
import numpy as np
from torchvision.datasets import CIFAR10

# 定义图像变换操作
#transform_original = transforms.Compose([
#    transforms.ToTensor()
#])
transform_original = transforms.Compose([])
# 定义不同的图像变换
transform_rotate = transforms.Compose([
    transforms.RandomRotation(30),
    transforms.ToTensor()
])

transform_flip = transforms.Compose([
    transforms.RandomHorizontalFlip(p=1),
    transforms.ToTensor()
])

transform_crop = transforms.Compose([
    transforms.RandomCrop(32, padding=4),
    transforms.ToTensor()
])

transform_rotate_30 = transforms.Compose([
    transforms.Lambda(lambda img: transforms.functional.rotate(img, -30)),
    transforms.ToTensor(),
    transforms.Resize(36),       # 先放大尺寸
    transforms.CenterCrop(30)      # 再中心裁剪
])

transform_rotate_60 = transforms.Compose([
    transforms.Lambda(lambda img: transforms.functional.rotate(img, -60)),
    transforms.ToTensor(),
    transforms.Resize(36),       # 先放大尺寸
    transforms.CenterCrop(30)      # 再中心裁剪
])

transform_stretch = transforms.Compose([
    # 将图像的宽度拉伸为原来的1.5倍，高度不变
    transforms.Resize((32, int(32 * 1.5))),
    transforms.ToTensor(),
    transforms.CenterCrop(32)
])

def add_noise(tensor):
    noise = torch.randn(tensor.size()) * 0.1
    return torch.clamp(tensor + noise, 0, 1)

# 加载CIFAR10数据集
testset = CIFAR10(root='./data', train=False, download=True, transform=transform_original)

# 选择指定索引的10张图片（这里选择前10张）
selected_indices = list(range(10))
#images = [testset[i]  :reference[]{#0} for i in selected_indices]
images = [testset[i][0] for i in selected_indices]
# 创建大图画布
fig, axs = plt.subplots(10, 8, figsize=(15, 30))
plt.subplots_adjust(wspace=0.1, hspace=0.8)
fontsize=6
# 处理并绘制每个图像
for row in range(10):
    # 原始图像
    #original_img = images[row].numpy().transpose((1, 2, 0))
    original_img = transforms.ToTensor()(images[row]).numpy().transpose((1, 2, 0))
    axs[row, 0].imshow(original_img)
    axs[row, 0].set_title("Original", fontsize=fontsize)
    
    # 旋转后的图像
    #rotated_img = transform_rotate(testset[selected_indices[row]]  :reference[]{#0}.numpy().transpose((1, 2, 0)))
    rotated_img = transform_rotate(testset[selected_indices[row]][0])
    axs[row, 1].imshow(rotated_img.numpy().transpose((1, 2, 0)))
    axs[row, 1].set_title("Random Rotated", fontsize=fontsize)
    
    # 翻转后的图像
    #flipped_img = transform_flip(testset[selected_indices[row]]  :reference[]{#0}.numpy().transpose((1, 2, 0)))
    flipped_img = transform_flip(testset[selected_indices[row]][0])
    axs[row, 2].imshow(flipped_img.numpy().transpose((1, 2, 0)))
    axs[row, 2].set_title("Flipped", fontsize=fontsize)
    
    # 裁剪后的图像
    #cropped_img = transform_crop(testset[selected_indices[row]]  :reference[]{#0}.numpy().transpose((1, 2, 0)))
    cropped_img = transform_crop(testset[selected_indices[row]][0])
    axs[row, 3].imshow(cropped_img.numpy().transpose((1, 2, 0)))
    axs[row, 3].set_title("Cropped", fontsize=fontsize)

    # 旋转30°后的图像
    rotated_img_30 = transform_rotate_30(testset[selected_indices[row]][0])
    axs[row, 4].imshow(rotated_img_30.numpy().transpose((1, 2, 0)))
    axs[row, 4].set_title("Rotated 30°", fontsize=fontsize)

    # 旋转60°后的图像
    rotated_img_60 = transform_rotate_60(testset[selected_indices[row]][0])
    axs[row, 5].imshow(rotated_img_60.numpy().transpose((1, 2, 0)))
    axs[row, 5].set_title("Rotated 60°", fontsize=fontsize)

    # 拉伸后的图像
    stretched_img = transform_stretch(testset[selected_indices[row]][0])
    axs[row, 6].imshow(stretched_img.numpy().transpose((1, 2, 0)))
    axs[row, 6].set_title("Stretched", fontsize=fontsize)
    # 加噪声后的图像
    #noisy_img = add_noise(images[row])
    noisy_img = add_noise(transforms.ToTensor()(images[row]))
    axs[row, 7].imshow(noisy_img.numpy().transpose((1, 2, 0)))
    axs[row, 7].set_title("Noisy", fontsize=fontsize)

# 关闭所有坐标轴
for ax in axs.flat:
    ax.axis('off')

plt.savefig('cifar10_augmentations.png', bbox_inches='tight', dpi=200)
plt.show()
