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

#ifndef _JETANALYSIS_HH_
#define _JETANALYSIS_HH_
//*****************************************************************
/// \class JetAnalysis
/// 
/// A JetAnalysis holds a list of JetTools which together perform a desired
///  analysis.
/// In its execute(inputJets, outputJets) method, JetAnalysis copies inputJet
///  into outputJets then calls sequentially the execute() method of its tools
///  upon outputJets.  Thus outputJets finally contains the result of the
///  JetTool sequence.
/// TODO: is this part necessary? :
/// JetAnalysis also holds a JetMomentMap. This map is passed to the JetTools in
///  the init() method so that the JetTools can fill it when necessary.
//*****************************************************************

#include "JetMomentMap.hh"
#include "Jet.hh"
#include "JetTool.hh"
#include "CustomMessage.hh"

#include <list>
#include <string>

namespace SpartyJet { 

class JetTool;
class JetCollection;

typedef std::list<JetTool*> jettool_list_t;

class JetAnalysis {
public:

  JetAnalysis()                 : m_name("JetAnalysis"), m_measureTime(false), m_log("JetAnalysis") {}
  JetAnalysis(std::string name) : m_name(name), m_measureTime(false), m_log(name) {}
  JetAnalysis(JetTool* tool)    : m_name(tool->name()), m_measureTime(false), m_log(m_name) {add_tool(tool);}
  ~JetAnalysis() {m_mmap.clear();}

  /// Add a JetTool. Addition order matters. Must be called before init()
  void add_tool(JetTool* tool);

  /// Add a JetTool before any other 
  /// Addition order matters. Must be called before init()
  void add_tool_front(JetTool* tool);

  /// Initialize this alg and all its JetTools.
  void init();

  /// Run the jet tool sequence
  /// @param inputJets is copied into outputJets. 
  /// @param outputJets is passed to execute(JetCollection& outputJets)
  void execute(const Jet::jet_list_t& inputJets, JetCollection& outputJets) const;
  
  /// Run the jet tool sequence
  /// @param inputJets is coped into outputJets. 
  /// @param outputJets is passed to execute(JetCollection& outputJets)
  void execute(const JetCollection& inputJets, JetCollection& outputJets) const;
  
  /// Run the jet tool sequence
  /// @param outputJets is passed to the tools for modification
  void execute(JetCollection& outputJets) const;

  /// Finalize this alg and all its JetTools.
  void finalize();

  std::string name();
  void set_name(std::string name);
  
  JetMomentMap* get_jet_moment_map() {return &m_mmap;}

  /// Allows timing measurement. Must be called before init()
  void do_time_measure() {m_measureTime = true;}

  // removes all messages
  void make_silent() {m_log.silent_all();}

  // print tools
  void print_tools() const;

protected:
  
  JetMomentMap m_mmap;  ///< This map is only needed to hold structure of JetMomentMap to be computed
                        ///< the actual moments will be stored in the JetCollection. 
  std::string m_name;   ///< The analysis name
  mutable jettool_list_t m_toolList;  ///< The list of JetTools (TODO: make JetTool::execute() const)

  bool m_measureTime;
  void prepare_time(JetTool* jt);
  void record_time(JetTool* jt, float t, JetMomentMap* map) const;

  mutable Message m_log;
};

} // namespace SpartyJet

#endif
