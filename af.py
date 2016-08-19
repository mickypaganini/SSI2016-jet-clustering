print(__doc__)

from sklearn.cluster import AffinityPropagation
from sklearn import metrics
from sklearn.datasets.samples_generator import make_blobs
import numpy as np
from read_data import read_data

def af(readin, event=2):
	##############################################################################
	# Generate sample data
	if readin:
		X_all, e_all = read_data()
		X = X_all[event]
	else:
		centers = [[1, 1], [-1, -1], [1, -1]]
		X, labels_true = make_blobs(n_samples=300, centers=centers, cluster_std=0.5,
															random_state=0)

	##############################################################################
	# Compute Affinity Propagation
	af = AffinityPropagation(preference=-1).fit(X) #preference=-50
	cluster_centers_indices = af.cluster_centers_indices_
	#print af.cluster_centers_
	labels = af.labels_

	n_clusters_ = len(cluster_centers_indices)

	print('Estimated number of clusters: %d' % n_clusters_)
	if not readin:
		print("Homogeneity: %0.3f" % metrics.homogeneity_score(labels_true, labels))
		print("Completeness: %0.3f" % metrics.completeness_score(labels_true, labels))
		print("V-measure: %0.3f" % metrics.v_measure_score(labels_true, labels))
		print("Adjusted Rand Index: %0.3f"
					% metrics.adjusted_rand_score(labels_true, labels))
		print("Adjusted Mutual Information: %0.3f"
					% metrics.adjusted_mutual_info_score(labels_true, labels))
		print("Silhouette Coefficient: %0.3f"
					% metrics.silhouette_score(X, labels, metric='sqeuclidean'))

	##############################################################################
	# Plot result
	import matplotlib.pyplot as plt
	from itertools import cycle

	plt.close('all')
	plt.figure(1)
	plt.clf()

	colors = cycle('bgrcmykbgrcmykbgrcmykbgrcmyk')
	for k, col in zip(range(n_clusters_), colors):
		class_members = labels == k
		cluster_center = X[cluster_centers_indices[k]]
		plt.plot(X[class_members, 0], X[class_members, 1], col + '.')
		plt.plot(cluster_center[0], cluster_center[1], 'o', markerfacecolor=col,
						 markeredgecolor='k', markersize=14)
		for x in X[class_members]:
			plt.plot([cluster_center[0], x[0]], [cluster_center[1], x[1]], col)

	plt.title('Estimated number of clusters: %d' % n_clusters_)
	plt.show()

if __name__ == '__main__':
	import sys
	import argparse

	# -- read in arguments
	parser = argparse.ArgumentParser()
	parser.add_argument('--readin', help="pass this flag to read in blobs from txt file; else make_blobs", action='store_true')
	parser.add_argument('--event', help="int, number of the event to consider", type=int)
	
	args = parser.parse_args()

	# -- pass arguments to main
	if args.event is not None:
		sys.exit(af(args.readin, args.event))
	else:
		sys.exit(af(args.readin))
