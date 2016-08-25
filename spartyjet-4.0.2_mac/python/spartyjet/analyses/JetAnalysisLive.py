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

'''Extends the basic JetAnalysis class with metadata for interactive use.

JetAnalysisLive extends the basic SpartyJet::JetAnalysis class with a function
outputVariables() that returns a list of (name, type) tuples.  'name' is a
string corresponding to a jet moment stored in the output of the analysis;
'type' is either 'F' or 'I', depending on whether the variable is floating point
or integer type.  The set of variables should just be the ones expected to be
useful in separating signal and background.

Analyses must also define the function parameters(), which returns a list of
Parameter objects.  These specify the input parameters, default values, and
reasonable ranges.  The analysis should be constructable with a dictionary
of parameter names and values, e.g. the following should construct with default
values:

params = FooAnalysis.parameters()
analysis = FooAnalysis(**dict([(p.name, p.defaultValue) for p in params]))
'''

from spartyjet import SpartyJet as SJ, fastjet as fj

class Parameter(object):
  '''Simple struct representing an input parameter to a jet analysis.
  
  Contains a name, a value, and an optional range.  If range is not None it
  should be a 2-tuple giving a min and max value for the parameter.
  '''
  def __init__(self, name, value=0.0, range=None):
    self.name = name
    self.value = value
    self.range = range


# Basic template of the analysis object used in this code
#  Essentially just a SpartJet JetAnalysis plus some metadata
class JetAnalysisLive(SJ.JetAnalysis):
  def __init__(self, tool):
    SJ.JetAnalysis.__init__(self, tool)
  
  @staticmethod
  def outputVariables():
    return []
  
  @staticmethod
  def parameters():
    return []


class AntiKt(JetAnalysisLive):
  def __init__(self, R=1.0, pTmin=200.0):
    antiKtFinder = SJ.FastJet.FastJetFinder('AntiKt', fj.antikt_algorithm, R)
    antiKtFinder.set_ptmin(pTmin)
    JetAnalysisLive.__init__(self, antiKtFinder)
  
  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass']]
  
  @staticmethod
  def parameters():
    return [Parameter('R', 1.0), Parameter('pTmin', 200.0)]


# These two are just re-clustered versions of AntiKt
class AntiKtPlusCA(AntiKt):
  def __init__(self, **kwargs):
    AntiKt.__init__(self, **kwargs)
    self.set_name('CA')
    self.add_tool(SJ.FastJet.FastJetRecluster('CAcluster', fj.cambridge_algorithm, 100.0))

class AntiKtPlusKt(AntiKt):
  def __init__(self, **kwargs):
    AntiKt.__init__(self, **kwargs)
    self.set_name('Kt')
    self.add_tool(SJ.FastJet.FastJetRecluster('KTcluster', fj.kt_algorithm, 100.0))

