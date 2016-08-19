#!/usr/bin/env python
# $Id: Boost2011.py 545 2012-01-18 06:10:03Z cvermilion $
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

# Create a jet builder---------------------------
builder = SJ.JetBuilder(SJ.ERROR)

# Configure input -------------------------------
input = getInputMaker('../data/Zprime_ttbar.hepmc')
builder.configure_input(input)

# input tool: calorimeter sim
#builder.add_jetTool_input(SJ.RadialSmearingTool())
#builder.add_jetTool_input(SJ.JetPtSelectorTool(1.*input.getGeV()))


# ------------------------- Analyses ---------------------------------
analyses = []

# They all start with Anti-kt 1.0 jets, so set this up and fork off
antiktFinder = SJ.FastJet.FastJetFinder('AntiKt', fj.antikt_algorithm, 1.0)
AntiKt = SJ.JetAnalysis(antiktFinder)
# cut on pT *before* forking to save time
selector = fj.SelectorPtMin(200.0) * fj.SelectorNHardest(2)
AntiKt.add_tool(SJ.FastJet.SelectorTool(selector)) # two highest-pt jets over 200
AKTparent = SJ.ForkToolParent('AntiKtParent')
AntiKt.add_tool(AKTparent)
analyses.append(AntiKt)

# recluster with CA, then fork again for different taggers
CA = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, 'CA'))
CA.add_tool(SJ.FastJet.FastJetRecluster('CAcluster', fj.cambridge_algorithm, 100.0))
CAparent = SJ.ForkToolParent('CAParent')
CA.add_tool(CAparent)
analyses.append(CA)

# recluster with kT
Kt = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, 'KT'))
Kt.add_tool(SJ.FastJet.FastJetRecluster('KTcluster', fj.kt_algorithm, 100.0))
KTparent = SJ.ForkToolParent('KTParent')
Kt.add_tool(KTparent)
analyses.append(Kt)

# do some forks before measurement, just for clarity of output
ACF = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, 'ACF'))
analyses.append(ACF)
ATLAS = SJ.JetAnalysis(SJ.ForkToolChild(KTparent, 'ATLAS'))
analyses.append(ATLAS)
TW = SJ.JetAnalysis(SJ.ForkToolChild(KTparent, 'TW'))
analyses.append(TW)
NSub = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, 'NSub'))
analyses.append(NSub)

# pruning
big_CA_def = fj.JetDefinition(fj.cambridge_algorithm, 100.0)
Pruned50 = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, "Pruned"))
pruner50 = fj.Pruner(fj.cambridge_algorithm, 0.05, 0.1)
Pruned50.add_tool(SJ.FastJet.TransformerTool("Pruner", pruner50))
analyses.append(Pruned50)

# trimming
Trimmed = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, "Trimmed"))
trimmer = fj.Filter(0.35, fj.SelectorPtFractionMin(0.03))
Trimmed.add_tool(SJ.FastJet.TransformerTool("TrimmerTool", trimmer))
analyses.append(Trimmed)

# filtering
Filtered = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, "Filtered"))
filter = fj.Filter(0.35, fj.SelectorNHardest(3))
Filtered.add_tool(SJ.FastJet.TransformerTool("FilterTool", filter))
analyses.append(Filtered)

# JH top tagger
JH50 = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, "JH"))
JH50transformer = fj.JHTopTagger(0.04, 0.19, 1.0, 81.0)
JH50.add_tool(SJ.FastJet.TransformerTool("JHTagger", JH50transformer))
analyses.append(JH50)

# CMS top tagger
CMS = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, "CMS"))
# measure mass *before* "pruning" step
massFunction = SJ.FastJet.MassFunction()
CMS.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(massFunction, "AKTmass"))
CMStransformer = fj.CMSTopTagger(0.05, 0.4, 0.0004)
CMS.add_tool(SJ.FastJet.TransformerTool("CMSTagger", CMStransformer))
analyses.append(CMS)

# HEP top tagger, including dipolarity
HEP = SJ.JetAnalysis(SJ.ForkToolChild(CAparent, "HEP"))
HEPtransformer = fj.HEPTopTagger()
HEP.add_tool(SJ.FastJet.TopTaggerDipolarityTool(HEPtransformer, "HEPTagger")) # with dipolarity!
#HEP.add_tool(SJ.FastJet.TransformerTool("HEPTagger", HEPtransformer))  # no dipolarity
analyses.append(HEP)

# Qjets: very slow!
'''
Qjets = SJ.JetAnalysis(SJ.ForkToolChild(AKTparent, "Qjets"))
qplugin = QjetsPlugin(.1, .5, 0., 0., .1)
qtool = SJ.FastJet.QjetsTool(qplugin, 100)
Qjets.add_tool(qtool)
analyses.append(Qjets)
'''

[builder.add_analysis(a, False) for a in analyses]


# ------------------ Measurements ------------------------------------

# ATLAS z_cut variables
indices = [1, 2, 3, 4]
zCutFunctions = [fj.zCutFunction(i) for i in indices]
[ATLAS.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(zCut, "zcut"+str(i))) for (zCut,i) in zip(zCutFunctions, indices)]

# Thaler-Wang z_cell
zCellFunction = fj.zCellFunction()
TW.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(zCellFunction, "zcell"))

# N-Subjettiness
nsub_tools = []
for i in [1,2,3]:
   nsub_tools += [fj.Nsubjettiness(i, Njettiness.kt_axes, 1.0, 1.0)]
   NSub.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(nsub_tools[-1], "tau"+str(i)+"_kt"))
   # these ones are the ones actually used in the report
   nsub_tools += [fj.Nsubjettiness(i, Njettiness.onepass_kt_axes, 1.0, 1.0)]
   NSub.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(nsub_tools[-1], "tau"+str(i)))

# Add a min-mass tool to analyses that don't have a different W identifier

minMass = fj.MinMassFunction()
for a in [Pruned50, Filtered, Trimmed, ATLAS, TW, NSub]:
  a.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(minMass, "mW"))
  

# add angular correlation ("Jet Substructure Without Trees") tool
ACF.add_tool(SJ.FastJet.AngularCorrelationTool(4.0, False, 0.06))
# Require three peaks
ACF.add_tool(SJ.JetMomentSelectorTool(int)("nPeaks", 3, 3))


# Configure output--------------------------------
builder.add_text_output("../data/output/boost2011.dat") # optional
outfile = "../data/output/boost2011.root"
builder.configure_output("SpartyJet_Tree", outfile)

# Run SpartyJet
builder.process_events()

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)

