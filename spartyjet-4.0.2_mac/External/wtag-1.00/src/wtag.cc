/*
   Multivariate W-tagging
   Authors: Yanou Cui, Zhenyu Han and Matthew Schwartz
   Reference:  
   Usage:   
*/
#include <iostream>

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/tools/Pruner.hh"

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TMarker.h"
#include "TStyle.h"

#include "TMVA/Reader.h"
#include "TMVA/Config.h"
#include "TMVA/Tools.h"
#include "TMVA/MethodCuts.h"
#include "wtag.h"



using namespace fastjet;
using namespace std;

namespace Wtag {

double dot(double *p1, double *p2)
{
   return p1[0]*p2[0] - p1[1]*p2[1] - p1[2]*p2[2] - p1[3]*p2[3];
}

double invmass(double p1[], double p2[])
{
   double q[4];
   for (int i = 0; i < 4; i ++)
     q[i] = p1[i] + p2[i];
   return sqrt(dot(q, q));
}

double invmass(double p1[], double p2[], double p3[])
{

   double p[4];
   double temp;
   for (int i = 0; i < 4; i ++) 
     p[i] = p1[i] + p2[i] +p3[i];
   return sqrt(dot(p, p));
}

inline double min(double x1, double x2)
{
   if (x1 > x2) return x2;
   else return x1;
} 

int cal_ipt(double pt)
{
   int tempi = (int) ((pt - 200.)/50.);
   if (tempi  < 0) tempi = 0;
   if (tempi < 0) 
   {
      cout << "Error: jet pt < 200 is not allowed." << endl;
      exit(0);
      
   }
   if (tempi >= NPT) tempi = NPT - 1;
   return tempi;
}

int cal_ieff(double eff)
{
    int tempi;
    tempi = (int) (eff*NEFF);
   
    return tempi;
}

void jet_pars::set_trimming_par_file(char* filename)
{
    strcpy(trimming_par_file, filename);  
}  

void jet_pars::get_trimming_par_file(char* filename)
{
    strcpy(filename, trimming_par_file);  
}  

void jet_pars::set_pruning_par_file(char* filename)
{
    strcpy(pruning_par_file, filename);
    
}  

void jet_pars::get_pruning_par_file(char* filename)
{
    strcpy(filename, pruning_par_file);
    
}  

void jet_pars::set_filtering_par_file(char* filename)
{
    strcpy(filtering_par_file, filename);
}  

void jet_pars::get_filtering_par_file(char* filename)
{
    strcpy(filename, filtering_par_file);
}  

void jet_pars::set_bdtcut_filename(char* filename)
{
    strcpy(bdtcut_filename, filename);
}

void jet_pars::get_bdtcut_filename(char* filename)
{
    strcpy(filename, bdtcut_filename);
}

void jet_pars::set_bdteff_filename(char* filename)
{
    strcpy(bdteff_filename, filename);
}

void jet_pars::get_bdteff_filename(char* filename)
{
    strcpy(filename, bdteff_filename);
}
void jet_pars::set_bdtweight_dir(char* filename)
{
    strcpy(bdtweight_dir, filename);
}

void jet_pars::get_bdtweight_dir(char* filename)
{
    strcpy(filename, bdtweight_dir);
}

void jet_pars::set_bdtweight_prefix(char* filename)
{
   strcpy(bdtweight_prefix, filename);
}

void jet_pars::get_bdtweight_prefix(char* filename)
{
   strcpy(filename, bdtweight_prefix);
}


void jet_pars::set_bdtweight_name(double pt, char * filename)
{
   //allowing specifying the weight file for a particular pt bin
   int i = cal_ipt(pt);
   strcpy(bdtweight_name[i], filename);

   //indicate that the weight file is specified for pt bin i.
   bdtweights_set[i] = true;
}

void jet_pars::get_bdtweight_name(double pt, char * filename)
{
   
   int i = cal_ipt(pt);
   //if specified the weight file name for a particular pt bin
   if (bdtweights_set[i] == true) strcpy(filename, bdtweight_name[i]);
   else 
   {
      char ptlabel[10];
      sprintf(ptlabel, "%d", 200 + 50*cal_ipt(pt));
      strcpy(filename, bdtweight_dir);
      strcat(filename, bdtweight_prefix);        
      strcat(filename, ptlabel);
      strcat(filename, "_BDT.weights.xml");
   }
    
}

double jet_pars::get_bdtcut_opt(double pt)
{
   if (initiated) return bdtcuts_opt[cal_ipt(pt)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   }
}

double jet_pars::get_bdtcut_opt_es(double pt)
{
   if (initiated) return bdtcuts_opt_es[cal_ipt(pt)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   }
}
double jet_pars::get_bdtcut(double pt, double es)
{
   if (initiated) 
   {
      //cout << "ipt = " << cal_ipt(pt) << endl;
      //cout << "ieff = " << cal_ieff(es) << endl;
      //cout << "bdtcut = " << bdtcuts[cal_ipt(pt)][cal_ieff(es)] << endl;
      return bdtcuts[cal_ipt(pt)][cal_ieff(es)];
   }     
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}
      
double jet_pars::get_bdtcut_es(double pt, double es)
{
   if (initiated) 
       return bdtcuts_es[cal_ipt(pt)][cal_ieff(es)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}
   
double jet_pars::get_bdtcut_eb(double pt, double es)
{
   if (initiated) 
       return bdtcuts_eb[cal_ipt(pt)][cal_ieff(es)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}
   
double jet_pars::get_bdtcut_sig(double pt, double es)
{
   if (initiated) 
       return bdtcuts_sig[cal_ipt(pt)][cal_ieff(es)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}
   
double jet_pars::get_filtering_es(double pt)
{
   if (initiated)
       return filtering_es[cal_ipt(pt)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}

double jet_pars::get_filtering_eb(double pt)
{
   if (initiated)
       return filtering_eb[cal_ipt(pt)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}

double jet_pars::get_filtering_sig(double pt)
{
   if (initiated)
       return filtering_sig[cal_ipt(pt)];
   else 
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   } 
}
jet_pars::jet_pars()
{
   initiated = false;
   strcpy(trimming_par_file, "../data/trimming_parameters.dat");
   strcpy(pruning_par_file, "../data/pruning_parameters.dat");
   strcpy(filtering_par_file, "../data/filtering_parameters.dat");
   strcpy(bdtcut_filename, "../data/BDTcuts.dat");
   strcpy(bdteff_filename, "../data/effs_bdtv.dat");
   strcpy(bdtweight_dir, "../data/weights/");
   strcpy(bdtweight_prefix, "mvars_8142_");
   for (int i = 0; i < NPT; i ++) bdtweights_set[i] = false;
}


double jet_pars::get_Rsub(double pt)
{
   if (initiated) return Rsub[cal_ipt(pt)];
   else
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   }  
}

double jet_pars::get_fcut(double pt)
{
   if (initiated) return fcut[cal_ipt(pt)];
   else
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   }  
  
}

double jet_pars::get_Rcut(double pt)
{
   if (initiated) return Rcut[cal_ipt(pt)];
   else
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   }  
}

double jet_pars::get_zcut(double pt)
{
   if (initiated) return zcut[cal_ipt(pt)];
   else
   {
      cout << "error: jet_pars not initiated" << endl;
      exit(0);
   }  
}

double jet_pars::get_mu(double pt)
{
    if (initiated) return mu[cal_ipt(pt)];
    else
    {
       cout << "error: jet_pars not initiated" << endl;
       exit(0);
    }  

}

double jet_pars::get_ycut(double pt)
{
    if (initiated) return ycut[cal_ipt(pt)];
    else
    {
       cout << "error: jet_pars not initiated" << endl;
       exit(0);
    }  
   
}


void jet_mvars::foutput(ofstream &fout)
{
    //write the variables to fout 
    fout << mass << "\t" << pt << "\t" << mass2 << "\t" << pt2 << "\t"
         << mass3 << "\t" << pt3 << "\t" << mass4 << "\t" << pt4 << "\t"
         << mass5 << "\t" << pt5 << "\t" << mass6 << "\t" << pt6 << "\t"
         << mass7 << "\t" << pt7 << "\t" << mass8 << "\t" << pt8 << "\t"
         << mass9 << "\t" << pt9 << "\t" << mass10 << "\t" << pt10 << "\t"
         << mass11 << "\t" << pt11 << "\t"
         << masstrim << "\t" << pttrim << "\t" 
         << massprune << "\t" << ptprune << "\t" << massfilter << "\t" << ptfilter
         << "\t" << nsubjets << "\t" << ptratio  << "\t" << ptsub1 << "\t" << masssub1  
         << "\t" << ptsub2 << "\t" << masssub2 << "\t" << subjetdR << "\t" 
         << pangle1 << "\t" << psize1 << "\t"  << pangle2 << "\t" << psize2 
         
         << "\t" << rapsub1 << "\t" << phisub1 << "\t" << rapsub2 << "\t" << phisub2
         << "\t"  
         << planarflow <<"\t" << planarflow4 << "\t" 
         << endl;        
}

bool jet_mvars::finput(ifstream &fin)
{
    //reading variables from fin
    fin >> mass >> pt 
        >> mass2 >> pt2 >> mass3 >> pt3 >> mass4 >> pt4
        >> mass5 >> pt5 >> mass6 >> pt6 >> mass7 >> pt7 
        >> mass8 >> pt8 >> mass9 >> pt9 >> mass10 >> pt10
        >> mass11 >> pt11
        >> masstrim >> pttrim >> massprune >> ptprune >> massfilter >> ptfilter
        >> nsubjets >> ptratio >> ptsub1 >> masssub1  
        >> ptsub2 >> masssub2 >> subjetdR
        >> pangle1 >> psize1 >> pangle2 >> psize2 
       
        >> rapsub1 >> phisub1 >> rapsub2 >> phisub2
        >>  planarflow >> planarflow4 ;
           
    if (fin.eof()) return false;
    else return true;
    
}

/*jet_mvars::jet_mvars()
{
    mass = 0, ptsub1   = 0, ptsub2   = 0, masssub1  = 0, masssub2  = 0, subjetdR = 0;
    masswf41 = 0, masswf42 = 0, masswf151 = 0, masswf152 = 0;
    rapsub1  = 0, rapsub2  = 0, phisub1   = 0, phisub2   = 0;
    
}*/
void jet_pars::read_jetpars()
//read jet algorithm parameters and save in pars
{
   
   //open file data/trimming_parameters.dat and plot the best Rsub and fcut
   ifstream trimpara_file(trimming_par_file, ios::in);
   if (!trimpara_file)
   {
      cout << " error openning file " <<  trimming_par_file << endl;
      return;
   }
   while (!trimpara_file.eof())
   {
      double pt, R, maxsig, maxRsub, maxfcut, njets_ww, njets_wj, maxnsig, maxnbg;
      trimpara_file >> pt >> R >> maxsig >> maxRsub >> maxfcut >> njets_ww >> njets_wj >> maxnsig >> maxnbg;
      if (trimpara_file.eof()) break;
      if (fabs(R - 1.2) < 0.001) 
      {
         int ipt = cal_ipt(pt);
         Rsub[ipt] = maxRsub;
         fcut[ipt] = maxfcut;
      }
   }
   trimpara_file.close();


   //open file filter_parameters.dat and plot the best Rsub and fcut
   ifstream filterpara_file(filtering_par_file, ios::in);
   if (!filterpara_file)
   {
      cout << " error openning file " << filtering_par_file << endl;
      return;
   }
 
   while (!filterpara_file.eof())
   {
      double pt, R, maxsig, maxmu, maxycut, njets_ww, njets_wj, maxnsig, maxnbg;
      filterpara_file >> pt >> R >> maxsig >> maxmu >> maxycut >> njets_ww >> njets_wj >> maxnsig >> maxnbg;
      
      if (filterpara_file.eof()) break;
      if (fabs(R - 1.2) < 0.001) 
      {
         int ipt = cal_ipt(pt);
         mu[ipt] = maxmu;
         ycut[ipt] = maxycut;
         filtering_es[ipt] = maxnsig*1./njets_ww;
         filtering_eb[ipt] = maxnbg*1./njets_wj;
         filtering_sig[ipt] = maxsig;
      }
   }
   filterpara_file.close();
  
   //open file pruning_parameters.dat and read the best Rsub and fcut
   ifstream prunepara_file(pruning_par_file, ios::in);
   if (!prunepara_file)
   {
      cout << " error openning file " << pruning_par_file << endl;
      return;
   }
   
   while (!prunepara_file.eof())
   {
      double pt, R, maxsig, maxRcut, maxzcut, njets_ww, njets_wj, maxnsig, maxnbg;
      prunepara_file >> pt >> R >> maxsig >> maxRcut >> maxzcut >> njets_ww >> njets_wj >> maxnsig >> maxnbg;
      
      if (prunepara_file.eof()) break;
      if (fabs(R - 1.2) < 0.001) 
      {
         int ipt = cal_ipt(pt);
        
         Rcut[ipt] = maxRcut;
         zcut[ipt] = maxzcut;
      }
   }
   prunepara_file.close();
           
   //read BDT cuts corresponding to the best significance
   ifstream bdtcuts_file(bdtcut_filename, ios::in);
   if (!bdtcuts_file) 
   {
      cout << "Error opening BDT cut file" << endl;
      exit(0);
   }
   for (int i = 0; i < NPT; i ++)
   {
      double sig, eS, eB;
      bdtcuts_file >> bdtcuts_opt_es[i] >> bdtcuts_opt_eb[i] >> bdtcuts_opt_sig[i] >> bdtcuts_opt[i];    
   }
   bdtcuts_file.close();

   //read BDT cuts as a function of signal efficiency
      
   
   ifstream bdteffs_file(bdteff_filename, ios::in);
   if (!bdteffs_file)
   {
      cout << "Error opeining BDT eff file" << endl;
      exit(0);
   }
   while (!bdteffs_file.eof())
   {
      double pt, eS, eB, sig, bdtvalue;
      bdteffs_file >> pt >> eS >> eB >> sig >> bdtvalue;
      if (bdteffs_file.eof()) break;
      int ipt = cal_ipt(pt);
      int ieff = cal_ieff(eS);
      bdtcuts_es[ipt][ieff] = eS;
      bdtcuts_eb[ipt][ieff] = eB;
      bdtcuts_sig[ipt][ieff] = sig;  
      bdtcuts[ipt][ieff] = bdtvalue;
   }

   
   initiated = true;
}



void copy_momentum(PseudoJet &jet, double p[])
{
   p[0] = jet.e();
   p[1] = jet.px();
   p[2] = jet.py();
   p[3] = jet.pz();
}

double cosmd(double * pmother, double *pdaughter)
{
   TLorentzVector mother(pmother[1], pmother[2], pmother[3], pmother[0]);
   TLorentzVector daughter(pdaughter[1], pdaughter[2], pdaughter[3], pdaughter[0]);
   TVector3 boost;
   boost = - mother.BoostVector();
   daughter.Boost(boost);
   TVector3 v3mother(mother.Px(), mother.Py(), mother.Pz());
   TVector3 v3daughter(daughter.Px(), daughter.Py(), daughter.Pz());

   double temp;
   temp = cos(v3daughter.Angle(v3mother));
   return temp;
}



void print_momentum(double p[4])
{
   cout << p[0] << "  " << p[1] << "  " << p[2] << "  " << p[3] << endl;
}


double invmass( PseudoJet &j1, PseudoJet &j2)
{
   double q[4];
   q[0] = j1.E() + j2.E();
   q[1] = j1.px() + j2.px();
   q[2] = j1.py() + j2.py();
   q[3] = j1.pz() + j2.pz();
   return sqrt(dot(q, q));
}

double PT(double p[])
{
   return sqrt(p[1]*p[1] + p[2]*p[2]);
}

double invmass(vector<PseudoJet> &j1, vector<PseudoJet> &j2)
{
   double q[4];
   for (int i = 0; i < 4; i ++) q[i] =0;
   for (int i = 0; i < j1.size(); i ++)
   {
      q[0] += j1[i].E();
      q[1] += j1[i].px();
      q[2] += j1[i].py();
      q[3] += j1[i].pz();
   }

   for (int i = 0; i < j2.size(); i ++)
   {
      q[0] += j2[i].E();
      q[1] += j2[i].px();
      q[2] += j2[i].py();
      q[3] += j2[i].pz();
   }
   return sqrt(dot(q, q));
}
void pfrometaphiptm(double *p, double eta, double phi, double pt, double m)
//obtain p[4] from eta, phi, pt, m
{
   double px, py, pz, e;

   px = pt*cos(phi);
   py = pt*sin(phi);
   pz = pt*sinh(eta);
   //p = pt*cosh(eta);
   e  = sqrt(px*px + py*py + pz*pz + m*m);

   p[0] = e;
   p[1] = px;
   p[2] = py;
   p[3] = pz;
}

double dR(PseudoJet &jet1, PseudoJet &jet2)
{
   //calculate the distance between two jets
   double  deltaR, dy, dphi, y1, y2, phi1, phi2;
   y1 = jet1.rap();
   y2 = jet2.rap();
   phi1 = jet1.phi();
   phi2 = jet2.phi();
   dphi = fabs(phi1 - phi2);
   if (dphi > PI) dphi = 2*PI - dphi; 
   dy = y1 - y2;
   deltaR = sqrt(dphi*dphi + dy*dy); 
  
   return deltaR;
}


void pull(fastjet::ClusterSequence & clustSeq, fastjet::PseudoJet &jet, double p[2])
{
   //calculate pull as a two-vector
   vector <fastjet::PseudoJet> cons = clustSeq.constituents(jet);
   p[0] = 0;
   p[1] = 0;
   double ptjet, yjet, phijet;
   ptjet = jet.perp();
   yjet  = jet.rapidity();
   phijet= jet.phi_std();
   for (int i = 0; i < cons.size(); i ++)
   {
      double dy, dphi, ptpar, dr;
      dy = cons[i].rapidity() - yjet;
      dphi = cons[i].phi_std() - phijet;
      if (dphi > PI) dphi = 2*PI - dphi;
      if (dphi < -PI) dphi = 2*PI + dphi;
      dr = sqrt(dy*dy + dphi*dphi);
      ptpar = cons[i].perp();
      p[0] += ptpar/ptjet*dr*dy;
      p[1] += ptpar/ptjet*dr*dphi;  
   }     
}  

double pull_angle(ClusterSequence & clustSeq, PseudoJet &jet, double axis[2])
{
  
   double p[2];
   pull(clustSeq, jet, p);
   double asize, psize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);
   psize = sqrt(p[0]*p[0] + p[1]*p[1]);
   double angle = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize));
   //cout << " angle = " << angle << endl;
   return angle;
}

double pull_angle_beam(ClusterSequence & clustSeq, PseudoJet &jet)
{
   double axis[2];
   axis[0] = 1.;
   axis[1] = 0.;
   double p[2];
   pull(clustSeq, jet, p);
   double asize, psize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);
   psize = sqrt(p[0]*p[0] + p[1]*p[1]);
   
   double angle;
   if (asize*psize < 1e-10) angle = -0.01;
   else angle = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize));
   
   return angle;
}

void find_axis(PseudoJet &jet1, PseudoJet &jet2, double axis[2])
{

  axis[0] = jet2.rapidity() - jet1.rapidity();
  axis[1] = jet2.phi_std() - jet1.phi_std();
}
double planar_flow(ClusterSequence & clustSeq, PseudoJet &jet)
{
   double I[3][3];
   for (int i = 0; i < 3; i ++) for (int j = 0; j < 3; j ++) I[i][j] = 0;

   TVector3 zaxis(jet.px(), jet.py(), jet.pz());
   zaxis *= 1/zaxis.Mag();
   TVector3 zbeam(0, 0, 1);
   TVector3 xaxis = zaxis.Cross(zbeam);
   xaxis *= 1/xaxis.Mag();
   
   TVector3 yaxis = xaxis.Cross(zaxis);
   yaxis *= 1/yaxis.Mag();

   double mJ = jet.m();
   vector<PseudoJet> cons = clustSeq.constituents(jet);
   for (int i = 0; i < cons.size(); i ++)
   {
      double px, py, e;
      TVector3 vcons(cons[i].px(), cons[i].py(), cons[i].pz());
      px = vcons.Dot(xaxis);
      py = vcons.Dot(yaxis);
      e  = cons[i].e();
      I[1][1] += px*px/(e*mJ);
      I[1][2] += px*py/(e*mJ);
      I[2][1] += py*px/(e*mJ);
      I[2][2] += py*py/(e*mJ);
   }   
  
   double pf = 4*(I[1][1]*I[2][2] - I[1][2]*I[2][1])/((I[1][1]+I[2][2])*(I[1][1]+I[2][2]));
   
   return pf;

}

double pull_angle(ClusterSequence & clustSeq, PseudoJet &jet1, PseudoJet &jet2)
{
   double p[2];
   pull(clustSeq, jet1, p);

   double axis[2];
   find_axis(jet1, jet2, axis);

   double asize, psize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);
   psize = sqrt(p[0]*p[0] + p[1]*p[1]);
   double angle;
   if (asize*psize < 1e-10) angle = -0.01;
   else angle = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize));
   
   return angle;
}

void pull_angle_size(ClusterSequence & clustSeq, PseudoJet &jet1, PseudoJet &jet2, double & pangle, double &psize)
{
   double p[2];
   pull(clustSeq, jet1, p);

   double axis[2];
   find_axis(jet1, jet2, axis);

   double asize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);   
   psize = sqrt(p[0]*p[0] + p[1]*p[1]);
  
   
   if (asize*psize < 1e-10) pangle = -0.01;
   else pangle = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize));
   
   //cout << " angle = " << angle << endl;
   
}

void pull_angle_size(ClusterSequence & clustSeq, PseudoJet &jet1, PseudoJet &jet2, double & pangle1, double & psize1, double &pangle2, double &psize2)
{
   double p[2];
   pull(clustSeq, jet1, p);
   double axis[2];
   find_axis(jet1, jet2, axis);

   double asize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);   
   Float_t psizesq = p[0]*p[0] + p[1]*p[1];
   if (psizesq > 0) psize1 = sqrt(psizesq);
   else psize1 = 0;
   
   
   if (asize*psize1 < 1e-10) pangle1 = - 0.01;
   else pangle1 = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize1));
   
   pull(clustSeq, jet2, p);
   find_axis(jet2, jet1, axis);
   psizesq = p[0]*p[0] + p[1]*p[1];
   if (psizesq > 0) psize2 = sqrt(psizesq);
   else psize2 = sqrt(psizesq);
   if (asize*psize2 < 1e-10) pangle2 = - 0.01;
   else pangle2 = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize2));
   
}

void combine_jets(ClusterSequence &clustSeq, vector<PseudoJet> & jets, ClusterSequence &combined_seq)
{
    
    vector<PseudoJet> allcons;
    for (int i = 0; i < jets.size(); i ++)
    {
       vector<PseudoJet> cons = clustSeq.constituents(jets[i]);
       for (int j = 0; j < cons.size(); j ++)
          allcons.push_back(cons[j]);
    }
    
    Strategy               strategy = Best;
    RecombinationScheme    recombScheme = E_scheme;
    JetDefinition         *jetDef = NULL;
    double R = pi;
    double p = 1;
    jetDef = new JetDefinition(ee_genkt_algorithm, R, p, recombScheme, strategy);
    ClusterSequence combined(allcons, *jetDef);
    combined_seq = combined;
    delete jetDef;
} 




vector<PseudoJet> resolve(ClusterSequence &clusSeq, PseudoJet & jet, ClusterSequence &resolved_seq, double Rfilt)
{
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   jetDef = new JetDefinition(cambridge_algorithm, Rfilt,
                                      recombScheme, strategy);
  
   vector<PseudoJet> cons = clusSeq.constituents(jet);
   ClusterSequence tempseq(cons, *jetDef);
   resolved_seq = tempseq;
   vector<PseudoJet> inclusiveJets = resolved_seq.inclusive_jets();
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   delete jetDef;
   return sortedJets;
}

vector<PseudoJet> filter(ClusterSequence &clusSeq, PseudoJet jet,  ClusterSequence & filtered_seq, double mu = 0.67, double ycut = 0.1)
//filtering procedure defined in arXiv:0802.2470
{
   
   PseudoJet parent1, parent2;
 
   double dr = 0.3;
   
   bool hasparent = clusSeq.has_parents(jet, parent1, parent2);
   bool found_heavy = false;
   while (hasparent)
   {
      double m, m1, m2;
      m = jet.m();
      m1 = parent1.m();
      m2 = parent2.m();
      
      dr = dR(parent1, parent2);
      double y = min(parent1.perp2(), parent2.perp2())/jet.m2()*dr*dr;
      if (m2 > m1) 
      {
         m1 = m2;
         parent1 = parent2;
      }
      if (m1 < mu*m && y > ycut) 
      {
	 found_heavy = true;
         break;  
      }
      jet = parent1;
      hasparent = clusSeq.has_parents(jet, parent1, parent2);
   }
   vector<PseudoJet> filtered;
   filtered.resize(0);
   if (found_heavy) return resolve(clusSeq, jet, filtered_seq, min(0.3, dr/2.));   
   else return filtered;
}

vector<PseudoJet> trim(ClusterSequence &clusSeq, PseudoJet &jet, ClusterSequence & trimmed_seq, double Rsub = 0.2, double fcut = 0.03, int jet_algorithm = 0)
//trimming defined in arXiv:0912.1342
{
   
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   if (jet_algorithm == 0) jetDef = new JetDefinition(kt_algorithm, Rsub,
                                      recombScheme, strategy);
   else if (jet_algorithm == 1) jetDef =  new JetDefinition(cambridge_algorithm, Rsub,
                                      recombScheme, strategy);
   
   vector<PseudoJet> cons = clusSeq.constituents(jet);
   ClusterSequence temp_seq(cons, *jetDef);
  
   double ptcut = fcut*jet.perp();
   vector<PseudoJet> inclusiveJets = temp_seq.inclusive_jets(ptcut);
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   trimmed_seq = temp_seq;
   delete jetDef;
   return sortedJets;

}

vector<PseudoJet> trim_h(ClusterSequence &clusSeq, PseudoJet &jet, ClusterSequence & trimmed_seq, double H, double Rsub = 0.2, double fcut = 0.005)
//trimming defined in arXiv:0912.1342
//trim fcut*H
{
   
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   jetDef = new JetDefinition(kt_algorithm, Rsub,
                                      recombScheme, strategy);
   
   vector<PseudoJet> cons = clusSeq.constituents(jet);
   ClusterSequence temp_seq(cons, *jetDef);
  
   double ptcut = fcut*H;
   vector<PseudoJet> inclusiveJets = temp_seq.inclusive_jets(ptcut);
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   trimmed_seq = temp_seq;
   delete jetDef;
   return sortedJets;

}

PseudoJet trim_h(ClusterSequence &clusSeq, PseudoJet &jet, double H, double Rsub = 0.2, double fcut = 0.03)
//trimming defined in arXiv:0912.1342
//combine the trimmed sequence to a single jet
{
   ClusterSequence trimmed_seq;
   vector <PseudoJet> trimmed = trim_h(clusSeq, jet, trimmed_seq, H, Rsub, fcut);
   ClusterSequence combined_seq;
   combine_jets(trimmed_seq, trimmed, combined_seq);

   vector<PseudoJet> inclusiveJets = combined_seq.inclusive_jets();
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   return sortedJets[0];

}

PseudoJet trim(ClusterSequence &clusSeq, PseudoJet &jet, double Rsub = 0.2, double fcut = 0.03)
//trimming defined in arXiv:0912.1342
//combine the trimmed sequence to a single jet
{
   ClusterSequence trimmed_seq;
   vector <PseudoJet> trimmed = trim(clusSeq, jet, trimmed_seq, Rsub, fcut);
   ClusterSequence combined_seq;
   combine_jets(trimmed_seq, trimmed, combined_seq);

   vector<PseudoJet> inclusiveJets = combined_seq.inclusive_jets();
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   return sortedJets[0];

}
vector<PseudoJet> prune(ClusterSequence &clusSeq, PseudoJet &jet, ClusterSequence &pruned_seq, double R = 1.5, double zcut = 0.1, double Rcut_factor = 0.5, int jet_algorithm = 1)
// Rcut = 2*(m/pT)*RCUT_FACTOR for now; might add other options

{
   JetAlgorithm jetalg;
   if (jet_algorithm == 0) jetalg = kt_algorithm;
   else if (jet_algorithm == 1) jetalg = cambridge_algorithm;
/*   //fast prune init
   //const JetDefinition JET_DEF(kt_algorithm, R, Best);
   //const JetDefinition JET_DEF_BIGR(kt_algorithm, 0.5*pi, JET_DEF.recombination_scheme(), JET_DEF.strategy());
   const JetDefinition JET_DEF(jetalg, R, Best);
   const JetDefinition JET_DEF_BIGR(jetalg, 0.5*pi, JET_DEF.recombination_scheme(), JET_DEF.strategy());
   FastPrunePlugin *PRplugin = new FastPrunePlugin(JET_DEF, JET_DEF_BIGR, zcut, Rcut_factor);
   JetDefinition pruned_def(PRplugin);
   
   vector<PseudoJet> cons = clusSeq.constituents(jet);
  
   ClusterSequence temp_seq(cons, pruned_def);
   vector<PseudoJet> pruned_jets = temp_seq.inclusive_jets(10.0);
   vector<PseudoJet> sortedJets  = sorted_by_pt(pruned_jets); 
   pruned_seq = temp_seq;
   delete PRplugin;
   return sortedJets;
*/

   Pruner pruner(jetalg, zcut, Rcut_factor);
   return vector<PseudoJet>(1, pruner(jet));
}


vector<PseudoJet> recluster(ClusterSequence &clusSeq, vector<PseudoJet> &jets, ClusterSequence & trimmed_seq, double Rsub = 0.2, int jet_algorithm = 0)
//recluster a vector of jets using Rsub
{
   
   
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   if (jet_algorithm == 0) jetDef = new JetDefinition(kt_algorithm, Rsub,
                                      recombScheme, strategy);
   else if (jet_algorithm == 1) jetDef = new JetDefinition(cambridge_algorithm, Rsub,
                                      recombScheme, strategy);
   vector<PseudoJet> inputs;
   for (int i = 0; i < jets.size(); i ++)
   {   
      vector<PseudoJet> cons = clusSeq.constituents(jets[i]);
      for (int j = 0; j < cons.size(); j ++)
         inputs.push_back(cons[j]);
   }         
   ClusterSequence temp_seq(inputs, *jetDef);
  
   vector<PseudoJet> inclusiveJets = temp_seq.inclusive_jets();
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   trimmed_seq = temp_seq;
   delete jetDef;
   return sortedJets;

}

vector<PseudoJet> recluster(ClusterSequence &clusSeq, PseudoJet &jet, ClusterSequence & trimmed_seq, double Rsub = 0.2, int jet_algorithm = 0)
//recluster a vector of jets using Rsub
{
   
   
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   if (jet_algorithm == 0) jetDef = new JetDefinition(kt_algorithm, Rsub,
                                      recombScheme, strategy);
   else if (jet_algorithm == 1) jetDef = new JetDefinition(cambridge_algorithm, Rsub,
                                      recombScheme, strategy);
   vector<PseudoJet> inputs;
   vector<PseudoJet> cons = clusSeq.constituents(jet);
   for (int j = 0; j < cons.size(); j ++)
      inputs.push_back(cons[j]);
            
   ClusterSequence temp_seq(inputs, *jetDef);
  
   vector<PseudoJet> inclusiveJets = temp_seq.inclusive_jets();
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   trimmed_seq = temp_seq;
   delete jetDef;
   return sortedJets;

}

vector<PseudoJet> cluster(vector<PseudoJet> & inputs, ClusterSequence & cluster_seq, double R, int jet_algorithm = 0)
//recluster a vector of jets using Rsub
{
   
   
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   if (jet_algorithm == 0) 
      jetDef = new JetDefinition(kt_algorithm, R, recombScheme, strategy);
   else if (jet_algorithm == 1)
     jetDef = new JetDefinition(cambridge_algorithm, R, recombScheme, strategy);
  
   ClusterSequence temp_seq(inputs, *jetDef);
  
   vector<PseudoJet> inclusiveJets = temp_seq.inclusive_jets();
   vector<PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   cluster_seq = temp_seq;
   delete jetDef;
   return sortedJets;

}



void pull_angle_size(ClusterSequence & clustSeq1, vector<PseudoJet> &jets1, ClusterSequence & clustSeq2, vector<PseudoJet> &jets2, Float_t & pangle, Float_t &psize)
{
   ClusterSequence combi_seq_1;  
   combine_jets(clustSeq1, jets1, combi_seq_1);
   ClusterSequence combi_seq_2;  
   combine_jets(clustSeq2, jets2, combi_seq_2);
   
   vector<PseudoJet> inclusiveJets1 = combi_seq_1.inclusive_jets();
   vector<PseudoJet> sortedJets1    = sorted_by_pt(inclusiveJets1); 
   vector<PseudoJet> inclusiveJets2 = combi_seq_2.inclusive_jets();
   vector<PseudoJet> sortedJets2    = sorted_by_pt(inclusiveJets2);
   
   pangle = -1.;
   psize  = -1.;
   if (sortedJets1.size() != 1 || sortedJets2.size() != 1) 
   { 
      cout << "should have 1 jet after combination" << endl;
      return;
   } 

   double p[2];
   pull(combi_seq_1, sortedJets1[0], p);

   double axis[2];
   find_axis(sortedJets1[0], sortedJets2[0], axis);

   double asize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);
   psize = sqrt(p[0]*p[0] + p[1]*p[1]);
   if (asize*psize < 10e-10) pangle = - 0.01;
   else pangle = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize));   
}

void pull_angle_size(ClusterSequence & clustSeq1, PseudoJet &jet1, ClusterSequence & clustSeq2, PseudoJet &jet2, Float_t & pangle, Float_t &psize)
{
   pangle = -1.;
   psize  = -1.;
 

   double p[2];
   pull(clustSeq1, jet1, p);

   double axis[2];
   find_axis(jet1, jet2, axis);

   double asize;
   asize = sqrt(axis[0]*axis[0] + axis[1]*axis[1]);
   psize = sqrt(p[0]*p[0] + p[1]*p[1]);
   if (asize*psize < 10e-10) pangle = - 0.01;
   else  pangle = acos((p[0]*axis[0] + p[1]*axis[1])/(asize*psize));   
}


bool jet_mvars::get_mvars(ClusterSequence &clustSeq, PseudoJet &jet, jet_pars &jetpars)
{
    
    mass = jet.m();
    pt   = jet.perp();
    
    double mu, ycut, Rsub, fcut, Rcut, zcut;
    
    mu   = jetpars.get_mu(pt);
    ycut = jetpars.get_ycut(pt);
    Rsub = jetpars.get_Rsub(pt);
    fcut = jetpars.get_fcut(pt);
    Rcut = jetpars.get_Rcut(pt);
    zcut = jetpars.get_zcut(pt);
    
    //filter 
    ClusterSequence reclust_seq;
    vector <PseudoJet> reclustered;
    reclustered = recluster(clustSeq, jet, reclust_seq, 1.5, 1);
    ClusterSequence filtered_seq;
    vector <PseudoJet> filtered = filter(reclust_seq, reclustered[0], filtered_seq, mu, ycut);
    double ptot[4];
    for (int ip = 0; ip < 4; ip ++) ptot[ip] = 0;
    for (int j = 0; j < filtered.size() && j < 3; j ++)
    {
        ptot[0] += filtered[j].e();
        ptot[1] += filtered[j].px();
        ptot[2] += filtered[j].py();
        ptot[3] += filtered[j].pz();
    }

    double massfiltersq = dot(ptot, ptot);    
    if (massfiltersq > 1e-10 ) massfilter = sqrt(massfiltersq);
    else massfilter = 0;  
    ptfilter = sqrt(ptot[1]*ptot[1] + ptot[2]*ptot[2]);
    for (int j = 0; j < 4; j ++) pfilter[j] = ptot[j];
    
    if (massfilter < 60 || massfilter > 100) return false;

  
    planarflow = planar_flow(clustSeq, jet);

    //trim          
    ClusterSequence  trimmed_seq;
    vector<PseudoJet> trimmed = trim(clustSeq, jet, trimmed_seq, Rsub, fcut);  

    for (int ip = 0; ip < 4; ip ++) ptot[ip] = 0;
    for (int j = 0; j < trimmed.size(); j ++)
    {
        ptot[0] += trimmed[j].e();
        ptot[1] += trimmed[j].px();
        ptot[2] += trimmed[j].py();
        ptot[3] += trimmed[j].pz();
    }
    double masstrimsq = dot(ptot, ptot);
    if (masstrimsq > 1e-10) masstrim = sqrt(masstrimsq);
    else masstrim = 0;
    pttrim   = sqrt(ptot[1]*ptot[1] + ptot[2]*ptot[2]);
             
    //prune 
    ClusterSequence  pruned_seq;
    vector<PseudoJet> pruned = prune(clustSeq, jet, pruned_seq, 1.5, zcut, Rcut); 
    for (int ip = 0; ip < 4; ip ++) ptot[ip] = 0;
    for (int j = 0; j < pruned.size(); j ++)
    {
        ptot[0] += pruned[j].e();
        ptot[1] += pruned[j].px();
        ptot[2] += pruned[j].py();
        ptot[3] += pruned[j].pz();
    }
    double massprunesq = dot(ptot, ptot);
    if (massprunesq > 1e-10 ) massprune = sqrt(massprunesq);
    else massprune = 0;  
    ptprune = sqrt(ptot[1]*ptot[1] + ptot[2]*ptot[2]);
    


    //jetmass and pt for R = 0.2 to R = 1.1
    ClusterSequence reclustSeq;

    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.2, 1);
    mass2 = reclustered[0].m();
    pt2   = reclustered[0].perp();
               
    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.3, 1);
    mass3 = reclustered[0].m();
    pt3   = reclustered[0].perp();

    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.4, 1);
    mass4 = reclustered[0].m();
    pt4   = reclustered[0].perp();
    if (mass4 > 0.1)
       planarflow4 = planar_flow(reclust_seq, reclustered[0]);
    else 
       planarflow4 = 0;
      

    if (planarflow4 < 1e-10) planarflow4 = 0;
    if (planarflow < 1e-10) planarflow  = 0;
    
    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.5, 1);
    mass5 = reclustered[0].m();
    pt5   = reclustered[0].perp();
    
    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.6, 1);
    mass6 = reclustered[0].m();
    pt6   = reclustered[0].perp();

    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.7, 1);
    mass7 = reclustered[0].m();
    pt7   = reclustered[0].perp();

    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.8, 1);
    mass8 = reclustered[0].m();
    pt8   = reclustered[0].perp();
    
    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 0.9, 1);
    mass9 = reclustered[0].m();
    pt9   = reclustered[0].perp();
    
    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 1.0, 1);
    mass10 = reclustered[0].m();
    pt10   = reclustered[0].perp();

    reclustered.resize(0);
    reclustered =  recluster(clustSeq, jet, reclust_seq, 1.1, 1);
    mass11 = reclustered[0].m();
    pt11   = reclustered[0].perp();

    
    //variables related to subjets          
    //number of subjets with pt > 10 
    int nsubjets_all = filtered.size();
    nsubjets = 0;
    for (int isubjet = 0; isubjet < nsubjets_all; isubjet ++)
    {
        if (filtered[isubjet].perp() > 10.) 
           nsubjets ++;
        else break;   
    } 

    if (nsubjets >= 2)
    {
      
       rapsub1 = filtered[0].rapidity();
       rapsub2 = filtered[1].rapidity();
       phisub1 = filtered[0].phi();
       phisub2 = filtered[1].phi();
      
       ptratio = filtered[1].perp()/filtered[0].perp();
       	         
      
       pangle1 = 0; pangle2 = 0; psize1 = 0; psize2 = 0;
       pull_angle_size(filtered_seq, filtered[0], filtered[1], pangle1, psize1, pangle2, psize2);

       subjetdR = dR(filtered[0], filtered[1]);

       ptsub1 = filtered[0].perp();
       masssub1 = filtered[0].m();
       ptsub2 = filtered[1].perp();
       masssub2 = filtered[1].m();
               
       //boost to W rest frame and look at jetmass
       vector<PseudoJet> temp_inputs, filtered_inputs;
       for (int j = 0; j < 4; j ++) ptot[j] = 0;
       for (int j = 0; j < filtered.size(); j ++)
       {                
           vector <PseudoJet> filtered_cons = filtered_seq.constituents(filtered[j]);
           for (int k = 0; k < filtered_cons.size(); k ++)
           {
               temp_inputs.push_back(filtered_cons[k]);
               ptot[0] += filtered_cons[k].e();
               ptot[1] += filtered_cons[k].px();
               ptot[2] += filtered_cons[k].py();
               ptot[3] += filtered_cons[k].pz();
           }                             
      }
      TLorentzVector v4(ptot[1], ptot[2], ptot[3], ptot[0]);
      TVector3 boost = - v4.BoostVector();
      for (int j = 0; j < temp_inputs.size(); j ++)
      {
          TLorentzVector vcons(temp_inputs[j].px(), temp_inputs[j].py(), temp_inputs[j].pz(), temp_inputs[j].e());
          vcons.Boost(boost);
          PseudoJet tempjet(vcons.Px(), vcons.Py(), vcons.Pz(), vcons.E());
          filtered_inputs.push_back(tempjet);
      }
     
   }
   return true;
}


double BDTvalue(jet_mvars & jetmvars, jet_pars * jetpars_ptr, bool reset = false)
{
   static bool initiated = false;
  
   static TMVA::Reader * reader[NPT];
   static Float_t mass, pt, mass2, pt2, mass3, pt3, mass4, pt4, mass5, pt5;
   static Float_t mass6, pt6, mass7, pt7, mass8, pt8, mass9, pt9, mass10, pt10, mass11, pt11;
   static Float_t masstrim, pttrim, massprune, ptprune, massfilter, ptfilter;
   static Float_t njets;
   static Float_t ptratio, ptsub1, masssub1, ptsub2, masssub2, subjetdR, pangle1, psize1, pangle2, psize2, twist, masswf41, masswf42, masswf151, masswf152;
   static Float_t phisub1, phisub2, rapsub1, rapsub2;
   static Float_t angularity, angularity4, planarflow, planarflow4, helangle;
   static Float_t ptsub3, masssub3;
   static int ptarray[NPT];
   static Float_t massratio110, massratio100, massratio90, massratio80, massratio70, massratio60, massratio50, massratio40;
   static Float_t ptratio110, ptratio100, ptratio90, ptratio80, ptratio70, ptratio60, ptratio50, ptratio40, ptratio30, ptratio20;
   static Float_t filtermassratio, filterptratio;
   static Float_t trimmedmassratio, trimptratio;
   static Float_t prunedmassratio, pruneptratio;
  
   static Float_t subptratio1, subptratio2, subptmassratio1, subptmassratio2;
   
   if (reset)
   {
      for (int i = 0; i < NPT; i ++) 
      { 
         if (reader[i]) delete reader[i];
         initiated = false;
      }
   }
   if (!initiated)
   {
      
      //book TMVA Readers
      
      for (int i = 0; i < NPT; i ++) ptarray[i] = 200 + 50*i;
      for (int i = 0; i < NPT; i ++) 
      {
         reader[i] = new TMVA::Reader( "!Color:Silent" );    
         reader[i]->AddVariable("mass", &mass);
         /*reader[i]->AddVariable("mass11/mass", &massratio110);
         reader[i]->AddVariable("mass10/mass", &massratio100);
         reader[i]->AddVariable("mass9/mass", &massratio90);
         reader[i]->AddVariable("mass8/mass", &massratio80);
         reader[i]->AddVariable("mass7/mass", &massratio70);
         reader[i]->AddVariable("mass6/mass", &massratio60);
         reader[i]->AddVariable("mass5/mass", &massratio50);
         reader[i]->AddVariable("mass4/mass", &massratio40);*/
         reader[i]->AddVariable("pt11/pt", &ptratio110);
         reader[i]->AddVariable("pt10/pt", &ptratio100);
         reader[i]->AddVariable("pt9/pt", &ptratio90);
         reader[i]->AddVariable("pt8/pt", &ptratio80);
         reader[i]->AddVariable("pt7/pt", &ptratio70);
         reader[i]->AddVariable("pt6/pt", &ptratio60);
         reader[i]->AddVariable("pt5/pt", &ptratio50);
         reader[i]->AddVariable("pt4/pt", &ptratio40);
         reader[i]->AddVariable("pt3/pt", &ptratio30);
         reader[i]->AddVariable("pt2/pt", &ptratio20);
         reader[i]->AddVariable("massfilter/mass", &filtermassratio);
         reader[i]->AddVariable("ptfilter/pt", &filterptratio);
         reader[i]->AddVariable("masstrim/mass", &trimmedmassratio);
         reader[i]->AddVariable("pttrim/pt", &trimptratio);
         reader[i]->AddVariable("massprune/mass", &prunedmassratio);
         reader[i]->AddVariable("ptprune/pt", &pruneptratio);         
         reader[i]->AddVariable("planarflow4", &planarflow4);
         reader[i]->AddVariable("planarflow", &planarflow);
         reader[i]->AddVariable("ptsub1/pt", &subptratio1);
         reader[i]->AddVariable("ptsub2/pt", &subptratio2);
         reader[i]->AddVariable("masssub1/pt", &subptmassratio1);
         reader[i]->AddVariable("masssub2/pt", &subptmassratio2);
         reader[i]->AddVariable("subjetdR", &subjetdR);
         reader[i]->AddVariable("njets", &njets);    
      
         char ptlabel[10];
         sprintf(ptlabel, "%d", ptarray[i]);
         //
         // book the MVA methods
         //
         char methodName[200] = "BDT method";
         char weightfile[200];
         
         jetpars_ptr->get_bdtweight_name(200 + 50.*i, weightfile);
         reader[i]->BookMVA(methodName, weightfile); 
       
      } 
      initiated = true;
   }

   mass = jetmvars.mass; pt = jetmvars.pt; 
   mass2 = jetmvars.mass2; pt2 = jetmvars.pt2; mass3 = jetmvars.mass3; pt3 = jetmvars.pt3;
   mass4 = jetmvars.mass4; pt4 = jetmvars.pt4; mass5 = jetmvars.mass5; pt5 = jetmvars.pt5;
   mass6 = jetmvars.mass6; pt6 = jetmvars.pt6; mass7 = jetmvars.mass7; pt7 = jetmvars.pt7;
   mass8 = jetmvars.mass8; pt8 = jetmvars.pt8; mass9 = jetmvars.mass9; pt9 = jetmvars.pt9;
   mass10 = jetmvars.mass10; pt10 = jetmvars.pt10; mass11 = jetmvars.mass11; pt11 = jetmvars.pt11;
   
   masstrim = jetmvars.masstrim; pttrim = jetmvars.pttrim; massprune = jetmvars.massprune;
   ptprune = jetmvars.ptprune; massfilter = jetmvars.massfilter; ptfilter  = jetmvars.ptfilter;
   njets = jetmvars.nsubjets; ptratio = jetmvars.ptratio; 

   ptsub1 = jetmvars.ptsub1;
   masssub1 = jetmvars.masssub1; ptsub2 = jetmvars.ptsub2; masssub2 = jetmvars.masssub2;
   subjetdR = jetmvars.subjetdR; pangle1 = jetmvars.pangle1; psize1 = jetmvars.psize1; 
   pangle2 = jetmvars.pangle2; psize2 = jetmvars.psize2;
   phisub1 = jetmvars.phisub1; rapsub1 = jetmvars.rapsub1;
   phisub2 = jetmvars.phisub2; rapsub2 = jetmvars.rapsub2;

 
   planarflow = jetmvars.planarflow; planarflow4 = jetmvars.planarflow4;
   
  

   massratio110 = mass11/mass;
   massratio100 = mass10/mass;
   massratio90 = mass9/mass;
   massratio80 = mass8/mass;
   massratio70 = mass7/mass;
   massratio60 = mass6/mass;
   massratio50 = mass5/mass;
   massratio40 = mass4/mass;
   ptratio110 = pt11/pt;
   ptratio100 = pt10/pt;
   ptratio90 = pt9/pt;
   ptratio80 = pt8/pt;
   ptratio70 = pt7/pt;
   ptratio60 = pt6/pt;
   ptratio50 = pt5/pt;
   ptratio40 = pt4/pt;
   ptratio30 = pt3/pt;
   ptratio20 = pt2/pt;
   filtermassratio = massfilter/mass;
   filterptratio   = ptfilter/pt;
   trimmedmassratio = masstrim/mass;
   trimptratio   = pttrim/pt;
   prunedmassratio = massprune/mass;
   pruneptratio   = ptprune/pt;
   subptratio1 = ptsub1/pt;
   subptratio2 = ptsub2/pt;
   subptmassratio1 = masssub1/pt;
   subptmassratio2 = masssub2/pt;
   
   
   
   Float_t v;
   int ipt = cal_ipt(pt);
  
   v = reader[ipt]->EvaluateMVA("BDT method");
   return v;
}


bool wtag(ClusterSequence & clustSeq, PseudoJet & jet, double signal_eff, jet_pars * jetpars_ptr)
{
   static bool initiated = false;
   static jet_pars jet_pars_default;
   static bool jet_pars_initiated = false;
   
   if (!initiated)
   {
      
      cout << "***********************************************************" << endl;
      cout << "*            Multivariate W-jet tagging                   *" << endl;
      cout << "*                                                         *" << endl;
      cout << "*  Written by Yanou Cui, Zhenyu Han and Matthew Schwartz  *" << endl;
      cout << "*  Reference: arXiv:1012.                             *" << endl;
      cout << "*  Version: 1.00                                          *" << endl; 
      cout << "*  http://jets.physics.harvard.edu/wtag                   *" << endl;
      cout << "***********************************************************" << endl;
      cout << endl;
      initiated = true;
   } 
  
   if (jetpars_ptr == NULL && jet_pars_initiated == false)
   {
      jet_pars_default.read_jetpars();
      jet_pars_initiated = true;
   }
   
   if (jetpars_ptr == NULL) jetpars_ptr = &jet_pars_default;

   jet_mvars jetmvars;
   jetmvars.get_mvars(clustSeq, jet, *jetpars_ptr);    

   
   if (jetmvars.massfilter > 100 || jetmvars.massfilter < 60) return false; //pass filtered mass cut 


   double v = BDTvalue(jetmvars, jetpars_ptr);
   int ipt = cal_ipt(jetmvars.pt); 

   double bdtcut;
   double filter_eff = jetpars_ptr->get_filtering_es(jetmvars.pt);
   if (signal_eff > filter_eff) 
   {
      cout << "Error: signal efficiency cannot be larger than filtering efficiency. " << endl;
      cout << "efficiency(filtering) = " << filter_eff << "   efficiency requested = " << signal_eff << endl;
      cout << "reset signal efficiency to " << filter_eff << "." << endl;
      signal_eff = filter_eff;
   }
   double bdteff = signal_eff/filter_eff;
   if (bdteff > .999) bdteff = .999;
   if (signal_eff < 0) bdtcut = jetpars_ptr->get_bdtcut_opt(jetmvars.pt);
   else bdtcut = jetpars_ptr->get_bdtcut(jetmvars.pt, bdteff);
   if (v > bdtcut) return true;
   else return false;
 
}

} // namespace Wtag
