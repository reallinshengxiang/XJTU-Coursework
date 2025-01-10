import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
import random
import math
readfile = pd.read_csv('3 (2).csv')
data = readfile.iloc[:1000, :24]
labels = readfile.iloc[:1000, 24]
scaler = StandardScaler()
data_scaled = scaler.fit_transform(data)
def deallist(list):
    maxdis = 0
    totdis = 0
    for i in range(0, len(list)):
        totdis = totdis + (list[i] - (i) / (len(list) - 1)) * (list[i] - (i) / (len(list) - 1))
    return totdis
def calculate_objective_function(results, k, epsilon=1e-6):
    grouped = results.groupby('Cluster')['Label'].value_counts().unstack().fillna(0) 
    good_counts = grouped[1] + epsilon
    bad_counts = grouped[0] + epsilon
    ratios = good_counts / (bad_counts + good_counts)
    sorted_ratios = sorted(ratios)  
    return deallist(sorted_ratios) / k
def getans(results, k, epsilon=1e-6):
    num = [0] * k
    grouped = results.groupby('Cluster')['Label'].value_counts().unstack().fillna(0)
    good_counts = grouped[1] + epsilon
    bad_counts = grouped[0] + epsilon
    ratios = good_counts / (bad_counts + good_counts)
    print(ratios)
    cluster = results['Cluster']
    for i in range(len(cluster)):
        num[cluster[i]] = num[cluster[i]] + 1
    print(num)
def simulated_annealing(data, labels, initial_temp, final_temp, alpha, num_clusters, num_iterations):
    current_temp = initial_temp
    kmeans = KMeans(n_clusters=num_clusters, init='k-means++', n_init=10)
    clusters = kmeans.fit_predict(data)
    results = pd.DataFrame({'Cluster': clusters, 'Label': labels})
    current_solution = results
    current_objective_value = calculate_objective_function(results, num_clusters)
    best_solution = current_solution
    best_objective_value = current_objective_value
    while current_temp > final_temp:
        print(current_temp)
        for j in range(num_iterations):
            new_kmeans = KMeans(n_clusters=num_clusters, init='k-means++', n_init=10)
            new_clusters = new_kmeans.fit_predict(data)
            new_results = pd.DataFrame({'Cluster': new_clusters, 'Label': labels})
            new_objective_value = calculate_objective_function(new_results, num_clusters)
            if new_objective_value < current_objective_value:
                current_solution = new_results
                current_objective_value = new_objective_value
                if new_objective_value < best_objective_value:
                    best_solution = new_results
                    best_objective_value = new_objective_value
            else:
                acceptance_probability = math.exp((current_objective_value - new_objective_value) / current_temp)
                if acceptance_probability > random.random():
                    current_solution = new_results
                    current_objective_value = new_objective_value
        current_temp *= alpha

    return best_solution, best_objective_value
initial_temp = 1000
final_temp = 1
alpha = 0.95
num_clusters = 5
num_iterations = 100
best_solution, best_objective_value = simulated_annealing(data_scaled, labels, initial_temp, final_temp, alpha, num_clusters, num_iterations)
print(f"Best Objective Function Value: {best_objective_value}")
getans(best_solution, num_clusters)
