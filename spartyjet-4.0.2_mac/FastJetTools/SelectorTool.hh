// Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
//                 Brian Martin, and Christopher Vermilion
//
//----------------------------------------------------------------------
// This file is part of SpartyJet.
//
//  SpartyJet is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  SpartyJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with SpartyJet; if not, write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------

#ifndef _SELECTOR_TOOL_HH_
#define _SELECTOR_TOOL_HH_

#include "JetTools/JetSelectorTool.hh"
#include "JetCore/JetCollection.hh"
#include "fastjet/Selector.hh"

#include <cassert>

/// A simple wrapper for FastJet 3 Selectors
 
namespace SpartyJet {
namespace FastJet {

class SelectorTool : public JetSelectorTool {
public:
  SelectorTool(fastjet::Selector* selector, std::string name="SelectorTool")
    : JetSelectorTool(name), _selector(selector) {}

  virtual void execute(JetCollection& inputJets) {
    // if Selector applies jet-by-jet, just use pass_cut below like a "regular" JetSelectorTool
    if (_selector->applies_jet_by_jet()) {
      JetSelectorTool::execute(inputJets);
      return;
    }
    
    m_map = inputJets.get_JetMomentMap(); // now any tool can use the map in pass_cut()

    std::vector<const fastjet::PseudoJet*> pjs;
    for (size_t i = 0; i < inputJets.size(); ++i)
      pjs.push_back(inputJets[i]);
    
    _selector->nullify_non_selected(pjs);
    
    Jet::jet_list_t fail_list;
    for (size_t i = 0; i < inputJets.size(); ++i) {
      if (pjs[i] == NULL)
        fail_list.push_back(inputJets[i]);
    }
    inputJets.filter_out(fail_list);
  }

  virtual bool pass_cut(Jet* j) {
    return (*_selector)(*j);
  }

protected:
  fastjet::Selector* _selector;
};

} // namespace FastJet
} // namespace SpartyJet

#endif
