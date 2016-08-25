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

#ifndef _JET_STRUCTURE_HH_
#define _JET_STRUCTURE_HH_

#include "JetCore/CustomMessage.hh"
#include "fastjet/PseudoJetStructureBase.hh"

///////////////////////////////////////////////////////////////////////////////
/// A jet structure class, implementing FastJet's PseudoJetStructureBase
///  interface using SpartyJet internals.  The goal is a quick and simple
///  ability to use FastJet-based substructure tools without changing SpartyJet
///  internals all at once.  These internals may change, but hopefully this
///  interface will be stable.
///
/// I've copied all of the functions from PseudoJetStructureBase; those that are
///  not implemented are commented out.  Some will simply return false; others
///  will throw an Error.  Which is which is documented below.
///
/// Comments describing functionality are taken from PseudoJetStructureBase.hh,
///  (c) the FastJet authors.
///////////////////////////////////////////////////////////////////////////////


namespace SpartyJet {

class Jet;
class JetCollection;

class JetStructure : public fastjet::PseudoJetStructureBase {
public:

  JetStructure(const Jet* j, const JetCollection* jc) : m_jet(j), m_jetCollection(jc), m_log("JetStructure") {}
  virtual ~JetStructure() {}

  virtual std::string description() const {return "SpartJet structure for a PseudoJet";}

  /// default false is OK
  //virtual bool has_associated_cluster_sequence() const {return false;}

  /// default NULL is OK
  //virtual const fastjet::ClusterSequence* associated_cluster_sequence() const;
  
  /// default false OK
  //virtual bool has_valid_cluster_sequence() const {return false;}

  /// default: throws an Error
  //virtual const fastjet::ClusterSequence* validated_cs() const;

  /// default: throws an Error
  //virtual const fastjet::ClusterSequenceAreaBase* validated_csab() const;


  /// check if it has been recombined with another fastjet::PseudoJet in which
  /// case, return its partner through the argument. Otherwise,
  /// 'partner' is set to 0.
  virtual bool has_partner(const fastjet::PseudoJet& reference, fastjet::PseudoJet& partner) const;

  /// check if it has been recombined with another fastjet::PseudoJet in which
  /// case, return its child through the argument. Otherwise, 'child'
  /// is set to 0.
  virtual bool has_child(const fastjet::PseudoJet& reference, fastjet::PseudoJet& child) const;

  /// check if it is the product of a recombination, in which case
  /// return the 2 parents through the 'parent1' and 'parent2'
  /// arguments. Otherwise, set these to 0.
  virtual bool has_parents(const fastjet::PseudoJet& reference, fastjet::PseudoJet& parent1, fastjet::PseudoJet& parent2) const;

/* TODO
  /// check if the reference fastjet::PseudoJet is contained the second one
  /// passed as argument.
  virtual bool object_in_jet(const fastjet::PseudoJet& reference, const fastjet::PseudoJet& jet) const;
*/

  /// return true if the structure supports constituents. (Can just be one.) 
  virtual bool has_constituents() const {return true;}

  /// retrieve the constituents. 
  virtual std::vector<fastjet::PseudoJet> constituents(const fastjet::PseudoJet& reference) const;

/* TODO
  /// return true if the structure supports exclusive_subjets. 
  virtual bool has_exclusive_subjets() const {return false;}

  /// return a vector of all subjets of the current jet (in the sense
  /// of the exclusive algorithm) that would be obtained when running
  /// the algorithm with the given dcut. 
  ///
  /// Time taken is O(m ln m), where m is the number of subjets that
  /// are found. If m gets to be of order of the total number of
  /// constituents in the jet, this could be substantially slower than
  /// just getting that list of constituents.
  ///
  /// By default, throws an Error
  virtual std::vector<fastjet::PseudoJet> exclusive_subjets(const fastjet::PseudoJet& reference, const double& dcut) const;

  /// return the size of exclusive_subjets(...); still n ln n with same
  /// coefficient, but marginally more efficient than manually taking
  /// exclusive_subjets.size()
  ///
  /// By default, throws an Error
  virtual int n_exclusive_subjets(const fastjet::PseudoJet& reference, const double& dcut) const;

  /// return the list of subjets obtained by unclustering the supplied
  /// jet down to nsub subjets (or all constituents if there are fewer
  /// than nsub).
  ///
  /// By default, throws an Error
  virtual std::vector<fastjet::PseudoJet> exclusive_subjets_up_to(const fastjet::PseudoJet& reference, int nsub) const;

  /// return the dij that was present in the merging nsub+1 -> nsub 
  /// subjets inside this jet.
  ///
  /// By default, throws an Error
  virtual double exclusive_subdmerge(const fastjet::PseudoJet& reference, int nsub) const;

  /// return the maximum dij that occurred in the whole event at the
  /// stage that the nsub+1 -> nsub merge of subjets occurred inside 
  /// this jet.
  ///
  /// By default, throws an Error
  virtual double exclusive_subdmerge_max(const fastjet::PseudoJet& reference, int nsub) const;
*/

  virtual bool has_pieces(const fastjet::PseudoJet& reference) const;

  /// retrieve the pieces building the jet. 
  virtual std::vector<fastjet::PseudoJet> pieces(const fastjet::PseudoJet& reference) const;


/* TODO
  /// check if it has a defined area
  ///
  /// false by default
  virtual bool has_area() const {return false;}

  /// return the jet (scalar) area.
  ///
  /// By default, throws an Error
  virtual double area(const fastjet::PseudoJet& reference) const;

  /// return the error (uncertainty) associated with the determination
  /// of the area of this jet.
  ///
  /// By default, throws an Error
  virtual double area_error(const fastjet::PseudoJet& reference) const;

  /// return the jet 4-vector area.
  ///
  /// By default, throws an Error
  virtual fastjet::PseudoJet area_4vector(const fastjet::PseudoJet& reference) const;

  /// true if this jet is made exclusively of ghosts.
  ///
  /// By default, throws an Error
  virtual bool is_pure_ghost(const fastjet::PseudoJet& reference) const;
*/

private:
  const Jet* m_jet;
  const JetCollection* m_jetCollection;
  mutable Message m_log;
};



}  // namespace SpartyJet
#endif


