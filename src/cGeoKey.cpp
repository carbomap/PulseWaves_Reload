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
    
    inFile->read((char *)&gKeyDirectoryVersion, sizeof(gKeyDirectoryVersion));
    inFile->read((char *)&gKeyRevision, sizeof(gKeyRevision));
    inFile->read((char *)&gKeyMinorRevision, sizeof(gKeyMinorRevision));
    inFile->read((char *)&gKeyNumberOfKeys, sizeof(gKeyNumberOfKeys));
    
};



void cGeoKeyHeader::print() const
{
    
};



cGeoKey::cGeoKey()
{

}



void cGeoKey::read(std::fstream* inFile)
{
    
    inFile->read((char *)&gKeyID, sizeof(gKeyID));
    inFile->read((char *)&gKeyTiffTagLocation, sizeof(gKeyTiffTagLocation));
    inFile->read((char *)&gKeyCount, sizeof(gKeyCount));
    inFile->read((char *)&gKeyValueOffset, sizeof(gKeyValueOffset));
    
}


void cGeoKey::print() const
{
    
}