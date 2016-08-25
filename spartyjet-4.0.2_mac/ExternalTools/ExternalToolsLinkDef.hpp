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
#pragma link off all function;
#pragma link off all namespaces;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ class fastjet::MinMassFunction;
#pragma link C++ class fastjet::zCellFunction;
#pragma link C++ class fastjet::zCutFunction;

#pragma link C++ class SpartyJet::FastJet::AngularCorrelationTool;

#pragma link C++ class SpartyJet::FastJet::TransformerTool;

#pragma link C++ class fastjet::CMSTopTagger;
#pragma link C++ class fastjet::HEPTopTagger;
#pragma link C++ class fastjet::WTagger;

#pragma link C++ class SpartyJet::FastJet::TopTaggerDipolarityTool;
#pragma link C++ class SpartyJet::RadialSmearingTool;

// njettiness
#pragma link C++ class fastjet::NjettinessPlugin;
#pragma link C++ class fastjet::Nsubjettiness;
#pragma link C++ class Njettiness;
#pragma link C++ enum Njettiness::AxesMode;

// qjets
#pragma link C++ class QjetsPlugin;
#pragma link C++ class SpartyJet::FastJet::QjetsTool;


#endif
