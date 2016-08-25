#!/usr/bin/env python
# $Id: guiExample.py 545 2012-01-18 06:10:03Z cvermilion $
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
import spartyjet.style
from spartyjet.gui import SpartyGui
from ROOT import gClient, gStyle, TFile, TTree, TIter
import sys
#======================================

if len(sys.argv) < 2:
  print 'Usage: ./guiExample.py filename [filename2 ...]'

files = sys.argv[1:]

# find trees
trees = []
for filename in files:
  f = TFile(filename)
  treenames = []
  next = TIter(f.GetListOfKeys())
  k = next()
  while k:
    if k.GetClassName() == "TTree" and k.GetName() not in treenames:
      trees += [(k.GetName(), filename)]
      treenames += [k.GetName()]
    k = next()

gui = SpartyGui(gClient.GetRoot())
[gui.addTree(tree, file) for tree,file in trees]

#To manually set input branches use 'inputname'
#[gui.addTree("SpartyJet_Tree", file, inputname='Clusters') for file in files]

gui.init()

# If you call this interactively, via "python -i guiExample.py", then you can
#  interact with the GUI via the interpreter, e.g.:

## If input is in MeV : reset the min pt to 1000 (1 by default)
#gui.viewersOption_min_pt_display(1000.)
## Set the final pt cut when running jet alg
#gui.setLiveAlgFinalCut( 1000.)
## Include input particles in the 2D event view
# gui.Event2DView.option_2Dview_draw_input = True


# To require keyboard input to exit
raw_input()


