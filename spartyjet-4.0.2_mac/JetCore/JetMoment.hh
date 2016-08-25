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

#ifndef _JETMOMENT_HH_
#define _JETMOMENT_HH_

/// A JetMoment is a function-like object, which returns
///   a result templated to be of type T.
/// It also holds the result, so is useful for storing moments.

#include "CustomMessage.hh"

#include <vector>
#include <string>

namespace SpartyJet {

class Jet;
class JetCollection;
class BranchWrap;

/// A simple non-templated base class for JetMoment and EventMoment for I/O interface
class Moment {
public:
  Moment(std::string name = "") : m_name(name) {}
  virtual ~Moment() {}
  void                SetName(std::string name)  {m_name = name;}
  const std::string & GetName()  const           {return m_name;}
  virtual Moment*     MakeCopy() const           {return new Moment(m_name);}
  virtual Moment&     operator=(const Moment &m) {m_name = m.m_name; return *this;}

  /// Specific Moment derivatives define this function
  ///  For EventMoments the Jet* is unnecessary and can be NULL
  virtual void CalculateMoment(Jet* jet, JetCollection &jetColl) {}

  virtual BranchWrap* GetBranchWrap() const {return NULL;}

protected:
  std::string m_name;
  Message m_log;
};

/// JetMoment is a base class for functions on Jets.
/// JetMoment is a base class for functions on Jets.
/// Use by making a derived class and defining CalculateMoment.
template<class T>
class JetMoment : public Moment {
public:
  JetMoment(std::string name = "") : Moment(name) {}
  JetMoment(const JetMoment& m)   : Moment(m.m_name), m_value(m.m_value) {}
  ~JetMoment() {}

  virtual Moment* MakeCopy() const {return new JetMoment<T>(*this);}
  virtual Moment& operator=(const Moment &m) {
    if (this != &m) {
      Moment::operator=(m);
      const JetMoment<T> *jm = dynamic_cast<const JetMoment<T>*>(&m);
      if(jm) m_value = jm->GetValue();
    }
    return *this;
  }

  virtual T operator()(Jet* jet, JetCollection& jetColl) {
    CalculateMoment(jet, jetColl);
    return m_value;
  }
  
  const T& operator=(const T& t) {m_value = t; return t;}
  void SetValue(const T& t) {m_value = t;} const
  T GetValue() const {return m_value;}

  virtual BranchWrap* GetBranchWrap() const;

protected:
  T m_value; // store the value
};


/// EventMoment is a base class for functions on JetCollections.
/// Use by making a derived class and defining CalculateMoment.
/// Users should call Moment::SetName() (in, say, the JetTool that stores the
///   Moment -- see e.g. GenericMomentTool.hh).
template<class T>
class EventMoment : public Moment {
public:
  EventMoment(std::string name = "") : Moment(name) {}
  EventMoment(const EventMoment & m)   : Moment(m.m_name), m_value(m.m_value) {}
  ~EventMoment() {}

  virtual Moment* MakeCopy() const {return new EventMoment<T>(*this);}
  virtual Moment& operator=(const Moment &m) {
    if (this != &m) {
      Moment::operator=(m);
      const EventMoment<T> *jm = dynamic_cast<const EventMoment<T>*>(&m);
      if(jm) m_value = jm->GetValue();
    }
    return *this;
  }

  virtual T operator()(JetCollection &jetColl) {
    CalculateMoment(NULL, jetColl);
    return m_value;
  }

  const T& operator=(const T &t) {m_value = t; return t;}
  void SetValue(const T &t) {m_value = t;}
  T GetValue() const {return m_value;}

  virtual BranchWrap* GetBranchWrap() const;

protected:
  T m_value; // store the value
};

}  // namespace SpartyJet


#include "BranchWrap.hh"

namespace SpartyJet {

// forward declarations since BranchWrap.hh includes JetMoment.hh!
template <class T> class BranchWrap_JetMoment;
template <class T> class BranchWrap_EventMoment;

template <class T>
BranchWrap* JetMoment<T>::GetBranchWrap() const {return new BranchWrap_JetMoment<T>();}

template <class T>
BranchWrap* EventMoment<T>::GetBranchWrap() const {return new BranchWrap_EventMoment<T>();}

} // namespace SpartyJet


#endif
