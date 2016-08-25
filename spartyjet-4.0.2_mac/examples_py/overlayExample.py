#!/usr/bin/env python
# $Id: overlayExample.py 545 2012-01-18 06:10:03Z cvermilion $
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

# Create 2 jet builders for comparison with and without pileup
builder = SJ.JetBuilder(SJ.INFO)
builder.print_event_every(10)

builderPile = SJ.JetBuilder(SJ.INFO)
builderPile.print_event_every(10)

# Configure input -------------------------------
input = createNtupleInputMaker('../data/J2_clusters.root', inputprefix='Cluster')
builder.configure_input(input)

# Add the signal input to both builders
builder.configure_input(input)
builderPile.configure_input(input)

# Configure overlay ----------------------------
mbInput = createNtupleInputMaker('../data/minbias.root', inputprefix='Cluster')
numMinBias = 4

# Add the minbias events to one of the  builders
builderPile.add_minbias_events(numMinBias, mbInput, True) # Bool is whether to draw no. of mb events from poisson

# Configure algorithms --------------------------
anti7 = SJ.FastJet.FastJetFinder('AntiKt7', fastjet.antikt_algorithm, 0.7, True)
analysis = SJ.JetAnalysis(anti7)
builder.add_analysis(analysis)
builderPile.add_analysis(analysis)

# Determine pt density of sample with pileup
etaBins = stdVector(-4., -2., 0., 2., 4.)
densityTool = SJ.FastJet.PtDensityTool("PtDensityTool", fastjet.kt_algorithm, 0.5, fastjet.active_area, etaBins)
builderPile.add_jetTool_front(densityTool)

# Calculate area-bsed correction to jet pt
builderPile.add_jetTool(SJ.JetAreaCorrectionTool("AreaCorrTool"))

# Configure output of each builder 
# (Note the boolean in the second line tells SpartyJet to 
#  update the output file, this is needed to save both results)
outfile = "../data/output/overlay.root"
builder.configure_output("SignalOnly_Tree", outfile)
builderPile.configure_output("SignalPileup_Tree", outfile, True)

# Run Each Builder
builder.process_events(2)
print "Now running with Minbias events overlaid"
builderPile.process_events(2)

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)

