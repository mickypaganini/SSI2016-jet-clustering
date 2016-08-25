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

#ifndef _EVENTSHAPE_HH_
#define _EVENTSHAPE_HH_

#include "JetTools/JetSelectorTool.hh"
#include "JetCore/JetAnalysis.hh"
/////////////////////////////////////////////////////////////////////////
/// \class ShapeConfig
/// A convenience class to configure event shape calculation
///
/// This is just an easy way of configuring a JetAnalysis that will compute
/// event shapes. One gives ShapeConfig some JetTool that compute some global 
/// moments, then ShapeConfig returns a properly configured JetAnalysis.
/// For example :
///
///   eventshape::ShapeConfig shape;
///   eventshape::ThrustTool tt("Thrust");
///   shape.add_eventshape(&tt);
///   builder.add_eventshape_alg(shape.get_algo());
///
/// where builder is a JetBuilder instance. 
/////////////////////////////////////////////////////////////////////////
namespace SpartyJet { 

namespace eventshape {

  enum shape_type {
    // official spartyjet eventshape
    THRUST = 1,
    THRUST_PHI,
    THRUST_MINOR,
    
    // Reserve for user
    USER_DEFINED = 1000,

    //
    UNKNOWN = 10000
  };
  
  
  class ShapeConfig {
  public:
    ShapeConfig(std::string name="EventShape");
    
    
    void set_eta_range(double etamin, double etamax) {m_etaSelec.set_cut(etamax); m_etaSelec.set_cut2(etamin);}
    void set_pt_cut(double ptmin) {m_ptSelec.set_cut(ptmin);}
    
    void add_eventshape(shape_type type);
    void add_eventshape(JetTool* tool);
    
    JetAnalysis* get_analysis() {return &m_analysis;};
  protected:
    std::string m_name;
    JetEtaCentralSelectorTool m_etaSelec;
    JetPtSelectorTool m_ptSelec;
    
    JetAnalysis  m_analysis;
  };

};



}  // namespace SpartyJet
#endif
