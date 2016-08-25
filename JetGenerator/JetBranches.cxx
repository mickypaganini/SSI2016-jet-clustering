//
//  JetBranches.cxx
//  JetGenerator
//
//  Created by Heather Russell on 16/08/16.
//
//

#include "JetBranches.h"
#include <stdio.h>
#include "Riostream.h"
#include <iostream>
#include "TMath.h"
#include "TLorentzVector.h"

void JetBranches::initializeVectors(TTree* &t){
    c_energy = 0;
    c_eta = 0;
    c_phi = 0;
    //cell_filled = 0;
    
    j_energy = 0;
    j_eta = 0;
    j_phi = 0;
    
    maxEnergyCell = 0;
    maxEnergyCIndex = 0;
    maxEnergyJIndex = 0;
    
    t->Branch("jet_energy",&j_energy);
    t->Branch("jet_eta",&j_eta);
    t->Branch("jet_phi",&j_phi);
    
    t->Branch("cell_eta",&c_eta);
    t->Branch("cell_phi",&c_phi);
    t->Branch("cell_E",&c_energy);
}

void JetBranches::clearAllVectors(){

    for(unsigned int i=0; i<c_energy->size(); i++){
        c_energy->at(i).clear();
        c_eta->at(i).clear();
        c_phi->at(i).clear();
    }
    c_energy->clear();
    c_phi->clear();
    c_eta->clear();
    cell_filled.clear();
    
    j_energy->clear();
    j_eta->clear();
    j_phi->clear();

    maxEnergyCell = 0;
    maxEnergyCIndex = 0;
    maxEnergyJIndex = 0;
}

void JetBranches::generateJets(TRandom3 *rand, int nCells, bool makeJetsCloseby){
    std::vector<double> cell_eta;
    std::vector<double> cell_phi;
    std::vector<double> cell_energy;
    double jetEta = double(rand->Integer(53) + 4)*0.1 - 3.0;
    double jetPhi = double(rand->Integer(55) + 4)*0.1 - 3.1;
    if(makeJetsCloseby){
        if(j_eta->size() > 0){
            jetEta = j_eta->at(j_eta->size() - 1) + 0.4;
            jetPhi = j_phi->at(j_eta->size() - 1) + 0.4;
        }
    }
    double jetEta_Centre = 0;
    double jetCosPhi_Centre = 0;
    double jetSinPhi_Centre = 0;
    double jetEnergy = 0;
    double tmpEnergy = 0;

    for(unsigned int i_cell = 0; i_cell < nCells; i_cell++){
        double eta = rand->Gaus(jetEta,0.1);
        eta = double(TMath::Nint(eta*10.))*0.1;
        double phi = rand->Gaus(jetPhi,0.1);
        phi = double(TMath::Nint(phi*10.))*0.1;
        
        double energy = -1;
        if(i_cell < 2) energy = TMath::Abs(rand->Gaus(100,20));
        else energy = TMath::Abs(rand->Gaus(40,20));
        
        if(energy == 0) energy = 0.001;
        int cellTmp = int((eta + 3.0)*10.)*60 + int((phi + 3.1)*10.);

        while(std::find(cell_filled.begin(), cell_filled.end(), cellTmp) != cell_filled.end()){
            if(rand->Integer(2) == 1){
                eta = double(TMath::Nint(rand->Gaus(jetEta,0.2)*10.))*0.1;
            } else {
                phi = double(TMath::Nint(rand->Gaus(jetPhi,0.2)*10.))*0.1;
            }
            cellTmp = int((eta + 3.0)*10.)*60 + int((phi + 3.1)*10.);
        }
        
        if(energy > maxEnergyCell ){
            maxEnergyCell = energy;
            maxEnergyCIndex = i_cell;
            maxEnergyJIndex = j_eta->size();
        }
        cell_eta.push_back(eta);
        cell_phi.push_back(phi);
        cell_energy.push_back(energy);
        jetEta_Centre += eta*energy;
        jetCosPhi_Centre += cos(phi)*energy;
        jetSinPhi_Centre += sin(phi)*energy;
        jetEnergy += energy;
        cell_filled.push_back(cellTmp);

    }
    c_eta->push_back(cell_eta);
    c_phi->push_back(cell_phi);
    c_energy->push_back(cell_energy);

    j_energy->push_back(jetEnergy);
    j_phi->push_back(atan2(jetSinPhi_Centre/jetEnergy, jetCosPhi_Centre/jetEnergy));
    j_eta->push_back(jetEta_Centre/jetEnergy);
    return;

    
}
void JetBranches::splitHighestECell(JetBranches * &jetsCL){
    *jetsCL->j_eta = (*j_eta);
    *jetsCL->j_phi = (*j_phi);
    *jetsCL->j_energy = (*j_energy);

    *jetsCL->c_energy = (*c_energy);
    *jetsCL->c_eta = (*c_eta);
    *jetsCL->c_phi = (*c_phi);

    jetsCL->c_energy->at(maxEnergyJIndex).at(maxEnergyCIndex) = c_energy->at(maxEnergyJIndex).at(maxEnergyCIndex)/2;
    jetsCL->c_eta->at(maxEnergyJIndex).at(maxEnergyCIndex) = c_eta->at(maxEnergyJIndex).at(maxEnergyCIndex) + 0.05;
    jetsCL->c_phi->at(maxEnergyJIndex).at(maxEnergyCIndex) = c_phi->at(maxEnergyJIndex).at(maxEnergyCIndex) + 0.05;
    
    jetsCL->c_energy->at(maxEnergyJIndex).push_back(c_energy->at(maxEnergyJIndex).at(maxEnergyCIndex)/2);
    jetsCL->c_eta->at(maxEnergyJIndex).push_back(c_eta->at(maxEnergyJIndex).at(maxEnergyCIndex) - 0.05);
    jetsCL->c_phi->at(maxEnergyJIndex).push_back(c_phi->at(maxEnergyJIndex).at(maxEnergyCIndex) - 0.05);

}
void JetBranches::addIRNoise(int evt, TRandom3 *rand, JetBranches * &jetsIR, std::ofstream &txtFileIR, std::ofstream &datFileIR){

    *jetsIR->j_eta = (*j_eta);
    *jetsIR->j_phi = (*j_phi);
    *jetsIR->j_energy = (*j_energy);
    
    *jetsIR->c_energy = (*c_energy);
    *jetsIR->c_eta = (*c_eta);
    *jetsIR->c_phi = (*c_phi);
    
    std::vector<double> cell_eta;
    std::vector<double> cell_phi;
    std::vector<double> cell_energy;
    
    for(unsigned int i=0; i < 1000; i++){
        
        double noiseEta = double(rand->Integer(61))*0.1 - 3.0;
        double noisePhi = double(rand->Integer(63))*0.1 - 3.1;
        double noiseEnergy = 0.00000001;
        int cellTmp = int((noiseEta + 3.0)*10.)*60 + int((noisePhi + 3.1)*10.);
        if(std::find(cell_filled.begin(), cell_filled.end(), cellTmp) != cell_filled.end()){
            continue;
        }
        TLorentzVector cell;
        cell.SetPtEtaPhiM(noiseEnergy,noiseEta,noisePhi,0.0);
        
        cell_eta.push_back(noiseEta);
        cell_phi.push_back(noisePhi);
        cell_energy.push_back(noiseEnergy);
        txtFileIR << evt << " " << noiseEta;
        txtFileIR << " " << noisePhi;
        txtFileIR << " " << noiseEnergy << "\n";
        
        datFileIR << cell.E() << " " << cell.Px() << " " << cell.Py() << " " << cell.Pz() << "\n";
        
    }
    jetsIR->j_eta->push_back(-99.);
    jetsIR->j_phi->push_back(-99.);
    jetsIR->j_energy->push_back(0.);

    jetsIR->c_eta->push_back(cell_eta);
    jetsIR->c_phi->push_back(cell_phi);
    jetsIR->c_energy->push_back(cell_energy);
    
}