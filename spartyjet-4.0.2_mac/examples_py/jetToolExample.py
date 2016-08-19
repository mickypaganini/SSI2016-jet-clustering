#!/usr/bin/env python
# $Id: jetToolExample.py 545 2012-01-18 06:10:03Z cvermilion $
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

# NOTE: Many, but not all, of these tools are deprecated by equivalent or
# similar tools in FastJet 3.

# Create a jet builder---------------------------
builder = SJ.JetBuilder(SJ.INFO)

# Configure input -------------------------------
input = getInputMaker('../data/Zprime_ttbar.hepmc')
builder.configure_input(input)

# To store time per algorithm
#builder.do_time_measure()

# To add soft ghost particles to jets (useful for event plots)
#builder.adding_active_ghosts(5000)

# Configure algorithms --------------------------
name = 'AntiKt4'
alg = fj.antikt_algorithm
R = 0.4
findJetAreas = True
antikt4 = SJ.FastJet.FastJetFinder(name, alg, R, findJetAreas)
antikt4.set_areaChoice(fj.active_area)
builder.add_default_analysis(antikt4)

kt4 = SJ.FastJet.FastJetFinder('Kt4', fj.kt_algorithm, 0.4, True)
kt4.set_areaChoice(fj.active_area)
builder.add_default_analysis(kt4)

# Add Jet Tools ---------------------------------
# add_jetTool_input - Run once on inputs for all algorithms
# add_jetTool_front - Run before jet finding
# add_jetTool       - Run after  jet finding

# Select particles to be removed from input ( ex: neutrinos )
builder.add_jetTool_input(SJ.JetInputPdgIdSelectorTool(stdVector(-12, 12)))

# Determine event-by-event ptDensity from soft activity in bins of eta
densityTool = SJ.FastJet.PtDensityTool("PtDensityTool", fj.kt_algorithm, 0.5, fj.active_area, stdVector(-4., -2., 0., 2., 4.))
builder.add_jetTool_front(densityTool)
# Input min pt cut (Here only for one algorithm)
builder.add_jetTool_front(SJ.FastJet.SelectorTool(fj.SelectorPtMin(1.)), 'AntiKt4')
# Input eta cut
builder.add_jetTool_input(SJ.FastJet.SelectorTool(fj.SelectorAbsEtaMax(1.5)))

#======Here is where the algorithms defined above will run ======

# Final pt cut
builder.add_jetTool(SJ.FastJet.SelectorTool(fj.SelectorPtMin(7.)))

# Jet correction to pt according to area and pt density 
builder.add_jetTool(SJ.JetAreaCorrectionTool("AreaCorrTool"))

# Compute Y split values
R = 1.5
alg = fj.kt_algorithm
NYVals = 2
builder.add_jetTool(SJ.FastJet.YSplitterTool(R, alg, NYVals))

# Some geometric moments
builder.add_jetTool(SJ.EtaPhiMomentTool("EtaPhiMomTool"))
builder.add_jetTool(SJ.HullMomentTool("HullMomTool"))

# Convert from GeV to MeV (or reverse)
builder.add_jetTool(SJ.EConversionTool("EConvTool", False)) # Convert to MeV

# Add Event Shape -------------------------------
thrust = SJ.JetAnalysis("ThrustAnalysis")
thrust.add_tool(SJ.eventshape.ThrustTool("ThrustTool"))
builder.add_eventshape_analysis(thrust)

# Configure output--------------------------------
builder.add_text_output("../data/output/jetTool2.dat")
outfile = "../data/output/jetTool.root"
builder.configure_output("SpartyJet_Tree", outfile)

# Run SpartyJet
builder.process_events()

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)
