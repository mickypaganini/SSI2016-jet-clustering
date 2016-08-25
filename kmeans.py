print(__doc__)

from sklearn.cluster import KMeans
from sklearn import metrics
from sklearn.datasets.samples_generator import make_blobs
import numpy as np
from read_and_rescale_data import read_and_rescale_data
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from itertools import cycle

def kmeans(readin, event=2):
	##############################################################################
	# Generate sample data
	if readin:
		X_all, e_all = read_and_rescale_data()
		X = X_all[event]
		e = e_all[event]
		# Scale e to 0 mean, 1 sd to use as 'preference' in AffinityPropagation (IR)
		scaler = StandardScaler()
		preference = scaler.fit_transform(e) - 3 # -3 just seems to work well 

	else:
		centers = [[1, 1], [-1, -1], [1, -1]]
		X, labels_true = make_blobs(n_samples=300, centers=centers, cluster_std=0.5,
															random_state=0)
		preference = -50

	##############################################################################
	# Compute Affinity Propagation
	km = KMeans(init='k-means++', n_clusters=2, n_init=10) #preference=-1
	km.fit(X)
	Z=km.predict(X)

	##############################################################################
	# Plot result
	# -- display event
	binx = np.linspace(-3.5, 3.5, 71)
	biny = np.linspace(-3.5, 3.5, 71)
	if readin:
		class0=Z==0
		class1=Z==1
		class2=Z==2
		plt.hist2d(X[class1, 0], X[class1, 1], weights=e[class1].ravel(), bins=(binx, biny), cmap='spring', norm=LogNorm())
		cba = plt.colorbar()
		cba.set_label('Energy (GeV)')
		plt.hist2d(X[class0, 0], X[class0, 1], weights=e[class0].ravel(), bins=(binx, biny), cmap='winter', norm=LogNorm())
		cbb = plt.colorbar()
		plt.hist2d(X[class2, 0], X[class2, 1], weights=e[class2].ravel(), bins=(binx, biny), cmap='Greens', norm=LogNorm())
	plt.xlabel(r'$\eta$')
	plt.ylabel(r'$\phi$')
	# -- display clustering features
	for k in range(0,2):
		plt.plot(km.cluster_centers_[k,0], km.cluster_centers_[k,1], 'ko', markerfacecolor='None', markersize=10)
	plt.title('K means clustering')
	plt.show()

if __name__ == '__main__':
	import sys
	import argparse

	# Read in arguments
	parser = argparse.ArgumentParser()
	parser.add_argument('--readin', help="pass this flag to read in blobs from txt file; else make_blobs", action='store_true')
	parser.add_argument('--event', help="int, number of the event to consider", type=int)
	
	args = parser.parse_args()

	# Pass arguments to main
	if args.event is not None:
		sys.exit(kmeans(args.readin, args.event))
	else:
		sys.exit(kmeans(args.readin))
