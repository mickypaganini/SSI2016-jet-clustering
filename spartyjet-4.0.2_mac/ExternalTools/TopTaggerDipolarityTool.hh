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
 * Implements the dipolarity jet shape on top of a top tagger that identifies
 * a W with two subjets.  Dipolarity is described in arXiv:1102.1012, by
 * Hook, Jankowiak, and Wacker, and implemented in Dipolarity.hh, provided
 * by Martin Jankowiak.
 *
 * In this tagger-plus-dipolarity tool, the particles entering the dipolarity
 * sum are taken to be all consituents of the *original* (not filtered) jet
 * that are within DeltaR_{j1,j2}/2 of either j1 or j2 (the W subjets), and
 * *not* within the smallest cone that encloses the b subjet -- ie, the
 * maximum distance DeltaR_{b,k} for any constituent k in the b subjet.
 */

#ifndef _TOPTAGGERDIPOLARITYTOOL_HH_
#define _TOPTAGGERDIPOLARITYTOOL_HH_

#include "TransformerTool.hh"
#include "fastjet/tools/TopTaggerBase.hh"

namespace SpartyJet {
namespace FastJet {

class TopTaggerDipolarityTool : public TransformerTool {
public:
  TopTaggerDipolarityTool(fastjet::TopTaggerBase* tagger, std::string name="TopTaggerDipolarity")
    : TransformerTool(name, tagger) {
  }
  
  virtual void init(JetMomentMap* mmap=0) {
    TransformerTool::init(mmap);
    if (mmap) mmap->schedule_jet_moment<Double32_t>("dipolarity");
  }
  
  virtual void execute(Jet* j, JetMomentMap* map);
};



}
} // namespace SpartyJet

#endif
