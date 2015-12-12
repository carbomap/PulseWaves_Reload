//
//  PulseWaves.cpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
//

#include "../includes/PulseWaves.hpp"
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
#include "../includes/cGeoKey.hpp"
#include "../includes/cVlr.hpp"


using namespace std;


//-----------------------------------------------------------

PulseWaves::PulseWaves(string inFile)
{
	
    
    plsFilePath_ = inFile;
    // instantiation of the fstream class object
    
    std::fstream inPlsFile;
    
    inPlsFile_ = &inPlsFile;

    inPlsFile_->open(plsFilePath_.c_str(), std::ios::in | std::ios::binary);
    
    // checking if the file exist
    if (inPlsFile_->fail())
    {
        
        std::cout << "ERROR: Cannot open the file..." << std::endl;
        exit(1);
    
    }
    else
    {
        
        this->readHeader();
        this->readVLR();
        this->readData();
        this->readAVLR();

    }
    
    inPlsFile_->close();
    
    
};






//-----------------------------------------------------------
// Private methods for reading the file
void PulseWaves::printSep() const
{
    std::cout << "########################################################" << std::endl;
};



void PulseWaves::readHeader()
{

	// getting header structure
	cPlsHeader* plsHeader = new cPlsHeader;
    plsHeader->read(inPlsFile_);
    plsHeader->print();

    plsHeader_ = plsHeader;

};


// Method that reads the VLR and store them into an array
// Note that for the moment there is a little bug on the storage as
// the GeoKeyHeader is not properly stored !!!
// This needs some fixing.
void PulseWaves::readVLR()
{

    cVlrHeader* vlrHeaderArr = new cVlrHeader[plsHeader_->nVLR];
    
    // reading the VLR
    for (int i = 0; i < plsHeader_->nVLR; i++)
    {
        // getting the VLR ID record number
        U32 recID = cVlrHeader::whichVLR(inPlsFile_);
        
        
        cout << "" << recID << std::endl;
        cout << "Record ID:" << recID << std::endl;
        cout << "" << recID << std::endl;
        
        // instantiate the correct VLR class
        if (recID == 34735)
        {
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            vlrHeaderArr[i] = *tempVlr;
            
            printSep();
            cout << "Geokey descriptor found..." << std::endl;
            
            cGeoKeyHeader tempGKey;
            tempGKey.read(inPlsFile_);
            // putting GeoKey header in the vlr array
//            vlrHeaderArr[i] = tempGKey;
            
            // creating another array of Geokey
            cGeoKey* cGeoKeyArr = new cGeoKey[tempGKey.gKeyNumberOfKeys+1];
//            cGeoKeyArr[0] = tempGKey;
            
            for (int j = 1; j < tempGKey.gKeyNumberOfKeys+1; j++) {
                cGeoKey tempGKey;
                tempGKey.read(inPlsFile_);
                tempGKey.print();
                // putting GeoKey header in the vlr array
                cGeoKeyArr[j] = tempGKey;
            }
            
            cGeoKeyArr_ = cGeoKeyArr;
            
        }
        else if (recID >= 100001 && recID < 100255)
        {
            printSep();
            cout << "Scanner descriptor found..." << std::endl;
            
            cVlrScanner* tempVlr = new cVlrScanner;
            
            tempVlr->cVlrHeader::read(inPlsFile_);
            tempVlr->cVlrScanner::read(inPlsFile_);
            
            tempVlr->cVlrHeader::print();
            printSep();
            tempVlr->cVlrScanner::print();
            
            vlrHeaderArr[i] = *tempVlr;
            
        }
        else if (recID >= 200001  && recID < 200255)
        {
            printSep();
            cout << "Pulse sampling descriptor found..." << std::endl;
            
            cVlrPulseSampling* tempVlr = new cVlrPulseSampling;
            tempVlr->cVlrHeader::read(inPlsFile_);
            tempVlr->cVlrHeader::print();
            printSep();
            
            tempVlr->cVlrPulseSampling::read(inPlsFile_);
            tempVlr->cVlrPulseSampling::print();
            printSep();
            
            tempVlr->cVlrPulseSampling::read_SamplingRecords(inPlsFile_);
            
//            cVlrSamplingRecord* samplingRecordArr_ = new cVlrSamplingRecord[tempVlr->cVlrPulseSampling::numberOfSamples];
//            
//            U16 numberOfSampling = tempVlr->numberOfSamplings;
//            for (U16 w = 0; w < numberOfSampling; w++) {
//                
//                    cVlrSamplingRecord* tempSamplingRecord = new cVlrSamplingRecord;
//                    tempSamplingRecord->read(inPlsFile_);
//                    tempSamplingRecord->print();
//                    printSep();
//                    samplingRecordArr_[w] = *tempSamplingRecord;
//                }
            
        }
        else if (recID >= 300001 && recID < 300255)
        {
            printSep();
            cout << "Lookup Table descriptor found..." << std::endl;
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            inPlsFile_->seekg(tempVlr->recordLengthAfterHeader, std::ios::cur);
        }
        else
        {
            printSep();
            cout << "Generic VLR descriptor found..." << std::endl;
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            inPlsFile_->seekg(tempVlr->recordLengthAfterHeader, std::ios::cur);
        }
        
        
        
    }
    
    plsVlrArr_  = vlrHeaderArr;
    
};


void PulseWaves::readData()
{

};


void PulseWaves::readAVLR()
{

};
