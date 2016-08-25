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

#ifndef _CYL_GEOM_HH_
#define _CYL_GEOM_HH_

#include <utility>
#include <set>
#include <list>
#include <vector>
#include <iostream>


/// ------------------------------------------------
/// A small collection of 2D geometric function
/// ------------------------------------------------


namespace SpartyJet { 

/// Create classes for easier insertion in ROOT. Maybe not necessary
class point_t : public std::pair<float, float> { 
public:
  point_t() {}
  point_t(float x, float y) {first = x; second = y;}
};
class point_set_t : public std::set<point_t> {};
class point_vect_t : public std::vector<point_t> {};

typedef std::list<point_t> point_list_t;


// Very simple oriented line class
class line_t {
public:
  
  line_t(float cx, float cy, float cc, bool to_r) : m_cx(cx), m_cy(cy), m_cc(cc), m_oriented_r(to_r) {};
  line_t(point_t p1, point_t p2);
  
  float m_cx, m_cy, m_cc;
  bool m_oriented_r;

  bool is_above(point_t& p);
  bool is_below(point_t& p);

  bool is_left(point_t& p) {return m_oriented_r ? is_above(p) : is_below(p);};
  bool is_right(point_t& p) {return m_oriented_r ? is_below(p) : is_above(p);};

  void phi_shift(float dphi) {m_cc = m_cc - m_cy*dphi;}

  point_t intercept_y(float y);
  point_t intercept_x(float x);
  
};


template<class T>
void print_points(T& line);

// Find convex hull of a set of points in euclidian plan.
template< class inT, class ouT>
void findConvexHull(inT& inSet, ouT& outSet);
template<class ouT>
void findConvexHull(point_set_t& inSet, ouT& outSet );
template< class inT>
void _findConvexHull(point_set_t& inSet, inT& outSet );

// internally used by findConvexHull
void testHullLine(point_list_t& hull, point_t p);


template<class T>
float polygon_area(T& line);

template<class T>
float polygon_length(T& line);



// *******************************************************
// Cylindrical geometry **********************************
// *******************************************************

/// return average phi (i.e. second coordinate), if max(deltaphi) < pi
/// otherwise return -10.
template <class T>
float getMeanPhi(T& set);
template<class T>
float max_deltaR(point_t p, T& set);


// copy inSet into outSet with all phi coordinates recentered by phicenter
template<class T , class T2>
void recenter_set(T& inSet, T2& outSet, float phicenter);
// copy inSet into outSet with all phi coordinates recentered by
// average phi of inSet
template<class T , class T2>
void recenter_set(T& inSet, T2& outSet);



inline float in_mPI_pPI(float phi);
inline void  fix2pi(point_t& p);
inline float deltaR(point_t& p1, point_t& p2);
inline float deltaR2(point_t& p1, point_t& p2);

inline float deltaPhi(point_t& p1, point_t& p2);
inline float deltaPhi(float phi1, float phi2);



// *******************************************************
// Utils function **********************************
// *******************************************************
void listToSet(point_list_t& inList, point_set_t& outSet);
template<class T> 
void clear_delete(T& container);
template<class T> 
void delete_content(T& container);


} // namespace SpartyJet

// ***************************************************************************

// ***********************************************
// Inlined and template functions ****************************
// ***********************************************
#ifndef G__DICTIONARY
#include <cmath>
namespace SpartyJet { 


template<class T> 
void clear_delete(T& container){
  typedef typename T::iterator it_t;
  it_t it =  container.begin();
  it_t itE = container.end();
  for(; it != itE; ++it) delete *it;
  container.clear();
}
template<class T> 
void delete_content(T& container){
  typedef typename T::iterator it_t;
  it_t it =  container.begin();
  it_t itE = container.end();
  for(; it != itE; ++it) delete *it;
}

template<class T>
float max_deltaR(point_t p, T& set){
  typedef typename T::iterator it_t;
  it_t it  = set.begin();
  it_t itE = set.end();
  float r = 0;
  for (; it != itE; ++it){
    float t = deltaR(p, *it);
    if (t > r) r = t;
  }
  return r;
}

template<class T>
float polygon_area (T& line) {
  typedef typename T::iterator it_t;
  it_t it  = line.begin();
  it_t itE = line.end();
  float a = 0;
  for (; it != itE; ++it) {
    it_t itp = it;
    itp++;
    if (itp == itE) itp =  line.begin();
    a += ((*it).first*(*itp).second - (*itp).first*(*it).second);
  }
  return a/2;
}
  
template<class T>
float polygon_length(T& line){
  typedef typename T::iterator it_t;
  it_t it  = line.begin();
  it_t itE = line.end();
  float a = 0;
  for (; it != itE; ++it) {
    it_t itp = it;
    itp++;
    if (itp == itE) itp = line.begin();
    a += deltaR(*it, *itp);
  }
  return a;
}


template<class T>
void print_points(T& line) {
  typedef typename T::iterator it_t;
  it_t it  = line.begin();
  it_t itE = line.end();
  int i = 0;
  for (; it != itE; ++it) {
    std::cout << i << "\t  " << (*it).first << " , " << (*it).second << std::endl;
  }
}


inline float abs_dphi(float phi1, float phi2) {
  float d = fabs(phi1 - phi2);
  return d < M_PI ? d : fabs(d - 2*M_PI);
}
inline float deltaPhi(float phi1, float phi2) {
  return in_mPI_pPI(phi1 - phi2);
}
inline float deltaPhi(point_t& p1, point_t& p2) {
  return deltaPhi(p1.second, p2.second);
}
inline float in_mPI_pPI(float phi) {
  while (phi < -M_PI) phi += 2*M_PI;
  while (phi >= M_PI) phi -= 2*M_PI;
  return phi;
}
inline void fix2pi(point_t& p){
  while (p.second < -M_PI) p.second += 2*M_PI;
  while (p.second >= M_PI) p.second -= 2*M_PI;
}

inline point_t recenter(const point_t& p, const point_t& center) {
  point_t n(p.first, p.second - center.second);
  fix2pi(n);
  return n;
}
inline point_t recenter(const point_t& p, float phicenter){
  point_t n(p.first, p.second - phicenter);
  fix2pi(n);
  return n;
}
inline float deltaR2(point_t& p1, point_t& p2){
  return (p1.first-p2.first) * (p1.first-p2.first) + 
		abs_dphi(p1.second, p2.second) * abs_dphi(p1.second, p2.second) ;
}
inline float deltaR(point_t& p1, point_t& p2) {
  return sqrt(deltaR2(p1, p2));
}

template<class T, class T2>
void recenter_set(T& inSet, T2& outSet, float phicenter){
  typedef typename T::iterator it_t;
  typedef typename T2::iterator it_t2;
  it_t it = inSet.begin();
  it_t itE = inSet.end();
  it_t2 it2 = outSet.begin();
  for (; it != itE; ++it) {
    it2 = outSet.insert(it2, recenter(*it, phicenter));
  }
}
template<class T, class T2>
void recenter_set(T& inSet, T2& outSet){
  float phicenter = getMeanPhi(inSet);
  if (phicenter < -9) return;
  recenter_set(inSet, outSet, phicenter);
}

template <class T>
float getMeanPhi(T& set){
  // return mean
  typedef typename T::iterator it_t;
  it_t it = set.begin();
  it_t end = set.end();
  point_t fp = (*it);
  float max=0, min=0, mean=0;
  int n = 0;
  for (; it != end; ++it) {
    float phi = recenter((*it), fp).second;
    if ( phi > 0) {
      max = phi > max ? phi : max;
    } else{
      min = phi < min ? phi : min;
    }
    mean += phi;
    n++;
  }
  if ((max-min) <= (M_PI))
    return in_mPI_pPI(mean/n + fp.second);
  else return -10;
}


inline line_t::line_t(point_t p1, point_t p2){
  m_cy = p1.first - p2.first;
  m_cx = p2.second - p1.second;
  m_cc = -(m_cx*p1.first + m_cy*p1.second);  
  m_oriented_r = (p1.first < p2.first);
}

inline bool line_t::is_above(point_t& p){
  return ((m_cy != 0) && (p.second >= - (m_cx*p.first + m_cc)/m_cy));
}

inline bool line_t::is_below(point_t& p){
  return ((m_cy != 0) && (p.second <= - (m_cx*p.first + m_cc)/m_cy));
}

inline point_t line_t::intercept_y(float y) {
  if (m_cx == 0) return point_t(-99999, y);
  return point_t((-m_cc - m_cy*y)/m_cx, y);
}

inline point_t line_t::intercept_x(float x) {
  if (m_cy == 0) return point_t(x, -99999);
  return point_t(x, (-m_cc - m_cx*x)/m_cy);
}



// Convex Hull *************************************

template<class inT, class ouT>
void findConvexHull(inT& inSet, ouT& outSet) {
  point_set_t rset;
  typedef typename inT::iterator it_t;
  it_t it = inSet.begin();
  it_t itE = inSet.end();
  for(; it!=itE; ++it) rset.insert(*it);
  _findConvexHull(rset,outSet);
}

template<class ouT>
void findConvexHull(point_set_t& inSet, ouT& outSet ) {
  _findConvexHull(inSet, outSet);
}

template <class T>
void _findConvexHull(point_set_t& inSet, T& outSet ) {

  if (inSet.size() < 4) {  
    outSet.insert(outSet.begin(), inSet.begin(), inSet.end());
    return;
  }
  
  point_set_t::iterator s_it = inSet.begin();
  point_t point00 = (*s_it);
  point_t point01= point00;
  while (point01.first == point00.first) {
    ++s_it;
    point01 = *s_it;
  }
  --s_it;
  point01 = *s_it; 

  s_it = inSet.end();
  --s_it;
  point_t point11 = (*s_it);
  point_t point10= point11;
  while (point10.first == point11.first) {
    --s_it;
    point10 = *s_it;
  }
  ++s_it;
  point10 = *s_it; 

  // lower line :
  line_t lmin(point00, point10);
  // lower line :
  line_t lmax(point01, point11);
    
  // fill upper and lower list :
  point_list_t lowPoints, upPoints;

  s_it = inSet.begin();
  if (point00 == point01) { // make sure point is in both list
    lowPoints.push_back(point00);
    upPoints.push_back(point00);
    s_it++;
  }
  //std::cout << " lp size =" << lowPoints.size() << std::endl;
  point_set_t::iterator s_itE = inSet.end(); 
  s_itE--; // we'll deal ws_ith the end by hand
  for (; s_it!= s_itE; ++s_it) {
    point_t p = *s_it;
    //std::cout << " point "<< p.first << " , "<< p.second << std::endl;
    if (lmin.is_below(p)) {
      lowPoints.push_back(p);
      continue;
    }
    if (lmax.is_above(p)) {
      upPoints.push_front(p); // insert front soit is well sorted
    }
  }
  //std::cout << " lp size =" << lowPoints.size() << std::endl;
  if (point11 == point10) { // make sure point is in both list
    lowPoints.push_back(point11);
    upPoints.push_front(point11);
    s_it++;
  } else {
    lowPoints.push_back(point10);
    upPoints.push_front(point00);
  }
  //std::cout << " lp size =" << lowPoints.size() << std::endl;
  //std::cout << lowPoints.size() << " " << upPoints.size() << std::endl;

  // find lower hull :
  point_list_t lowHull;
  point_list_t::iterator it = lowPoints.begin();
  point_list_t::iterator itE = lowPoints.end();
  lowHull.push_back(point00); // here point00 == (*it)
  ++it;
  lowHull.push_back(*it);  // always put next point in stack
  ++it;
  unsigned int nn = lowPoints.size();
  if (nn > 2) {
    //std::cout << "building low hull : "<< lowPoints.size() <<std::endl; 
    while (it != itE){    
      testHullLine(lowHull, *it);
      ++it;
    }
  }
  // find upper hull :
  point_list_t upHull;
  it = upPoints.begin();
  itE = upPoints.end();
  upHull.push_back(point11); // here point11 == (*it)
  ++it;
  upHull.push_back(*it);  // always put next point in stack
  ++it; 
  if (upPoints.size() > 2) {
    //std::cout << "building up hull : "<< upPoints.size() <<std::endl; 
    while (it != itE) {   
      testHullLine(upHull, *it);    
      ++it;
    }
  }
//   std::cout << " low size = "<< lowHull.size() << std::endl;
//   std::cout << " up size = "<< upHull.size() << std::endl;
  // join Hull !
  outSet.insert(outSet.begin(), lowHull.begin(), lowHull.end());
  outSet.insert((outSet.end()), ++(upHull.begin()), --(upHull.end())); // avoid duplication
  
  //  std::cout << " Out size = "<< outSet.size() << std::endl;
}

}  // namespace SpartyJet
#endif //DICT


#endif

