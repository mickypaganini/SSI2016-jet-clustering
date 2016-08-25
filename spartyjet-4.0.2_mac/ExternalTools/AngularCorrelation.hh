// modification 9/7/11 CKV: adding std:: qualifiers where necessary, making header-defined funcs inline, adding header guards
#ifndef _ANGULAR_CORRELATION_HH_
#define _ANGULAR_CORRELATION_HH_

#include "fastjet/ClusterSequence.hh"
#include<cmath>
#define meshsize 500  // size of the mesh used in the acf and asf (the function is
                      // only calculated at a finite number of points)


// structure used to access the calculated angular correlation or structure functions
struct functiondata { double Rvals[meshsize]; double fvals[meshsize]; };
// structure used internally to represent a pair of particles
struct particlepair { double deltaR; double weight; };
// structure associated with peaks in the angular structure function
struct peak { double Rval; double height; double prominence;
              double partialmass; int index; };
class GaussTable; // lookup table used to calculate gaussians more quickly, defined below
                  // needed to initialize an angular structure function object

class ACF // angular correlation function class
{
 public: // two constructors and the function data itself
  // if 'normalize' is true then the acf is normalized so that ACF(R)->1 as R->infinity.
  // the maximum R up to which the acf is calculated can be set via R_max.
  // by default the acf is calculated up to the largest separation R between the various constituents of the jet
  ACF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet, bool normalize);
  ACF(std::vector<fastjet::PseudoJet> myjets, bool normalize);
  ACF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet, bool normalize, double R_max);
  ACF(std::vector<fastjet::PseudoJet> myjets, bool normalize, double R_max);
  functiondata Function;

 private: // internal code and data
  void ConstructACF(bool normalize, double R_max);
  std::vector<fastjet::PseudoJet> _cells;
  std::vector<particlepair> _pairs; 
  int _nparticles;
  int _npairs;
  double _Rmax; // the acf is calculated from R=0 to R=_Rmax
};

class ASF // angular structure function class
{
 public: // four constructors and the function data itself.
         // here dR over sqrt(2) is the width of the Gaussian kernel 
         // in the numerator of the angular structure function.
         // if 'erf' is true then the denominator of the asf uses
         // an error function of width dR instead of a theta function.
         // if 'erf' is false the theta function is used.      
 
  ASF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet, \
                   GaussTable mygausstable, double dR, bool erf);
  ASF(std::vector<fastjet::PseudoJet> myjets, \
                   GaussTable mygausstable, double dR, bool erf);
  // the user can specify the R_max up to which the asf should be calculated;
  // by default the asf is calculated up to the largest separation between the
  // various constituents of the jet; fixing R_max is useful if one is calculating
  // an asf averaged of an ensemble of jets 
  ASF(fastjet::ClusterSequence mycs, fastjet::PseudoJet myjet, \
                   GaussTable mygausstable, double dR, bool erf, double R_max);
  ASF(std::vector<fastjet::PseudoJet> myjets, \
                   GaussTable mygausstable, double dR, bool erf, double R_max);
  functiondata Function;
  // functions used to access identified peaks in the structure function
  // more details in AngularCorrelation.cc
  std::vector<peak> GetPeaks() { return _peaks; } 
  std::vector<peak> GetPeaksMinProm(double minprom); 
  std::vector<peak> GetPeaksMinProm(double minprom, double minR); 
  std::vector<peak> GetPeaksMinHeight(double minheight); 
  std::vector<peak> GetPeaksMinHeight(double minheight, double minR); 
  std::vector<peak> GetHeightSortedPeaksMinProm(double minprom); 
  std::vector<peak> GetRSortedPeaksMinProm(double minprom); 
  std::vector<peak> GetProminenceSortedPeaksMinProm(double minprom); 
  std::vector<peak> GetPartialMassSortedPeaksMinProm(double minprom); 
  std::vector<peak> GetHeightSortedPeaksMinProm(double minprom, double minR); 
  std::vector<peak> GetRSortedPeaksMinProm(double minprom, double minR); 
  std::vector<peak> GetProminenceSortedPeaksMinProm(double minprom, double minR); 
  std::vector<peak> GetPartialMassSortedPeaksMinProm(double minprom, double minR); 
  std::vector<peak> GetHeightSortedPeaksMinHeight(double minheight); 
  std::vector<peak> GetRSortedPeaksMinHeight(double minheight); 
  std::vector<peak> GetProminenceSortedPeaksMinHeight(double minheight); 
  std::vector<peak> GetPartialMassSortedPeaksMinHeight(double minheight); 
  std::vector<peak> GetHeightSortedPeaksMinHeight(double minheight, double minR); 
  std::vector<peak> GetRSortedPeaksMinHeight(double minheight, double minR); 
  std::vector<peak> GetProminenceSortedPeaksMinHeight(double minheight, double minR); 
  std::vector<peak> GetPartialMassSortedPeaksMinHeight(double minheight, double minR); 
  int n_peaks() { return _npeaks; }
  // returns number of peaks with prominence >= minprom
  int n_peaks_minprom(double minprom) { return ((int)GetPeaksMinProm(minprom).size()); }
  int n_peaks_minprom(double minprom, double minR) { return ((int)GetPeaksMinProm(minprom,minR).size()); }
  int n_peaks_minheight(double minheight) { return ((int)GetPeaksMinHeight(minheight).size()); }
  int n_peaks_minheight(double minheight, double minR) { return ((int)GetPeaksMinHeight(minheight,minR).size()); }
  functiondata _Denominator; // denominator of the ASF
  functiondata _Numerator; // numerator of the ASF (including the prefactor of R 
                           // on the RHS of the equality d/dlogR = R d/dR)
  void ConstructASF(GaussTable mygausstable, bool erf, double R_max); // internal function used to calculate ASF

 private: // internal functions used to identify peaks, calculate prominences etc.
  void FindPeaks();
  void SetProminences();
  void CalculatePartialMasses();
  double KeyColToRight(int p);
  double KeyColToLeft(int p);
  std::vector<fastjet::PseudoJet> _cells;
  std::vector<particlepair> _pairs; 
  std::vector<peak> _peaks;
  int _npeaks;
  int _nparticles;
  int _npairs;
  double _Rmax;
  double _dR;
};

class GaussTable // gaussian lookup table; also includes erf lookup table
{
#define Nbins 1000
#define argMAX 4.0

public:
 GaussTable();
 double gaussian(double x);
 double erf(double x);
private:
 double gaussianlookup[Nbins];
 double erflookup[Nbins];
};

inline GaussTable::GaussTable()  // constructor sets up lookup tables (do this only once!)
{
 for (int k=0; k<Nbins; k++)
 {
 gaussianlookup[k]= std::exp(-(double)k*k*argMAX*argMAX/(Nbins*Nbins));
 }

 for (int k=0; k<Nbins; k++)  // we use an approximation of erf found in
                              // Winitzki, Sergei (6 February 2008). "A handy approximation for 
                              // the error function and its inverse"
 {
 double a=0.140012;
 double x=(double)(k*argMAX/Nbins);
 double z=x*std::sqrt((1.27323954+a*x*x)/(1+a*x*x));
 erflookup[k]=std::sqrt(1.0-gaussian(z));
 }
}

// approximates exp(-x^2) for x in (-argMAX, argMAX), returning 0 outside of range
inline double GaussTable::gaussian(double x) 
{
int index=(int)(Nbins*(std::abs(x)/argMAX));
if (index<Nbins) return gaussianlookup[index];
else return 0.0;
}

inline double GaussTable::erf(double x)
{
int index=(int)(Nbins*(std::abs(x)/argMAX));
double sign=1.0;
if (x<0.0) sign=-1.0;
if (index<Nbins) return (sign*erflookup[index]);
else return sign;
}

// internal functions used for sorting
inline bool peakheightsortfunction(peak a, peak b) { return (a.height > b.height); }
inline bool peakRsortfunction(peak a, peak b) { return (a.Rval < b.Rval); }
inline bool peakprominencesortfunction(peak a, peak b) { return (a.prominence > b.prominence); }
inline bool peakpartialmasssortfunction(peak a, peak b) { return (a.partialmass > b.partialmass); }
inline bool ppsortfunction(particlepair a, particlepair b) { return (a.deltaR < b.deltaR); }

#endif
