#!/usr/bin/env python
# $Id: FJToolExample.py 545 2012-01-18 06:10:03Z cvermilion $
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
from ROOT import gSystem

builder = SJ.JetBuilder(SJ.DEBUG) # Message levels: DEBUG, INFO, WARNING, ERROR

# ****************** Create Builder ************************************

input = getInputMaker('../data/Zprime_ttbar.hepmc')
builder.configure_input(input)

# ****************** Add input tools ******************************
# These are run on the input before it is sent to each JetAnalysis tool chain.

builder.add_jetTool_input(SJ.JetPtSelectorTool(0.5*input.getGeV()))
builder.add_jetTool_input(SJ.JetEtaCentralSelectorTool(-1.5,1.5))

# ignore neutrinos and muons
builder.add_jetTool_input(SJ.JetInputPdgIdSelectorTool(stdVector(12, -12, 14, -14, 16, -16, 13, -13)))

# ****************** Set up algorithms **********************************

# Find with Anti-kT
name = 'AntiKt10'
alg = fj.antikt_algorithm
R = 1.0
findJetAreas = False
AntiKt10 = SJ.JetAnalysis(SJ.FastJet.FastJetFinder(name, alg, R, findJetAreas))
# fork for AntiKt10, so multiple tool chains can use this algorithm
AKTparent = SJ.ForkToolParent('AntiKt10Parent')
AntiKt10.add_tool(AKTparent)
# An example of using a FunctionOfPseudoJet measurement
nsub3 = fj.Nsubjettiness(3, Njettiness.onepass_kt_axes, 1.0, 1.0)
AntiKt10.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(nsub3, "tau3"))
builder.add_analysis(AntiKt10)

# Create a pruned analysis, using AntiKt10 as its input
Pruned = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, 'AntiKt10Pruned'))
# Note that we're finding with Anti-Kt and pruning with CA.
pruner = fj.Pruner(fj.cambridge_algorithm, 0.1, 0.5)
Pruned.add_tool(SJ.FastJet.TransformerTool("Pruner", pruner))
builder.add_analysis(Pruned)

# Find with Cambridge/Aachen
CA = SJ.JetAnalysis(SJ.FastJet.FastJetFinder('CA10', fj.cambridge_algorithm, 1.0, False))
builder.add_analysis(CA)
# fork for CA10
CAparent = SJ.ForkToolParent('CA10Parent')
CA.add_tool(CAparent)

# Set up Mass-Drop-Filter analysis (as in arXiv:0802.2470).
CA10MDF = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, 'CA10MDF'))
muCut = 0.67
yCut = 0.09
massDrop = fj.MassDropTagger(muCut, yCut)
CA10MDF.add_tool(SJ.FastJet.TransformerTool("MassDrop", massDrop))
# NOTE: using a non-adaptive filter (fixed Rsub) for now, since I haven't wrapped
# the DynamicRFilt for PyROOT.  Cf. FJToolExample.cc.
filter = fj.Filter(0.3, fj.SelectorNHardest(3))
CA10MDF.add_tool(SJ.FastJet.TransformerTool("Filter", filter))
builder.add_analysis(CA10MDF)

# Set up a simple filtering analysis.  Filters to R_filt = 0.2, keeps hardest
#  four subjets.
CA10Filtered = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, 'CA10Filtered'))
RFilt = 0.2
NSubjets = 4
filter2 = fj.Filter(RFilt, fj.SelectorNHardest(NSubjets))
CA10Filtered.add_tool(SJ.FastJet.TransformerTool("Filter", filter2))
builder.add_analysis(CA10Filtered)

# CMS W-tagging
CA10CMSWtag = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, 'CA10CMSWtag'))
CA10CMSWtag.add_tool(SJ.FastJet.TransformerTool("Pruner", pruner))
massDropCMS = fj.MassDropTagger(0.8, 0.0)
CA10CMSWtag.add_tool(SJ.FastJet.TransformerTool("MassDrop", massDropCMS))
builder.add_analysis(CA10CMSWtag)

# W-tagging splits from CA10
CA10Wtag = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, 'CA10Wtag'))
wtag = fj.WTagger()
CA10Wtag.add_tool(SJ.FastJet.TransformerTool("Wtag", wtag))
builder.add_analysis(CA10Wtag)


# ****************** Final tools *************************************

# Add a final pT cut to all analyses
builder.add_jetTool(SJ.FastJet.SelectorTool(fj.SelectorPtMin(10.0), 'PtCut'))

# ****************** Set up output and run ***************************

# Easy-to-read ASCII output
builder.add_text_output("../data/output/FJTool.dat")
# ROOT file output, stored in TTree with name "SpartyJet_Tree".  Includes
#  constituent information and Jet/EventMoments
outfile = "../data/output/FJTool.root"
builder.configure_output("SpartyJet_Tree", outfile)

# turn off all output from JetBuilder
# builder.silent_mode()
# Print an 'Events Processed: N' line every 100 events
#builder.print_event_every(100)
# Go!
builder.process_events()

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)

