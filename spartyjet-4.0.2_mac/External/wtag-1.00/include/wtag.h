/*************************************************************************************************
   Usage: the following function tags a W-jet: 

             bool wtag(ClusterSequence & clustSeq, PseudoJet &jet, 
                       double signal_eff = -1, jet_pars *jetpars_ptr = NULL)

          return value: true = tagged, false = not tagged
          clustSeq = the ClusterSequence the jet belongs to
          jet      = jet to be tagged
          signal_eff = signal efficiency, default = efficiency maximizing S/sqrt(B)
          jetpars_ptr = pointer to jet parameters, default = NULL, using default parameters



          The variables are stored in class jet_mvars (see below). To obtain the variables, first define jet paramemters

             jet_pars jetpars;
             jetpars.read_jetpars();

          Use jet_mvars::get_mvars(ClusterSequence &, PseudoJet &, jet_pars &) to calculate the variables. 
          For example,

             jet_mvars jet_mvars;
             jetmvars.get_mvars(clustSeq, jet, jetpars);

          Then one can use jet_mvars::foutput(ofstream &) to output the variables to a file
*************************************************************************************************/	  

#ifndef WTAG
#define WTAG

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

#define NPT 18  //number of pt bins 
#define PI 3.1415926535
#define NEFF 1000
//using namespace fastjet; // GAH!



namespace Wtag {


class jet_pars
//class to save jet algorithm parameters
{
   public:
     void read_jetpars();
     double get_Rsub(double pt);
     double get_fcut(double pt);
     double get_Rcut(double pt);
     double get_zcut(double pt);
     double get_mu(double pt);
     double get_ycut(double pt);
     double get_bdtcut_opt(double pt);
     double get_bdtcut_opt_es(double pt);
     double get_bdtcut_opt_eb(double pt);
     double get_bdtcut_opt_sig(double pt);
     double get_bdtcut(double pt, double es);
     double get_bdtcut_es(double pt, double es);
     double get_bdtcut_eb(double pt, double es);
     double get_bdtcut_sig(double pt, double es);

     double get_filtering_es(double pt);
     double get_filtering_eb(double pt);
     double get_filtering_sig(double pt);

     void set_trimming_par_file(char*);
     void set_pruning_par_file(char*);
     void set_filtering_par_file(char*);
     void set_bdtcut_filename(char*);
     void set_bdteff_filename(char*);
     void set_bdtweight_dir(char*);
     void set_bdtweight_prefix(char*);
     void set_bdtweight_name(double pt, char*);
 
     void get_trimming_par_file(char*);
     void get_pruning_par_file(char*);
     void get_filtering_par_file(char*);
     void get_bdtcut_filename(char*);
     void get_bdteff_filename(char*);
     void get_bdtweight_dir(char*);
     void get_bdtweight_prefix(char*);
     void get_bdtweight_name(double pt, char*);  
    
     jet_pars();

  private:
     
     //trimming parameters
     double Rsub[NPT];
     double fcut[NPT];

     //pruning parameters
     double Rcut[NPT];
     double zcut[NPT];

     //filtering parameters
     double mu[NPT];
     double ycut[NPT];
     double filtering_es[NPT];
     double filtering_eb[NPT];
     double filtering_sig[NPT];

     bool initiated;

     char trimming_par_file[200];
     char pruning_par_file[200];
     char filtering_par_file[200];
     
     char bdtcut_filename[200]; //file containing the best BDT cuts   
     char bdteff_filename[200]; //file containing BDT cuts as a function of signal efficiency 
     char bdtweight_dir[100];
     char bdtweight_prefix[100];
     char bdtweight_name[NPT][100];
     bool bdtweights_set[NPT];     

     double bdtcuts_opt[NPT];
     double bdtcuts_opt_es[NPT];
     double bdtcuts_opt_eb[NPT];
     double bdtcuts_opt_sig[NPT];
     double bdtcuts[NPT][NEFF];
     double bdtcuts_es[NPT][NEFF];
     double bdtcuts_eb[NPT][NEFF];
     double bdtcuts_sig[NPT][NEFF];
};


class jet_mvars
//class to calculate and save variables
{
   public:
      double mass, pt, masstrim, pttrim, massprune, ptprune, massfilter, ptfilter;
      double ptratio, pangle1, psize1, pangle2, psize2;
      double mass2, mass3, mass4, mass5, mass6, mass7, mass8, mass9, mass10, mass11;
      double pt2, pt3, pt4, pt5, pt6, pt7, pt8, pt9, pt10, pt11;
      
      int nsubjets;
      double ptsub1, ptsub2, masssub1, masssub2, subjetdR;
      double rapsub1, rapsub2, phisub1, phisub2;

      double planarflow, planarflow4;

      double pfilter[4];
      bool get_mvars(fastjet::ClusterSequence & clustSeq, fastjet::PseudoJet & jet, jet_pars &jetpars); 
    bool finput(std::ifstream &fin);
    void foutput(std::ofstream &fout);
     
};


bool wtag(fastjet::ClusterSequence & clustSeq, fastjet::PseudoJet &jet, double signal_eff = -1, jet_pars * jetpars_ptr = NULL);
//pass BDT cut = true, otherwise = false
//if signal_eff < 0, use cuts maximizing significance, stored in jetpars_prt->bestBDTcuts[ipt]
//if signal_eff specified, using cuts cooresponding to the signal efficiency

int cal_ipt(double pt);
int cal_ieff(double eff);

} // namespace Wtag

#endif
