//
//  PulseWaves.cpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Antoine Cottin. All rights reserved.
//

#include "../includes/PulseWaves.hpp"
#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;

PulseWaves::PulseWaves(string inFile)
{
	plsFilePath_ = inFile;
	std::cout << plsFilePath_ << std::endl;
	//    this->setPlsHeader();
	//    this->setPlsPulserec();
	//    this->setWvsHeader();
	this->readHeader();
	wvsHeader_ 	= new wvs_header;
	plsHeader_ 	= new pls_header;
	plsPulserec = new pls_pulserec;
	this->displayHeaderInformation();

};

// Default destructor
//~PulseWaves(){};

// public methods for the header
void PulseWaves::setPlsHeader()
{
	plsHeader_ = new pls_header;
}

void PulseWaves::setWvsHeader()
{
	wvsHeader_ = new wvs_header;
}

void PulseWaves::setPlsPulserec()
{
	plsPulserec = new pls_pulserec;
}

void PulseWaves::displayHeaderInformation() const
{

	std::cout << "" << std::endl;

	std::cout << "File signature:\t\t ";
	for (int i =0; i < 16; i++) {
		std::cout << plsHeader_->fileSignature[i];
	}
	std::cout << std::endl;

	std::cout << "Global Parameter:\t " << plsHeader_->globalParameter << std::endl;
	std::cout << "File Source ID:\t\t " << plsHeader_->fileSourceID << std::endl;
	std::cout << "GUID 01:\t\t\t " << plsHeader_->guid01 << std::endl;
	std::cout << "GUID 02:\t\t\t " << plsHeader_->guid02 << std::endl;
	std::cout << "GUID 03:\t\t\t " << plsHeader_->guid03 << std::endl;

	std::cout << "GUID 04:\t\t\t ";
	for (int i =0; i < 8; i++) {
		std::cout << boost::lexical_cast<std::string>(plsHeader_->guid04[i]);
	}
	std::cout << std::endl;

	std::cout << "System ID:\t\t\t ";
	for (int i =0; i < 64; i++) {
		std::cout << plsHeader_->systemID[i];
	}
	std::cout << std::endl;

	std::cout << "Software ID:\t\t ";
	for (int i =0; i < 64; i++) {
		std::cout << plsHeader_->generatingSoftware[i];
	}
	std::cout << std::endl;


	std::cout << "Day:\t\t\t\t " << plsHeader_->day << std::endl;
	std::cout << "Year:\t\t\t\t " << plsHeader_->year << std::endl;
	std::cout << "Header size:\t\t " << plsHeader_->headerSize << " Bytes" << std::endl;
	std::cout << "Version Major:\t\t " << boost::lexical_cast<std::string>(plsHeader_->versionMajor) << std::endl;
	std::cout << "Version Minor:\t\t " << boost::lexical_cast<std::string>(plsHeader_->versionMinor) << std::endl;
	std::cout << "Header Size:\t\t " << plsHeader_->headerSize << std::endl;
	std::cout << "Pulse Data Offet:\t " << plsHeader_->dataOffet << " Bytes" << std::endl;
	std::cout << "Number of Pulses:\t " << plsHeader_->nPulses << std::endl;
	std::cout << "Pulse Format:\t\t " << plsHeader_->pulseFormat << std::endl;
	std::cout << "pulse Attributes:\t " << plsHeader_->pulseAttributes << std::endl;
	std::cout << "pulse Size:\t\t\t " << plsHeader_->pulseSize << " Bytes" << std::endl;
	if (plsHeader_->pulseCompression == 0){std::cout << "Pulses are NOT compressed..." << std::endl;} else {std::cout << "Pulses are compressed..." << std::endl;}
	std::cout << "Number of VLR:\t\t " << plsHeader_->nVLR << std::endl;
	std::cout << "Number of AVLR:\t\t " << plsHeader_->nAVLR << std::endl;
	std::cout << "Time Scale/Offset:\t " << plsHeader_->scaleT << ", " << plsHeader_->offsetT << std::endl;
	std::cout << "Min/Max Time:\t\t " << plsHeader_->minT << ", " << plsHeader_->maxT << std::endl;
	std::cout << "Scale XYZ:\t\t\t " << plsHeader_->scaleX << ", " << plsHeader_->scaleY << ", " << plsHeader_->scaleZ << std::endl;
	std::cout << "Offset XYZ:\t\t\t " << plsHeader_->offsetX << ", " << plsHeader_->offsetY << ", " << plsHeader_->offsetZ << std::endl;
	std::cout << "Minimum XYZ:\t\t " << plsHeader_->minX << ", " << plsHeader_->minY << ", " << plsHeader_->minZ << std::endl;
	std::cout << "Maximum XYZ:\t\t " << plsHeader_->maxX << ", " << plsHeader_->maxY << ", " << plsHeader_->maxZ << std::endl;

	std::cout << "" << std::endl;

}

pls_header PulseWaves::getPlsHeader() const {return *plsHeader_;}
string PulseWaves::getSystemID() const {return boost::lexical_cast<std::string>(*plsHeader_->systemID);}
string PulseWaves::getSoftwareID() const {return boost::lexical_cast<std::string>(*plsHeader_->generatingSoftware);}
boost::uint16_t PulseWaves::getDay() const {return plsHeader_->day;}
boost::uint16_t PulseWaves::getYear() const { return plsHeader_->year;}
boost::uint8_t PulseWaves::getVersionMajor() const {return plsHeader_->versionMajor;}
boost::uint8_t PulseWaves::getVersionMinor()const{return plsHeader_->versionMinor;}
boost::uint16_t PulseWaves::getHeaderSize()const {return plsHeader_->headerSize;}
boost::uint64_t PulseWaves::getOffsetToPulses()const{return plsHeader_->dataOffet;}
boost::uint64_t PulseWaves::getNumbOfPulses()const{return plsHeader_->nPulses;}
boost::uint32_t PulseWaves::getPulseFormat()const{return plsHeader_->pulseFormat;}
boost::uint32_t PulseWaves::getPulseAttrib()const{return plsHeader_->pulseAttributes;}
boost::uint32_t PulseWaves::getPulseSize()const{return plsHeader_->pulseSize;}
boost::uint32_t PulseWaves::getPulseCompress()const{return plsHeader_->pulseCompression;}
boost::uint32_t PulseWaves::getNumbOfVLR()const{return plsHeader_->nVLR;}
boost::int32_t PulseWaves::getNumbOfAVLR()const{return plsHeader_->nAVLR;}
double PulseWaves::getTimeScale()const{return plsHeader_->scaleT;}
double PulseWaves::getTimeOffset()const{return plsHeader_->offsetT;}
boost::uint64_t PulseWaves::getTimeMin()const{return plsHeader_->minT;}
boost::uint64_t PulseWaves::getTMax()const{return plsHeader_->maxT;}
double PulseWaves::getXScale()const{return plsHeader_->scaleX;}
double PulseWaves::getYScale()const{return plsHeader_->scaleY;}
double PulseWaves::getZScale()const{return plsHeader_->scaleZ;}
double PulseWaves::getXOffset()const{return plsHeader_->offsetX;}
double PulseWaves::getYOffset()const{return plsHeader_->offsetY;}
double PulseWaves::getZOffset()const{return plsHeader_->offsetZ;}
double PulseWaves::getXMin()const{return plsHeader_->minX;}
double PulseWaves::getXMax()const{return plsHeader_->maxX;}
double PulseWaves::getYMin()const{return plsHeader_->minY;}
double PulseWaves::getYMax()const{return plsHeader_->maxY;}
double PulseWaves::getZMin()const{return plsHeader_->minZ;}
double PulseWaves::getZMax()const{return plsHeader_->maxZ;}


// public methods for the vlr

// public methods for the data block


// Private methods for reading the file
void PulseWaves::readHeader()
{

	// getting header structure
	pls_header plsHeader;

	// instantiation of the fstream class object
	std::fstream plsFile;
	plsFile.open(plsFilePath_.c_str(), std::ios::in | std::ios::binary);

	// checking if the file exist
	if (plsFile.fail())
	{
		std::cout << "ERROR: Cannot open the file..." << std::endl;
		exit(1);
	}

	// reading the file into memory
	plsFile.read((char *)&plsHeader, sizeof(plsHeader));

	// closing file
	plsFile.close();

	// assigning the read structure into the object data member
	*plsHeader_ = plsHeader;


};


void readVLR()
{

};


void readData()
{

};


void readAVLR()
{

};
