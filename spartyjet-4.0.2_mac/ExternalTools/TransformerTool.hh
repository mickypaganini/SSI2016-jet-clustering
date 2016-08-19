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

#ifndef _TRANSFORMERTOOL_HH_
#define _TRANSFORMERTOOL_HH_

#include "JetCore/JetTool.hh"
#include "JetCore/JetMomentMap.hh"
#include "TransformerMomentHandler.hh"

#include "fastjet/tools/Transformer.hh"
#include <vector>

namespace SpartyJet {
namespace FastJet {


/// Wraps a FastJet Transformer, including storing moments.  Adopts the transformer
class TransformerTool : public JetTool {
public:
  TransformerTool(std::string name, fastjet::Transformer* t) : JetTool(name), m_transformer(t) {
    m_moment_handler = getMomentHandler(t);
  }
  virtual ~TransformerTool() {delete m_transformer; delete m_moment_handler;}
  
  /// initializes any moments
  virtual void init(JetMomentMap* map) {m_moment_handler->init(map);}
  
  /// performs loop over jets
  virtual void execute(JetCollection& jc);

  /// executes the transformer on each jet, storing a 'zero jet' if the transformer fails
  virtual void execute(Jet* j, JetMomentMap* map);

protected:
  fastjet::Transformer* m_transformer;
  
  // this knows how to store JetMoments for a given Transformer 
  TransformerMomentHandler* m_moment_handler;
};


}
} // namespace SpartyJet

#endif
