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
        
        std::cout << "Reading header..." << std::endl;
        this->readHeader();
        std::cout << "Reading Variable Length Records..." << std::endl;
        this->readVLR();
        std::cout << "Reading Data Records..." << std::endl;
        this->readData();
        std::cout << "Reading Append Variable Length Record..." << std::endl;
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
        std::cout << "reckon recID: " << recID << std::endl;
        
        // instantiate the correct VLR class
        if (recID >= 34735 && recID <= 34757)
        {
            
            printSep();
            std::cout << "GeoKey descriptor found..." << std::endl;
            cGeoKey tempGK(inPlsFile_, &recID);
            vlrHeaderArr[i] = tempGK;
            
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
            
            cLutHeader* tempVlr = new cLutHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            tempVlr->read(inPlsFile_);
            tempVlr->readLutTable(inPlsFile_);
            
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
