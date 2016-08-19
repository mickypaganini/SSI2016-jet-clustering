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

#ifndef _SPARTYEVENTVIEW_H
#define _SPARTYEVENTVIEW_H

#include "JetCollExtended.hh"

#include "TObject.h"
#include "TH1.h"

#include <vector>
#include <string>

class TPad;

namespace SpartyJet {

typedef std::vector<TObject*> TOvect_t;

// ///////////////////////////////////////////////////////////
/// \class EventViewBase
/// Specializations of this base class draw a view of a given jetcollection
class EventViewBase {
public:

  /// Set it so histograms are not saved to the current directory -- no need for this
  ///  avoids warnings if we give more than one hist the same name
  EventViewBase(): option_use_rapidity(false),option_min_pt_jet_display(1) {TH1::AddDirectory(kFALSE);};
  virtual ~EventViewBase()  {};
  virtual std::string title(){return "";}
  virtual void draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" );

  /// The actual drawing method inherited by specialized classes
  virtual void i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" ) {}
  
  TOvect_t get_local_objects() {return m_local_objects;}

  virtual void clear_graphic_objects();

  virtual int num_pad_used() {return 1;}

  static TOvect_t s_gc_objects;
  static TPad* getPad();
  static void  setPad(TPad *p);

  static int color_code(int i);
  static int base_colors[];

  static int  option_low_pt_jet_color;
  bool option_use_rapidity;
  float option_min_pt_jet_display;


protected:

  static TPad* s_pad;  

  /// TObject used for the graphic representatoin are stored here and deleted
  /// when no more used. (garbage collection)
  TOvect_t m_local_objects;
};


class LegoView : public EventViewBase {
public:
  LegoView() : option_eta(0.1), option_phi(0.1), option_input(true), option_psr(false) {}

  virtual void i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" );

  virtual std::string title() {return "Lego plot";}

  float option_eta,option_phi;
  bool option_input;
  bool option_psr;
};



class JetViewBase;
class Jet2DView;

class Event2DView : public EventViewBase {
public:
  Event2DView() : option_2Dview_scale_markers(false), option_2Dview_draw_input(false){};

  //virtual void draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" ) ;
  virtual void i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" ) ;
  virtual void clear_graphic_objects();

  virtual std::string title(){return "2D view";}

  bool  option_2Dview_scale_markers;
  bool  option_2Dview_draw_input;

protected:
  // Custom garbage collectors for 2D view objects
  //  (needed because they don't inherit TObject)
  std::vector<JetViewBase*> m_gc_inpuColl;
  std::vector<std::vector<Jet2DView>*> m_gc_JetView;    
};



class SnowMassView : public EventViewBase {
public:
  
  SnowMassView();
  virtual void i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" ) ;    

  virtual std::string title(){return "Snowmass potential";}

// SNOWMASS OPTIONS
float option_ymin,option_ymax;
float option_phimin, option_phimax;
float option_ystep, option_phistep;
float option_radius;
bool option_log;
bool option_drawjets;


};

class PrintEvent : public EventViewBase {
public:
  
  PrintEvent(){};
  virtual void i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" ) ;    

  virtual std::string title(){return "Event dump";}
  virtual int num_pad_used(){return 0;}
};


class ParamSpace : public EventViewBase {
public:
  
  ParamSpace(){};
  virtual void i_draw_jets(JetCollExtended & jcoll, JetCollExtended &inputcoll, std::string hname="", std::string htitle="" ) ;    

  virtual std::string title(){return "Parameter space";}

};

} // namespace SpartyJet
#endif
