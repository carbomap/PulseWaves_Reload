//
//  cGeoKey.cpp
//  Project
//
//  Created by Antoine Cottin on 11/12/2015.
//
//

#include "../includes/cGeoKey.hpp"
#include <iostream>

cGeoKeyHeader::cGeoKeyHeader() : cVlrHeader()
{
//        cVlrHeader* vlrHeader = new cVlrHeader;
}



void cGeoKeyHeader::read(std::fstream* inFile)
{
    
    inFile->read((char *)&gKeyDirectoryVersion_, sizeof(gKeyDirectoryVersion_));
    inFile->read((char *)&gKeyRevision_, sizeof(gKeyRevision_));
    inFile->read((char *)&gKeyMinorRevision_, sizeof(gKeyMinorRevision_));
    inFile->read((char *)&gKeyNumberOfKeys_, sizeof(gKeyNumberOfKeys_));
    
};



void cGeoKeyHeader::print() const
{
    std::cout << "geoKey directory version: " << gKeyDirectoryVersion_ << std::endl;
    std::cout << "geoKey revision: " << gKeyRevision_ << std::endl;
    std::cout << "geoKey minor revision: " << gKeyMinorRevision_ << std::endl;
    std::cout << "geoKey number of keys: " << gKeyNumberOfKeys_ << std::endl;
    
};



cGeoKey::cGeoKey()
{

}



void cGeoKey::read(std::fstream* inFile)
{
    
    inFile->read((char *)&gKeyID_, sizeof(gKeyID_));
    inFile->read((char *)&gKeyTiffTagLocation_, sizeof(gKeyTiffTagLocation_));
    inFile->read((char *)&gKeyCount_, sizeof(gKeyCount_));
    inFile->read((char *)&gKeyValueOffset_, sizeof(gKeyValueOffset_));
    
}


void cGeoKey::print() const
{
    
    std::cout << "geoKey identity: " << gKeyID_ << std::endl;
    std::cout << "geoKey Tiff tag location: " << gKeyTiffTagLocation_ << std::endl;
    std::cout << "geoKey count: " << gKeyCount_ << std::endl;
    std::cout << "geoKey value offset: " << gKeyValueOffset_ << std::endl;
}