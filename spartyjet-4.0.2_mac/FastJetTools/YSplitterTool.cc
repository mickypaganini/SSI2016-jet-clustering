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

#include "YSplitterTool.hh"
#include "JetCore/JetCollection.hh"

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
using namespace fastjet;

namespace SpartyJet { 
namespace FastJet {
  
const int YSplitterTool::MAX;

YSplitterTool::YSplitterTool(float R, JetAlgorithm alg, int ny, int njet, std::string name)
: JetTool(name) { 
   m_jet_def = new JetDefinition(alg, R, Best);
   configure(ny, njet);
}

YSplitterTool::YSplitterTool(JetDefinition* jet_def, int ny, int njet, std::string name)
: JetTool(name) { 
   m_jet_def = jet_def;
   configure(ny, njet);
}

void YSplitterTool::configure(int ny, int njet) {
  m_njets = njet;

  if (ny > MAX) {
    m_log << ERROR << "MAX number of values is " << MAX << ", setting n=" << MAX << std::endl;
    m_nvalues = MAX;
  } else
    m_nvalues = ny;
}

void YSplitterTool::init(JetMomentMap* mmap) {
  if (mmap != NULL)
    mmap->schedule_jet_moment<JetMomentMap::value_store_t>("YS_vals");
}

void YSplitterTool::execute(JetCollection& inputJets) {
  // retrieve the map of the collection :
  JetMomentMap * themap = inputJets.get_JetMomentMap();
  if (!themap->has_jet_moment("YS_vals")) {
    m_log << ERROR << "No scheduled moment YS_vals" << std::endl;
    return;
  }

  // Loop over jets and run alg on constituents
  JetCollection::iterator jit = inputJets.begin();
  JetCollection::iterator jitE = inputJets.end();
  int nFilled = 0;
  for (; jit!=jitE; ++jit, ++nFilled) {
    JetMomentMap::value_store_t arr(m_nvalues, 0.0);
    
    if (nFilled >= m_njets && m_njets != -1) {
      // do nothing. just fill the moment with blank array
      themap->set_jet_moment("YS_vals", (*jit), arr);
      continue;
    }
    
    double jet_scale;;
    if (m_jet_def->jet_algorithm() == kt_algorithm)
      jet_scale = (*jit)->perp2();
    else if (m_jet_def->jet_algorithm() == cambridge_algorithm)
      jet_scale = 1.0;
    else if (m_jet_def->jet_algorithm() == antikt_algorithm)
      jet_scale = 1/(*jit)->perp2();
    else
      jet_scale = (*jit)->perp2();
    
    std::vector<PseudoJet> constituents = (*jit)->constituents();
    // Recluster constituents with new jet def
    ClusterSequence clust_seq(constituents, *m_jet_def);
    // Extract Y values
    for (int i = 1; i < m_nvalues + 1; i++) {
      arr[i-1] = clust_seq.exclusive_dmerge(i)/jet_scale;
    }
    // Save in Moment Map
    themap->set_jet_moment("YS_vals", (*jit), arr);
  }
}


}  // namespace FastJet
}  // namespace SpartyJet
