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

#ifdef __CINT__

#pragma link off all global;
#pragma link off all classes;
#pragma link off all function;

#pragma link C++ class SpartyJet::ForkToolParent;
#pragma link C++ class SpartyJet::ForkToolChild;
#pragma link C++ class SpartyJet::JetSelectorTool;
#pragma link C++ class SpartyJet::JetPtSelectorTool;
#pragma link C++ class SpartyJet::JetEtaCentralSelectorTool;
#pragma link C++ class SpartyJet::JetEtaForwardSelectorTool;
#pragma link C++ class SpartyJet::JetMassSelectorTool;
#pragma link C++ class SpartyJet::JetInputPdgIdSelectorTool;
#pragma link C++ class SpartyJet::JetPtORESelectorTool;
#pragma link C++ class SpartyJet::JetMomentSelectorTool<float>;
#pragma link C++ class SpartyJet::JetMomentSelectorTool<int>;
#pragma link C++ class SpartyJet::EtaPhiMomentTool;
#pragma link C++ class SpartyJet::EConversionTool;
#pragma link C++ class SpartyJet::MomentArrayTestTool;
#pragma link C++ class SpartyJet::HullMomentTool;
#pragma link C++ class SpartyJet::JetAreaCorrectionTool;
#pragma link C++ class SpartyJet::CalorimeterSimTool;
#pragma link C++ class SpartyJet::HardProcessMatchTool;

#pragma link C++ class SpartyJet::TopDownPruneTool;
#pragma link C++ class SpartyJet::MassDropTool;
#pragma link C++ class SpartyJet::JHPruneTool;
#pragma link C++ class SpartyJet::SubjetCutTool;
#pragma link C++ class SpartyJet::SubjetMergeTool;
#pragma link C++ class SpartyJet::MinMassTool;
#pragma link C++ class SpartyJet::UnclusterTool;

#pragma link C++ class SpartyJet::JetMomentTool;
#pragma link C++ class SpartyJet::EventMomentTool;
// New JetMoments -- need to add JetMoment<T> for any Moment you want to implement!
// double
#pragma link C++ class SpartyJet::JetMoment<Double32_t>+;
#pragma link C++ class SpartyJet::HeavierSubjetMass+;
#pragma link C++ class SpartyJet::MassMoment+;
#pragma link C++ class SpartyJet::PtMoment+;
#pragma link C++ class SpartyJet::FinalDij+;
#pragma link C++ class SpartyJet::zMoment+;
#pragma link C++ class SpartyJet::DeltaRMoment+;

// vector<Double32_t>
#pragma link C++ class SpartyJet::JetMoment<vector<Double32_t> >+;
// Event moments
#pragma link C++ class SpartyJet::EventMoment<Double32_t>+; //etc.
#pragma link C++ class SpartyJet::EventMoment<vector<Double32_t> >+;
#pragma link C++ class SpartyJet::DijetMassMoment+;
#pragma link C++ class SpartyJet::TrijetMassMoment+;
#pragma link C++ class SpartyJet::TrijetPtMoment+;

#endif
