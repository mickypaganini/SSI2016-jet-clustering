#!/usr/bin/env python
# $Id: mergedInputExample.py 545 2012-01-18 06:10:03Z cvermilion $
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

# Example showing the use of several input files whose events are merged.
# inputExample.py gives an example where the results for each file are separate.

def shortName(path):
  from os.path import basename
  b = basename(path)
  return b.split('.')[0] # take everything up to first period

input = SJ.MultiInput()
fileList = ['../data/J2_clusters_wPile.root', '../data/J2_clusters_wPile2.root']
for f in fileList:
    print "Opening: ", f
    input_i = createNtupleInputMaker(f, inputprefix='Cluster')
    input_i.set_name(shortName(f))
    input.addInputMaker(input_i)

builder = SJ.JetBuilder(SJ.INFO)    
builder.configure_input(input)
outfile = '../data/output/J2_clusters_wPile_merged.root'
builder.configure_output('SpartyJet_Tree', outfile)
builder.add_default_analysis(SJ.FastJet.FastJetFinder('Kt4', fastjet.kt_algorithm, 0.4))

#builder.process_events() # all events or use -1 
builder.process_events(20) # first 20 events (will go through files in order until 20 events reached)

# Save this script in the ROOT file (needs to go after process_events or it
#  gets over-written!)
writeCurrentFile(outfile)
