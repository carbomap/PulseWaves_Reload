//
//  cPlsHeader.cpp
//  Project
//
//  Created by Antoine Cottin on 09/12/2015.
//
//

#include "../includes/cPlsHeader.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>



//-----------------------------------------------------------------------------
cPlsHeader::cPlsHeader()
{
    
}



//-----------------------------------------------------------------------------
void cPlsHeader::read(std::fstream* plsInFile)
{
    
    // reading the file into memory
    plsInFile->read((char *)&fileSignature_, sizeof(fileSignature_));
    plsInFile->read((char *)&globalParameter_, sizeof(globalParameter_));
    plsInFile->read((char *)&fileSourceID_, sizeof(fileSourceID_));
    plsInFile->read((char *)&guid01_, sizeof(guid01_));
    plsInFile->read((char *)&guid02_, sizeof(guid02_));
    plsInFile->read((char *)&guid03_, sizeof(guid03_));
    plsInFile->read((char *)&guid04_, sizeof(guid04_));
    plsInFile->read((char *)&systemID_, sizeof(systemID_));
    plsInFile->read((char *)&generatingSoftware_, sizeof(generatingSoftware_));
    plsInFile->read((char *)&day_, sizeof(day_));
    plsInFile->read((char *)&year_, sizeof(year_));
    plsInFile->read((char *)&versionMajor_, sizeof(versionMajor_));
    plsInFile->read((char *)&versionMinor_, sizeof(versionMinor_));
    plsInFile->read((char *)&headerSize_, sizeof(headerSize_));
    plsInFile->read((char *)&dataOffet_, sizeof(dataOffet_));
    plsInFile->read((char *)&nPulses_, sizeof(nPulses_));
    plsInFile->read((char *)&pulseFormat_, sizeof(pulseFormat_));
    plsInFile->read((char *)&pulseAttributes_, sizeof(pulseAttributes_));
    plsInFile->read((char *)&pulseSize_, sizeof(pulseSize_));
    plsInFile->read((char *)&pulseCompression_, sizeof(pulseCompression_));
    plsInFile->read((char *)&reserved_, sizeof(reserved_));
    plsInFile->read((char *)&nVLR_, sizeof(nVLR_));
    plsInFile->read((char *)&nAVLR_, sizeof(nAVLR_));
    plsInFile->read((char *)&scaleT_, sizeof(scaleT_));
    plsInFile->read((char *)&offsetT_, sizeof(offsetT_));
    plsInFile->read((char *)&minT_, sizeof(minT_));
    plsInFile->read((char *)&maxT_, sizeof(maxT_));
    plsInFile->read((char *)&scaleX_, sizeof(scaleX_));
    plsInFile->read((char *)&scaleY_, sizeof(scaleY_));
    plsInFile->read((char *)&scaleZ_, sizeof(scaleZ_));
    plsInFile->read((char *)&offsetX_, sizeof(offsetX_));
    plsInFile->read((char *)&offsetY_, sizeof(offsetY_));
    plsInFile->read((char *)&offsetZ_, sizeof(offsetZ_));
    plsInFile->read((char *)&minX_, sizeof(minX_));
    plsInFile->read((char *)&maxX_, sizeof(maxX_));
    plsInFile->read((char *)&minY_, sizeof(minY_));
    plsInFile->read((char *)&maxY_, sizeof(maxY_));
    plsInFile->read((char *)&minZ_, sizeof(minZ_));
    plsInFile->read((char *)&maxZ_, sizeof(maxZ_));
    

};



//-----------------------------------------------------------------------------
void cPlsHeader::print() const
{
    
//    this->printSep();
    
    std::cout << "" << std::endl;
    
    std::cout << "File signature:\t\t ";
    for (int i = 0; i < 16; i++) {
        std::cout << fileSignature_[i];
    }
    std::cout << std::endl;
    
    std::cout << "Global Parameter:\t " << globalParameter_ << std::endl;
    std::cout << "File Source ID:\t\t " << fileSourceID_ << std::endl;
    std::cout << "GUID 01:\t\t\t " << guid01_ << std::endl;
    std::cout << "GUID 02:\t\t\t " << guid02_ << std::endl;
    std::cout << "GUID 03:\t\t\t " << guid03_ << std::endl;
    
    std::cout << "GUID 04:\t\t\t ";
    for (int i =0; i < 8; i++) {
        std::cout << boost::lexical_cast<std::string>(guid04_[i]);
    }
    std::cout << std::endl;
    
    std::cout << "System ID:\t\t\t ";
    for (int i =0; i < 64; i++) {
        std::cout << systemID_[i];
    }
    std::cout << std::endl;
    
    std::cout << "Software ID:\t\t ";
    for (int i =0; i < 64; i++) {
        std::cout << generatingSoftware_[i];
    }
    std::cout << std::endl;
    
    
    std::cout << "Day/Year:\t\t\t " << day_ << "/" << year_ << std::endl;
    std::cout << "Header size:\t\t " << headerSize_ << " Bytes" << std::endl;
    std::cout << "Version Major.Minor: " << static_cast<unsigned>(versionMajor_) << "." << static_cast<unsigned>(versionMinor_) << std::endl;
    std::cout << "Header Size:\t\t " << headerSize_ << std::endl;
    std::cout << "Pulse Data Offet:\t " << dataOffet_ << " Bytes" << std::endl;
    std::cout << "Number of Pulses:\t " << nPulses_ << std::endl;
    std::cout << "Pulse Format:\t\t " << pulseFormat_ << std::endl;
    std::cout << "pulse Attributes:\t " << pulseAttributes_ << std::endl;
    std::cout << "pulse Size:\t\t\t " << pulseSize_ << " Bytes" << std::endl;
    if (pulseCompression_ == 0){std::cout << "Pulses are NOT compressed..." << std::endl;} else {std::cout << "Pulses are compressed..." << std::endl;}
    std::cout << "Number of VLR:\t\t " << nVLR_ << std::endl;
    std::cout << "Number of AVLR:\t\t " << nAVLR_ << std::endl;
    std::cout << "Time Scale/Offset:\t " << scaleT_ << ", " << offsetT_ << std::endl;
    std::cout << "Min/Max Time:\t\t " << minT_ << ", " << maxT_ << std::endl;
    std::cout << "Scale XYZ:\t\t\t " << scaleX_ << ", " << scaleY_ << ", " << scaleZ_ << std::endl;
    std::cout << "Offset XYZ:\t\t\t " << offsetX_ << ", " << offsetY_ << ", " << offsetZ_ << std::endl;
    std::cout << "Minimum XYZ:\t\t " << minX_ << ", " << minY_ << ", " << minZ_ << std::endl;
    std::cout << "Maximum XYZ:\t\t " << maxX_ << ", " << maxY_ << ", " << maxZ_ << std::endl;
    
    std::cout << "" << std::endl;
    
}



//-----------------------------------------------------------------------------
void cPlsHeader::write() const
{
    
}
