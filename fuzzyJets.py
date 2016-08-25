import sys
import numpy as np
from numpy import matlib
from scipy.stats import multivariate_normal
from read_data import read_data
import matplotlib.pyplot as plt
import time
import visual

########## Description of Algorithm ###########
# We will assume having m events
# Each event should have k=3 jets
# Each event should have n 'parrticles' to be clustered into the k jets
# Input: cells  (size = [m,k,2])
#            np vector of size m
#                 each entry is a np vector of size k
#                       each entry of the above vector is of size d=2 dimentions (eta, phi)
# Input: energies   (size = [m,k,1])
#            similar structure as cells, but only energy information

def visualize(particles, ghost, mu, sigma, pi, nameString):
    visual.render_particlesAndJetsAndGhosts(particles, mu, sigma, ghost, nameString)
    pass
"""
    #import code; code.interact(local=locals())
"""
# A little inefficient, can be fixed...
def makeJets(Q, particles):
    thresholdP = 0.95
    for j in range(len(Q[0])):
        newJet = [0.]*4 #4-vector
        for i in range(len(particles)):
            if Q[i][j] > thresholdP:
                newParticle = [0.]*4
                newParticle[0] = particles[i][2]
                newParticle[1] = particles[i][0]
                newParticle[2] = particles[i][1]
                newParticle[0] = particles[i][2]
                newJet = np.array(newJet) + np.array(newParticle)
        print "Jet "+str(j)+": "+str(newJet[0])+" GeV (I guess?)"
        

def jetFunction(particleVec,mu,sigma):
    myPhi1 = abs(particleVec[1]-mu[1])
    myPhi2 = abs(particleVec[1]-(mu[1]+2*np.pi))
    myPhi3 = abs(particleVec[1]-(mu[1]-2*np.pi))
    wrap = 0
    if myPhi2 < myPhi1 and myPhi2 < myPhi3:
        wrap = 1
    if myPhi3 < myPhi1 and myPhi3 < myPhi2:
        wrap = -1
    absdeltaPhi = min(myPhi1, myPhi2, myPhi3)
    deltaR = np.sqrt((absdeltaPhi)**2 + (particleVec[0]-mu[0])**2)
    denom = 2*np.pi*(sigma**2)
    numerator = np.exp(-deltaR**2/(2*sigma**2))
    return numerator/denom, wrap

def expectation(mu, sigma, pi, particles):
    k = len(mu)
    d = len(mu[0])
    Q = np.empty((len(particles),k))
    wrapAround = []
    for i in range(len(particles)):
        wrapArr = [0]*k
        for j in range(k):
            denom = 0
            for jP in range(k):
                phiF1, wrap1 = jetFunction(particles[i],mu[jP],sigma[jP])
                denom += pi[jP]*phiF1
            phiF2, wrap2 = jetFunction(particles[i], mu[j], sigma[j])
            Q[i,j] = pi[j]*phiF2/denom
            wrapArr[j] = wrap2
        wrapAround.append(wrapArr)
    return Q, wrapAround
            
def maximization(Q, particles, mu, sigma, pi, wrapAround):
    #ptThreshold = 5
    #sigmaThreshold = 0.01
    #sigmaLimit = 1.5
    eventNumber = 8
    k = len(mu)
    d = len(mu[0]) #2-d grid
    allSigma = [] #Note that what goes in here is sigma and not sigma^2 (scalars)
    allMu = [] #Each entry is a 2-vector
    allPi = [] #scalars
    for j in range(k):
        if not convergedArr[j]:
            newMu = [0.,0.]
            newSigma = 0.
            newPi = 0.
            piDenom = 0.
            muDenom = 0.
            for i in range(len(particles)):
                piDenom += particles[i][2]
                muDenom += particles[i][2] * Q[i][j]
                newPi += particles[i][2] * Q[i][j]
                for c in range(d):
                    newMu[c] += particles[i][2] * Q[i][j] * (particles[i][c]+wrapAround[i][j]*2*np.pi)
            newMu = newMu/muDenom
            newPi = newPi/piDenom
                
            for myL in range(len(particles)):
                phi1 = abs(particles[myL][1]-newMu[1])
                phi2 = abs(particles[myL][1]-(newMu[1]+2*np.pi))
                phi3 = abs(particles[myL][1]-(newMu[1]-2*np.pi))
                absdeltaPhi = min(phi1, phi2, phi3)
                deltaR = np.sqrt((absdeltaPhi)**2 + (particles[myL][0]-newMu[0])**2)
                #if particles[myL][2] < ptThreshold:
                newSigma += Q[myL][j]*particles[myL][2]*deltaR**2
            newSigma = newSigma/(2.*muDenom)
            #if newSigma >= sigmaThreshold:
            #    newSigma = sigmaThreshold
            #if newSigma <= sigmaLimit:
            #newSigma = sigmaLimit
        else:
            newMu = mu[j]
            newSigma = sigma[j]**2 #Careful with sigma squared
            newPi = pi[j]
        allMu.append(newMu)
        allPi.append(newPi)
        allSigma.append(np.sqrt(np.abs(newSigma)))
    return allMu, allSigma, allPi

if __name__ == '__main__':
    debug = False
    eventNumber = 8
    ### Read in data ###
    particles = []
    myX, myE = read_data()
    for i in range(len(myE[eventNumber])):
        newEntry = []
        newEntry.append(myX[eventNumber][i][0])
        newEntry.append(myX[eventNumber][i][1])
        newEntry.append(myE[eventNumber][i][0])
        particles.append(newEntry)
    
    if debug:
        print "particles", particles
        
    ### InitializeParameters ###
    numK = 3 #Seed from AntiKt eventually
    d = 2
    pi = [1./numK]*numK #length k
    sigma = [1.]*numK #length k
    mu = [[0.0,3.],[2.,-1.],[2.5,3.]] #Seed with AntiKt eventually
    numParticles = len(particles) #total number of partcles in event
    numGhosts = numParticles * 10
    epsilonR = 0.4/100 #pt cone / 100
    epsilonS = 1./100
    smallPt = 1./10
    convergedArr = [False]*numK

    ### Make ghosts ###
    ghost = [[np.random.uniform(-np.pi,np.pi) for i in range(0,numK)] for j in range (0,numGhosts)]
    for g in ghost:
        g[2] = smallPt
    allParticles = particles + ghost
    
    num = 0
    visualize(particles, ghost, mu, sigma, pi,"fuzzy"+str(num)+".jpg")
    num += 1
    
    while True:
        
        if debug:
            print "Pi", pi
            print "mu", mu
            print "sigma", sigma
            print "bool", convergedArr

        ### Expectation Step ###
        Q, qWrap = expectation(mu, sigma, pi, allParticles)
        if debug:
            print "Q: ", Q

        if num==1:
            print "First Q: "
            print Q
        ### Maximization ###
        muPrime, sigmaPrime, piPrime = maximization(Q, allParticles, mu, sigma, pi, qWrap)
        
        ### Convergence Criteria ###
        for i in range(numK):
            absdeltaPhi = min(abs(mu[i][1]-muPrime[i][1]),abs(mu[i][1]-(muPrime[i][1]+2*np.pi)),abs(mu[i][1]-(muPrime[i][1]-2*np.pi)))
            deltaR = np.sqrt((absdeltaPhi)**2 + (mu[i][0]-muPrime[i][0])**2)
            if deltaR < epsilonR and np.abs(sigmaPrime[i]-sigma[i]) < epsilonS:
                convergedArr[i] = True

        ### Update ###
        mu = muPrime
        sigma = sigmaPrime
        pi = piPrime

        ### Visualization ###
        visualize(particles, ghost, mu, sigma, pi,"fuzzy"+str(num)+".jpg")
        num += 1
        
        ### Exit Criteria ###
        if convergedArr == [True]*numK:
            print "Final Q: "
            print Q
            makeJets(Q, allParticles)
            break
        
    arrLab = ["First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eigth","Ninth"]
    for i in range(len(mu)):
        print arrLab[i]+" centroid: eta="+str(mu[i][0])+", phi="+str(mu[i][1])+", weight="+str(pi[i])+", sigma="+str(sigma[i])

