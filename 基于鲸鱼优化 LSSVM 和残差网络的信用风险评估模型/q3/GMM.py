import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.mixture import GaussianMixture
 
np.random.seed(0)
data = pd.read_csv('data/Ger2.csv')
print(data)
df = data.iloc[:, :20]
gmm = GaussianMixture(n_components=4, random_state=0)
gmm.fit(df)
 
means = gmm.means_
covariances = gmm.covariances_
 
print("Means:", means)
print("Covariances:", covariances)

cluster_labels = gmm.predict(df)

data['cluster'] = cluster_labels

output_filename = 'data/Ger2_clustered.csv'
data.to_csv(output_filename, index=False)

print(data['cluster'].value_counts())

# TODO PCA降维