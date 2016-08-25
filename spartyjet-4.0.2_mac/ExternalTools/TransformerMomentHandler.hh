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

#ifndef _TRANSFORMER_MOMENT_HANDLER_HH_
#define _TRANSFORMER_MOMENT_HANDLER_HH_

#include "fastjet/tools/Transformer.hh"


namespace SpartyJet {

class Jet;
class JetMomentMap;

namespace FastJet {


/// The interface for a set of classes that define, for a given Transformer,
///  what JetMoments to store and their type.
/// Default is to just do nothing (many Transformers only deal with structure,
///  no extra variables).
class TransformerMomentHandler {
public:
  /// schedule any moments this Transformer calculates
  virtual void init(JetMomentMap* map) {}
  
  /// set moments for a given jet
  virtual void set_moments(const Jet* j, JetMomentMap* map) {}
};


/// Try all the Transformers we know about (that have moment information).
///  Return an appropriate moment handler, otherwise the do-nothing default.
TransformerMomentHandler* getMomentHandler(fastjet::Transformer* t);


/// Wrapper for generic top taggers (stores mW)
class TopTaggerMomentHandler : public TransformerMomentHandler {
public:
  virtual void init(JetMomentMap* map);
  virtual void set_moments(const Jet* j, JetMomentMap* map);
};

/// Hopkins, CMS, HEP taggers: also store cos_theta_h
class JHTopTaggerMomentHandler : public TopTaggerMomentHandler {
public:
  virtual void init(JetMomentMap* map);
  virtual void set_moments(const Jet* j, JetMomentMap* map);
};
class CMSTopTaggerMomentHandler : public TopTaggerMomentHandler {
public:
  virtual void init(JetMomentMap* map);
  virtual void set_moments(const Jet* j, JetMomentMap* map);
};
class HEPTopTaggerMomentHandler : public TopTaggerMomentHandler {
public:
  virtual void init(JetMomentMap* map);
  virtual void set_moments(const Jet* j, JetMomentMap* map);
};




}
} // namespace SpartyJet

#endif
