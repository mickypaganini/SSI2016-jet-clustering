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

from JetAnalysisLive import *
from boost import *

# Global list of Analysis classes
#  Can instantiate, e.g., via:
# for type in ListOfAnalyses:
#   analysis = type(**dict([(p.name, p.defaultValue) for p in type.outputVariables()]))
ListOfAnalyses = [AntiKt, AntiKtPlusCA, AntiKtPlusKt, # Basics
                  ATLAS, CMS, JohnsHopkins, HEP, NSubjettiness, Pruned, Trimmed, ThalerWang] # BOOST2011

# don't make analyses available without scoping
__all__ = ['JetAnalysisLive', 'boost', 'ListOfAnalyses']