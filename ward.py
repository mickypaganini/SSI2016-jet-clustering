
print(__doc__)

from sklearn import metrics
import numpy as np
from read_data import read_data
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from itertools import cycle
import os

from sklearn.neighbors import DistanceMetric

def ward(txtfile, event, weighted, noise):
	run = 'ward'
	##############################################################################
	# Read in sample data
	X_all, e_all = read_data(txtfile)
	X = X_all[event]
	e = e_all[event].ravel()

	##############################################################################
	# Set variables depending on noise and weighting decisions
	# Filter out noise
	if not noise: 
		X = X[e > 1e-7]
		e = e[e > 1e-7]

	X_unweighted = X
	e_unweighted = e
	# Upweight events with high energy
	if weighted:
		# Weight by E/E_noise (actually that would be too high)
		NOISE_LVL = 0.08 # GeV
		X_rep = []
		e_rep = []
		for p, energy in zip(X, e):
			n_replications = int(np.ceil((energy / NOISE_LVL)))
			# if energy > 1:
			# 	print 'energy = {}, n_replications = {}'.format(energy, n_replications)
			X_rep.extend([p] * (n_replications))
			e_rep.extend([energy] * (n_replications))
		X = np.array(X_rep)
		e = np.array(e_rep)
		folder = 'weighted'
	else: # no weighting
		min_cluster_size=5
		folder = 'unweighted'

	# Sort output into correct directory
	if noise:
		folder = os.path.join(folder, 'with_noise', run)
	else:
		folder = os.path.join(folder, 'no_noise', run)	
	# Make sure that the output directory exists, otherwise create it
	if not os.path.exists(folder):
		os.makedirs(folder)

	##############################################################################
	# Compute Ward
	from sklearn.cluster import AgglomerativeClustering

	#for linkage in ('ward', 'average', 'complete'):
	linkage = 'ward'
	print linkage
	clusterer = AgglomerativeClustering(linkage=linkage, n_clusters=2)
	clusterer.fit(X)
 
 	print 'done'
	##############################################################################
	# Output cluster info
	labels = clusterer.labels_
	n_clusters_ = len(set(labels))
	if -1 in set(labels): # '-1' is just the group of unclustered objects
		n_real_clusters = n_clusters_ - 1 
	else:
		n_real_clusters = n_clusters_
	print('Estimated number of clusters: %d' % (n_real_clusters))
	# Find center of mass energy and position for cluster
	cluster_centers = []
	cluster_energies = []
	for l in set(labels): # !! WARNING !!: these should be computed with unweighted quantities
		#_e = np.unique(e[labels == l])
		#_X = np.unique(np.array([(x, y) for x, y in zip(X[labels == l, 0], X[labels == l, 1])]))
		b = np.array(list(set(zip(X[labels == l, 0], X[labels == l, 1], e[labels == l]))))
		_X = b[:, :2]
		_e = b[:, -1].ravel()
		cme = sum(_e)
		cm = np.sum(_X * _e[:, np.newaxis], axis=0) / cme
		#cme = sum(e[labels == l])
		#cm = np.sum(X[labels == l] * e[labels == l][:, np.newaxis], axis=0) / cme
		print 'Cluster {}: Center = {}, Energy = {}'.format(l, cm, cme)
		cluster_centers.append(cm)
		cluster_energies.append(cme)
	
	##############################################################################
	# Plot result
	# -- display event
	plot_eta_phi(X, X_unweighted, e, e_unweighted, n_clusters_, labels, cluster_centers, folder)

# ---------------------------------------------------------------------

def plot_eta_phi(X, X_unweighted, e, e_unweighted, n_clusters_, labels, cluster_centers, folder):
	binx = np.linspace(-3.0, 3.0, 61)
	biny = np.linspace(-3.1, 3.1, 63)
	
	#plt.hist2d(X[:, 0], X[:, 1], weights=e.ravel(), bins=(binx, biny), cmap='rainbow', norm=LogNorm())
	plt.hist2d(X_unweighted[:, 0], X_unweighted[:, 1], weights=e_unweighted.ravel(), bins=(binx, biny), cmap='rainbow', norm=LogNorm())
	cb = plt.colorbar()
	cb.set_label('Energy (GeV)')
	plt.xlabel(r'$\eta$')
	plt.ylabel(r'$\phi$')
	# -- display clustering features
	for k in range(n_clusters_):
		class_members = labels == k
		cluster_center = cluster_centers[k]

		if sum(class_members) == 0:
			#pass
			plt.plot(cluster_center[0], cluster_center[1], 'kx', mew=2, markersize=14)
		else:
			plt.plot(cluster_center[0], cluster_center[1], 'ko', markerfacecolor='None', #markeredgecolor='k', 
							 markersize=14)
		for x in X[class_members]:
			plt.plot([cluster_center[0], x[0]], [cluster_center[1], x[1]], color='black',alpha=0.2)

	plt.savefig(os.path.join(folder, 'etaphi.pdf'))
	plt.show()

# ---------------------------------------------------------------------

if __name__ == '__main__':
	import sys
	import argparse

	# Read in arguments
	parser = argparse.ArgumentParser()
	parser.add_argument('--txtfile', help="path to the text file with data", default='JetGenerator/clu15_2jets_withNoise.txt')
	parser.add_argument('--event', help="int, number of the event to consider", type=int, default=1)
	parser.add_argument('--weighted', help="boolean that determines whether to weight the points by their energy", default=False, action='store_true')
	parser.add_argument('--noise', help="boolean that determines whether to add noise", default=False, action='store_true')
	args = parser.parse_args()

	sys.exit(ward(args.txtfile, args.event, args.weighted, args.noise))
	