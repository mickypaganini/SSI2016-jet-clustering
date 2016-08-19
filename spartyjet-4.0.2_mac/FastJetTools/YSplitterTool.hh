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

#ifndef _YSPLITTERTOOL_HH_
#define _YSPLITTERTOOL_HH_

#include "FastJetFinder.hh"
#include "JetCore/JetTool.hh"
#include <string>

namespace SpartyJet { 
namespace FastJet {

class YSplitterTool : public  JetTool {
public :

  YSplitterTool(std::string name="YSplitter") : JetTool(name) {};
  YSplitterTool(float R, fastjet::JetAlgorithm alg, int ny, int njet=-1, std::string name="YSplitter" );
  YSplitterTool(fastjet::JetDefinition *jet_def, int ny, int njet=-1, std::string name="YSplitter" );

  // Maximum number of y-values
  static const int MAX=4;

  virtual void init(JetMomentMap *mmap=0);
  virtual void execute(JetCollection &inputJets);
  virtual void finalize() {}

  void configure(int ny, int njet=-1);
  void set_n_values(int x)  {m_nvalues = x;}
  void set_n_jets(int n)    {m_njets = n;}

private:

  // Jet Description used for clustering of constituents
  fastjet::JetDefinition* m_jet_def;

  // Number of yvalues per jets
  int m_nvalues;

  // Number of jets for which Yvalues are computed (by default :-1 == all)
  int m_njets;
};

}  // namespace FastJet
}  // namespace SpartyJet
#endif
