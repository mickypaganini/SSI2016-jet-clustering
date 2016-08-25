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

#include "PtDensityTool.hh"
#include "JetCore/JetCollection.hh"

#include "FastJetUtils.hh"
#include "fastjet/ClusterSequenceArea.hh"

namespace SpartyJet { 
namespace FastJet {

PtDensityTool::PtDensityTool(std::string name, fastjet::JetAlgorithm densAlg,
                             float R, fastjet::AreaType area,
                             std::vector<float> etaBins)
: JetTool(name) {
  m_densDef = fastjet::JetDefinition(densAlg, R);
  m_areaDef = fastjet::AreaDefinition(area);
  setEtaBins(etaBins);
}

PtDensityTool::PtDensityTool(std::string name, fastjet::JetDefinition* densDef,
                             fastjet::AreaType area, std::vector<float> etaBins)
: JetTool(name) {
	m_densDef  = *densDef;
	m_areaDef = fastjet::AreaDefinition(area);
	setEtaBins(etaBins);
}

PtDensityTool::PtDensityTool(std::string name,fastjet::JetDefinition* densDef,
                             fastjet::AreaType area,
                             std::vector<fastjet::RangeDefinition>* rangeDefVec)
: JetTool(name) {
  m_densDef = *densDef;
  m_areaDef = fastjet::AreaDefinition(area);
  m_rangeDefVec = *rangeDefVec;
}

void PtDensityTool::init(JetMomentMap* mmap) 
{
  if (mmap != 0) {
    if (!mmap->has_event_moment("ptDensity")) {
         mmap->schedule_event_moment<JetMomentMap::value_store_t>("ptDensity");
         mmap->schedule_event_moment<JetMomentMap::value_store_t>("ptDensityBins");
    }
  }
}

void PtDensityTool::execute(JetCollection& inputJets) 
{
  // retrieve the map of the collection :
  JetMomentMap* themap = inputJets.get_JetMomentMap();

  // Convert to PseudoJets
  std::vector<fastjet::PseudoJet> pjets;
  pjets.reserve(inputJets.size()); // we know what will be the size
  JetCollection::iterator jItr = inputJets.begin();
  for (; jItr != inputJets.end(); ++jItr)
    pjets.push_back(**jItr);
	
  // Find jets
  fastjet::ClusterSequenceArea clust_seq_area(pjets,m_densDef,m_areaDef);

  // Extract ptDensity
  JetMomentMap::value_store_t rhoVec;
  JetMomentMap::value_store_t rhoBinVec;
  std::vector<fastjet::RangeDefinition>::iterator rItr =  m_rangeDefVec.begin();
  std::vector<fastjet::RangeDefinition>::iterator rItrE = m_rangeDefVec.end();
  double rapMin, rapMax;
  rItr->get_rap_limits(rapMin, rapMax);
  rhoBinVec.push_back((float)rapMin);
  for (; rItr != rItrE; ++rItr) {
    float rho = clust_seq_area.median_pt_per_unit_area(*rItr);
    rhoVec.push_back(rho);
    m_log << DEBUG << "rho = " << rho << " in " << (*rItr).description() << std::endl;
    rItr->get_rap_limits(rapMin, rapMax);
    rhoBinVec.push_back((float)rapMax);
  }

  // Save to map
  themap->set_event_moment("ptDensity", rhoVec);
  themap->set_event_moment("ptDensityBins", rhoBinVec);
}

void PtDensityTool::setEtaBins(std::vector<float> etaBins)
{
  float rapMin = etaBins[0];
  for (unsigned int i = 1; i < etaBins.size(); ++i) {
    m_rangeDefVec.push_back(fastjet::RangeDefinition(rapMin, etaBins[i]));
    rapMin = etaBins[i];
  }      
}

}  // namespace SpartyJet::FastJet
}  // namespace SpartyJet
					                   	                
