print(__doc__)

from sklearn.cluster import KMeans
from sklearn import metrics
from sklearn.datasets.samples_generator import make_blobs
import numpy as np
from read_data import read_data
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from itertools import cycle

def km(readin, event=2, n_clusters_=2, inputFile = 'JetGenerator/clu10_2jets_withNoise.txt'):
    ##############################################################################
    # Generate sample data
    if readin:
        X_all, e_all = read_data(inputFile)
        X = X_all[event]
        xWeights = np.array([weights[0] for weights in e_all[event]])#(e_all[event] - e_all[event].min())/(e_all[event].max() - e_all[event].min())
        #xWeights = (xWeights - xWeights.min())/(xWeights.max() - xWeights.min())
        #print(xWeights)
        #print('max element in array: ', xWeights.max())
        #print('min element in array: ', xWeights.min())
        #print('size of array: ', xWeights.size, ' and X: ', X.size)
        #print(len(X), ' x ', len(X[0]))
    
    ##############################################################################
    # Compute Weighted Kmeans

    kmeans = KMeans(n_clusters=n_clusters_)
    kmeans.fit(X,sample_weight=xWeights)

    k_means_labels = kmeans.labels_
    k_means_cluster_centers = kmeans.cluster_centers_
    k_means_labels_unique = np.unique(k_means_labels)
    Z=kmeans.predict(X)
    #cluster_centers_indices = af.cluster_centers_indices_
    #labels = af.labels_
    #n_clusters_ = len(cluster_centers_indices)
    
    #print('Estimated number of clusters: %d' % n_clusters_)
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


    binx = np.linspace(-3.0, 3.0, 60)
    biny = np.linspace(-3.1, 3.1, 62)

    my_cmaps = [plt.cm.get_cmap('Blues'), plt.cm.get_cmap('Greens'),plt.cm.get_cmap('Reds'),plt.cm.get_cmap('Oranges'),plt.cm.get_cmap('Purples'),plt.cm.get_cmap('RdPu'),plt.cm.get_cmap('PuBuGn'),plt.cm.get_cmap('YlGnBu'),plt.cm.get_cmap('BuPu'),plt.cm.get_cmap('bone')]
    for map in my_cmaps:
        map.set_under('lightgray')

    my_cmap_greens = plt.cm.get_cmap('Greens')
    my_cmap_greens.set_under('lightgray')
    my_cmap_blues = plt.cm.get_cmap('Blues')
    my_cmap_blues.set_under('lightgray')
    my_cmap_reds = plt.cm.get_cmap('Reds')
    my_cmap_reds.set_under('lightgray')
    my_cmap_oranges = plt.cm.get_cmap('Oranges')
    my_cmap_oranges.set_under('lightgray')
    my_cmap_purples = plt.cm.get_cmap('Purples')
    my_cmap_purples.set_under('lightgray')
    my_cmap_rdpu = plt.cm.get_cmap('RdPu')
    my_cmap_rdpu.set_under('lightgray')

    v = np.linspace(0., 150, 15, endpoint=True)
#print(k_means_cluster_centers[:,1])
    orders = np.argsort(k_means_cluster_centers[:,1])
#print(orders)
    if readin:
      for k in range(0,n_clusters_):
        class0=Z==orders[k]
        plt.hist2d(X[class0, 0], X[class0, 1], weights=xWeights[class0].ravel(), bins=(binx, biny), vmin=1,cmap=my_cmaps[k], norm=LogNorm())
        if k == 0:
            cba = plt.colorbar(extend='min')
            cba.set_label('Energy (GeV)')
#        plt.hist2d(X[class1, 0], X[class1, 1], weights=xWeights[class1].ravel(), bins=(binx, biny), vmin=1, cmap=my_cmap_greens, norm=LogNorm())
#        plt.hist2d(X[class2, 0], X[class2, 1], weights=xWeights[class2].ravel(), bins=(binx, biny), vmin=1, cmap=my_cmap_reds, norm=LogNorm())
#        plt.hist2d(X[class3, 0], X[class3, 1], weights=xWeights[class3].ravel(), bins=(binx, biny), vmin=1, cmap=my_cmap_oranges, norm=LogNorm())
#        plt.hist2d(X[class4, 0], X[class4, 1], weights=xWeights[class4].ravel(), bins=(binx, biny), vmin=1, cmap=my_cmap_purples, norm=LogNorm())
#        plt.hist2d(X[class5, 0], X[class5, 1], weights=xWeights[class5].ravel(), bins=(binx, biny), vmin=1, cmap=my_cmap_rdpu, norm=LogNorm())

#plt.hist2d(X[class2, 0], X[class2, 1], weights=xWeights[class2].ravel(), bins=(binx, biny), cmap='Greens', norm=LogNorm())
    plt.xlabel(r'$\eta$')
    plt.ylabel(r'$\phi$')
    # -- display clustering features
    for k in range(0,n_clusters_):
        plt.plot(k_means_cluster_centers[orders[k],0], k_means_cluster_centers[orders[k],1], 'ko', markerfacecolor='None', markersize=10)
        print('eta: ', k_means_cluster_centers[orders[k],0],' phi: ', k_means_cluster_centers[orders[k],1])
    plt.title('Weighted k-means: 6 clusters, no noise')
    plt.show()


if __name__ == '__main__':
    import sys
    import argparse
    
    # Read in arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('--readin', help="pass this flag to read in blobs from txt file; else make_blobs", action='store_true')
    parser.add_argument('--event', help="int, number of the event to consider", type=int)
    parser.add_argument('--nClusters', help="int, number of clusters to make per event", type=int)
    parser.add_argument('--inputFile', help="file with the events", type=str)
    
    args = parser.parse_args()
    
    # Pass arguments to main
    if args.event is not None:
        sys.exit(km(args.readin, args.event, args.nClusters, args.inputFile))
    else:
        sys.exit(km(args.readin))
