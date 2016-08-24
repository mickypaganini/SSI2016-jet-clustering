print(__doc__)

from sklearn.cluster import AffinityPropagation
from sklearn import metrics
from sklearn.datasets.samples_generator import make_blobs
import numpy as np
from read_data import read_data
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from itertools import cycle

def af(readin, txtfile, event=2):
	##############################################################################
	# Generate sample data
	if readin:
		X_all, e_all = read_data(txtfile)
		X = X_all[event]
		e = e_all[event]
		# Scale e to 0 mean, 1 sd to use as 'preference' in AffinityPropagation (IR)
		scaler = StandardScaler()
		preference = scaler.fit_transform(e) - 100 # -3 just seems to work well 

	else:
		centers = [[1, 1], [-1, -1], [1, -1]]
		X, labels_true = make_blobs(n_samples=300, centers=centers, cluster_std=0.5,
															random_state=0)
		preference = -50

	##############################################################################
	# Compute Affinity Propagation
	af = AffinityPropagation(preference=preference).fit(X) #preference=-1
	cluster_centers_indices = af.cluster_centers_indices_
	cluster_centers = af.cluster_centers_
	print 'Centroids: \n{}'.format(cluster_centers)
	labels = af.labels_
	n_clusters_ = len(cluster_centers_indices)

	print('Estimated number of clusters: %d' % n_clusters_)
	if not readin: # -- need to have truth info about cluster label
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
	# -- display event
	binx = np.linspace(-3.0, 3.0, 61)
	biny = np.linspace(-3.1, 3.1, 63)
	if readin:
		plt.hist2d(X[:, 0], X[:, 1], weights=e.ravel(), bins=(binx, biny), cmap='rainbow', norm=LogNorm())
		cb = plt.colorbar()
		cb.set_label('Energy (GeV)')
	plt.xlabel(r'$\eta$')
	plt.ylabel(r'$\phi$')
	# -- display clustering features
	for k in range(n_clusters_):
		class_members = labels == k
		cluster_center = cluster_centers[k]
		if not readin:
			plt.plot(X[class_members, 0], X[class_members, 1], 'k.', alpha=0.2)
		plt.plot(cluster_center[0], cluster_center[1], 'ko', markerfacecolor='None', #markeredgecolor='k', 
						 markersize=14)
		for x in X[class_members]:
			plt.plot([cluster_center[0], x[0]], [cluster_center[1], x[1]], color='black',alpha=0.2)

	plt.title('Estimated number of clusters: %d' % n_clusters_)
	plt.show()

if __name__ == '__main__':
	import sys
	import argparse

	# Read in arguments
	parser = argparse.ArgumentParser()
	parser.add_argument('--readin', help="pass this flag to read in blobs from txt file; else make_blobs", action='store_true')
	parser.add_argument('--txtfile', help="path to the text file with data", default='JetGenerator/clu10_2jets_withNoise.txt')
	parser.add_argument('--event', help="int, number of the event to consider", type=int)
	
	args = parser.parse_args()

	# Pass arguments to main
	if args.event is not None:
		sys.exit(af(args.readin, args.txtfile, args.event))
	else:
		sys.exit(af(args.readin, args.txtfile))
