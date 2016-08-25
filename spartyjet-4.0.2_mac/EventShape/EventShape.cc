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

#include "EventShape.hh"

namespace SpartyJet { 
namespace eventshape {

  ShapeConfig::ShapeConfig(std::string name) : m_name(name) {
    m_etaSelec.set_cut(5.);
    m_etaSelec.set_cut2(-5.); 
    m_ptSelec.set_cut(0); 
    m_analysis.set_name(name); 
    
    m_analysis.add_tool(&m_etaSelec);
    m_analysis.add_tool(&m_ptSelec);
  }

  void ShapeConfig::add_eventshape(JetTool* tool) {
    m_analysis.add_tool(tool);
  }

  void ShapeConfig::add_eventshape(shape_type type) {
    // do nothing yet
  }

}
}  // namespace SpartyJet
