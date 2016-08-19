/////////////////////////////////////////////////////////////////////////////////////////////
//
//  dipolarity is a jet observable that quantifies the degree to which the radiation of two
//  subjets subjet1 and subjet2 is clustered in the region between the two subjets.  as input 
//  it requires the centers of the two subjets as well as the list of four vectors that enter
//  into the sum (but it does not require that these four vectors be partitioned between 
//  subjet1 and subjet2).
//
//  for more information see the reference:
//
//  arXiv:hep-ph/1102.1012     Jet Dipolarity: Top Tagging with Color Flow
//                             Anson Hook, Martin Jankowiak, Jay G. Wacker
//
//  caution:  this is provided as 'beta' code
//
//  This version (provided in SpartyJet) has some edits for std:: namespace
//  issues, to add the appropriate includes, and multiple-include guards (CKV 7/5/11).
//
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _DIPOLARITY_HH_
#define _DIPOLARITY_HH_

#include "fastjet/PseudoJet.hh"
#include <vector>
#include <cstdlib>

double signedphidist(double phia, double phib);

double Dipolarity(fastjet::PseudoJet subjet1, fastjet::PseudoJet subjet2, std::vector<fastjet::PseudoJet> subjets)
{
double y, phi, dist;
double dipolarity=0.0, u, yint, phiint;
double y1 = subjet1.rap(), y2 = subjet2.rap();
double phi1 = subjet1.phi(), phi2 = subjet2.phi();
double radius = std::sqrt(subjet1.plain_distance(subjet2));
fastjet::PseudoJet totjet(0,0,0,0);

  for (int k=0; k<(int)subjets.size(); k++)
  {
  totjet+=subjets[k];
  y = subjets[k].rap();
  phi = subjets[k].phi();
  u = (y-y1)*(y2-y1)+signedphidist(phi1,phi)*signedphidist(phi1,phi2);
  u /= ((y2-y1)*(y2-y1)+std::pow(signedphidist(phi1,phi2),2));
  if (u>1.0) u=1.0;   if (u<0.0) u=0.0;
  yint = y1 + u*(y2-y1);
  phiint = phi1 + u*signedphidist(phi1,phi2);
  if (phiint>6.28318531)   phiint-=6.28318531;
  if (phiint<0.0)          phiint+=6.28318531;
  dist = std::sqrt(std::pow(signedphidist(phiint,phi),2)+std::pow(yint-y,2));
  dipolarity+=subjets[k].perp()*dist*dist;
  }

dipolarity/=totjet.perp();
dipolarity/=(radius*radius);
return dipolarity;
}

// signed phi distance function
double signedphidist(double phia, double phib)
{
double deltaphi=std::abs(phia-phib);
double phiL=phia, phiS=phib;
if (phib>phia) { phiL=phib; phiS=phia; }

  if (6.28318531-phiL+phiS<deltaphi)
  {
  deltaphi=6.28318531-phiL+phiS;
  if (phia<phib) deltaphi*=-1;
  return deltaphi;
  }

  if (phia>phib) deltaphi*=-1;

return deltaphi;
}

#endif
