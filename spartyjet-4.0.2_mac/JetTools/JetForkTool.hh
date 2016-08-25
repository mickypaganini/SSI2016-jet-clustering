// Copyright 2010, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
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

#ifndef _JETFORKTOOL_HH_
#define _JETFORKTOOL_HH_

#include "JetCore/JetTool.hh"
#include "JetCore/JetCollection.hh"

// "Forking" JetTools are implemented via two classes:
//
// ForkToolParent
// ForkToolChild
//
// An FTP copies its input JetCollection to all its children;
// FTC's are children of an FTP and on execute, copy over their received JC.

namespace SpartyJet {

class ForkToolParent : public JetTool {
public:
  ForkToolParent(std::string name="ForkToolParent") : JetTool(name) {}
  virtual ~ForkToolParent() {}

  virtual void execute(JetCollection& jc) {
    jet_coll.clear_and_delete();
    jet_coll.deep_copy(jc);
  }
  virtual const JetCollection* get_jet_coll() {return &jet_coll;}

private:
  JetCollection jet_coll;
};



class ForkToolChild : public JetTool {
public:
  ForkToolChild(ForkToolParent* p, std::string name="ForkToolChild") : JetTool(name), parent(p) {}
  virtual ~ForkToolChild() {}


  virtual void execute(JetCollection& jc) {
    jc.clear_and_delete();
    jc.deep_copy(*(parent->get_jet_coll()));
  }

private:
  ForkToolParent *parent;


};

} // namespace SpartyJet
#endif // _JETFORKTOOL_HH_
