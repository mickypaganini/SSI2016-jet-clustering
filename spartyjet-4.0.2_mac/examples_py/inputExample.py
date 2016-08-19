#!/usr/bin/env python
# $Id: inputExample.py 545 2012-01-18 06:10:03Z cvermilion $
#----------------------------------------------------------------------
# Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
#                 Brian Martin, and Christopher Vermilion
#
#----------------------------------------------------------------------
# This file is part of SpartyJet.
#
#  SpartyJet is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 3 of the License, or
#  (at your option) any later version.
#
#  SpartyJet is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with SpartyJet; if not, write to the Free Software
#  Foundation, Inc.:
#      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#----------------------------------------------------------------------
from spartyjet import *
#===============================================

# Configure input -------------------------------
inputList = [] # List to store all types of input

# Text
textInput = getInputMaker('../data/J1_Clusters.dat')
inputList.append(textInput)

# Ntuple
# (getInputMaker should usually get ROOT files right, but only if prefix starts with 'Input')
ntupleInput = SJ.NtupleInputMaker(SJ.NtupleInputMaker.EtaPhiPtE_vector_float)
ntupleInput.set_prefix('Cluster_')
ntupleInput.set_n_name('N')
ntupleInput.set_variables('eta', 'phi', 'pt', 'e')
ntupleInput.setFileTree('../data/J2_clusters_wPile.root', 'clusterTree')
inputList.append(ntupleInput)

## Delphes ntuple (TODO: put a sample file in the SVN)
#DelphesInput = SJ.DelphesInputMaker('../data/delphes.root')
#inputList.append(DelphesInput)

# HepMC
hepMCInput = getInputMaker('../data/Zprime_ttbar.hepmc')
inputList.append(hepMCInput)

# StdHep
stdHepInput = getInputMaker('../data/ttbar_smallrun_pythia_events.hep')
inputList.append(stdHepInput)

# CalChep (Can't use getInputMaker -- same suffix as StdTextInput files)
calChepInput = SJ.CalchepPartonTextInput('../data/gg_ggg_events.dat')
inputList.append(calChepInput)

#Les Houches Event format
lheInput = getInputMaker('../data/w1j.lhe')
inputList.append(lheInput)

# output ROOT file
outfile = "../data/output/simple.root"

updateResults = False # bool switch to update ROOT file in each loop after 1st
for input in inputList:
    print "Now running on",input.name()

    # Create a jet builder---------------------------
    builder = SJ.JetBuilder(SJ.DEBUG)
    
    # Set the input----------------------------------
    builder.configure_input(input)

    # Configure algorithms --------------------------
    anti4 = SJ.FastJet.FastJetFinder('AntiKt4', fastjet.antikt_algorithm, 0.4)
    builder.add_default_analysis(anti4)

    # Configure output--------------------------------
    builder.configure_output(input.name()+"_Tree", outfile, updateResults)
    updateResults = True

    # Run SpartyJet
    builder.process_events(10)

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)

