//
//  JetGenerator.cxx
//  JetGenerator
//
//  Created by Heather Russell on 16/08/16.
//
//

#include <stdio.h>
#include "Riostream.h"
#include <iostream>
#include "TRandom3.h"
#include "TFile.h"
#include "TTree.h"
#include "JetBranches.h"
#include <fstream>
#include "TStopwatch.h"
#include "TLorentzVector.h"

TStopwatch timer;

int main(int argc, char **argv){
    timer.Start();

    std::cout << "running program!" << std::endl;
    
    std::cout << "You input " << argc << " arguments:" << std::endl;
    std::cout << "output file name: " << argv[1] << std::endl;
    std::cout << "will generate: " << argv[2] << " events, with ";
    std::cout << argv[3] << " jets per event." << std::endl;
    std::cout << "each jet will contain a mean of: " << argv[4] << " main cells." << std::endl;
    std::cout << "Infrared radiation is: " << argv[5] <<std::endl;
    std::cout << "Generate only nearby jets is: " << argv[6] <<std::endl;
    
    int nEvents = atoi(argv[2]);
    int nJetsPerEvent = atoi(argv[3]);
    int meanCells = atoi(argv[4]);
    bool doIRNoise = (TString(argv[5]) == "on") ? true : false;
    bool makeJetsCloseby = (TString(argv[6]) == "nearby") ? true : false;
    TFile *pFileRoot = TFile::Open((TString)argv[1]+".root","RECREATE");
    if(!pFileRoot) {
     throw std::runtime_error("Failed to create root file. Exiting.");
    }
    unsigned int i_evt = 0;
    std::ofstream txtFile;
    txtFile.open (std::string(argv[1])+".txt");

    std::ofstream txtFileIR;
    txtFileIR.open (std::string(argv[1])+"_withNoise.txt");
   
    std::ofstream datFile;
    datFile.open (std::string(argv[1])+".dat");
    
    std::ofstream datFileIR;
    datFileIR.open (std::string(argv[1])+"_withNoise.dat");
    
    JetBranches *jets = new JetBranches;
    JetBranches *jetsIR = new JetBranches;
    JetBranches *jetsCL = new JetBranches;
    
    TTree *tree = new TTree("jets","tree jet vectors");
    TTree *treeCL = new TTree("collinearJets","tree jet vectors with collinear splitting");
    TTree *treeIR = new TTree("jetsWithIR","tree jet vectors with IR safetly");

    tree->Branch("eventNumber",&i_evt);
    treeCL->Branch("eventNumber",&i_evt);
    treeIR->Branch("eventNumber",&i_evt);

    jets->initializeVectors(tree);
    //jetsCL->initializeVectors(treeCL);
    jetsIR->initializeVectors(treeIR);

    
    TRandom3 *rand = new TRandom3;
    txtFile << "event eta phi energy\n";
    txtFileIR << "event eta phi energy\n";

    for(i_evt = 0; i_evt < nEvents; i_evt++){
        if( i_evt % 1 == 0 ){
            timer.Stop();
            std::cout << "event " << i_evt  << ", time: " << timer.RealTime() << " s." << std::endl;
            timer.Start();
        }
        datFile << ".Event " << i_evt << "\n";
        for(unsigned int i_jet = 0; i_jet < nJetsPerEvent; i_jet++){
            int nCellsPerJet = rand->Gaus(meanCells, 2);
            if(nCellsPerJet <= 0 ) nCellsPerJet =1;
            jets->generateJets(rand, nCellsPerJet, makeJetsCloseby);
            for(unsigned int i_c=0;i_c < nCellsPerJet; i_c++){
                TLorentzVector cell; cell.SetPtEtaPhiM(jets->c_energy->at(i_jet).at(i_c),
                                                       jets->c_eta->at(i_jet).at(i_c),
                                                       jets->c_phi->at(i_jet).at(i_c),
                                                       0.0);
                txtFile << i_evt << " " << jets->c_eta->at(i_jet).at(i_c);
                txtFile << " " << jets->c_phi->at(i_jet).at(i_c);
                txtFile << " " << jets->c_energy->at(i_jet).at(i_c) << "\n";
    
                txtFileIR << i_evt << " " << jets->c_eta->at(i_jet).at(i_c);
                txtFileIR << " " << jets->c_phi->at(i_jet).at(i_c);
                txtFileIR << " " << jets->c_energy->at(i_jet).at(i_c) << "\n";
                
                datFile << cell.E() << " " << cell.Px() << " " << cell.Py() << " " << cell.Pz() << "\n";
                datFileIR << cell.E() << " " << cell.Px() << " " << cell.Py() << " " << cell.Pz() << "\n";

            }
        }
        //jets->splitHighestECell(jetsCL);
        if(doIRNoise) jets->addIRNoise(i_evt, rand, jetsIR, txtFileIR, datFileIR);
        tree->Fill();
        //treeCL->Fill();
        treeIR->Fill();
        
        jets->clearAllVectors();
        //jetsCL->clearAllVectors();
        jetsIR->clearAllVectors();

    }
    pFileRoot->Write();
    txtFile.close();
    txtFileIR.close();
    datFile.close();
    datFileIR.close();
    timer.Stop();
    return 1;
}
