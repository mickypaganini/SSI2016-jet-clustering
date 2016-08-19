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

#ifndef _JET_HH_
#define _JET_HH_

#include "fastjet/PseudoJet.hh"

#include <cstdio>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

namespace SpartyJet {

///////////////////////////////////////////////////////////////////////////////
/// Basic jet class, including all the standard 4-vector manipulations.
/// Holds a HistoryElement for substructure (merging history): see JetHistory.hh
/// Constituents can be accessed through the history structure, but to keep the
///   iterator interface the same (first/lastConstituent()), for now a
///   constituent vector<Jet*> is created and stored when these functions are
///   called -- maybe later these iterators can be implemented in a smarter way.
///////////////////////////////////////////////////////////////////////////////

template<class T> class HistoryNode;
template<class T> class HistoryProvider;
class HistoryElement;
class JetCollection;

class Jet : public fastjet::PseudoJet {
public:
  
  typedef std::vector<Jet*> constit_vect_t;
  typedef std::vector<Jet*> jet_list_t;
  typedef std::vector<Jet*>::const_iterator const_iterator;
  
  Jet(double p1, double p2, double p3, double p0, int index)
    : fastjet::PseudoJet(p1, p2, p3, p0) {set_defaults(); m_is_input = (index > -1); m_index = index;}
  Jet(const fastjet::PseudoJet& p) : fastjet::PseudoJet(p) {set_defaults();}
  
  const Jet& operator=(const Jet& j);
  const fastjet::PseudoJet& operator=(const fastjet::PseudoJet& pj)
    {if (&pj != this) PseudoJet::operator=(pj); return *this;}

  /// copy constructors also copy history
  Jet(const Jet& j);
  Jet(const Jet* j);
  /// construct a jet with given parents
  Jet(std::vector<Jet*>& parents);
  
  virtual ~Jet() {} ///< Note that Jet DOES NOT delete its HistoryElement!!
  
  void set_defaults();

  // ****** 4-vector behavior *******************************
  //
  /// Inherited from PseudoJet one has
  ///  px(), py(), pz(), e(), E()
  ///  reset(px, py, pz, E)
  /// Spherical coordinates :
  ///  phi()  (0-2pi) -- for (-pi,pi) use phi_std()
  /// Masses :
  ///  m() m2()
  /// Rapidity :
  ///  rapidity(), rap()
  ///  pseudorapidity(), eta()
  /// Transverse quantities :
  ///  Et(), Et2(), perp(), perp2()
  /// ... plus many other functions... see PseudoJet.hh
  double p()        const {return std::sqrt(modp2());}
  double pt()       const {return perp();}
  double pt2()      const {return perp2();}
  double Perp2()    const {return perp2();}
  double mass()     const {return m();}
  double et()       const {return Et();}

  void setE(double e) {reset(px(), py(), pz(), e);}

  /// Some methods to mimic important TLorentzVector behavior
  void SetPxPyPzE(double px, double py, double pz, double e) { reset(px, py, pz, e); }
  void SetPtEtaPhiE(double pt, double eta, double phi, double e) {
    pt = std::fabs(pt);
    reset(pt*std::cos(phi), pt*std::sin(phi), pt*std::sinh(eta), e);
  }
  void SetPtEtaPhiM(double pt, double eta, double phi, double m) {
    double p = pt*std::cosh(eta);
    reset(pt*std::cos(phi), pt*std::sin(phi), pt*std::sinh(eta), std::sqrt(p*p+m*m));
  }
  bool operator==(const Jet &v) const {
   return (px() == v.px()) && (py() == v.py()) && (pz() == v.pz()) && (e() == v.e());
  }

  // scales p so that the four-momentum is massless
  void set_massless() {
   double newPT = pt() * e() / std::sqrt(e()*e() - m2());
   SetPtEtaPhiM(newPT, eta(), phi(), 0.0);
  }
  
  // ************************************************************
   
  
  /// @deprecated Access jet constituents -- better to use PseudoJet::constituents
  int get_constituent_num() const;
  constit_vect_t::iterator first_constituent();
  constit_vect_t::iterator last_constituent();
  constit_vect_t::const_iterator first_constituent() const;
  constit_vect_t::const_iterator last_constituent() const;

  /// Does this jet correspond to an input particle?
  bool is_input() const {return m_is_input;}
  /// return position in initial collection (if this represents an input jet)
  int input_index() const {return m_index;}
  void set_index(int i) {m_index = i; m_is_input = true;}
  
  /// access to corresponding HistoryElement
  HistoryElement* history() {return m_history;}
  const HistoryElement* history() const {return m_history;}
  /// Clear out old history, replace with fresh one
  void clear_history();
  /// Set history.  Careful -- does not delete old history, to avoid circular Jet-HistoryElement destructors!
  void set_history(HistoryElement *he) {m_history = he;}
  
protected :
  bool m_is_input; ///< This jet corresponds to an input particle, with index m_index
  int m_index;     ///< position in a jet list (used for constituents positions)
  HistoryElement* m_history; ///< corresponding history element
  mutable constit_vect_t m_constituents; ///< list of constituent Jet*'s
  void build_constit_vect() const; ///< builds m_constituents for access

  /// Should only be used by HistoryElement, since this constructor does not
  ///  create a HE for this jet -- it should be used when the HE already exists.
  Jet() : fastjet::PseudoJet(0,0,0,0), m_is_input(false), m_index(0), m_history(0) {}
public:
  template<class T> friend class HistoryProvider;
  template<class T> friend class HistoryNode;
   
  void print() const {
    printf("#%4i p(%10.3e, %10.3e, %10.3e, %10.3e), pt(%10.3e), eta(%10.3e), phi(%10.3e), m(%10.3e)\n",
          input_index(), px(), py(), pz(), e(), perp(), eta(), phi(), m());
  }
};


// A PseudoJet stores a UserInfoBase pointer to associate arbitrary extra info.
// We use it to store a pointer back to the full Jet object, so that if a
// Jet (deriving from a PseudoJet) is copied into a PseudoJet, the pointer is
// copied and we can still access the full Jet.
//
// To use your own UserInfo in SpartyJet, you should derive from this class.
//
// The members are mutable and the functions const because FJ only provides
// const reference access to the user info.

class SpartyJetUserInfo : public fastjet::PseudoJet::UserInfoBase {
public:
  SpartyJetUserInfo(Jet* jet) : m_ptr(jet), m_ownjet(false) {}
  virtual ~SpartyJetUserInfo();
  
  Jet* jet() const {return m_ptr;}
  
  // Eventually this may always own the Jet, but for now only garbage collect on demand
  void should_delete() const {m_ownjet = true;}

private:
  mutable Jet* m_ptr;
  mutable bool m_ownjet;
};


// using functors is supposed to be faster... (??)
class JetSorter_Et {
public:
  bool operator()(Jet* j1, Jet* j2) {
    // deal with numerical uncertainty : 
    if (std::fabs( j1->et() - j2->et()) < 0.001) return 0;
    else return j1->et() > j2->et();
    //return (j1->et() > j2->et());    
  }
};

class JetSorter_Pt {
public:
  bool operator()(Jet* j1, Jet* j2) {
    return (j1->pt() > j2->pt());
  }
};

class JetSorter_Eta {
public:
  bool operator()(Jet* j1, Jet* j2) {
    return (j1->eta() > j2->eta());
  }
};

class JetSorter_E {
public:
  bool operator()(Jet* j1, Jet* j2) {
    return (j1->e() > j2->e());
  }
};


template<class T>
inline void sort_jet_list(Jet::jet_list_t& list) {
  std::sort(list.begin(), list.end(), T());
}
inline void sort_list_et(Jet::jet_list_t& list) {
  std::sort(list.begin(), list.end(), JetSorter_Et());
}
inline void sort_list_pt(Jet::jet_list_t& list) {
  std::sort(list.begin(), list.end(), JetSorter_Pt());
}

}  // namespace SpartyJet
#endif


