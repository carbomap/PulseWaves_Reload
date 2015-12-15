//
//  PulseWaves.cpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
//

// C++
#include <iostream>
#include <fstream>

// BOOST
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
//#include <boost/filesystem.hpp>
//#include <boost/timer/timer.hpp>

// PulseWaves_Reload
#include "../includes/PulseWaves.hpp"
#include "../includes/cGeoKey.hpp"
#include "../includes/cVlr.hpp"
#include "../includes/cPlsPulse.hpp"
#include "../includes/cAVlr.hpp"



//-----------------------------------------------------------------------------
PulseWaves::PulseWaves(std::string inFile)
{
	
//    boost::timer::cpu_timer timer;

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
        
        printSep();
        std::cout << "Reading header..." << std::endl;
        this->readHeader();
        
        printSep();
        std::cout << "Reading Variable Length Records..." << std::endl;
        this->readVLR();
        
        printSep();
        std::cout << "Reading Data Records..." << std::endl;
        this->readData();
        
        printSep();
        std::cout << "Reading Append Variable Length Record..." << std::endl;
        this->readAVLR();

    }
    
    inPlsFile_->close();
    
//    std::cout << timer.format() << '\n';
    
};



//-----------------------------------------------------------------------------
void PulseWaves::printSep()
{
    std::cout << "########################################################" << std::endl;
};



//-----------------------------------------------------------------------------
void PulseWaves::readHeader()
{

	// getting header structure
	cPlsHeader* plsHeader = new cPlsHeader;
    plsHeader->read(inPlsFile_);
    plsHeader->print();

    plsHeader_ = plsHeader;

};



//-----------------------------------------------------------------------------
// Method that reads the VLR and store them into an array
void PulseWaves::readVLR()
{

    cVlrHeader* vlrHeaderArr = new cVlrHeader[plsHeader_->nVLR_];
    
    // reading the VLR
    for (U32 i = 0; i < plsHeader_->nVLR_; i++)
    {
        // getting the VLR ID record number
        U32 recID = cVlrHeader::whichVLR(inPlsFile_);
//        std::cout << "reckon recID: " << recID << std::endl;
        
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
            
            vlrHeaderArr[i] = *tempVlr;
            
        }
        else if (recID >= 300001 && recID < 300255)
        {
            printSep();
            std::cout << "Lookup Table descriptor found..." << std::endl;
            
            cLutHeader* tempVlr = new cLutHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            tempVlr->read(inPlsFile_);
            tempVlr->readLutTable(inPlsFile_);
            
            vlrHeaderArr[i] = *tempVlr;
            
        }
        else
        {
            printSep();
            std::cout << "Generic VLR descriptor found..." << std::endl;
            std::cout << "VLR #" << recID << std::endl;
            
            cVlrHeader* tempVlr = new cVlrHeader;
            tempVlr->cVlrHeader::read(inPlsFile_);
            inPlsFile_->seekg(tempVlr->recordLengthAfterHeader_, std::ios::cur);
            
            vlrHeaderArr[i] = *tempVlr;
        }
        
        
        
    }
    
    plsVlrArr_ = vlrHeaderArr;
    
};



//-----------------------------------------------------------------------------
void PulseWaves::readData()
{

    plsPulseArray* plsPlsArr_ = new plsPulseArray(inPlsFile_, plsHeader_);
    plsPulseArr_ = plsPlsArr_;
    
};



//-----------------------------------------------------------------------------
void PulseWaves::readAVLR()
{
    
    if (plsHeader_->nAVLR_ == 0) {
        std::cout << "No AVLR in the file, nothing to read..." << std::endl;
    } else {
        std::cout << "The file contains " << plsHeader_->nAVLR_ << " Append Variable Lenght Record" << std::endl;
        inPlsFile_->seekg(0, std::ios::end);
        cAVlrHeader* tempAVlr = new cAVlrHeader;
        tempAVlr->read(inPlsFile_);
        tempAVlr->print();
        plsAVlrArr_ = tempAVlr;
        tempAVlr = 0;
        }
    
};



//-----------------------------------------------------------------------------
cPlsHeader* PulseWaves::getHeader()
{
    return plsHeader_;
}



//-----------------------------------------------------------------------------
cVlrHeader* PulseWaves::getVlr(I32 index)
{
    if (index <= plsHeader_->nVLR_) {
        std::cout << "Index outside the allowed range..." << std::endl;
    } else {
        return &plsVlrArr_[index];
    }
}



//-----------------------------------------------------------------------------
plsPulseRec PulseWaves::getPulse(I64 index) const
{
    if (index >= plsHeader_->nPulses_) {
        std::cout << "Index outside the allowed range..." << std::endl;
    } else {
        plsPulseRec retRec = plsPulseArr_->getPulse(index);
        return retRec;
    }
}



//-----------------------------------------------------------------------------
plsPulseRec* PulseWaves::getPulsePtr(I64 index)
{
    if (index <= plsHeader_->nPulses_) {
        std::cout << "Index outside the allowed range..." << std::endl;
    } else {
        plsPulseRec* retRec = plsPulseArr_->getPulseAddrs(index);
        return retRec;
    }

}



//-----------------------------------------------------------------------------
void PulseWaves::printPulse(I64 index) const
{
    
    if (index >= plsHeader_->nPulses_) {
        std::cout << "Index outside allowed range..." << std::endl;
    } else { plsPulseArr_->getPulse(index).print();}
    
}



//-----------------------------------------------------------------------------
void PulseWaves::printPulses() const
{
    
    for (I64 i = 0; i < plsHeader_->nPulses_; i++) {
        (plsPulseArr_->getPulse(i)).print();
    }
}