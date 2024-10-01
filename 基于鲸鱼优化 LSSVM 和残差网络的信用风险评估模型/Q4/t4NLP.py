import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from scipy.optimize import minimize, LinearConstraint, Bounds
from scipy.spatial.distance import pdist, squareform
import math
readfile = pd.read_csv('3 (2).csv')
data = readfile.iloc[:1000, :24]
labels = readfile.iloc[:1000, 24]
scaler = StandardScaler()
data_scaled = scaler.fit_transform(data)
def calculate_proportion_difference_with_penalty_and_constraints(cluster_assignments, data_scaled, labels, k, d=1.0, penalty_weight=1.0, epsilon=1e-6):
    cluster_assignments = np.round(cluster_assignments).astype(int)
    results = pd.DataFrame({'Cluster': cluster_assignments, 'Label': labels})
    grouped = results.groupby('Cluster')['Label'].value_counts(normalize=True).unstack().fillna(0)
    good_ratios = grouped.get(1, pd.Series([0]*k))
    bad_ratios = grouped.get(0, pd.Series([0]*k))
    ratios = good_ratios / (bad_ratios + good_ratios + epsilon)
    proportion_difference = ratios.std()
    penalty = np.sum([np.exp(-abs(ratios[i] - ratios[j])) for i in range(k) for j in range(i + 1, k)]) 

    for cluster in range(k):
        cluster_points = data_scaled[cluster_assignments == cluster]
        if len(cluster_points) > 1:
            distances = pdist(cluster_points, 'euclidean')
            if np.any(distances > d):
                return float('inf') 

    return -(proportion_difference - penalty_weight * penalty)
def optimize_clusters(data_scaled, labels, k, d=1.0, penalty_weight=1.0, epsilon=1e-6):
    n_samples = data_scaled.shape[0]
    initial_cluster_assignments = np.random.randint(0, k, n_samples)
    bounds = Bounds([0]*n_samples, [k-1]*n_samples)
    constraints = []
    result = minimize(
        calculate_proportion_difference_with_penalty_and_constraints, 
        initial_cluster_assignments, 
        args=(data_scaled, labels, k, d, penalty_weight, epsilon),
        method='trust-constr',
        bounds=bounds,
        constraints=constraints,
        options={'disp': True}
    )

    return result.x

k = 10  
d = 1.0  
penalty_weight = 1.0

optimal_cluster_assignments = optimize_clusters(data_scaled, labels, k, d, penalty_weight)

optimal_cluster_assignments = np.round(optimal_cluster_assignments).astype(int)
results = pd.DataFrame({'Cluster': optimal_cluster_assignments, 'Label': labels})
print(f"Optimal cluster assignments:\n{results}")
grouped = results.groupby('Cluster')['Label'].value_counts(normalize=True).unstack().fillna(0)
good_ratios = grouped.get(1, pd.Series([0]*k))
bad_ratios = grouped.get(0, pd.Series([0]*k))
ratios = good_ratios / (bad_ratios + good_ratios + epsilon)
print(ratios)
