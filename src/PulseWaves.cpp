/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 PulseWaves.cpp
 
 PURPOSE:
 
 Implementation of the PulseWaves class.
 
 COPYRIGHT:
 
 (c) Antoine Cottin, Carbomap Ltd. - 12/2015
 
 This is free software; you can redistribute and/or modify it under the
 terms of the GNU Lesser General Licence as published by the Free Software
 Foundation. See the COPYING file for more information.
 
 This software is distributed WITHOUT ANY WARRANTY and without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 
 AUTHOR:
 
 a.cottin@carbomap.com  -  http://www.carbomap.com
 
 -----------------------------------------------------------------------------
 */



// C++
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

// BOOST
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
#include <boost/filesystem.hpp>
#include <boost/timer/timer.hpp>

// PulseWaves_Reload
#include "../includes/PulseWaves.hpp"
#include "../includes/cGeoKey.hpp"
#include "../includes/cVlr.hpp"
#include "../includes/cPlsPulse.hpp"
#include "../includes/cAVlr.hpp"



//-----------------------------------------------------------------------------
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

//    cVlrHeader* vlrHeaderArr = new cVlrHeader[plsHeader_->nVLR_];
    U32 gCount = 0;
    U32 hCount = 0;
    
    // reading the VLR
    for (U32 i = 0; i < plsHeader_->nVLR_; i++)
    {
        // getting the VLR ID record number
        U32 recID = cVlrHeader::whichVLR(inPlsFile_);
        plsVlrID_.push_back(recID);
        
//        std::cout << "reckon recID: " << recID << std::endl;
        
        // instantiate the correct VLR class
        if (recID >= 34735 && recID <= 34757)
        {
            
            printSep();
            std::cout << "GeoKey descriptor found..." << std::endl;
//            std::unique_ptr<cGeoKey> tempGK(new cGeoKey(inPlsFile_, &recID));
            
//            cGeoKey tempGK(inPlsFile_, &recID);
            
            std::unique_ptr<cGeoKey> tempGK (new cGeoKey(inPlsFile_, &recID));
            
//            vlrHeaderArr[i] = tempGK;
            
//            plsGeoKey_.push_back(tempGK);
            
            plsVLRType_.push_back(gCount + 100);
            gCount++;
            
            plsSuperVlrArr_.push_back( std::move(tempGK) );
            
        }
        else if (recID >= 100001 && recID < 100255)
        {
            
            printSep();
            std::cout << "Scanner descriptor found..." << std::endl;
            
//            cVlrScanner* tempVlr = new cVlrScanner;
            std::unique_ptr<cVlrScanner> tempVlr (new cVlrScanner());
//            cVlrScanner tempVlr;

            tempVlr->cVlrHeader::read(inPlsFile_);
            tempVlr->cVlrScanner::read(inPlsFile_);
            
            tempVlr->cVlrHeader::print();
            printSep();
            tempVlr->cVlrScanner::print();
            
//            vlrHeaderArr[i] = *tempVlr;
//            plsVlrArr_.push_back(tempVlr);
            
            plsVLRType_.push_back(hCount + 200);
            hCount++;
            
            plsSuperVlrArr_.push_back( std::move(tempVlr) );
            
        }
        else if (recID >= 200001  && recID < 200255)
        {
            
            printSep();
            std::cout << "Pulse sampling descriptor found..." << std::endl;
            
            cVlrPulseSampling tempVlr;// = new cVlrPulseSampling;
            tempVlr.cVlrHeader::read(inPlsFile_);
            tempVlr.cVlrHeader::print();
            printSep();
            
            tempVlr.cVlrPulseSampling::read(inPlsFile_);
            tempVlr.cVlrPulseSampling::print();
            printSep();
            
            tempVlr.cVlrPulseSampling::read_SamplingRecords(inPlsFile_);
            
//            vlrHeaderArr[i] = *tempVlr;
            plsVlrArr_.push_back(tempVlr);
            
            plsVLRType_.push_back(hCount + 200);
            hCount++;
            
        }
        else if (recID >= 300001 && recID < 300255)
        {
            printSep();
            std::cout << "Lookup Table descriptor found..." << std::endl;
            
            cLutHeader tempVlr;// = new cLutHeader;
            tempVlr.cVlrHeader::read(inPlsFile_);
            tempVlr.read(inPlsFile_);
            tempVlr.readLutTable(inPlsFile_);
            
            plsVlrArr_.push_back(tempVlr);
//            vlrHeaderArr[i] = *tempVlr;
            
            plsVLRType_.push_back(hCount + 200);
            hCount++;
            
        }
        else
        {
            printSep();
            std::cout << "Generic VLR descriptor found..." << std::endl;
            std::cout << "VLR #" << recID << std::endl;
            
            cVlrHeader tempVlr;// = new cVlrHeader;
            tempVlr.cVlrHeader::read(inPlsFile_);
            inPlsFile_->seekg(tempVlr.recordLengthAfterHeader_, std::ios::cur);
            
           plsVlrArr_.push_back(tempVlr);
//            vlrHeaderArr[i] = *tempVlr;
            
            plsVLRType_.push_back(hCount + 200);
            hCount++;
        }
        
        
        
    }
    
//    plsVlrArr_ = vlrHeaderArr;
    
};



//-----------------------------------------------------------------------------
void PulseWaves::readData()
{

//    plsPulseArray* plsPlsArr_ = new plsPulseArray(inPlsFile_, plsHeader_);
//    plsPulseArr_ = plsPlsArr_;
    
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
std::vector<U32> PulseWaves::getVlrIDs()
{

    return plsVlrID_;

}


//-----------------------------------------------------------------------------
cVlrHeader PulseWaves::getVlr(I32 index)
{
    
    if (plsVLRType_[index] < 200) {
        return plsGeoKey_[plsVLRType_[index] - 100];
    } else {
        return plsVlrArr_[plsVLRType_[index] - 200];
    }

}



//-----------------------------------------------------------------------------
plsPulseRec PulseWaves::getPulses(I64 index) const
{
    plsPulseRec retRec;
    retRec.getPulses(plsFilePath_, plsHeader_, index);
        
//        plsPulseRec retRec = plsPulseArr_->getPulse(index);
        
        return retRec;
    
}



//-----------------------------------------------------------------------------
std::vector<plsPulseRec> PulseWaves::getPulses(std::vector<I64> index) const
{
    
    std::vector<plsPulseRec> tempPulseVec(index.size());

    for (size_t i = 0; i < index.size(); i++)
    {
        tempPulseVec[i] = plsPulseArr_->getPulse(i);
    }
    
    return tempPulseVec;
    
}



//-----------------------------------------------------------------------------
plsPulseRec PulseWaves::getWaves(I64 index) const
{
    
    plsPulseRec tempulse = this->getPulses(index);
    
    // get waveform byte offset
    I64 byteOffset = tempulse.waveOffset_;
    
    // get puslse descriptor and parse it
    I8 plsVlrID = tempulse.pulseDesIndex_ & '000000000000000111';
    
    // get corresponding VLR
    
    
    // checking if any Extra-Bytes exist and if so, moving forward
    
    
    // extracting information from sampling records
    
    
    
}



//-----------------------------------------------------------------------------
std::vector<plsPulseRec> PulseWaves::getWaves(std::vector<I64> index) const
{
    
    
    
}



//-----------------------------------------------------------------------------
void PulseWaves::printPulse(I64 index) const
{
    
//    if (index >= plsHeader_->nPulses_) {
//        std::cout << "Index outside allowed range..." << std::endl;
//    } else { plsPulseArr_->getPulse(index).print();}
    
}



//-----------------------------------------------------------------------------
void PulseWaves::printPulses() const
{
    
//    for (I64 i = 0; i < plsHeader_->nPulses_; i++) {
//        (plsPulseArr_->getPulse(i)).print();
//    }
}