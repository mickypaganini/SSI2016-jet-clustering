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

#ifndef _JETTOOL_HH_
#define _JETTOOL_HH_

#include "Jet.hh"
#include "CustomMessage.hh"

#include <string>

//////////////////////////////////////////////////////////////////////////////
// JetTool is the base class from which all operations on JetCollections must
//  be performed.
// Concrete classes such as jet finder algo must be implemented in a derived
//  class.
// The user should override either:
//   execute(JetCollection&)
//   execute(Jet*)
// If the first is not overridden, the second is run on each jet in the
//  JetCollection.
namespace SpartyJet {

class JetMomentMap;
class JetCollection;

class JetTool {
public:
  JetTool() : m_name() {}
  virtual ~JetTool() {}
  JetTool(std::string name) : m_name(name) {m_log.set_name(name);}
  virtual void init(JetMomentMap* mmap=0) {}
  virtual void execute(JetCollection& inputJets);
  virtual void finalize() {}

  virtual void execute(Jet* jet) {}

  std::string name()           {return m_name;}
  void set_name(std::string n) {m_name = n;}

  virtual bool   contains_area() {return false;}
  virtual double getConeRadius() {return 0.0;}

protected:
  std::string m_name;
  Message m_log;
  JetMomentMap* m_map; // stored so that tools acting on jets can set moments
};

}  // namespace SpartyJet
#endif
