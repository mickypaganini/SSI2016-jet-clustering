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
import os

def af(txtfile, event, weighted, noise):
	run = 'af_10jets_overlap'
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
		NOISE_LVL = 0.1 # GeV
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
	# Compute Affinity Propagation
	# af = AffinityPropagation(preference=preference).fit(X)
	# af = AffinityPropagation(preference=((e**2) - np.mean(e**2))).fit(X)
	#preference = e**2 - np.percentile(e**2, 99.5)
	#preference = (1 / (1 + np.exp(-(e - e.mean())))) - 1
	scaler = StandardScaler()
	scaled_e = scaler.fit_transform(e)
	preference = scaled_e - 100 # for 2 overlapping jets to give us 1 cluster
	#preference = scaled_e**6 - 60
	af = AffinityPropagation(preference=preference).fit(X)

	##############################################################################
	# Output cluster info
	cluster_centers_indices = af.cluster_centers_indices_
	cluster_centers = af.cluster_centers_
	labels = af.labels_
	n_clusters_ = len(cluster_centers_indices)
	print('Estimated number of clusters: %d' % n_clusters_)
	for l in range(n_clusters_):
		#cme = sum(e_unweighted[labels == n])
		b = np.array(list(set(zip(X[labels == l, 0], X[labels == l, 1], e[labels == l]))))
		_X = b[:, :2]
		_e = b[:, -1].ravel()
		cme = sum(_e)
		cm = np.sum(_X * _e[:, np.newaxis], axis=0) / cme
		print 'Cluster {}: CM = {}, Center = {}, Energy = {}'.format(l, cm, cluster_centers[l], cme)
	
	##############################################################################
	# Plot result
	plot_eta_phi(X, X_unweighted, e, e_unweighted, n_clusters_, labels, cluster_centers, folder)
	# # -- display event
	# binx = np.linspace(-3.0, 3.0, 61)
	# biny = np.linspace(-3.1, 3.1, 63)
	# if readin:
	# 	plt.hist2d(X[:, 0], X[:, 1], weights=e.ravel(), bins=(binx, biny), cmap='rainbow', norm=LogNorm())
	# 	cb = plt.colorbar()
	# 	cb.set_label('Energy (GeV)')
	# plt.xlabel(r'$\eta$')
	# plt.ylabel(r'$\phi$')
	# # -- display clustering features
	# for k in range(n_clusters_):
	# 	class_members = (labels == k)# & (e > 1)
	# 	cluster_center = cluster_centers[k]
	# 	if not readin:
	# 		plt.plot(X[class_members, 0], X[class_members, 1], 'k.', alpha=0.2)
	# 	plt.plot(cluster_center[0], cluster_center[1], 'ko', markerfacecolor='None', #markeredgecolor='k', 
	# 					 markersize=14)
	# 	for x in X[class_members]:
	# 		plt.plot([cluster_center[0], x[0]], [cluster_center[1], x[1]], color='black',alpha=0.2)
	# plt.title('Estimated number of clusters: %d' % n_clusters_)
	# plt.savefig(os.path.join(folder, 'etaphi.pdf'))
	# plt.show()

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
		cme = sum(e_unweighted[labels == k])
		if cme > 1:
			for x in X[class_members]:
				plt.plot([cluster_center[0], x[0]], [cluster_center[1], x[1]], color='black',alpha=0.2)

	plt.savefig(os.path.join(folder, 'etaphi.pdf'))
	plt.show()


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

	sys.exit(af(args.txtfile, args.event, args.weighted, args.noise))