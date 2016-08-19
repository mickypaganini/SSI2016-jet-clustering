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


/*
 * Wraps the Qjets plugin.  For each initial jet passed to this tool, the Qjets
 * plugin is run N times, producing jets representing different possible
 * pruning histories.  The average jet mass <m> and the "volatility" 
 * V = sqrt(<m^2> - <m>^2)/<m>  are stored as jet moments.
 */

#ifndef _QJETSTOOL_HH_
#define _QJETSTOOL_HH_

#include "JetCore/JetTool.hh"
#include "JetCore/JetCollection.hh"
#include "Qjets/QjetsPlugin.hh"

#include "fastjet/ClusterSequence.hh"

namespace SpartyJet {
namespace FastJet {

class QjetsTool : public JetTool {
public:
  QjetsTool(QjetsPlugin* plugin, int N, std::string name="QjetsTool")
    : JetTool(name), _plugin(plugin), _N(N) {
  }
  ~QjetsTool() {}
  
  void init(JetMomentMap* mmap=0) {
    if (mmap) {
      mmap->schedule_jet_moment<Double32_t>("QjetMass");
      mmap->schedule_jet_moment<Double32_t>("QjetVolatility");
    }
  }
  
  void execute(JetCollection& inputJets) {
    fastjet::JetDefinition jet_def(_plugin);
    JetCollection::iterator it, itE = inputJets.end();
    for (it = inputJets.begin(); it != itE; ++it) {
      double mSum = 0.0;
      double m2Sum = 0.0;
      for (int n = 0; n < _N; ++n) {
        fastjet::ClusterSequence cs((*it)->constituents(), jet_def);
        fastjet::PseudoJet qjet = cs.inclusive_jets()[0];
        double mass = qjet.m();
        mSum += mass;
        m2Sum += mass*mass;
      }
      
      // calculate and store average mass and volatility
      double mave = mSum/_N;
      double m2ave = m2Sum/_N;
      double volatility = std::sqrt(m2ave - mave*mave)/mave;
      JetMomentMap* map = inputJets.get_JetMomentMap();
      map->set_jet_moment("QjetMass", *it, mave);
      map->set_jet_moment("QjetVolatility", *it, volatility);
    
    }

  }

protected:
  QjetsPlugin* _plugin;
  int _N; // how many plugin clusterings to run for each jet
};



}
} // namespace SpartyJet

#endif
