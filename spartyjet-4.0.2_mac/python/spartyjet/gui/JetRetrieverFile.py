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

from spartyjet import SpartyJet as SJ

class PyJetRetrieverFile(SJ.JetRetrieverFile):
    def __init__(self):
        SJ.JetRetrieverFile.__init__(self)

    def guess_input(self):
        t = self.get_tree()
        blist = t.GetListOfBranches() # iterating directly broke in at least one ROOT/Python combo
        for i in range(blist.GetLast()):
            s = blist[i].GetName()
            if 'input' in s.lower():
                return s[:s.rfind('_')]

        print 'WARNING: Could not find input collection.  Please specify explicitly in addTree().'
        print '  On-the-fly algorithms and some event displays will be broken,'
        print '  but run plots should be OK.'
        return ''

    def find_algs(self, inputname, alias=""):
        t = self.get_tree()
        if alias != '':
            alias = alias+'.'
        names = set()
        blist = t.GetListOfBranches()
        for i in range(blist.GetLast()):
            s = blist[i].GetName()
            names.add(alias+s[:s.rfind( '_')] )
        names = list(names - set([inputname]))
        names.sort()
        print 'Found algs ', names
        self.set_input_name(inputname)
        for n in names:
            self.add_jetcoll_reader(n, True)
        self.names = names
        return names

    def fill_collection(self, jc_item, event):
        numc = self.names.index(jc_item.name)
        self.get_collection(jc_item.inputcoll, jc_item.jetcoll, numc, event)
        
            
        
