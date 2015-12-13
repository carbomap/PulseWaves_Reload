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


//-----------------------------------------------------------

PulseWaves::PulseWaves(std::string inFile)
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

    cVlrHeader* vlrHeaderArr = new cVlrHeader[plsHeader_->nVLR_];
    
    // reading the VLR
    for (int i = 0; i < plsHeader_->nVLR_; i++)
    {
        // getting the VLR ID record number
        U32 recID = cVlrHeader::whichVLR(inPlsFile_);
        
        // instantiate the correct VLR class
        if (recID == 34735)
        {
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            
            printSep();
            tempVlr->cVlrHeader::print();
            
            vlrHeaderArr[i] = *tempVlr;
            
            printSep();
            std::cout << "GeoKeyDirectoryTag Record found..." << std::endl;
            
            cGeoKeyHeader tempGKey;
            tempGKey.read(inPlsFile_);
            tempGKey.print();
            printSep();
            
            // putting GeoKey header in the vlr array
//            vlrHeaderArr[i] = tempGKey;
            
            // creating another array of Geokey
            cGeoKey* cGeoKeyArr = new cGeoKey[tempGKey.gKeyNumberOfKeys_+1];
//            cGeoKeyArr[0] = tempGKey;
            
            for (int j = 1; j < tempGKey.gKeyNumberOfKeys_+1; j++) {
                std::cout << "GeoKey " << j << " of " << tempGKey.gKeyNumberOfKeys_ << std::endl;
                
                cGeoKey tempGKey;
                tempGKey.read(inPlsFile_);
                tempGKey.print();
                printSep();
                // putting GeoKey header in the vlr array
                cGeoKeyArr[j] = tempGKey;
            }
            
            cGeoKeyArr_ = cGeoKeyArr;
            
        }
        else if (recID == 34736)
        {
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            
            tempVlr->cVlrHeader::print();
            
            vlrHeaderArr[i] = *tempVlr;
            
            printSep();
            std::cout << "GeoDoubleParamsTag Record found..." << std::endl;
            
            F64 tempArr[tempVlr->cVlrHeader::recordLengthAfterHeader_ / 8];
//            boost::array<F64,3> tempArr;
            inPlsFile_->read((char *)&tempArr, sizeof(tempArr));
            for (int z =0; z < tempVlr->cVlrHeader::recordLengthAfterHeader_ / 8; z++) {
                std::cout << tempArr[z] << ", ";
                
            }
            std::cout << "" << std::endl;
            printSep();
            
        }
        else if (recID == 34737)
        {
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            
            tempVlr->cVlrHeader::print();
            printSep();

            std::cout << "GeoAsciiParamsTag Record found..." << std::endl;
            
            const int length = tempVlr->cVlrHeader::recordLengthAfterHeader_;
            U8 tempArr[length];
//            boost::array<I8,23> tempArr;
            inPlsFile_->read((char *)&tempArr, sizeof(tempArr));
            std::cout << tempArr << std::endl;
            
            
        }
        else if (recID >= 100001 && recID < 100255)
        {
            
            printSep();
            std::cout << "Scanner descriptor found..." << std::endl;
            
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
            std::cout << "Pulse sampling descriptor found..." << std::endl;
            
            cVlrPulseSampling* tempVlr = new cVlrPulseSampling;
            tempVlr->cVlrHeader::read(inPlsFile_);
            tempVlr->cVlrHeader::print();
            printSep();
            
            tempVlr->cVlrPulseSampling::read(inPlsFile_);
            tempVlr->cVlrPulseSampling::print();
            printSep();
            
            tempVlr->cVlrPulseSampling::read_SamplingRecords(inPlsFile_);
            
        }
        else if (recID >= 300001 && recID < 300255)
        {
            printSep();
            std::cout << "Lookup Table descriptor found..." << std::endl;
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            inPlsFile_->seekg(tempVlr->recordLengthAfterHeader_, std::ios::cur);
        }
        else
        {
            printSep();
            std::cout << "Generic VLR descriptor found..." << std::endl;
            std::cout << "VLR #" << recID << std::endl;
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            inPlsFile_->seekg(tempVlr->recordLengthAfterHeader_, std::ios::cur);
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
