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

from ROOT import gSystem

# Load SpartyJet.  <spartyjet-dir>/lib should be in $[DY]LD_LIBRARY_PATH for Linux [Mac]

_sj_libs=[  'libExternal.so',
            'libJetCore.so',
            'libIO.so',
            'libJetTools.so',
            'libFastJetTools.so',
            'libExternalTools.so',
            'libEventShape.so',
            'libSpartyDisplay.so',
            'libUserPlugins.so'
        ]

[gSystem.Load(lib) for lib in _sj_libs]

# Load SpartyJet:: and fastjet:: namespaces and give them aliases
from ROOT import SpartyJet
SJ = SpartyJet
from ROOT import fastjet
fj = fastjet

# external tools not in the SpartyJet or fastjet namespaces
from ROOT import Njettiness
from ROOT import QjetsPlugin

# use ROOT's Double32_t (many moments are stored this way) as 'double'
#from ROOT import Double_t as double

# make main directory available
from os.path import join, abspath, pardir
SPARTYJETDIR = abspath(join(__path__[0], pardir, pardir))

# explicitly load sub-modules so user can just do 'from spartyjet import *'
from io import getInputMaker, createNtupleInputMaker, writeCurrentFile
from utils import stdVector
from analyses import JetAnalysisLive, boost


# ----- Extend Python syntax for FJ Selectors -----
# Duck punch Selector's operators to use globally-defined C++ operators
#  (See External/FJWrapper.hh)
# Use these functions via:
#  s_or = s1 | s2
#  s_and = s1 & s2
#  s_times = s1 * s2
# Note that and/or use bitwise operators.  For jet-by-jet Selectors, & and * are
#  equivalent.
def Selector_or(self, other):
    return fj.Selector_or(self, other)
fj.Selector.__or__ = Selector_or

def Selector_and(self, other):
    return fj.Selector_and(self, other)
fj.Selector.__and__ = Selector_and

def Selector_mul(self, other):
    return fj.Selector_mul(self, other)
fj.Selector.__mul__ = Selector_mul


# ----- Start-up routines --------------

# print a banner
def _centeredLine(l):
    return '|' + l.center(78) + '|'

def _printBanner():
    print '#' + ('-'*78) + '#'
    print _centeredLine('SpartyJet 4.0.1')
    print _centeredLine('P.-A. Delsart, K. Geerlings, J. Huston, B. Martin, C. K. Vermilion')
    print _centeredLine('http://projects.hepforge.org/spartyjet')
    print _centeredLine(' ')
    print _centeredLine('A package for jet finding and visualization')
    print _centeredLine('Jet finding is performed using the FastJet package.')
    print _centeredLine(' ')
    print _centeredLine('Many externally authored tools are provided with SpartyJet;')
    print _centeredLine('see COPYING for details.')
    print _centeredLine(' ')
    print _centeredLine('If you use SpartyJet for a publication, please cite arXiv:1201.3617.')
    print '#' + ('-'*78) + '#'

_printBanner()

