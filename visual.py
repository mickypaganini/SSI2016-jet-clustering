"""
    Some helper functions for visualizing events.
"""
from read_data import read_data
import numpy as np
import math
import matplotlib.pyplot as plt

def get_events():
    v, e = read_data()
    events = [np.concatenate((v[i], e[i]), 1) for i in xrange(len(e))]
    return events

def render_particles(event):
    plt.title("Particle Positions")
    x, y, e = zip(*event)
    plt.scatter(x, y, c=e, vmin=10, vmax=200, cmap="gist_rainbow") 
    plt.colorbar()

def render_ghosts(event):
    plt.title("Particle Positions")
    x, y, e = zip(*event)
    plt.scatter(x, y, facecolors='none') 

def render_jets(mu, sigma):
    sizeScale = 1800/0.4
    for j in range(len(mu)):
        x,y = mu[j][0],mu[j][1]
        plt.scatter(x,y, s=sigma[j]*sizeScale,facecolors='none')
    
def show_particles(event):
    plt.figure()
    render_particles(event)
    plt.show()

def render_particlesAndJets(event, mu, sigma):
    plt.figure()
    render_particles(event)
    render_jets(mu, sigma)
    plt.title("Particles and Centroids")
    plt.show()
    
def render_particlesAndJetsAndGhosts(event, mu, sigma, ghost, nameString):
    plt.figure()
    render_particles(event)
    render_jets(mu, sigma)
    render_ghosts(ghost)
    plt.title("Particles and Centroids")
    #plt.show()
    plt.savefig(nameString)
    
def show_events(events):
    for i, e in enumerate(events):
        plt.subplot(2, int(math.ceil(len(events)/2.)), i+1)
        render_particles(e)
        plt.title("Event %d" % i)

    plt.show()
