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

#ifndef _JETMOMENT_TOOL_HH_
#define _JETMOMENT_TOOL_HH_

/// A JetMomentTool takes a JetMoment object in its constructor,
///   and calculates this function for all jets when it is executed.
/// Some example JetMoments are given below.

#include "JetCore/JetTool.hh"
#include "JetCore/JetMomentMap.hh"
#include "JetCore/JetMoment.hh"
#include "JetCore/JetCollection.hh"
#include "JetCore/JetHistory.hh"

#include <vector>
#include <algorithm>

namespace SpartyJet {

class JetMomentTool : public JetTool {
public:
  JetMomentTool(std::string name, Moment *m) : JetTool(name), m_moment(m) {}
  virtual void init(JetMomentMap *mmap) {if(mmap != NULL) mmap->schedule_jet_moment(m_moment);}
  virtual void execute(JetCollection &inputJets);
  virtual ~JetMomentTool() {}

protected:
  Moment *m_moment;
};

/// Like JetMomentTool, but calculates for the whole event
class EventMomentTool : public JetTool {
public:
  EventMomentTool(std::string name, Moment *m) : JetTool(name), m_moment(m) {}
  virtual void init(JetMomentMap *mmap) {if(mmap != NULL) mmap->schedule_event_moment(m_moment);}
  virtual void execute(JetCollection &inputJets);
  virtual ~EventMomentTool() {}

protected:
  Moment *m_moment;
};


/// Here is an example JetMoment
class HeavierSubjetMass : public JetMoment<Double32_t> {
public:
  HeavierSubjetMass(std::string name = "", bool sc = false) : JetMoment<Double32_t>(name), scale(sc) {}
  virtual void CalculateMoment(Jet* jet, JetCollection &jetColl) {
    std::vector<Jet*> parents = jetColl.get_parents(jet);
    if (parents.size() == 0) {m_value = 0.0; return;}
    
    std::vector<Jet*>::iterator it, itE;
    it = parents.begin();
    itE = parents.end();
    m_value = 0.;
    for (; it != itE; ++it) {
      if (scale && jet->m() > 0.0)
        m_value = std::max((*it)->m() / jet->m(), m_value);
      else
        m_value = std::max((*it)->m(), m_value);
    }
  }
protected:
  bool scale;
};

/// Another example JetMoment
class FinalDij : public JetMoment<Double32_t> {
public:
  FinalDij(std::string name = "") : JetMoment<Double32_t>(name) {}
  virtual void CalculateMoment(Jet *jet, JetCollection &jetColl) {
    m_value = jetColl.get_dij(jet);
  }
};

/// These two are useful if you're not storing the full jet 4-momentum
class MassMoment : public JetMoment<Double32_t> {
public:
  MassMoment(std::string name = "M") : JetMoment<Double32_t>(name) {}
  virtual void CalculateMoment(Jet *jet, JetCollection &jetColl) {
    m_value = jet->m();
  }
};

class PtMoment : public JetMoment<Double32_t> {
public:
  PtMoment(std::string name = "Pt") : JetMoment<Double32_t>(name) {}
  virtual void CalculateMoment(Jet *jet, JetCollection &jetColl) {
    m_value = jet->pt();
  }
};

class zMoment : public JetMoment<Double32_t> {
public:
  zMoment(std::string name = "z") : JetMoment<Double32_t>(name) {}
  virtual void CalculateMoment(Jet *jet, JetCollection &jetColl) {
    std::vector<Jet*> parents = jetColl.get_parents(jet);
    if (parents.size() == 0) {m_value = 0.0; return;}
    
    std::vector<Jet*>::iterator it, itE;
    it = parents.begin();
    itE = parents.end();
    m_value = 1.0;
    for (; it != itE; ++it) {
      m_value = std::min((*it)->pt() / jet->pt(), m_value);
    }
  }
};

class DeltaRMoment : public JetMoment<Double32_t> {
public:
  DeltaRMoment(std::string name = "DR") : JetMoment<Double32_t>(name), warn(true) {}
  virtual void CalculateMoment(Jet *jet, JetCollection &jetColl) {
    std::vector<Jet*> parents = jetColl.get_parents(jet);
    if (parents.size() == 0) {m_value = 0.0; return;}
    if (parents.size() != 2) {
      m_value = 0.0;
      if(warn) {std::cout << "DeltaR only valid for 2 parents!\n"; warn = false;}
      return;
    }
    
    const Jet *p1 = parents[0];
    const Jet *p2 = parents[1];
    m_value = std::sqrt(p1->plain_distance(*p2));
  }
private:
  bool warn;
};


/// Simple event moment: dijet mass.  Takes first two jets (presumably ranked in pt)
class DijetMassMoment : public EventMoment<Double32_t> {
public:
  DijetMassMoment(std::string name="dijetMass") : EventMoment<Double32_t>(name) {}
  
  virtual void CalculateMoment(Jet* jet, JetCollection& jetColl) {
    if (jetColl.size() < 2) m_value = 0.0;
    else {
      fastjet::PseudoJet psum = *(jetColl[0]) + *(jetColl[1]);
      m_value = psum.m();
    }
  }
};

inline int factorial(int n) {if (n <= 1) return 1; else return n*factorial(n-1);}

/// Measures all trijet masses and stores
class TrijetMassMoment : public EventMoment<std::vector<Double32_t> > {
public:
  TrijetMassMoment(std::string name="trijetMasses") : EventMoment<std::vector<Double32_t> >(name) {}
  
  virtual void CalculateMoment(Jet* jet, JetCollection& jetColl) {
    // store all n_C_3 triplets
    int n = jetColl.size();
    if (n < 3) {
      m_value.clear();
      return;
    }
    m_value.resize(factorial(n)/(factorial(n-3)*6));
    int tripletIndex = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        for (int k = j+1; k < n; ++k) {
          m_value[tripletIndex] = (*jetColl[i] + *jetColl[j] + *jetColl[k]).m();
          ++tripletIndex;
        }
  }
};

/// Measures all trijet pTs and stores (for use with masses, to cut on m/pT)
class TrijetPtMoment : public EventMoment<std::vector<Double32_t> > {
public:
  TrijetPtMoment(std::string name="trijetPts") : EventMoment<std::vector<Double32_t> >(name) {}
  
  virtual void CalculateMoment(Jet* jet, JetCollection& jetColl) {
    // store all n_C_3 triplets
    int n = jetColl.size();
    if (n < 3) {
      m_value.clear();
      return;
    }
    m_value.resize(factorial(n)/(factorial(n-3)*6));
    int tripletIndex = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        for (int k = j+1; k < n; ++k) {
          m_value[tripletIndex] = (*jetColl[i] + *jetColl[j] + *jetColl[k]).perp();
          ++tripletIndex;
        }
  }
};

}  // namespace SpartyJet



#endif


