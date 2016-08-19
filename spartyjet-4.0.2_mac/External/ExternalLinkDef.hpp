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

#ifdef __CINT__

#pragma link off all global;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all namespaces;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ namespace fastjet;

// basics
#pragma link C++ class fastjet::JetDefinition;
#pragma link C++ class fastjet::JetDefinition::Plugin;
#pragma link C++ class fastjet::BasicRandom<int>;
#pragma link C++ class fastjet::BasicRandom<double>;
#pragma link C++ class fastjet::AreaDefinition;

// PseudoJet
#pragma link C++ class fastjet::PseudoJet;
#pragma link C++ class std::vector<fastjet::PseudoJet>;
#pragma link off function fastjet::PseudoJet::user_info_shared_ptr();
#pragma link off function fastjet::PseudoJet::set_structure_shared_ptr(const fastjet::SharedPtr<fastjet::PseudoJetStructureBase> &);
#pragma link off function fastjet::PseudoJet::structure_shared_ptr();

// ClusterSequence: turn off dictionary for two functions that use templated arguments
//  (this is a limitation of CINT, see ROOT bug 31591)
#pragma link C++ class fastjet::ClusterSequence;
#pragma link off function fastjet::ClusterSequence::transfer_from_sequence(const fastjet::ClusterSequence&, const fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*);
#pragma link off function fastjet::ClusterSequence::structure_shared_ptr();
// templated constructor is not available, so we provide a wrapper in FJWrapper.hh
#pragma link C++ function fastjet::make_ClusterSequence(const std::vector<fastjet::PseudoJet>&, const fastjet::JetDefinition&, const bool&);

// Selectors
#pragma link C++ class fastjet::Selector;
#pragma link off function fastjet::Selector::worker();

// structure
#pragma link C++ class fastjet::PseudoJetStructureBase;
#pragma link C++ class fastjet::WrappedStructure;
#pragma link off function fastjet::WrappedStructure::WrappedStructure(const fastjet::SharedPtr<fastjet::PseudoJetStructureBase>&);
#pragma link C++ class fastjet::TopTaggerBase;
#pragma link C++ class fastjet::TopTaggerBaseStructure;


// tools
#pragma link C++ class fastjet::FunctionOfPseudoJet<Double32_t>;
#pragma link C++ class fastjet::FunctionOfPseudoJet<float>;
#pragma link C++ class fastjet::FunctionOfPseudoJet<int>;
#pragma link C++ class fastjet::FunctionOfPseudoJet<bool>;
#pragma link C++ class fastjet::FunctionOfPseudoJet<std::vector<Double32_t> >;
#pragma link C++ class fastjet::FunctionOfPseudoJet<std::vector<float> >;
#pragma link C++ class fastjet::FunctionOfPseudoJet<std::vector<int> >;
#pragma link C++ class fastjet::FunctionOfPseudoJet<std::vector<bool> >;

#pragma link C++ class fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>;
#pragma link C++ class fastjet::Transformer;

#pragma link C++ class fastjet::Boost;
#pragma link C++ class fastjet::CASubJetTagger;
#pragma link C++ class fastjet::Filter;
#pragma link C++ class fastjet::GridMedianBackgroundEstimator;
#pragma link C++ class fastjet::JetMedianBackgroundEstimator;
#pragma link C++ class fastjet::MassDropTagger;
#pragma link C++ class fastjet::RestFrameNSubjettinessTagger;
#pragma link C++ class fastjet::RestFrameNSubjettinessTaggerStructure;
#pragma link C++ class fastjet::Subtractor;
#pragma link C++ class fastjet::JHTopTagger;
#pragma link C++ class fastjet::JHTopTaggerStructure;
#pragma link C++ class fastjet::Unboost;
#pragma link C++ class fastjet::Pruner;
#pragma link C++ class fastjet::PrunerStructure;



// FastJet Plugins
// Need to uncomment these lines and rebuild External to use plugins in
//  ROOT or PyROOT scripts.

// -shipped fastjet plugins
// --to use:
// ----if using fastjet shipped with spartyjet
// 		 simply uncomment the lines below
// ----if using external fastjet
// 		 recompile with ./configure --enable-allcxxplugins
// 		 and uncomment lines below
//#pragma link C++ class fastjet::SISConePlugin;
//#pragma link C++ class fastjet::SISConeBasePlugin;
//#pragma link C++ class fastjet::JadePlugin;
//#pragma link C++ class fastjet::CMSIterativeConePlugin;
//#pragma link C++ class fastjet::ATLASConePlugin;
//#pragma link C++ class fastjet::CDFMidPointPlugin;
//#pragma link C++ class fastjet::D0RunIIConePlugin;
//#pragma link C++ class fastjet::EECambridgePlugin;
//#pragma link C++ class fastjet::TrackJetPlugin;

#endif
