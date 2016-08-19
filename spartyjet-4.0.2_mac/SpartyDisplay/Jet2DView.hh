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

#ifndef _JET_2DVIEW_HH_
#define _JET_2DVIEW_HH_

#include "JetTools/cyl_geom.hh"

#include <list>

#include "TMarker.h"
#include "TPolyLine.h"

namespace SpartyJet { 

class PtMarker : public TMarker {
public:
  PtMarker() {}
  PtMarker(double eta, double phi, double pt, int type=20) : TMarker(eta, phi, type), m_pt(pt) {}
  double m_pt;

  void Draw() {TMarker::Draw();}
  void Draw(TAttMarker &m) {
    m.Copy(*this);
    TMarker::Draw();
  }

  void Draw(int color, int style, float size) {
    TAttMarker m(color, style, size);
    Draw(m);
  }
  ClassDef(PtMarker,0);
};


class JetViewBase {
public:
  virtual ~JetViewBase(){}
};

template <class T>
class MarkerColl : public JetViewBase, std::list<T> {
public:
  typedef std::list< T > mark_list_t;  
  typedef typename mark_list_t::iterator mark_it_t;
  MarkerColl() : mark_list_t(), m_mtype(20), m_msize(0.5) {}
  virtual ~MarkerColl(){}

#define MARKLOOP( code ) mark_it_t it=this->begin();mark_it_t itE=this->end();for(;it!=itE;++it){code }

  void push_back(PtMarker p) {
    p.SetMarkerColor(m_mcolor);
    p.SetMarkerSize(m_msize);
    p.SetMarkerStyle(m_mtype);
    mark_list_t::push_back(p);
  }
  void push_back(float eta, float phi, float pt, int type=20) {push_back(PtMarker(eta, phi, pt, type));}

  void set_color(int col)  {MARKLOOP( (*it).SetMarkerColor(col); ); m_mcolor = col;set_pline_color(col);}
  void set_type(int col)   {MARKLOOP( (*it).SetMarkerStyle(col); ); m_mtype = col;}
  void set_size(float col) {MARKLOOP( (*it).SetMarkerSize(col); ); m_msize = col;}

  void clear() {mark_list_t::clear();}

  void scale_markers(float ptmin, float f) {MARKLOOP( float pt=(*it).m_pt; if(pt>ptmin )(*it).SetMarkerSize( 0.4+(pt-ptmin)*f); else (*it).SetMarkerSize(0.4) ;);}

  void buildHull();
  void Draw();
  //void clear(){m_markers.clear();}
  
  void set_pline_color(int i);

  //MarkerColl m_markers;
  TPolyLine m_pline[2];
  
  int m_mtype;
  int m_mcolor;
  float m_msize;

};

class Jet2DView : public MarkerColl<PtMarker> {
public:
  virtual ~Jet2DView(){}
};


template<class T>
void MarkerColl<T>::Draw(){
  MARKLOOP( (*it).Draw(); );
  m_pline[0].Draw();
  m_pline[1].Draw();
}

template<class T>
void MarkerColl<T>::set_pline_color(int i){
  m_pline[0].SetLineColor(i);
  m_pline[1].SetLineColor(i);
}  // namespace SpartyJet


template<class T>
void MarkerColl<T>::buildHull(){
  
    point_set_t points_1;

    mark_it_t it = this->begin();
    mark_it_t itE= this->end();
    for(; it != itE; ++it){
      points_1.insert(point_t((*it).GetX(), (*it).GetY() ) );
    }

    // get center
    float phicenter = getMeanPhi(points_1);
    point_set_t points_c;
    recenter_set(points_1, points_c, phicenter);

    // find centered hull
    point_list_t hull_c;
    findConvexHull(points_c, hull_c);

    // uncenter hull
    point_list_t hull;
    recenter_set(hull_c, hull, -phicenter);

    // re-add first point at the end.
    hull.push_back( *(hull.begin()) );

    // build polyline
    m_pline[0].SetPolyLine(-1);m_pline[1].SetPolyLine(-1); // deletes arrays
    float xinter[2] = {-M_PI, M_PI};

    bool line=0;
    point_t p,prevp;
    point_list_t::iterator hit = hull.begin();
    point_list_t::iterator hitE = hull.end();
    prevp = *hit;
    hit++;
    m_pline[line].SetNextPoint(prevp.first, prevp.second); // set the 1st point !
    for(; hit != hitE; hit++){
      p = *hit;
      if( fabs(p.second - prevp.second) < 3.14159) {
        m_pline[line].SetNextPoint(p.first, p.second);
        prevp = p;
        continue;
      }
      // we're changing side ! first compute border point
      bool side = prevp.second > p.second;
      point_t virtual_p = p;
      if(side) virtual_p.second = p.second+M_PI*2;
      else     virtual_p.second = p.second-M_PI*2;
      line_t l(prevp,virtual_p);
      point_t border_point = l.intercept_y(xinter[side]);
      m_pline[line].SetNextPoint(border_point.first, border_point.second);
    
      // now other side
      border_point.second = xinter[!side]; // other intercept is at same x, reverse y
      line = !line;
      m_pline[line].SetNextPoint(border_point.first, border_point.second);
      m_pline[line].SetNextPoint(p.first, p.second);
      prevp = p;
    }
    m_pline[0].SetLineColor(m_mcolor);
    m_pline[1].SetLineColor(m_mcolor);


}


}  // namespace SpartyJet
#endif
