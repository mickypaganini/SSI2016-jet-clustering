/////////////////////////////////////////////////////////////////////
//
//  The following code can be used for phenomenological analyses that make
//  use of the angular correlation function and angular structure function
//  introduced in 'Jet Substructure Without Trees', arXiv:hep-ph/1104.1646,
//  M. Jankowiak and A.J. Larkoski.  
//
//  Some (not terribly large) amount of effort has been put into optimizing the code.  
//  In particular the Gaussian kernel in the angular structure function is approximated
//  by a lookup table, which the user should initialize only once.  Needless to say,
//  optimum efficiency has not been achieved.  
//
//  This code makes use of the FastJet package (M. Cacciari, G.P. Salam,
//  G. Soyez; www.fastjet.fr) and has been tested with release 2.4.2. 
//
//  The following sample code illustrates some of the features of the two classes
//  introduced: ACF (angular correlation function) and ASF (angular structure function).
//
//
//  #include "AngularCorrelation.cc"
//
//  // suppose you have a PseudoJet myjet associated with a ClusterSequence mycs
//  ACF myacf(mycs, myjet, false);  // the constructor for the angular correlation function
//  // now that we have the (unnormalized) myacf we can print out the function
//  // note that the mesh size is set in AngularCorrelation.hh  
//  for (int k=0; k<meshsize; k++)
//  {
//  printf("G(%f)=%f\n", myacf.Function.Rvals[k], myacf.Function.fvals[k]);
//  }
//
//  // the Gaussian kernel used in calculating the angular structure function uses
//  // a lookup table which must be initialized (this should only be done once) 
//  GaussTable mygausstable; 
//  // now we can initalize an angular structure function object, setting the width
//  // of the Gaussian kernel to 0.06/sqrt(2) and using the erf denominator 
//  ASF myasf(mycs, myjet, mygausstable, 0.06, true);
//  // as above we can access the function directly
//  for (int k=0; k<meshsize; k++)
//  {
//  printf("DG(%f)=%f\n", myasf.Function.Rvals[k], myasf.Function.fvals[k]);
//  }
//  // but the angular structure function class also has several support functions
//  // for example we can access all the peaks with a prominence >= 4.0
//  vector<peak> mypeaks = myasf.GetRSortedPeaksMinProm(4.0);
//  printf("the ASF has a total of %d peaks with prominence >= 4.0",(int)mypeaks.size());
//  for (int k=0; k<(int)mypeaks.size(); k++)
//  {
//  printf("the ASF has a peak at R=%f with prominence=%f\n", mypeaks[k].Rval, mypeaks[k].prominence);
//  }
//
/////////////////////////////////////////////////////////////////////

#include "AngularCorrelation.hh"
#include <stdio.h>
// added CKV
using namespace std;

/////////////////   Angular Structure Function   ////////////////////
//
//  initialize angular structure function with dR setting the width of the Gaussian kernel
//  and the width of the error function, if 'erf' is true (otherwise the denominator
//  uses a step function

ASF::ASF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet,\
                                   GaussTable mygausstable, double dR, bool erf)
{
_cells = mycs.constituents(myjet);
_nparticles = (int) _cells.size();
_dR=dR;

ConstructASF(mygausstable, erf, 0.0);
FindPeaks();
SetProminences();
CalculatePartialMasses();
}  // end ASF constructor

// same as above, except the user explicitly passes a vector of PseudoJets
ASF::ASF(vector<fastjet::PseudoJet> myjets, GaussTable mygausstable, double dR, bool erf)
{
for (int k=0; k<(int)myjets.size(); k++) _cells.push_back(myjets[k]);
_nparticles = (int)_cells.size();
_dR=dR;

ConstructASF(mygausstable, erf, 0.0);
FindPeaks();
SetProminences();
CalculatePartialMasses();
}  // end ASF constructor

// the user can specify the R_max up to which the asf is calculated
ASF::ASF(vector<fastjet::PseudoJet> myjets, GaussTable mygausstable, double dR, bool erf, double R_max)
{
for (int k=0; k<(int)myjets.size(); k++) _cells.push_back(myjets[k]);
_nparticles = (int)_cells.size();
_dR=dR;

ConstructASF(mygausstable, erf, R_max);
FindPeaks();
SetProminences();
CalculatePartialMasses();
}  // end ASF constructor

// the user can specify the R_max up to which the asf is calculated
ASF::ASF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet,\
                                   GaussTable mygausstable, double dR, bool erf, double R_max)
{
_cells = mycs.constituents(myjet);
_nparticles = (int) _cells.size();
_dR=dR;

ConstructASF(mygausstable, erf, R_max);
FindPeaks();
SetProminences();
CalculatePartialMasses();
}  // end ASF constructor

void ASF::ConstructASF(GaussTable mygausstable, bool erf, double R_max)  // internal function used to calculate ASF
{
particlepair pp;

  for (int k=0; k<_nparticles; k++)  // go through all pairs of particles
  {
   for (int j=0; j<k; j++)
   {
   pp.deltaR=sqrt(_cells[k].plain_distance(_cells[j]));
   pp.weight=_cells[k].perp()*_cells[j].perp()*pp.deltaR*pp.deltaR;
   _pairs.push_back(pp);
   }
  }

_npairs=(int)_pairs.size();
if (_npairs<2) return; //{ printf("Error: cannot construct an ASF from fewer than two cells!\n"); return; }
sort(_pairs.begin(), _pairs.end(), ppsortfunction);
if (R_max == 0.0) _Rmax = _pairs[_npairs-1].deltaR;  // sort pairs in deltaR
else              _Rmax=R_max;

double Rval, fval;
if (!erf) // use theta function denominator
{
  _Denominator.Rvals[0]=0.0;
  _Denominator.fvals[0]=0.0;
  int searchstart=0;
  for (int k=1; k<meshsize; k++)  // calculate denominator of ASF
  {
  Rval=(double)k*_Rmax/(meshsize-1);
  _Denominator.Rvals[k]=Rval;
  fval=_Denominator.fvals[k-1];
   
   for (int j=searchstart; j<_npairs; j++)
   {
    if (_pairs[j].deltaR<=Rval)
    { 
    fval+=_pairs[j].weight;
    searchstart++;
    }
    else break; 
   }
   _Denominator.fvals[k]=fval;
 } 
}
else  // erf denominator
{
  _Denominator.Rvals[0]=0.0;
  _Denominator.fvals[0]=0.0;
  _Numerator.fvals[0]=0.0;
  for (int k=1; k<meshsize; k++)  // calculate denominator of ASF
  {
  fval=0.0;
  Rval=(double)k*_Rmax/(meshsize-1);
  _Denominator.Rvals[k]=Rval;
   
   for (int j=0; j<_npairs; j++)
   {
    fval+=_pairs[j].weight*0.5*(1.0+mygausstable.erf((Rval-_pairs[j].deltaR)/_dR));
   }
   _Denominator.fvals[k]=fval;
 } 
}

  // calculate numerator of asf
  for (int k=0; k<meshsize; k++)
  {
  Rval=_Denominator.Rvals[k];
  Function.Rvals[k]=Rval;
  if (_Denominator.fvals[k]==0.0) { Function.fvals[k]=0.0; continue; }
  fval=0.0;

   for (int j=0; j<_npairs; j++) // with a Gaussian kernel all pairs can enter into the numerator
                                 // make changes in this loop to implement a different kernel
   {
   // summing terms which enter into the numerator of the ASF
   //fval+=_pairs[j].weight*exp(-pow((abs(Rval-_pairs[j].deltaR)/_dR),2.0));  // slower version of the line below
   fval+=_pairs[j].weight*mygausstable.gaussian((Rval-_pairs[j].deltaR)/_dR);
   }
 
  static const double sqrtoneoverpi = 0.564189584;
  _Numerator.fvals[k]=fval*((sqrtoneoverpi*Rval)/(_dR));
  Function.fvals[k]=_Numerator.fvals[k]/_Denominator.fvals[k];
  // put together numerator and denominator and normalize to yield ASF
  }
}

vector<peak> ASF::GetPeaksMinProm(double minprom)  // get all peaks in ASF with prominence >= minprom; peaks are unsorted
{
vector<peak> peaks;
 
 for (int k=0; k<_npeaks; k++)
 {
 if (_peaks[k].prominence>=minprom) peaks.push_back(_peaks[k]);
 }

return peaks;
}

vector<peak> ASF::GetPeaksMinProm(double minprom, double minR) // as above with additional cut on minimum R of peak
{
vector<peak> peaks;
 
 for (int k=0; k<_npeaks; k++)
 {
 if (_peaks[k].prominence>=minprom && _peaks[k].Rval>=minR) peaks.push_back(_peaks[k]);
 }

return peaks;
}

vector<peak> ASF::GetPeaksMinHeight(double minheight)  // get all peaks in ASF with height >= minheight; peaks are unsorted
{
vector<peak> peaks;
 
 for (int k=0; k<_npeaks; k++)
 {
 if (_peaks[k].height>=minheight) peaks.push_back(_peaks[k]);
 }

return peaks;
}

vector<peak> ASF::GetPeaksMinHeight(double minheight, double minR) // as above with additional cut on minimum R of peak 
{
vector<peak> peaks;
 
 for (int k=0; k<_npeaks; k++)
 {
 if (_peaks[k].height>=minheight && _peaks[k].Rval>=minR) peaks.push_back(_peaks[k]);
 }

return peaks;
}

vector<peak> ASF::GetHeightSortedPeaksMinProm(double minprom)
 // same as GetPeaksMinProm but sorted in height, from low to high
{
vector<peak> peaks=GetPeaksMinProm(minprom);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakheightsortfunction);
return peaks;
}

vector<peak> ASF::GetHeightSortedPeaksMinProm(double minprom, double minR)
 // same as above but with additional cut on minimum R of peak
{
vector<peak> peaks=GetPeaksMinProm(minprom, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakheightsortfunction);
return peaks;
}

vector<peak> ASF::GetRSortedPeaksMinProm(double minprom)  // peaks sorted in R
{
vector<peak> peaks=GetPeaksMinProm(minprom);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakRsortfunction);
return peaks;
}

vector<peak> ASF::GetRSortedPeaksMinProm(double minprom, double minR)  // with additional cut on minimum R of peak
{
vector<peak> peaks=GetPeaksMinProm(minprom, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakRsortfunction);
return peaks;
}

vector<peak> ASF::GetProminenceSortedPeaksMinProm(double minprom) // peaks sorted in prominence
{
vector<peak> peaks=GetPeaksMinProm(minprom);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakprominencesortfunction);
return peaks; 
}

vector<peak> ASF::GetProminenceSortedPeaksMinProm(double minprom, double minR) // with additional cut on minimum R of peak 
{
vector<peak> peaks=GetPeaksMinProm(minprom, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakprominencesortfunction);
return peaks; 
}

vector<peak> ASF::GetPartialMassSortedPeaksMinProm(double minprom, double minR) // sorted in partial mass
{
vector<peak> peaks=GetPeaksMinProm(minprom, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakpartialmasssortfunction);
return peaks; 
}

vector<peak> ASF::GetPartialMassSortedPeaksMinProm(double minprom) // sorted in partial mass
{
vector<peak> peaks=GetPeaksMinProm(minprom);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakpartialmasssortfunction);
return peaks; 
}

vector<peak> ASF::GetHeightSortedPeaksMinHeight(double minheight)
 // same as GetPeaksMinHeight but sorted in height, from low to high
{
vector<peak> peaks=GetPeaksMinHeight(minheight);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakheightsortfunction);
return peaks;
}

vector<peak> ASF::GetHeightSortedPeaksMinHeight(double minheight, double minR)
 // same as above but with additional cut on minimum R of peak
{
vector<peak> peaks=GetPeaksMinHeight(minheight, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakheightsortfunction);
return peaks;
}

vector<peak> ASF::GetRSortedPeaksMinHeight(double minheight)  // peaks sorted in R
{
vector<peak> peaks=GetPeaksMinHeight(minheight);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakRsortfunction);
return peaks;
}

vector<peak> ASF::GetRSortedPeaksMinHeight(double minheight, double minR)  // with additional cut on minimum R of peak
{
vector<peak> peaks=GetPeaksMinHeight(minheight, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakRsortfunction);
return peaks;
}

vector<peak> ASF::GetProminenceSortedPeaksMinHeight(double minheight) // peaks sorted in prominence
{
vector<peak> peaks=GetPeaksMinHeight(minheight);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakprominencesortfunction);
return peaks; 
}

vector<peak> ASF::GetProminenceSortedPeaksMinHeight(double minheight, double minR) // with additional cut on minimum R of peak 
{
vector<peak> peaks=GetPeaksMinHeight(minheight, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakprominencesortfunction);
return peaks; 
}

vector<peak> ASF::GetPartialMassSortedPeaksMinHeight(double minheight, double minR) // sorted in partial mass
{
vector<peak> peaks=GetPeaksMinHeight(minheight, minR);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakpartialmasssortfunction);
return peaks; 
}

vector<peak> ASF::GetPartialMassSortedPeaksMinHeight(double minheight) // sorted in partial mass
{
vector<peak> peaks=GetPeaksMinHeight(minheight);
if ((int)peaks.size()>1)
sort(peaks.begin(), peaks.end(), peakpartialmasssortfunction);
return peaks; 
}

void ASF::FindPeaks() // internal function used to find peaks in ASF
{
peak mypeak;

  for (int k=1; k<meshsize-1; k++)
  {
  double lefth=Function.fvals[k-1];
  double height=Function.fvals[k];
  double righth=Function.fvals[k+1];

   if (lefth < height && righth < height)
   {
   mypeak.height=height;
   mypeak.Rval=Function.Rvals[k];
   mypeak.index=k;
   _peaks.push_back(mypeak);
   }
  }

_npeaks=(int)_peaks.size();
}

void ASF::CalculatePartialMasses() // calculate the partial mass of each peak
{
  for (int k=0; k<_npeaks; k++)
  {
  #define sqrtpi 1.77245385
  _peaks[k].partialmass=sqrt(sqrtpi*_dR*_peaks[k].height*_Denominator.fvals[_peaks[k].index]/_peaks[k].Rval);  
  }
}

void ASF::SetProminences() //  calculate prominences of each peak
{
  for (int k=0; k<_npeaks; k++)
  {
  double height=_peaks[k].height;
  double leftdescent=height-KeyColToLeft(k);
  double rightdescent=height-KeyColToRight(k);
  if (leftdescent<rightdescent) _peaks[k].prominence=leftdescent;
  else _peaks[k].prominence=rightdescent;
  }
}

double ASF::KeyColToRight(int p) // find 'key col' to right of peak p
{
int higherpeak=-1;
double height = _peaks[p].height;
double keycol=height;

 for (int k=p+1; k<_npeaks; k++)
 {
  if (_peaks[k].height > height) { higherpeak=k; break; }
 }

 if (higherpeak!=-1)
 {
 int startindex=_peaks[p].index;
 int endindex=_peaks[higherpeak].index;
   for (int j=startindex+1; j<endindex; j++)
   {
   if (Function.fvals[j]<keycol) keycol=Function.fvals[j];
   }
 }
 else keycol=0.0;

return keycol;
}

double ASF::KeyColToLeft(int p)  // find 'key col' to left of peak p
{
int higherpeak=-1;
double height = _peaks[p].height;
double keycol=height;

 for (int k=p-1; k>=0; k--)
 {
  if (_peaks[k].height > height) { higherpeak=k; break; }
 }

 if (higherpeak!=-1)
 {
 int endindex=_peaks[p].index;
 int startindex=_peaks[higherpeak].index;
   for (int j=startindex+1; j<endindex; j++)
   {
   if (Function.fvals[j]<keycol) keycol=Function.fvals[j];
   }
 }
 else keycol=0.0;

return keycol;
}

///////////////////////////////////////////////////////////////////
////////////      Angular Correlation Function    /////////////////
///////////////////////////////////////////////////////////////////

ACF::ACF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet, bool normalize) // the acf has no support for erf smoothing
                                                                                  // if you want smoothing use the asf and
                                                                                  // extract myasf._Denominator 
{
_cells = mycs.constituents(myjet);
_nparticles = (int) _cells.size();
ConstructACF(normalize, 0.0);
} // end ACF constructor

ACF::ACF(vector<fastjet::PseudoJet> myjets, bool normalize)
{
for (int k=0; k<(int)myjets.size(); k++) _cells.push_back(myjets[k]);
_nparticles = (int) _cells.size();
ConstructACF(normalize, 0.0);
} // end ACF constructor

ACF::ACF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet, bool normalize, double R_max)  // allow user to specify R_max 
{
_cells = mycs.constituents(myjet);
_nparticles = (int) _cells.size();
ConstructACF(normalize, R_max);
} // end ACF constructor

ACF::ACF(vector<fastjet::PseudoJet> myjets, bool normalize, double R_max)
{
for (int k=0; k<(int)myjets.size(); k++) _cells.push_back(myjets[k]);
_nparticles = (int) _cells.size();
ConstructACF(normalize, R_max);
} // end ACF constructor

void ACF::ConstructACF(bool normalize, double R_max)  // internal function used to calculate ACF
{
particlepair pp;

  for (int k=0; k<_nparticles; k++)  // go through all pairs of particles
  {
   for (int j=0; j<k; j++)
   {
   pp.deltaR=sqrt(_cells[k].plain_distance(_cells[j]));
   pp.weight=_cells[k].perp()*_cells[j].perp()*pp.deltaR*pp.deltaR;
   _pairs.push_back(pp);
   }
  }

_npairs=(int)_pairs.size();
if (_npairs<2) { printf("Error: cannot construct an ACF from fewer than two cells!\n"); return; }
sort(_pairs.begin(), _pairs.end(), ppsortfunction); // sort pairs w.r.t. R
if (R_max==0.0) _Rmax = _pairs[_npairs-1].deltaR;
else            _Rmax = R_max;

  Function.Rvals[0]=0.0;
  Function.fvals[0]=0.0;
  int searchstart=0;
  for (int k=1; k<meshsize; k++) // calculate angular correlation function
  {
  double Rval=(double)k*_Rmax/(meshsize-1);
  Function.Rvals[k]=Rval;
  Function.fvals[k]=Function.fvals[k-1];
   
   for (int j=searchstart; j<_npairs; j++)
   {
    if (_pairs[j].deltaR<=Rval)
    { 
    Function.fvals[k]+=_pairs[j].weight;
    searchstart++;
    }
    else break;
   }
  }
  if (normalize)
  for (int k=1; k<meshsize; k++) Function.fvals[k]/=Function.fvals[meshsize-1];
  // normalize ACF so that ACF->1 as R->R_max
}
