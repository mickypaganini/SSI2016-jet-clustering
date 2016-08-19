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

#include "TransformerMomentHandler.hh"
#include "JetCore/Jet.hh"
#include "JetCore/JetMomentMap.hh"

#include "fastjet/tools/TopTaggerBase.hh"
#include "fastjet/tools/JHTopTagger.hh"

#include "CMSTopTagger.hh"
#include "HEPTopTaggerWrapper.hh"
using namespace fastjet;

namespace SpartyJet {
namespace FastJet {

TransformerMomentHandler* getMomentHandler(fastjet::Transformer* t) {
  if (dynamic_cast<CMSTopTagger*>(t))    return new CMSTopTaggerMomentHandler();
  if (dynamic_cast<HEPTopTagger*>(t))    return new HEPTopTaggerMomentHandler();
  if (dynamic_cast<JHTopTagger*>(t))     return new JHTopTaggerMomentHandler();
  if (dynamic_cast<TopTaggerBase*>(t))   return new TopTaggerMomentHandler();
  return new TransformerMomentHandler();
}


void TopTaggerMomentHandler::init(JetMomentMap* map) {map->schedule_jet_moment<Double32_t>("mW");}

void TopTaggerMomentHandler::set_moments(const Jet* j, JetMomentMap* map) {
  map->set_jet_moment<Double32_t>("mW", j, j->structure_of<TopTaggerBase>().W().m());
}


void JHTopTaggerMomentHandler::init(JetMomentMap* map) {
  TopTaggerMomentHandler::init(map);
  map->schedule_jet_moment<Double32_t>("cosThetaH");
}

void JHTopTaggerMomentHandler::set_moments(const Jet* j, JetMomentMap* map) {
  TopTaggerMomentHandler::set_moments(j, map);
  map->set_jet_moment<Double32_t>("cosThetaH", j, j->structure_of<JHTopTagger>().cos_theta_W());
}


void CMSTopTaggerMomentHandler::init(JetMomentMap* map) {
  TopTaggerMomentHandler::init(map);
  map->schedule_jet_moment<Double32_t>("cosThetaH");
}

void CMSTopTaggerMomentHandler::set_moments(const Jet* j, JetMomentMap* map) {
  TopTaggerMomentHandler::set_moments(j, map);
  map->set_jet_moment<Double32_t>("cosThetaH", j, j->structure_of<CMSTopTagger>().cos_theta_W());
}


void HEPTopTaggerMomentHandler::init(JetMomentMap* map) {
  TopTaggerMomentHandler::init(map);
  map->schedule_jet_moment<Double32_t>("cosThetaH");
}

void HEPTopTaggerMomentHandler::set_moments(const Jet* j, JetMomentMap* map) {
  TopTaggerMomentHandler::set_moments(j, map);
  map->set_jet_moment<Double32_t>("cosThetaH", j, j->structure_of<HEPTopTagger>().cos_theta_W());
}




}
} // namespace SpartyJet
