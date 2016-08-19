import csv
import numpy as np

def read_data(filename='JetGenerator/testing.txt'):
    '''
    definition:
    -----------
        transform data from txt file to numpy ndarrays
    args:
    -----
        filename (optional): string with path to the data file
    returns:
    --------
        X: list of length n_events of numpy ndarrays of dimensions [n_points, 2],
           which represents the etas and phis of all points in all events
        e: list of length n_events of numpy ndarrays of dimension [n_points, 1],
           which represents the energies of all points in all events
        -- e.g.: to get the numpy array with etas and phis in the first event,
                 use X[0]
    '''
    X_flat = []
    e_flat = []
    with open(filename, 'rb') as csvfile:
        reader = csv.DictReader(csvfile, delimiter=' ')
        for row in reader:
            X_flat.append([int(row['event']), float(row['eta']), float(row['phi'])])
            e_flat.append([int(row['event']), float(row['energy'])])
    X_flat = np.array(X_flat)
    e_flat = np.array(e_flat)

    X = []
    e = []
    for ev in np.unique(X_flat[:, 0]):
        X.append(X_flat[X_flat[:, 0] == ev, 1:])
        e.append(e_flat[e_flat[:, 0] == ev, 1:])

    return X, e