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

import os
import JetHistoryGui

_initialCutTool = SJ.JetPtSelectorTool(0.0)
_finalCutTool = SJ.JetPtSelectorTool(1.0)


class PyJetRetrieverLive(object):    
    """Holds a JetAnalysis and uses it to rebuild a jet collection"""

    @staticmethod
    def setFinalCut(cut):
        _finalCutTool.setCut(cut)

    def __init__(self, analysis):
        """Sets up an analysis to run live on inputs"""
        analysis.add_tool_front(_initialCutTool)
        analysis.add_tool(_finalCutTool)
        self.analysis = analysis
        analysis.init()
        self.currentEvent = -1
        pass


    def fill_collection(self, jc_item, event):
        """ jc_item a JetCollItems. 
        The input jet collection and jet collection associated (jetcoll) to this jc_item are filled
        jc_item.jetcoll is the result of the jet algorithm holded by self
        event (int) : the event number
        """
        # do not re-run if this event has already been found.
        if self.currentEvent == event:
            return
        self.currentEvent = event
        jc_item.jetcoll.clear_and_delete()
        #print ' Filling collection ',jc_item.inputcoll , jc_item.jetcoll
        jc_item.input_retriever.fill_inputColl(jc_item.inputcoll,event)
        #print '  ... input filled ',jc_item.inputcoll.size()
        self.analysis.execute(jc_item.inputcoll, jc_item.jetcoll)
        #print '  JetRetrieverLive alg executed.'
        self.analysis.finalize()
        ## inph = set( el.jet for el in JetHistoryGui.vector_iterate(jc_item.jetcoll.history()) if not el.parent1  )
        ## for  i in inph:
        ##     print i, i.e()
        #print jc_item.jetcoll,'  after fill_collection inph=',inph

        jc_item.jetcoll.set_algo_indices(jc_item.inputcoll.size())

    def get_current_event(self):
        return self.currentEvent
    

