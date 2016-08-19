#!/usr/bin/env python
# $Id: pythiaExample.py 545 2012-01-18 06:10:03Z cvermilion $
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
from spartyjet import SpartyJet as SJ, fastjet as fj, writeCurrentFile
from ROOT import TPythia8, gSystem
#===============================================

# Example showing how to pass events directly from Pythia to SpartyJet.
# Requires that you have built ROOT's Pythia 6 and/or 8 interface.

gSystem.Load('libEG') # import common event gen lib

# Create a jet builder(MessageLevel = INFO)------
builder = SJ.JetBuilder(SJ.INFO)

######### PYTHIA8 #########
# Load Libraries
gSystem.Load('libEGPythia8')
# Creat TPythia8 object
pythia = TPythia8()
# Single W production
pythia.ReadString('WeakSingleBoson:ffbar2W = on')
# Force decay W->ev
pythia.ReadString("24:onMode = off")
pythia.ReadString("24:onIfAny = 11 12")
# UE
pythia.ReadString("PartonLevel:MI = off") 
# ISR,FSR, beam remnant
pythia.ReadString("PartonLevel:ISR = on") 
pythia.ReadString("PartonLevel:FSR = on")
pythia.ReadString("PartonLevel:Remnants = on")
# Hadronize
pythia.ReadString("HadronLevel:all = on")
# Initialize for LHC
pythia.Initialize(2212,2212, 7000.)
# Initialize for Tevatron
#pythia.Initialize( 2212, -2212, 1960.)
###########################


######### PYTHIA6 #########
## Load Library
#ROOT.gSystem.Load("libEGPythia6")
## Create TPythia8 object
#pythia = ROOT.TPythia6()
## Turn on W+jet production
#pythia.SetMSEL(14)
## Turn off all decay modes except W->e+nu
#decayChOff = [190,191,192,194,195,196,198,199,200,207,208]
#for dc in decayChOff:
#    pythia.SetMDME(dc,1,0)
## Turn on W->e+nu
#pythia.SetMDME(206,1,1)
## Initialize for LHC
#pythia.Initialize('cms','p+','p+',7000.)
## Initialize for Tevatron
##pythia.Initialize('cms','p+','p-',1960.)
###########################

# Create input object and add to builder --------
input = SJ.PythiaInput(pythia)

# Event Particle printout (Only usable in Pythia8)
#input.printEvent(True)

builder.configure_input(input)

# Create jet finder and add to builder ----------
analysis = SJ.JetAnalysis(SJ.FastJet.FastJetFinder('AntiKt4', fj.antikt_algorithm, 0.4))
builder.add_analysis(analysis) 

# Configure text output--------------------------
builder.add_text_output("../data/output/pythia.dat")

# Configure ntuple output------------------------
outfile = "../data/output/pythia.root"
builder.configure_output("SpartyJet_Tree", outfile)

# Run SpartyJet----------------------------------
builder.process_events(10)

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)

