import pandas as pd
import numpy as np

file_path = 'data/Ger.csv'
data = pd.read_csv(file_path)
data = data.iloc[:, :20]
data_values = data.values.astype(float)
print(data_values)
for i in range(data_values.shape[0]):
    for j in range(data_values.shape[1]):
        if data_values[i, j] == 0:
            data_values[i, j] = 0.01
print(data_values)

def entropy(values):
    e = -np.sum(values * np.log(values))
    return e

num_attributes = data_values.shape[1]
entropies = []
for i in range(num_attributes):
    attribute_values = data_values[:, i]
    normalized_values = attribute_values / np.sum(attribute_values)
    e = entropy(normalized_values)
    entropies.append(e)

def calculate_weights(entropies):
    n = len(entropies)
    weights = []
    sum_e = np.sum(entropies)
    for e in entropies:
        w = (1 - e) / (n - sum_e)
        weights.append(w)
    return weights

weights = calculate_weights(entropies)

weights_normalized = weights / np.sum(weights)

print("属性权重（未归一化）：", weights)
print("属性权重（归一化）：", weights_normalized)
