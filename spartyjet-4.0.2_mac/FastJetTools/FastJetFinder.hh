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

#ifndef _FASTJETFINDER_HH_
#define _FASTJETFINDER_HH_

#include "JetCore/JetTool.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/AreaDefinition.hh"
#include "fastjet/PseudoJet.hh"
#include <string>

namespace fastjet {
class JetDefinition;
}

namespace SpartyJet {

class JetMomentMap;
namespace FastJet {

/// A simple wrapper for FastJet jet finding.  The user can specify either an
///  algorithm from the FastJet::JetAlgorithm enum or pass their own
///  JetDefinition (note that this allows plugin use as well).
class FastJetFinder : public JetTool {
public :
  FastJetFinder(std::string name="FastJetFinder", fastjet::JetAlgorithm alg=fastjet::kt_algorithm, double R=0.4, bool area=false);
  FastJetFinder(fastjet::JetDefinition* jet_def, std::string name="FastJetFinder", bool area=false);
  virtual ~FastJetFinder();
  
  void set_defaults(); // set default parameters
  void set_algorithm(fastjet::JetAlgorithm alg, double R = 0.4);
  void set_area(bool x)            {m_area = x;}
  void set_areaChoice(fastjet::AreaType x)  {m_areaChoice = x;}
  void set_inclusive(bool x)       {m_inclusive = x;} // jets are found either inclusively or exclusively; inclusive is default
  void set_Rparam(double x)        {set_algorithm(m_jet_def->jet_algorithm(),x);}
  void set_ptmin(double x)         {m_ptmin = x; m_inclusive = true;} // default = 5.0 GeV
  
  // set one or the other for exclusive jets -- default is to use dcut = 25.0
  void set_dcut(double x)          {m_dcut = x;  m_inclusive = false;}
  void set_njets(int n)            {m_njets = n; m_inclusive = false;}

  void configure_area(double,int,double,double,double,double);
  void set_ghost_etamax(double x)  {m_ghost_etamax = x;}
  void set_repeat(int x)           {m_repeat = x;}
  void set_ghost_area(double x)    {m_ghost_area = x;}
  void set_grid_scatter(double x)  {m_grid_scatter = x;}
  void set_kt_scatter(double x)    {m_kt_scatter = x;}
  void set_mean_ghost_kt(double x) {m_mean_ghost_kt = x;}

  virtual bool contains_area()     {return m_area;}
  double getConeRadius()           {return m_jet_def->R();}

  virtual void init(JetMomentMap* mmap=0);
  virtual void execute(JetCollection& inputJets);
  virtual void finalize() {};


protected:
  bool m_area;
  fastjet::AreaType m_areaChoice;
  bool m_inclusive;

  double m_ptmin;
  double m_dcut;
  int m_njets;

  // area parameters
  double m_ghost_etamax;
  int    m_repeat;
  double m_ghost_area;
  double m_grid_scatter;
  double m_kt_scatter;
  double m_mean_ghost_kt;

  bool m_use_ext_jet_def; // if true, we don't own the JetDefinition, and shouldn't mess with it

  fastjet::JetDefinition* m_jet_def;
};


/// A simple specialization of FastJetFinder which reclusters jets already found.
/// For each jet in inputJets, the specified algorithm is run on its constituents,
///  and all resulting jets are stored in the output.
class FastJetRecluster : public FastJetFinder {
public:
  FastJetRecluster(std::string name = "FastJetRecluster", fastjet::JetAlgorithm alg=fastjet::kt_algorithm, double R=0.4, bool area=false)
    : FastJetFinder(name, alg, R, area) {}
  FastJetRecluster(fastjet::JetDefinition* jet_def, std::string name="FastJetRecluster", bool area=false)
    : FastJetFinder(jet_def, name, area) {}
  ~FastJetRecluster() {}

  void execute(JetCollection& inputJets);
};


}  // namespace SpartyJet::FastJet
}  // namespace SpartyJet
#endif
