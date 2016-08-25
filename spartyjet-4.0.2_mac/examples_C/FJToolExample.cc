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
 * This is an example C++ program to drive SpartyJet.  Can be used:
 *  $> ./FJToolExample.exe
 *
 * NB: Python scripts are now the preferred way to use SpartyJet!  See
 * examples_py/FJToolExample.py for a better-maintained set of FastJet tool
 * examples.
 */

#include "SJconfig.h"

#include "JetCore/JetBuilder.hh"
#include "JetCore/JetAnalysis.hh"
#include "IO/HepMCInput.hh"
#include "FastJetTools/FastJetFinder.hh"
#include "FastJetTools/FastJetTool.hh"
#include "JetTools/JetForkTool.hh"
#include "JetTools/JetSelectorTool.hh"
#include "JetTools/JetMomentTool.hh"
#include "JetTools/TopDownPruneTool.hh"
#include "JetTools/HardProcessMatchTool.hh"
#include "FastJetTools/PseudoJetMoment.hh"
#include "ExternalTools/TransformerTool.hh"
#include "ExternalTools/AngularCorrelationTool.hh"
#include "ExternalTools/BoostVariables.hh"

#include "fastjet/Selector.hh"
#include "fastjet/tools/Filter.hh"
#include "fastjet/tools/MassDropTagger.hh"
#include "fastjet/tools/Pruner.hh"

#include <string>
using namespace std;

using namespace fastjet;
using namespace SpartyJet;
using namespace SpartyJet::FastJet;

/// *** The following small class is copied from fastjet/examples/11-filter.cc
/// *** (c) the FastJet authors.

// a function returning
//   min(Rmax, deltaR_factor * deltaR(j1,j2))
// where j1 and j2 are the 2 subjets of j
// if the jet does not have 2 exactly pieces, Rmax is used.
class DynamicRfilt : public FunctionOfPseudoJet<double>{
public:
  // default ctor 
  DynamicRfilt(double Rmax, double deltaR_factor) : _Rmax(Rmax), _deltaR_factor(deltaR_factor){}

  // action of the function
  double result(const PseudoJet &j) const{
    if (! j.has_pieces()) return _Rmax;

    vector<PseudoJet> pieces = j.pieces();
    if (! pieces.size()==2) return _Rmax;

    double deltaR = pieces[0].delta_R(pieces[1]);
    return min(_Rmax, _deltaR_factor * deltaR);
  }

private:
  double _Rmax, _deltaR_factor;
};


int main() {

  // Create a builder object
  JetBuilder builder(DEBUG);
  //builder.silent_mode(); // turn off debugging

  InputMaker* input = new HepMCInput(string(SPARTYJET_DIR)+"/data/Zprime_ttbar.hepmc");
  builder.configure_input(input);

  builder.add_default_analysis(new FastJetFinder("AntiKt10", antikt_algorithm, 1.5, false));
  // fork for AntiKt10
  ForkToolParent* parent = new ForkToolParent("AntiKt10Parent");
  builder.add_jetTool(parent, "AntiKt10");

  builder.add_default_analysis(new FastJetFinder("CA10Filtered", cambridge_algorithm, 1.0, false));
  // fork for CA10
  ForkToolParent* CAparent = new ForkToolParent("CA10Parent");
  builder.add_jetTool(CAparent, "CA10Filtered");
  
  // forked analysis; anti-kT reclustered with kT
  builder.add_default_analysis(new ForkToolChild(parent, "Kt10"));
  builder.add_jetTool(new FastJetRecluster("Kt10Recluster", kt_algorithm, 1.0), "Kt10");
  
  // pruning
  builder.add_default_analysis(new ForkToolChild(parent, "Pruned"));
  builder.add_jetTool(new TransformerTool("Pruner", new Pruner(cambridge_aachen_algorithm, 0.1, 0.5)), "Pruned");

  builder.add_jetTool_input(new JetPtSelectorTool(0.5*input->getGeV()));
  builder.add_jetTool_input(new JetEtaCentralSelectorTool(-1.5,1.5));


  // a FunctionOfPseudoJet-based moment: "minMass", which finds the minimum-mass pairing of three subjets
  //  Note that PseudoJetMomentTools adopt the function passed to them and
  //  delete on destruction -- don't pass a pointer to a local variable!
  PseudoJetMomentTool<Double32_t> minMassTool(new MinMassFunction(), "massMoment");
  builder.add_jetTool(&minMassTool, "Kt10");
    
  // ATLAS top-tagging "zcut" variables
  PseudoJetMomentTool<double> zcutTool(new zCutFunction(1), "zCut1");
  builder.add_jetTool(&zcutTool, "Kt10");
  
  // Angular correlations
  AngularCorrelationTool angleTool(4.0, false, 0.06);
  builder.add_jetTool(&angleTool, "AntiKt10");
  // Require three peaks
  builder.add_jetTool(new JetMomentSelectorTool<int>("nPeaks", 3, 3), "AntiKt10");

  builder.add_analysis(new JetAnalysis(new ForkToolChild(CAparent, "CA10MDF")));
  MassDropTagger massDrop(0.667, 0.09);
  builder.add_jetTool(new TransformerTool("MassDropTool", &massDrop), "CA10MDF");
  DynamicRfilt Rfilt(0.3, 0.5);
  Filter dynamicFilter(&Rfilt, SelectorNHardest(3));
  builder.add_jetTool(new TransformerTool("DynamicFilterTool", &dynamicFilter), "CA10MDF");
  

  Filter filt(0.2, SelectorNHardest(4));
  builder.add_jetTool(new TransformerTool("FilterTool", &filt), "CA10Filtered");


  builder.add_analysis(new JetAnalysis(new ForkToolChild(CAparent, "CA10Trimmed")));
  Filter trim(0.2, SelectorPtFractionMin(0.05));
  builder.add_jetTool(new TransformerTool("TrimTool", &trim), "CA10Trimmed");

  builder.add_jetTool(new JetPtSelectorTool(10*input->getGeV()));

  // see if jets match hard process partons
  builder.add_jetTool(new HardProcessMatchTool());

  builder.add_text_output(string(SPARTYJET_DIR)+"/data/output/FJTool.dat");
  builder.configure_output("SpartyJet_Tree",string(SPARTYJET_DIR)+"/data/output/FJTool.root");

  builder.process_events(10);

  return 0;
}
