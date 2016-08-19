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

'''
A pair of helper functions for creating InputMakers to read files.

In most cases, you can just do
  input = getInputMaker('filename.ext')
and the function will create the appropriate InputMaker based on the extension.

For ROOT files, this calls createNtupleInputMaker.  If getInputMaker('foo.root')
fails, you may need to call createNtupleInputMaker directly to supply
information such as the correct TTree name, the input prefix for momentum
branches, etc.

'''

import logging
m_log = logging.getLogger('SpartyLog')
outStr = logging.StreamHandler()
format = logging.Formatter("%(module)-18s  %(levelname)-8s  %(message)s")
outStr.setFormatter(format)
m_log.addHandler(outStr)

from spartyjet import SJ

def syncMessageLevel():
    '''Gets spartyjet global message level
    and sets logger to same level'''
    ld = { 
            SJ.DEBUG  :logging.DEBUG,
            SJ.INFO   :logging.INFO,
            SJ.WARNING:logging.WARNING,
            SJ.ERROR  :logging.ERROR
        }
    
    m_log.setLevel(ld[SJ.GlobalLevel()])


def createNtupleInputMaker(filename, treename="", inputprefix="GUESS", Nvar="",
                           momentumVars=(), inputType=None, masslessMode=False, inputsuffix=""):
    """ Create & configure a NtupleInputMaker class
    
    The function will try to guess eveything from the given filename
    TODO: Figure out input name in more cases.
    """
    from ROOT import TFile, TTree
    
    syncMessageLevel()

    f = TFile(filename)
    if not f.IsOpen():
        m_log.error('Could not open ROOT file with name ', filename)
        return

    # ---------------------------------
    # get tree
    tree = None
    if treename == "":
        # use the first TTree found
        keys = [k.GetName() for k in f.GetListOfKeys( ) ]
        for k in keys:
            t = f.Get(k)
            if isinstance(t, TTree):
                tree = t
                treename = k
                break
    else:
        tree = f.Get(treename)
    if not bool(tree) :
        m_log.error("Couldn't find tree in ",filename)
        return
    # ---------------------------------

    branches = [b.GetName() for b in  tree.GetListOfBranches( ) ]


    # ---------------------------------
    # Guess input prefix if not set
    if inputprefix=="GUESS":
        # branches, lower case
        for bn in branches:
        # we'll look for vars containing 'input'
            if 'input' in bn.lower() and '_' in bn:
                inputprefix = bn[:bn.find('_')] # get the part before '_'
                break
        # we'll look for  vars without prefix'
            if bn.lower() == 'eta' or bn.lower() == 'px':
                inputprefix = ''
                break
        if inputprefix=="GUESS":
            m_log.error("Couldn't guess proper prefix for input variables")
            return
        else:
            m_log.info("Found prefix input = "+inputprefix)
    # ---------------------------------



    if inputprefix == '':
        # retrieve all variables starting with inputprefix
        branches = [ b for b in branches if '_' not in b ]
        # retrieve all vars from the branch name above : the XX part in bla_XX
        vars = dict([(b.lower(),b) for b in branches])
    else:
        if not inputprefix.endswith('_'): inputprefix += '_'
        # retrieve all variables starting with inputprefix
        branches = [ b for b in branches if b.startswith(inputprefix) ]
        # retrieve all vars from the branch name above : the XX part in bla_XX
        vars = dict( [( b[b.find('_')+1:].lower(), b[b.find('_')+1:] ) for b in branches] )


    # ---------------------------------
    # Guess kinematic variables 
    if momentumVars==():
        # try px,py,pz,e
        vars_set = set(vars.keys())
        if vars_set.issuperset(set(['px','py','pz','e'])):
            momentumVars = tuple([ vars[k] for k in ('px','py','pz','e') ])
        elif vars_set.issuperset(set(['eta','phi','pt','e'])):
            momentumVars = tuple([ vars[k] for k in ('eta','phi','pt','e') ])
        elif vars_set.issuperset(set(['eta','phi','p_t','e'])):
            momentumVars = tuple([ vars[k] for k in ('eta','phi','p_t','e') ])
        elif vars_set.issuperset(set(['eta','phi','pt','m'])):
            momentumVars = tuple([ vars[k] for k in ('eta','phi','pt','m') ])
        elif vars_set.issuperset(set(['eta','phi','p_t'])):
            momentumVars = tuple([ vars[k] for k in ('eta','phi','p_t') ])
        elif vars_set.issuperset(set(['eta','phi','pt'])):
            momentumVars = tuple([ vars[k] for k in ('eta','phi','pt') ])

        if momentumVars == ():
            m_log.error("Couldn't guess  kinematic input variables")
            return
        else:
            m_log.info("Found kinematic input = "+str(momentumVars))
    # ---------------------------------
    # Guess input type
    if inputType == None:
        vtype = _branchType(tree.GetBranch(inputprefix+momentumVars[0]))
        momkey = (momentumVars[0]+momentumVars[-1]).lower()
        inputType = {
            'pxevector_double'   : SJ.NtupleInputMaker.PxPyPzE_vector_double ,  
            'pxevector_float'    : SJ.NtupleInputMaker.PxPyPzE_vector_float,
            'pxearray_double'    : SJ.NtupleInputMaker.PxPyPzE_array_double,
            'pxearray_float'     : SJ.NtupleInputMaker.PxPyPzE_array_float,
            'etaevector_double'  : SJ.NtupleInputMaker.EtaPhiPtE_vector_double,  
            'etaevector_float'   : SJ.NtupleInputMaker.EtaPhiPtE_vector_float,
            'etaearray_double'   : SJ.NtupleInputMaker.EtaPhiPtE_array_double,
            'etaearray_float'    : SJ.NtupleInputMaker.EtaPhiPtE_array_float,
            'etamvector_double'  : SJ.NtupleInputMaker.EtaPhiPtM_vector_double,
            'etamvector_float'   : SJ.NtupleInputMaker.EtaPhiPtM_vector_float,
            'etamarray_double'   : SJ.NtupleInputMaker.EtaPhiPtM_array_double,
            'etamarray_float'    : SJ.NtupleInputMaker.EtaPhiPtM_array_float,
            'etaptvector_double' : SJ.NtupleInputMaker.EtaPhiPt_vector_double,
            'etaptvector_float'  : SJ.NtupleInputMaker.EtaPhiPt_vector_float,
            'etaptarray_double'  : SJ.NtupleInputMaker.EtaPhiPt_array_double,
            'etaptarray_float'   : SJ.NtupleInputMaker.EtaPhiPt_array_float
            }[momkey+vtype]
        m_log.info("Input variables type = "+vtype)
    
    # ---------------------------------
    # Guess variable N
    # only needed if array input
    if Nvar == "":
        for nName in ['n','num','nparticle']:
            if nName in vars:
                Nvar = vars[nName]
        if Nvar == "":
            if 'array' in vtype:
                m_log.error("Couldn't guess proper input_n variable, please define manually.")
                return
            else:
                m_log.info("Couldn't guess proper input_n variable, input_n will be read from vector size.")
        else:
            m_log.info("Found prefix input_n = "+inputprefix+Nvar)
    # ---------------------------------

    # guess if PDG Ids are stored
    pdgName = None
    for b in branches:
      if 'pdg' in b.lower():
        pdgName = b[b.find('_')+1:]
        break
        

    input = SJ.NtupleInputMaker(inputType)
    input.set_prefix(inputprefix)
    input.set_n_name(Nvar)
    input.set_variables(*momentumVars)
    input.setFileTree(filename, treename)
    input.set_name("InputJet")
    input.set_masslessMode(masslessMode) # 

    if (pdgName is not None):
      input.read_pdgId(True)
      input.set_pdgId_name(pdgName)
    
    return input

def getInputMaker(filename):
   """
   Guesses the appropriate InputMaker given a file's extension.
   
   For .root files, calls createNtupleInputMaker below.  Other supported formats:
   .hep (StdHep)
   .hepmc (HepMC)
   .lhe (Les Houches Accord event format)
   .UW (simple text format)
   .dat (assumes file can be read by StdTextInput)
   """
   from ROOT import SpartyJet as SJ
   extensionMap = {
      'hepmc' : SJ.HepMCInput,
      'lhe' : SJ.LheInput,
      'UW' : SJ.HuskyInput,
      'dat' : SJ.StdTextInput
   }

   try:
      extensionMap['hep'] = SJ.StdHepInput
   except:
      pass

   extension = filename.split('.')[-1] # everything after the last '.'
   if extension == 'root':
      return createNtupleInputMaker(filename)
   elif extension in extensionMap.keys():
      return extensionMap[extension](filename)
   elif extension == 'hep':
      m_log.error(filename+" cannot be loaded. StdHepInput not enabled.  To enable, edit MakefileCommonOpt and then type 'make'")
      import sys
      sys.exit(1)
   else:
      m_log.error("Can't identify file type from extension "+extension+"!")
      import sys
      sys.exit(1)



# utils ...
def _branchType(b):
    from ROOT import TBranchElement
    if isinstance(b, TBranchElement):
        if 'double' in b.GetTypeName():
            return 'vector_double'
        else:
            return 'vector_float'            
    else: # assume it's a TBranch
        if '/F' in b.GetTitle( ):
            return 'array_float'
        else:
            return 'array_double'


def writeCurrentFile(rootFile):
    ''' Save a copy of the current script, as a TText, in the current ROOT file
        nothing happens if a ROOT file is not currently open!
    '''
    import sys, os.path
    from ROOT import TString, TText, TFile
    filename = sys.argv[0]
    if (not os.path.exists(filename)):
        m_log.error("Could not open file "+filename+"!")
        return
    s = TString()
    t = TText()
    # Too fresh
    #with open(filename) as input:
    input = open(filename)
    if input:
        for line in input:
            s += line
    t.SetName(os.path.basename(filename))
    t.SetText(0,0,s.Data())
    f = TFile(rootFile, 'UPDATE')
    t.Write()
    f.Close()

