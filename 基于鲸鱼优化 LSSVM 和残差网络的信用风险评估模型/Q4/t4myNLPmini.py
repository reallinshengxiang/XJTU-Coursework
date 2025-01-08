import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from scipy.optimize import minimize
from scipy.spatial.distance import pdist, squareform

# 读取数据
readfile = pd.read_csv('3 (2).csv')

data = readfile.iloc[:1000, :24]
labels = readfile.iloc[:1000, 24]


scaler = StandardScaler()
data_scaled = scaler.fit_transform(data)

def calculate_proportion_difference_with_penalty(cluster_assignments, data_scaled, labels, k, epsilon=1e-6, penalty_weight=1.0):
    results = pd.DataFrame({'Cluster': np.round(cluster_assignments).astype(int), 'Label': labels})
    grouped = results.groupby('Cluster')['Label'].value_counts(normalize=True).unstack().fillna(0)
    good_ratios = grouped.get(1, pd.Series([0]*k))
    bad_ratios = grouped.get(0, pd.Series([0]*k))
    ratios = good_ratios / (bad_ratios + good_ratios + epsilon)


    proportion_difference = ratios.std()  


    penalty = 0
    for i in range(k):
        for j in range(i + 1, k):
            penalty += np.exp(-abs(ratios[i] - ratios[j])) 

    return -(proportion_difference - penalty_weight * penalty) 


def distance_constraint(cluster_assignments, data_scaled, k, d=1.0):
    constraints = []
    cluster_assignments = np.round(cluster_assignments).astype(int)
    for cluster in range(k):
        cluster_points = data_scaled[cluster_assignments == cluster]
        if len(cluster_points) > 1:
            distances = pdist(cluster_points, 'euclidean')
            constraints.extend(distances - d)
    return np.array(constraints)


def optimize_clusters(data_scaled, labels, k, d=1.0, penalty_weight=1.0, epsilon=1e-6):
    n_samples = data_scaled.shape[0]

    initial_assignments = np.random.randint(0, k, n_samples)

    cons = {'type': 'ineq', 'fun': lambda x: -distance_constraint(x, data_scaled, k, d)}

    result = minimize(calculate_proportion_difference_with_penalty, initial_assignments, args=(data_scaled, labels, k, epsilon, penalty_weight), constraints=cons, method='SLSQP', options={'disp': True})
    optimal_cluster_assignments = np.round(result.x).astype(int)
    return optimal_cluster_assignments, result.fun
k = 6  
d = 1.0 
penalty_weight = 2.0
epsilon = 1e-6
optimal_cluster_assignments, best_objective_value = optimize_clusters(data_scaled, labels, k, d, penalty_weight, epsilon)
best_results = pd.DataFrame({'Cluster': optimal_cluster_assignments, 'Label': labels})
print(f"Best Objective Function Value: {best_objective_value}")
grouped = best_results.groupby('Cluster')['Label'].value_counts(normalize=True).unstack().fillna(0)
good_ratios = grouped.get(1, pd.Series([0]*k))
bad_ratios = grouped.get(0, pd.Series([0]*k))
ratios = good_ratios / (bad_ratios + good_ratios + epsilon)
print(ratios)
