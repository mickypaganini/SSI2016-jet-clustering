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

'''The jet analyses implemented for the Boost2011 report, arXiv:1201.0008.
'''

from spartyjet import SpartyJet as SJ, fastjet as fj, Njettiness
from JetAnalysisLive import AntiKt, AntiKtPlusCA, AntiKtPlusKt, Parameter
import ROOT


class KtMinMass(AntiKtPlusKt):
  def __init__(self, **kwargs):
    AntiKtPlusKt.__init__(self, **kwargs)
    self.set_name('KtMinMass')
    # min-mass mW measurement
    minMass = fj.MinMassFunction()
    self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(minMass, "mW"))

  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass', 'mW']]


class ATLAS(KtMinMass):
  def __init__(self, **kwargs):
    KtMinMass.__init__(self, **kwargs)
    self.set_name('ATLAS')
    # set up zcut variables
    zCutFunctions = [fj.zCutFunction(i) for i in range(1,5)]
    [self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(zCut, 'zcut'+str(i))) for (i, zCut) in enumerate(zCutFunctions, 1)]

  def outputVariables(self):
    vars = ['mass', 'mW']+['zcut'+str(i) for i in range(1,5)]
    return [('_'.join([self.name(), var]), 'F') for var in vars]  


class CMS(AntiKtPlusCA):
  def __init__(self, deltap=0.05, deltar=0.4, A=.0004, **kwargs):
    AntiKtPlusCA.__init__(self, **kwargs)
    self.set_name('CMS')
    # measure and save mass before "pruning" step
    massFunction = SJ.FastJet.MassFunction()
    self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(massFunction, "AKTmass"))

    CMStransformer = fj.CMSTopTagger(deltap, deltar, A)
    ROOT.SetOwnership(CMStransformer, False) # Don't understand why this is necessary...
    self.add_tool(SJ.FastJet.TransformerTool("CMSTagger", CMStransformer))

  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['AKTmass', 'mW', 'cosThetaH']]
  
  @staticmethod
  def parameters():
    return AntiKtPlusCA.parameters() + [Parameter('deltap', 0.05, [0.0, 0.25]), Parameter('deltar', 0.4, [0.1, 0.6]), Parameter('A', 0.0004)]#, [0.0, 0.002])]


class HEP(AntiKtPlusCA):
  def __init__(self, mass_drop_threshold=0.8, max_subjet_mass=30.0, **kwargs):
    AntiKtPlusCA.__init__(self, **kwargs)
    self.set_name('HEP')
    HEPtransformer = fj.HEPTopTagger(mass_drop_threshold, max_subjet_mass)
    ROOT.SetOwnership(HEPtransformer, False)
    self.add_tool(SJ.FastJet.TransformerTool("HEPTagger", HEPtransformer))
      
  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass', 'mW', 'cosThetaH']]
  
  @staticmethod
  def parameters():
    return AntiKtPlusCA.parameters() + [Parameter('mass_drop_threshold', 0.8, [0.5, 1.0]), Parameter('max_subjet_mass', 30.0, [10.0, 60.0])]


class JohnsHopkins(AntiKtPlusCA):
  def __init__(self, deltap=0.1, deltar=0.19, **kwargs):
    AntiKtPlusCA.__init__(self, **kwargs)
    self.set_name('JH')
    JHtransformer = fj.JHTopTagger(deltap, deltar, 10.0) # last arg is cos_theta_W_max
    ROOT.SetOwnership(JHtransformer, False)
    self.add_tool(SJ.FastJet.TransformerTool("JHTagger", JHtransformer))
    
  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass', 'mW', 'cosThetaH']]
  
  @staticmethod
  def parameters():
    return AntiKtPlusCA.parameters() + [Parameter('deltap', 0.1, [0.0, 0.25]), Parameter('deltar', 0.19, [0.1, 0.35])]


class NSubjettiness(AntiKt):
  def __init__(self, axesChoice=Njettiness.onepass_kt_axes, beta=1.0, **kwargs):
    AntiKt.__init__(self, **kwargs)
    self.set_name('NSub')
    for i in [1,2,3]:
      nsub_tool = fj.Nsubjettiness(i, axesChoice, beta, R)
      self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(nsub_tool, "tau"+str(i)))

  def outputVariables(self):
    vars = [s.replace('$$', self.name()) for s in ['$$_tau3/$$_tau2', '$$_mass', '$$_tau2/$$_tau1']]
    return [(var, 'F') for var in vars]


class Pruned(AntiKt):
  def __init__(self, zcut=0.1, Dcut=0.5, **kwargs):
    AntiKt.__init__(self, **kwargs)
    self.set_name('Pruned')
    pruner = fj.Pruner(fj.cambridge_algorithm, zcut, Dcut)
    self.add_tool(SJ.FastJet.TransformerTool("Pruner", pruner))
    # min-mass mW measurement
    minMass = fj.MinMassFunction()
    self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(minMass, "mW"))

  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass', 'mW']]

  @staticmethod
  def parameters():
    return AntiKt.parameters() + [Parameter('zcut', 0.1, [0.0, 0.5]), Parameter('Dcut', 0.5, [0.1, 1.0])]


class Trimmed(AntiKt):
  def __init__(self, Rsub=0.35, pTFrac=0.03, **kwargs):
    AntiKt.__init__(self, **kwargs)
    self.set_name('Trimmed')
    trimmer = fj.Filter(Rsub, fj.SelectorPtFractionMin(pTFrac))
    ROOT.SetOwnership(trimmer, False)
    self.add_tool(SJ.FastJet.TransformerTool("TrimmerTool", trimmer))
    # min-mass mW measurement
    minMass = fj.MinMassFunction()
    self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(minMass, "mW"))
  
  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass', 'mW']]

  @staticmethod
  def parameters():
    return AntiKt.parameters() + [Parameter('Rsub', 0.35, [0.1, 0.5]), Parameter('pTFrac', 0.03, [0.0, 0.15])]


class ThalerWang(KtMinMass):
  def __init__(self, **kwargs):
    KtMinMass.__init__(self, **kwargs)
    self.set_name('TW')
    zCellFunction = fj.zCellFunction()
    self.add_tool(SJ.FastJet.PseudoJetMomentTool(double)(zCellFunction, "zcell"))
  
  def outputVariables(self):
    return [('_'.join([self.name(), var]), 'F') for var in ['mass', 'mW', 'zcell']]

