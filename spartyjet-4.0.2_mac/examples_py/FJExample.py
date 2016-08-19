#!/usr/bin/env python
# $Id: FJExample.py 545 2012-01-18 06:10:03Z cvermilion $
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
builder = SJ.JetBuilder(SJ.INFO)
#builder.silent_mode() # turns off debugging information

# Configure input -------------------------------
input = getInputMaker('../data/J1_Clusters.dat')
builder.configure_input(input)

#**********************************************************************************
## Below are all the different ways one may use FastJet from within SpartyJet

## Run fastjet with SpartyJet handling jet definition
name = 'AntiKt4'
alg = fj.antikt_algorithm
R = 0.4
findJetAreas = False

anti4 = SJ.FastJet.FastJetFinder(name, alg, R, findJetAreas)
builder.add_default_analysis(anti4)

## Run fastjet by passing custom Jet Definiton to SpartyJet
anti7_def = fj.JetDefinition(fj.antikt_algorithm, 0.7)
anti7 = SJ.FastJet.FastJetFinder(anti7_def, 'AntiKt7', findJetAreas)
builder.add_default_analysis(anti7)

## Run SISCone via included plugin algorithm (need to build SISCone dictionaries - see External/ExternalLinkDef.hpp)
#coneRadius = 0.7
#overlapThreshold = 0.75
#sisPlugin = fj.SISConePlugin(coneRadius, overlapThreshold)
#sisPlugin_jet_def = fj.JetDefinition(sisPlugin)
#sis7 = SJ.FastJet.FastJetFinder(sisPlugin_jet_def, 'SISCone7', findJetAreas)
#builder.add_default_analysis(sis7)

## User Plugin example
## If lib*.so is genereated as in ../external/UserPlugins/ExamplePlugin/Makefile
## then lib*.so file must be included as follows:
from ROOT import gSystem
gSystem.Load('../UserPlugins/ExamplePlugin/libExamplePlugin.so')
## else one must place the Plugin's lib*.a file and header file
## in ../fastjet/UserPlugins/ lib/ and include/ respectively
## See UserPlugins/Makefile and the manual for more information
plugin = fj.ExamplePlugin(fj.JetDefinition(fj.antikt_algorithm, 1.0))
plugin_jet_def = fj.JetDefinition(plugin)
exFinder = SJ.FastJet.FastJetFinder(plugin_jet_def, 'ExamplePlugin', False)
builder.add_default_analysis(exFinder)

## Other plugins shipped with FastJet
## To use these plugins one must:
## - uncomment the necessary lines in spartyjet/FastJetCore/FastJetCoreLinkDef.hpp
## - recompile FastJet with ./configure --enable-allcxxplugins 
##   (not need to recompile if you use FastJet shipped with SpartyJet)
## - recompile spartyjet/fastjet dir by doing: make fastjetC && make fastjet

## 3 examples, see FastJet docs for more

## CMS Iterative Cone Plugin
#coneRadius = 0.4
#seedThresh = 1.0
#cmsConePlugin = fj.CMSIterativeConePlugin(coneRadius, seedThresh)
#cmsCone_jet_def = fj.JetDefinition(cmsConePlugin)
#cmsCone = SJ.FastJet.FastJetFinder(cmsCone_jet_def, 'CMSCone', False)
#builder.add_default_analysis(cmsCone)

## Jade Plugin
#jPlugin = fj.JadePlugin()
#jPlugin_jet_def = fj.JetDefinition(jPlugin)
#jade = SJ.FastJet.FastJetFinder(jPlugin_jet_def, 'Jade', False)
#builder.add_default_analysis(jade)

## e-e Cambridge Plugin
#ycut = 0.4
#eecPlugin = fj.EECambridgePlugin(ycut)
#eecPlugin_jet_def = fj.JetDefinition(eecPlugin)
#eec = SJ.FastJet.FastJetFinder(eecPlugin_jet_def, 'EECambridge', False)
#builder.add_default_analysis(eec)


#**********************************************************************************

# Configure output--------------------------------
builder.add_text_output("../data/output/simple.dat")
outfile = "../data/output/simple.root"
builder.configure_output("SpartyJet_Tree", outfile)

# Run SpartyJet
builder.process_events(10)

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)

