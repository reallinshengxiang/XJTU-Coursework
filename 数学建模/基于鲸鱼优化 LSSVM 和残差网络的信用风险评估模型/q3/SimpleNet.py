import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader

import pandas as pd
from sklearn.metrics import roc_auc_score, accuracy_score, confusion_matrix

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.metrics import accuracy_score, roc_auc_score, confusion_matrix, precision_recall_curve, auc
from sklearn.model_selection import train_test_split
import itertools

df = pd.read_csv('data/Aus1.csv')
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

# def evaluate_model(model, dataloader):
#     model.eval()
#     y_true = []
#     y_pred = []
    
#     with torch.no_grad():
#         for inputs, labels in dataloader:
#             outputs = model(inputs)
#             predictions = torch.round(torch.sigmoid(outputs))
            
#             y_true.extend(labels.numpy())
#             y_pred.extend(predictions.numpy())
    
#     y_true = [int(x) for x in y_true]
#     y_pred = [int(x) for x in y_pred]
    
#     accuracy = accuracy_score(y_true, y_pred)
#     print(y_true)
#     print(y_pred)
#     auc = roc_auc_score(y_true, y_pred)
    
#     tn, fp, fn, tp = confusion_matrix(y_true, y_pred).ravel()
#     type1_error = fp / (fp + tn)
#     type2_error = fn / (fn + tp)
    
#     return accuracy, auc, type1_error, type2_error



class CustomDataset(Dataset):
    def __init__(self, csv_file, train=True):
        self.data = pd.read_csv(csv_file)
        
        if train:
            self.data = self.data.iloc[:600]
        else:
            self.data = self.data.iloc[600:]
        
        self.X = self.data.iloc[:, :20].values
        self.y = self.data.iloc[:, 24].values
        self.y = torch.tensor(self.y, dtype=torch.float32)
        self.X = torch.tensor(self.X, dtype=torch.float32)
        # print(self.y)
        
    def __len__(self):
        return len(self.data)
    
    def __getitem__(self, idx):
        features = self.X[idx]
        label = self.y[idx]
        return features, label

class SimpleNN(nn.Module):
    def __init__(self):
        super(SimpleNN, self).__init__()
        self.ae1 = nn.Linear(20, 10)
        self.relu = nn.ReLU()
        self.dropout = nn.Dropout(p=0.5) 
        self.ae2 = nn.Linear(10, 20)
        self.fc1 = nn.Linear(20, 37)
        self.fc2 = nn.Linear(37, 20)
        self.fc3 = nn.Linear(20, 1)
        self.fc4 = nn.Linear(20, 20)
        self.fc5 = nn.Linear(20, 20)
        self.fc6 = nn.Linear(20, 20)
        self.mlp1 = nn.Linear(20, 50)
        self.mlp2 = nn.Linear(50, 20)

    # def forward(self, x):
    #     x = self.ae1(x)
    #     x = self.relu(x)
    #     x = self.ae2(x)
    #     y = self.fc1(x)
    #     y = self.relu(y)
    #     # x = self.dropout(x)
    #     # x = y + x
    #     y = self.fc2(y)
    #     y = self.relu(y)
    #     # x = self.dropout(x)
    #     x = y + x
    #     x = self.fc3(x)
    #     # x = self.relu(x)
    #     return x
    
    def forward(self, x):
        # x = self.ae1(x)
        # x = self.relu(x)
        # x = self.ae2(x)
        # y = self.fc4(x)
        # y = self.relu(y)
        # x = y + x
        # x = y
        # y = self.fc5(x)
        # y = self.relu(y)
        # x = y + x
        # x = y
        # y = self.fc6(x)
        # y = self.relu(y)
        # x = y + x
        # x = y
        x = self.mlp1(x)
        x = self.relu(x)
        x = self.mlp2(x)
        x = self.fc3(x)
        # x = self.relu(x)
        return x

csv_file = 'data/Ger2_shuffled.csv'
# csv_file = 'data/Ger1.csv'

train_dataset = CustomDataset(csv_file, train=True)
val_dataset = CustomDataset(csv_file, train=False)

train_dataloader = DataLoader(train_dataset, batch_size=32, shuffle=True)
val_dataloader = DataLoader(val_dataset, batch_size=32, shuffle=False)

model = SimpleNN()

criterion = nn.BCEWithLogitsLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

num_epochs = 100

# for epoch in range(num_epochs):
#     model.train()
#     running_loss = 0.0
#     for inputs, labels in train_dataloader:
#         optimizer.zero_grad()
#         outputs = model(inputs)
#         # print(outputs)
#         loss = criterion(outputs.squeeze(), labels)
#         loss.backward()
#         optimizer.step()

#         running_loss += loss.item()

#     train_loss = running_loss / len(train_dataloader)
    
#     model.eval()
#     val_loss = 0.0
#     with torch.no_grad():
#         for inputs, labels in val_dataloader:
#             outputs = model(inputs)
#             loss = criterion(outputs.squeeze(), labels)
#             val_loss += loss.item()

#     val_loss /= len(val_dataloader)
    
#     print(f'Epoch [{epoch+1}/{num_epochs}], Train Loss: {train_loss:.4f}, Val Loss: {val_loss:.4f}')

# print('Finished Training')

def evaluate_model(model, dataloader):
    model.eval()
    y_true = []
    y_pred = []
    
    with torch.no_grad():
        for inputs, labels in dataloader:
            outputs = model(inputs)
            predictions = torch.round(torch.sigmoid(outputs))
            
            y_true.extend(labels.numpy())
            y_pred.extend(predictions.numpy())
    
    y_true = [int(x) for x in y_true]
    y_pred = [int(x) for x in y_pred]
    
    accuracy = accuracy_score(y_true, y_pred)
    auc_value = roc_auc_score(y_true, y_pred)
    
    return accuracy, auc_value

# 训练过程中记录训练集准确率
train_accuracies = []
train_aucs = []
plt.figure()
for epoch in range(num_epochs):
    model.train()
    running_loss = 0.0
    for inputs, labels in train_dataloader:
        optimizer.zero_grad()
        outputs = model(inputs)
        loss = criterion(outputs.squeeze(), labels)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

    train_loss = running_loss / len(train_dataloader)
    
    # Evaluate on training set
    train_accuracy, train_auc = evaluate_model(model, train_dataloader)
    train_accuracies.append(train_accuracy)
    train_aucs.append(train_auc)
    
    model.eval()
    val_loss = 0.0
    with torch.no_grad():
        for inputs, labels in val_dataloader:
            outputs = model(inputs)
            loss = criterion(outputs.squeeze(), labels)
            val_loss += loss.item()

    val_loss /= len(val_dataloader)
    
    print(f'Epoch [{epoch+1}/{num_epochs}], Train Loss: {train_loss:.4f}, Train Accuracy: {train_accuracy:.4f}, Train AUC: {train_auc:.4f}, Val Loss: {val_loss:.4f}')

    # 在这里绘制训练过程中准确率的变化图
    
    plt.plot(range(1, epoch + 2), train_accuracies)
    # plt.plot(range(1, epoch + 2), train_aucs, label='Train AUC')

    
    
    

print('Finished Training')
plt.xlabel('Epoch')
plt.ylabel('准确率')
# plt.title('Training Metrics')
# plt.legend()
plt.grid(True)
plt.show()

# 最终评估模型
val_accuracy, val_auc = evaluate_model(model, val_dataloader)
print(f'Validation Accuracy: {val_accuracy:.4f}')
print(f'Validation AUC: {val_auc:.4f}')


# print(f'Validation Accuracy: {val_accuracy:.4f}')
# print(f'Validation AUC: {val_auc:.4f}')
# print(f'Validation Type I Error: {val_type1_error:.4f}')
# print(f'Validation Type II Error: {val_type2_error:.4f}')



# 评估模型
model.eval()
y_true = []
y_pred = []

with torch.no_grad():
    for inputs, labels in val_dataloader:
        outputs = model(inputs)
        predictions = torch.round(torch.sigmoid(outputs)).numpy()
        y_true.extend(labels.numpy())
        y_pred.extend(predictions)

y_true = np.array(y_true)
y_pred = np.array(y_pred)

# 计算评估指标
accuracy = accuracy_score(y_true, y_pred)
auc1 = roc_auc_score(y_true, y_pred)
cm = confusion_matrix(y_true, y_pred)
tn, fp, fn, tp = cm.ravel()
type1_error = fp / (fp + tn)
type2_error = fn / (fn + tp)

print(f'Validation Accuracy: {accuracy:.4f}')
print(f'Validation AUC: {auc1:.4f}')
print(f'Validation Type I Error: {type1_error:.4f}')
print(f'Validation Type II Error: {type2_error:.4f}')

# 绘制混淆矩阵
plt.figure()
plt.imshow(cm, interpolation='nearest', cmap=plt.cm.Greens)
plt.colorbar()
# plt.title('Confusion Matrix')
plt.xlabel('预测')
plt.ylabel('真实')
plt.xticks([0, 1], ['正样本', '负样本'])
plt.yticks([0, 1], ['正样本', '负样本'])
plt.show()

# 绘制精确度-召回率曲线
precision, recall, _ = precision_recall_curve(y_true, y_pred)
pr_auc = auc(recall, precision)

plt.figure()
plt.plot(recall, precision, color='darkorange', lw=2, label=f'PR曲线')
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.title('Precision-Recall curve')
plt.legend(loc='lower right')
plt.show()




# import torch
# import torch.nn as nn
# import torch.optim as optim
# from torch.utils.data import Dataset, DataLoader
# import pandas as pd
# import matplotlib.pyplot as plt
# from sklearn.metrics import accuracy_score


# class SimpleNN(nn.Module):
#     def __init__(self):
#         super(SimpleNN, self).__init__()
#         self.ae1 = nn.Linear(14, 10)
#         self.relu = nn.ReLU()
#         self.dropout = nn.Dropout(p=0.5) 
#         self.ae2 = nn.Linear(10, 14)
#         self.fc1 = nn.Linear(14, 37)
#         self.fc2 = nn.Linear(37, 14)
#         self.fc3 = nn.Linear(14, 1)
#         self.fc4 = nn.Linear(14, 14)
#         self.fc5 = nn.Linear(14, 14)
#         self.fc6 = nn.Linear(14, 14)
#         self.mlp1 = nn.Linear(14, 50)
#         self.mlp2 = nn.Linear(50, 14)

#     # def forward(self, x):
#     #     x = self.ae1(x)
#     #     x = self.relu(x)
#     #     x = self.ae2(x)
#     #     y = self.fc1(x)
#     #     y = self.relu(y)
#     #     # x = self.dropout(x)
#     #     # x = y + x
#     #     y = self.fc2(y)
#     #     y = self.relu(y)
#     #     # x = self.dropout(x)
#     #     x = y + x
#     #     x = self.fc3(x)
#     #     # x = self.relu(x)
#     #     return x
    
#     def forward(self, x):
#         x = self.ae1(x)
#         x = self.relu(x)
#         x = self.ae2(x)
#         y = self.fc4(x)
#         y = self.relu(y)
#         x = y + x
#         x = y
#         y = self.fc5(x)
#         y = self.relu(y)
#         x = y + x
#         x = y
#         y = self.fc6(x)
#         y = self.relu(y)
#         x = y + x
#         x = y
#         x = self.mlp1(x)
#         x = self.relu(x)
#         x = self.mlp2(x)
#         x = self.fc3(x)
#         # x = self.relu(x)
#         return x


# class CustomDataset(Dataset):
#     def __init__(self, csv_file, train=True):
#         self.data = pd.read_csv(csv_file)
        
#         if train:
#             self.data = self.data.iloc[:1200]
#         else:
#             self.data = self.data.iloc[1200:]
        
#         self.X = self.data.iloc[:, :14].values
#         self.y = self.data.iloc[:, -1].values
#         self.y = torch.tensor(self.y, dtype=torch.float32)
#         self.X = torch.tensor(self.X, dtype=torch.float32)
        
#     def __len__(self):
#         return len(self.data)
    
#     def __getitem__(self, idx):
#         features = self.X[idx]
#         label = self.y[idx]
#         return features, label

# def evaluate_model(model, dataloader):
#     model.eval()
#     y_true = []
#     y_pred = []
    
#     with torch.no_grad():
#         for inputs, labels in dataloader:
#             outputs = model(inputs)
#             predictions = torch.round(torch.sigmoid(outputs))
            
#             y_true.extend(labels.numpy())
#             y_pred.extend(predictions.numpy())
    
#     y_true = [int(x) for x in y_true]
#     y_pred = [int(x[0]) for x in y_pred]
    
#     accuracy = accuracy_score(y_true, y_pred)
    
#     return accuracy

# # Load your dataset and create dataloaders
# csv_file = 'data/Ger3.csv'
# train_dataset = CustomDataset(csv_file, train=True)
# val_dataset = CustomDataset(csv_file, train=False)

# train_dataloader = DataLoader(train_dataset, batch_size=32, shuffle=True)
# val_dataloader = DataLoader(val_dataset, batch_size=32, shuffle=False)

# # Initialize your model, criterion, and optimizer
# model = SimpleNN()
# criterion = nn.BCEWithLogitsLoss()
# optimizer = optim.Adam(model.parameters(), lr=0.001)

# # Training loop
# num_epochs = 50
# train_accuracy_values = []
# val_accuracy_values = []

# for epoch in range(num_epochs):
#     model.train()
#     running_loss = 0.0
#     correct = 0
#     total = 0
    
#     for inputs, labels in train_dataloader:
#         optimizer.zero_grad()
#         outputs = model(inputs)
#         loss = criterion(outputs.squeeze(), labels)
#         loss.backward()
#         optimizer.step()

#         running_loss += loss.item()
        
#         # Calculate training accuracy
#         predicted = torch.round(torch.sigmoid(outputs))
#         correct += (predicted == labels).sum().item()
#         total += labels.size(0)
    
#     train_accuracy = correct / total
#     train_accuracy_values.append(train_accuracy)
    
#     # Evaluate on validation set
#     model.eval()
#     val_accuracy = evaluate_model(model, val_dataloader)
#     val_accuracy_values.append(val_accuracy)
    
#     print(f'Epoch [{epoch+1}/{num_epochs}], Train Loss: {running_loss / len(train_dataloader):.4f}, Train Acc: {train_accuracy:.4f}, Val Acc: {val_accuracy:.4f}')

# print('Finished Training')

# # Plotting accuracy over epochs
# plt.figure()
# plt.plot(range(1, num_epochs+1), train_accuracy_values, label='Train Accuracy')
# plt.plot(range(1, num_epochs+1), val_accuracy_values, label='Validation Accuracy')
# plt.xlabel('Epoch')
# plt.ylabel('Accuracy')
# plt.title('Training and Validation Accuracy')
# plt.legend()
# plt.grid(True)
# plt.show()
