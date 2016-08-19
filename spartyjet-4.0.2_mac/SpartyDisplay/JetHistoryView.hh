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

#ifndef _JET_HISTORYVIEW_HH_
#define _JET_HISTORYVIEW_HH_

#include "JetCore/JetCollection.hh"
#include "JetCore/JetHistory.hh"
#include "Jet2DView.hh"
#include "TH2F.h"

namespace SpartyJet { 

  class JetHistoryView : public  PtMarker , public HistoryProvider<JetHistoryView> {
  public:    
    JetHistoryView() {}
    ~JetHistoryView() {}
    template<class T>
    JetHistoryView(const HistoryProvider<T> &hp)
      : HistoryProvider<JetHistoryView>(hp) {set_defaults();}
    template<class T>
    JetHistoryView & operator= (const HistoryProvider<T> &hp) {
      if (&hp == dynamic_cast<T*>(this)) return *this;
      HistoryProvider<JetHistoryView>::operator=(hp);
      return *this;
    }
    void set_defaults() {SetMarkerStyle(kFullCircle); SetMarkerColor(kWhite); SetMarkerSize(1);}
    
    void drawConstituents(int color=kGray, int style=kFullDotSmall, float size=1);
    
    void setConstitutentStyle(int style);
    void setConstitutentColor(int color);
    void setConstitutentSize(float size);
    void setConstitutentAtt(TAttMarker &m);
    
    void drawParent(int color=kGray, int style=kFullDotSmall, float size=1);
    
    void drawJet(int color=kGray, int style=kFullDotSmall, float size=1)
          {Draw(color, style, size);}
    void drawJet(TAttMarker &m) {Draw(m);}
    
    void buildJet();
    
    void debug();

  protected:
    ClassDef(JetHistoryView, 0);
  };


  class JetHistViewCollection {
  public:
    JetHistViewCollection() {}
    JetHistViewCollection(JetCollection &jcoll);

    void drawConstituents(bool onlyFinalJet=false);

    size_t size() {return m_hview.size();}
    JetHistoryView* at(int i) {return m_hview[i];}
    JetHistoryView* operator[](int i) {return m_hview[i];}

    size_t finalSize(){return m_hview.size();}
    JetHistoryView* finalJet(int i){return m_hview[i];}

  protected:
    std::vector<JetHistoryView*> m_hview;
  };

}
#endif
