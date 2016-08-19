// Copyright (c) 2012 Christopher K. Vermilion
//
//----------------------------------------------------------------------
//  This file is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  This file is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  The GNU General Public License is available at
//  http://www.gnu.org/licenses/gpl.html or you can write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------


/*
 * Wraps the W-tagging tool from Cui, Han, and Schwartz.
 * See External/wtag-1.00/README.  The various cuts can be fiddled with by
 * editing the parameter files in wtag-1.00/data.  The ability to generate new
 * parameters is not available from within SpartyJet (yet).
 */

#ifndef _WTAGGER_HH_
#define _WTAGGER_HH_

#include "SJconfig.h"
#include "External/wtag-1.00/include/wtag.h"

#include "fastjet/tools/Transformer.hh"

#include <string>
#include <sstream>

FASTJET_BEGIN_NAMESPACE

class WTagger : public Transformer {
public:
  WTagger(double signal_eff=-1)
    : _signal_eff(signal_eff), _jet_pars() {
    std::string dataDir = std::string(SPARTYJET_DIR)+"/External/wtag-1.00/data/";
    std::string trimming_file  = dataDir+"trimming_parameters.dat";
    std::string pruning_file   = dataDir+"pruning_parameters.dat";
    std::string filtering_file = dataDir+"filtering_parameters.dat";
    std::string bdtcut_file    = dataDir+"BDTcuts.dat";
    std::string bdteff_file    = dataDir+"effs_bdtv.dat";
    std::string bdtweight_dir  = dataDir+"weights/";
    // const_cast wouldn't be nec. if wtag code took "const char*" arguments, but I don't want to change their code
    _jet_pars.set_trimming_par_file (const_cast<char*>(trimming_file.c_str()));
    _jet_pars.set_pruning_par_file  (const_cast<char*>(pruning_file.c_str()));
    _jet_pars.set_filtering_par_file(const_cast<char*>(filtering_file.c_str()));
    _jet_pars.set_bdtcut_filename   (const_cast<char*>(bdtcut_file.c_str()));
    _jet_pars.set_bdteff_filename   (const_cast<char*>(bdteff_file.c_str()));
    _jet_pars.set_bdtweight_dir     (const_cast<char*>(bdtweight_dir.c_str()));
    
    _jet_pars.read_jetpars();
  }
  ~WTagger() {}
  
  
  /// returns a textual description of the tagger
  virtual std::string description() const;

  /// runs the tagger on the given jet and
  /// returns the tagged PseudoJet if successful, or a PseudoJet==0 otherwise
  /// (standard access is through operator()).
  ///  \param jet   the PseudoJet to tag
  virtual PseudoJet result(const PseudoJet & jet) const {

    if (jet.has_valid_cluster_sequence()) {
      ClusterSequence* cs = const_cast<ClusterSequence*>(jet.validated_cs()); // to avoid changing W-tagging code
      PseudoJet& temp_jet = const_cast<PseudoJet&>(jet);                      // ditto
      bool tagged = Wtag::wtag(*cs, temp_jet, _signal_eff, &_jet_pars);
      
      if (tagged) return jet;
    }
    return jet * 0.;
  }

  typedef PseudoJetStructureBase StructureType;

protected:
  double _signal_eff; // to pass to wtag()
  mutable Wtag::jet_pars _jet_pars;
};

inline std::string WTagger::description() const {
  std::stringstream o("W tagger with signal efficiency");
  o << _signal_eff;
  return o.str();
}


FASTJET_END_NAMESPACE


#endif
