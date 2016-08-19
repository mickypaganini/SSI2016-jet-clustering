#!/usr/bin/env python
# $Id: simpleExample.py 545 2012-01-18 06:10:03Z cvermilion $
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
#================================================

# Create a jet builder(MessageLevel = INFO)------
builder = SJ.JetBuilder(SJ.INFO)

# Create input object and add to builder --------
input = getInputMaker('../data/J1_Clusters.dat')
builder.configure_input(input)

# Create jet finder and add to builder ----------
name = 'AntiKt4'
alg = fj.antikt_algorithm
R = 0.4
antikt4Finder = SJ.FastJet.FastJetFinder(name, alg, R)
analysis = SJ.JetAnalysis(antikt4Finder)
builder.add_analysis(analysis)

# Shortcut:
#builder.add_default_analysis(SJ.FastJet.FastJetFinder('AntiKt4', fastjet.antikt_algorithm, 0.4))

# Add a jet measurement
builder.add_jetTool(SJ.EtaPhiMomentTool())

# Configure text output (optional) --------------
builder.add_text_output("../data/output/simple.dat")

# Configure ntuple output------------------------
outfile = "../data/output/simple.root"
builder.configure_output("SpartyJet_Tree", outfile)

builder.set_output_type(SJ.kVector, SJ.kDouble)

# Run SpartyJet----------------------------------
builder.process_events(10)

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)
