/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 cGeoKey.cpp
 
 PURPOSE:
 
 Implementation of the GeoKey related (cGeoKey, cGeoKeyDir, cGeoKeyDir_subKey, cGeoKeyDblPrm, cGeoKeyAscii) classes.
 
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

// BOOST
#include <boost/lexical_cast.hpp>

// PulseWaves_Reload
#include "../includes/cGeoKey.hpp"
#include "../includes/PulseWavesDefs.hpp"



//-----------------------------------------------------------------------------
cGeoKey::cGeoKey(std::fstream* inFile, U32* recID) : cVlrHeader()
{

    if (*recID == 34735)
    {
        
        std::cout << "GeoKeyDirectoryTag Record found..." << std::endl;
        this->cVlrHeader::read(inFile);
        this->cVlrHeader::print();
        
        cGeoKeyDir* GeoKeyDir_ = new cGeoKeyDir;
        GeoKeyDir_->read(inFile);
        GeoKeyDir_->print();
        GeoKeyDir_->readGeoKeySubDir(inFile);
        
    }
    else if (*recID == 34736)
    {
       
        std::cout << "GeoDoubleParamsTag Record found..." << std::endl;
        
        cGeoKeyDblPrm*  cGeoKeyDP_ = new cGeoKeyDblPrm;
        cGeoKeyDP_->cVlrHeader::read(inFile);
        cGeoKeyDP_->cVlrHeader::print();
        cGeoKeyDP_->read(inFile);
        cGeoKeyDP_->print();
        
        
    }
    else if (*recID == 34737)
    {
        std::cout << "GeoAsciiParamsTag Record found..." << std::endl;
        cGeoKeyAscii*  cGeoKeyAC_ = new cGeoKeyAscii;
        cGeoKeyAC_->cVlrHeader::read(inFile);
        cGeoKeyAC_->cVlrHeader::print();
        cGeoKeyAC_->read(inFile);
        cGeoKeyAC_->print();
        
    }

}



//-----------------------------------------------------------------------------
void cGeoKey::read(std::fstream* inFile)
{
    
}



//-----------------------------------------------------------------------------
void cGeoKey::print() const
{
    
}



//-----------------------------------------------------------------------------
cGeoKeyDir::cGeoKeyDir()
{
    
}



//-----------------------------------------------------------------------------
void cGeoKeyDir::read(std::fstream* inFile)
{
    
    inFile->read((char *)&gKeyDirectoryVersion_, sizeof(gKeyDirectoryVersion_));
    inFile->read((char *)&gKeyRevision_, sizeof(gKeyRevision_));
    inFile->read((char *)&gKeyMinorRevision_, sizeof(gKeyMinorRevision_));
    inFile->read((char *)&gKeyNumberOfKeys_, sizeof(gKeyNumberOfKeys_));
    
};



//-----------------------------------------------------------------------------
void cGeoKeyDir::readGeoKeySubDir(std::fstream* inFile)
{
    
    // creating an array of GeokeySubDir
    cGeoKeyDir_subKey* cGeoKeySubDirArr_ = new cGeoKeyDir_subKey[gKeyNumberOfKeys_];
    
    
    for (int j = 0; j < gKeyNumberOfKeys_; j++)
    {
        
        std::cout << "GeoKey " << j+1 << " of " << gKeyNumberOfKeys_ << std::endl;
        
        cGeoKeyDir_subKey tempGKeySDir;
        tempGKeySDir.read(inFile);
        tempGKeySDir.print();
//        printSep();
        // putting GeoKey header in the vlr array
        cGeoKeySubDirArr_[j] = tempGKeySDir;
    
    }
    
}



//-----------------------------------------------------------------------------
void cGeoKeyDir::print() const
{
    std::cout << "geoKey directory version: " << gKeyDirectoryVersion_ << std::endl;
    std::cout << "geoKey revision: " << gKeyRevision_ << std::endl;
    std::cout << "geoKey minor revision: " << gKeyMinorRevision_ << std::endl;
    std::cout << "geoKey number of keys: " << gKeyNumberOfKeys_ << std::endl;
    
};



//-----------------------------------------------------------------------------
cGeoKeyDir_subKey::cGeoKeyDir_subKey()
{

    
}



//-----------------------------------------------------------------------------
void cGeoKeyDir_subKey::read(std::fstream* inFile)
{
    
    inFile->read((char *)&gKeyID_, sizeof(gKeyID_));
    inFile->read((char *)&gKeyTiffTagLocation_, sizeof(gKeyTiffTagLocation_));
    inFile->read((char *)&gKeyCount_, sizeof(gKeyCount_));
    inFile->read((char *)&gKeyValueOffset_, sizeof(gKeyValueOffset_));
    
}



//-----------------------------------------------------------------------------
void cGeoKeyDir_subKey::print() const
{
    
    std::cout << "geoKey identity: " << gKeyID_ << std::endl;
    std::cout << "geoKey Tiff tag location: " << gKeyTiffTagLocation_ << std::endl;
    std::cout << "geoKey count: " << gKeyCount_ << std::endl;
    std::cout << "geoKey value offset: " << gKeyValueOffset_ << std::endl;
}



//-----------------------------------------------------------------------------
cGeoKeyDblPrm::cGeoKeyDblPrm() : cVlrHeader()
{
    
}



//-----------------------------------------------------------------------------
void cGeoKeyDblPrm::read(std::fstream* inFile)
{
 
    size_t size = recordLengthAfterHeader_ / 8;
//    F64* vecArr_ = new F64[size];
    F64 vecArr_[size];
    inFile->read((char *)&vecArr_, sizeof(vecArr_));
    
}



//-----------------------------------------------------------------------------
void cGeoKeyDblPrm::print() const
{
    for (int z = 0; z < (this->cVlrHeader::recordLengthAfterHeader_ / 8); z++) {
        if (z == (this->cVlrHeader::recordLengthAfterHeader_ / 8) - 1) {
            std::cout << &vecArr_[z];
        } else std::cout << &vecArr_[z] << ", ";
        
    }
    
    std::cout << "" << std::endl;

}



//-----------------------------------------------------------------------------
cGeoKeyAscii::cGeoKeyAscii()
{
    
}



//-----------------------------------------------------------------------------
void cGeoKeyAscii::read(std::fstream* inFile)
{
    
    size_t size = this->cVlrHeader::recordLengthAfterHeader_;
    U8* vVecArr_ =  new U8[size];
//    inFile->read((char *)&vVecArr_, sizeof(vVecArr_));
    
    
    
    U8 dum;
    for(size_t i=0; i<size; i++)
    {
        inFile->read((char *)&dum, sizeof(dum));
        vVecArr_[i] = dum;
    }

    
//    vecArr_ = &vVecArr_;
//    inFile->read((char *)&vVecArr_, sizeof(vVecArr_));
    
//    std::vector<U8> vVecArr_;
//    U8 dum;
//    for(int i=0; i<size; i++)
//    {
//        inFile->read((char *)&dum, sizeof(dum));
//        vVecArr_.push_back(dum);
//        
//    }
    
    vecArr_ = vVecArr_;
}



//-----------------------------------------------------------------------------
void cGeoKeyAscii::print() const
{

        std::cout << vecArr_ << std::endl;
    
}




