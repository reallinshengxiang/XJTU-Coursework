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

def calculate_proportion_difference_with_penalty(results, k, epsilon=1e-6, penalty_weight=1.0):
    grouped = results.groupby('Cluster')['Label'].value_counts(normalize=True).unstack().fillna(0)
    good_ratios = grouped.get(1, pd.Series([0]*k))
    bad_ratios = grouped.get(0, pd.Series([0]*k))
    ratios = good_ratios / (bad_ratios + good_ratios + epsilon)

    proportion_difference = ratios.std()

    penalty = 0
    for i in range(k):
        for j in range(i + 1, k):
            penalty += math.exp(-abs(ratios[i] - ratios[j])) 

    return proportion_difference - penalty_weight * penalty

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


def simulated_annealing_fixed_k(data, labels, initial_temp, final_temp, alpha, k, num_iterations, penalty_weight):
    current_temp = initial_temp

    kmeans = KMeans(n_clusters=k, init='k-means++', n_init=10)
    clusters = kmeans.fit_predict(data)
    results = pd.DataFrame({'Cluster': clusters, 'Label': labels})
    current_solution = results
    current_objective_value = calculate_proportion_difference_with_penalty(results, k, penalty_weight=penalty_weight)
    
    best_solution = current_solution
    best_objective_value = current_objective_value

    while current_temp > final_temp:
        print(current_temp)
        for j in range(num_iterations):
            new_solution = current_solution.copy()
            idx = np.random.randint(0, len(data))
            new_cluster = np.random.randint(0, k)
            new_solution.at[idx, 'Cluster'] = new_cluster
            
            new_objective_value = calculate_proportion_difference_with_penalty(new_solution, k, penalty_weight=penalty_weight)
            

            if new_objective_value > current_objective_value:  
                current_solution = new_solution
                current_objective_value = new_objective_value
                if new_objective_value > best_objective_value:
                    best_solution = current_solution
                    best_objective_value = new_objective_value
            else:
                acceptance_probability = math.exp((new_objective_value - current_objective_value) / current_temp)
                if acceptance_probability > random.random():
                    current_solution = new_solution
                    current_objective_value = new_objective_value


        current_temp *= alpha

    return best_solution, best_objective_value

initial_temp = 1000
final_temp = 1
alpha = 0.96
k = 6 
num_iterations = 100
penalty_weight = 1.0  

best_solution, best_objective_value = simulated_annealing_fixed_k(data_scaled, labels, initial_temp, final_temp, alpha, k, num_iterations, penalty_weight)


print(f"Best Objective Function Value: {best_objective_value}")
getans(best_solution, k)
