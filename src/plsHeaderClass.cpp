//
//  plsHeaderClass.cpp
//  Project
//
//  Created by Antoine Cottin on 09/12/2015.
//
//

#include "../includes/plsHeaderClass.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>

plsHeaderClass::plsHeaderClass()
{
    
}

void plsHeaderClass::read(std::fstream* plsInFile)
{
    
    // reading the file into memory
    plsInFile->read((char *)&fileSignature, sizeof(fileSignature));
    plsInFile->read((char *)&globalParameter, sizeof(globalParameter));
    plsInFile->read((char *)&fileSourceID, sizeof(fileSourceID));
    plsInFile->read((char *)&guid01, sizeof(guid01));
    plsInFile->read((char *)&guid02, sizeof(guid02));
    plsInFile->read((char *)&guid03, sizeof(guid03));
    plsInFile->read((char *)&guid04, sizeof(guid04));
    plsInFile->read((char *)&systemID, sizeof(systemID));
    plsInFile->read((char *)&generatingSoftware, sizeof(generatingSoftware));
    plsInFile->read((char *)&day, sizeof(day));
    plsInFile->read((char *)&year, sizeof(year));
    plsInFile->read((char *)&versionMajor, sizeof(versionMajor));
    plsInFile->read((char *)&versionMinor, sizeof(versionMinor));
    plsInFile->read((char *)&headerSize, sizeof(headerSize));
    plsInFile->read((char *)&dataOffet, sizeof(dataOffet));
    plsInFile->read((char *)&nPulses, sizeof(nPulses));
    plsInFile->read((char *)&pulseFormat, sizeof(pulseFormat));
    plsInFile->read((char *)&pulseAttributes, sizeof(pulseAttributes));
    plsInFile->read((char *)&pulseSize, sizeof(pulseSize));
    plsInFile->read((char *)&pulseCompression, sizeof(pulseCompression));
    plsInFile->read((char *)&reserved, sizeof(reserved));
    plsInFile->read((char *)&nVLR, sizeof(nVLR));
    plsInFile->read((char *)&nAVLR, sizeof(nAVLR));
    plsInFile->read((char *)&scaleT, sizeof(scaleT));
    plsInFile->read((char *)&offsetT, sizeof(offsetT));
    plsInFile->read((char *)&minT, sizeof(minT));
    plsInFile->read((char *)&maxT, sizeof(maxT));
    plsInFile->read((char *)&scaleX, sizeof(scaleX));
    plsInFile->read((char *)&scaleY, sizeof(scaleY));
    plsInFile->read((char *)&scaleZ, sizeof(scaleZ));
    plsInFile->read((char *)&offsetX, sizeof(offsetX));
    plsInFile->read((char *)&offsetY, sizeof(offsetY));
    plsInFile->read((char *)&offsetZ, sizeof(offsetZ));
    plsInFile->read((char *)&minX, sizeof(minX));
    plsInFile->read((char *)&maxX, sizeof(maxX));
    plsInFile->read((char *)&minY, sizeof(minY));
    plsInFile->read((char *)&maxY, sizeof(maxY));
    plsInFile->read((char *)&minZ, sizeof(minZ));
    plsInFile->read((char *)&maxZ, sizeof(maxZ));
    

};



void plsHeaderClass::print() const
{
    
//    this->printSep();
    
    std::cout << "" << std::endl;
    
    std::cout << "File signature:\t\t ";
    for (int i = 0; i < 16; i++) {
        std::cout << fileSignature[i];
    }
    std::cout << std::endl;
    
    std::cout << "Global Parameter:\t " << globalParameter << std::endl;
    std::cout << "File Source ID:\t\t " << fileSourceID << std::endl;
    std::cout << "GUID 01:\t\t\t " << guid01 << std::endl;
    std::cout << "GUID 02:\t\t\t " << guid02 << std::endl;
    std::cout << "GUID 03:\t\t\t " << guid03 << std::endl;
    
    std::cout << "GUID 04:\t\t\t ";
    for (int i =0; i < 8; i++) {
        std::cout << boost::lexical_cast<std::string>(guid04[i]);
    }
    std::cout << std::endl;
    
    std::cout << "System ID:\t\t\t ";
    for (int i =0; i < 64; i++) {
        std::cout << systemID[i];
    }
    std::cout << std::endl;
    
    std::cout << "Software ID:\t\t ";
    for (int i =0; i < 64; i++) {
        std::cout << generatingSoftware[i];
    }
    std::cout << std::endl;
    
    
    std::cout << "Day:\t\t\t\t " << day << std::endl;
    std::cout << "Year:\t\t\t\t " << year << std::endl;
    std::cout << "Header size:\t\t " << headerSize << " Bytes" << std::endl;
    std::cout << "Version Major:\t\t " << boost::lexical_cast<std::string>(versionMajor) << std::endl;
    std::cout << "Version Minor:\t\t " << boost::lexical_cast<std::string>(versionMinor) << std::endl;
    std::cout << "Header Size:\t\t " << headerSize << std::endl;
    std::cout << "Pulse Data Offet:\t " << dataOffet << " Bytes" << std::endl;
    std::cout << "Number of Pulses:\t " << nPulses << std::endl;
    std::cout << "Pulse Format:\t\t " << pulseFormat << std::endl;
    std::cout << "pulse Attributes:\t " << pulseAttributes << std::endl;
    std::cout << "pulse Size:\t\t\t " << pulseSize << " Bytes" << std::endl;
    if (pulseCompression == 0){std::cout << "Pulses are NOT compressed..." << std::endl;} else {std::cout << "Pulses are compressed..." << std::endl;}
    std::cout << "Number of VLR:\t\t " << nVLR << std::endl;
    std::cout << "Number of AVLR:\t\t " << nAVLR << std::endl;
    std::cout << "Time Scale/Offset:\t " << scaleT << ", " << offsetT << std::endl;
    std::cout << "Min/Max Time:\t\t " << minT << ", " << maxT << std::endl;
    std::cout << "Scale XYZ:\t\t\t " << scaleX << ", " << scaleY << ", " << scaleZ << std::endl;
    std::cout << "Offset XYZ:\t\t\t " << offsetX << ", " << offsetY << ", " << offsetZ << std::endl;
    std::cout << "Minimum XYZ:\t\t " << minX << ", " << minY << ", " << minZ << std::endl;
    std::cout << "Maximum XYZ:\t\t " << maxX << ", " << maxY << ", " << maxZ << std::endl;
    
    std::cout << "" << std::endl;
    
}
//
//
//
//
//string plsHeaderClass::getSystemID() const {return boost::lexical_cast<std::string>(*systemID);}
//string plsHeaderClass::getSoftwareID() const {return boost::lexical_cast<std::string>(*generatingSoftware);}
//boost::uint16_t plsHeaderClass::getDay() const {return day;}
//boost::uint16_t plsHeaderClass::getYear() const { return year;}
//boost::uint8_t plsHeaderClass::getVersionMajor() const {return versionMajor;}
//boost::uint8_t plsHeaderClass::getVersionMinor()const{return versionMinor;}
//boost::uint16_t plsHeaderClass::getHeaderSize()const {return headerSize;}
//boost::uint64_t plsHeaderClass::getOffsetToPulses()const{return dataOffet;}
//boost::uint64_t plsHeaderClass::getNumbOfPulses()const{return nPulses;}
//boost::uint32_t plsHeaderClass::getPulseFormat()const{return pulseFormat;}
//boost::uint32_t plsHeaderClass::getPulseAttrib()const{return pulseAttributes;}
//boost::uint32_t plsHeaderClass::getPulseSize()const{return pulseSize;}
//boost::uint32_t plsHeaderClass::getPulseCompress()const{return pulseCompression;}
//boost::uint32_t plsHeaderClass::getNumbOfVLR()const{return nVLR;}
//boost::int32_t plsHeaderClass::getNumbOfAVLR()const{return nAVLR;}
//double plsHeaderClass::getTimeScale()const{return scaleT;}
//double plsHeaderClass::getTimeOffset()const{return offsetT;}
//boost::uint64_t plsHeaderClass::getTimeMin()const{return minT;}
//boost::uint64_t plsHeaderClass::getTMax()const{return maxT;}
//double plsHeaderClass::getXScale()const{return scaleX;}
//double plsHeaderClass::getYScale()const{return scaleY;}
//double plsHeaderClass::getZScale()const{return scaleZ;}
//double plsHeaderClass::getXOffset()const{return offsetX;}
//double plsHeaderClass::getYOffset()const{return offsetY;}
//double plsHeaderClass::getZOffset()const{return offsetZ;}
//double plsHeaderClass::getXMin()const{return minX;}
//double plsHeaderClass::getXMax()const{return maxX;}
//double plsHeaderClass::getYMin()const{return minY;}
//double plsHeaderClass::getYMax()const{return maxY;}
//double plsHeaderClass::getZMin()const{return minZ;}
//double plsHeaderClass::getZMax()const{return maxZ;}
