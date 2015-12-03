//
//  PulseWaves.hpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Antoine Cottin. All rights reserved.
//

#ifndef PulseWaves_hpp
#define PulseWaves_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/cstdint.hpp>
#include <boost/lexical_cast.hpp>
#include <string.h>

#endif /* PulseWaves_hpp */

using namespace std;


#pragma pack(push, r1, 1)
struct pls_header{
	boost::int8_t	fileSignature[16];
	boost::uint32_t globalParameter;
	boost::uint32_t fileSourceID;
	boost::uint32_t guid01;
	boost::uint16_t guid02;
	boost::uint16_t guid03;
	boost::uint8_t 	guid04[8];
	boost::int8_t 	systemID[64];
	boost::int8_t 	generatingSoftware[64];
	boost::uint16_t day;
	boost::uint16_t year;
	boost::uint8_t 	versionMajor;
	boost::uint8_t 	versionMinor;
	boost::uint16_t headerSize;
	boost::int64_t 	dataOffet;
	boost::int64_t 	nPulses;
	boost::uint32_t pulseFormat;
	boost::uint32_t pulseAttributes;
	boost::uint32_t pulseSize;
	boost::uint32_t pulseCompression;
	boost::int64_t 	reserved;
	boost::uint32_t nVLR;
	boost::int32_t 	nAVLR;
	double 			scaleT;
	double 			offsetT;
	boost::int64_t 	minT;
	boost::int64_t 	maxT;
	double 			scaleX;
	double 			scaleY;
	double 			scaleZ;
	double 			offsetX;
	double 			offsetY;
	double 			offsetZ;
	double 			minX;
	double 			maxX;
	double 			minY;
	double 			maxY;
	double 			minZ;
	double 			maxZ;
};
#pragma pack(pop, r1)


struct wvs_header{
	char signature[16];
	unsigned long compression;
	char reserve[44];
};



struct pls_pulserec{
	long long 		gpsTime; 		//        ; GPS time
	long long 		waveOffset; 	//        ; Bytes offset to wave record
	long 			anchorX; 		//        ; Anchor point of the wave
	long 			anchorY; 		//        ; Anchor point of the wave
	long 			anchorZ; 		//        ; Anchor point of the wave
	long 			targetX; 		//        ; Ending point of the wave
	long 			targetY; 		//        ; Ending point of the wave
	long 			targetZ; 		//        ; Ending point of the wave
	short 			firstReturn; 	//        ; Duration in sampling units from the anchor point to the first recorded waveform sample
	short 			lastReturn; 	//        ; Duration in sampling units from the anchor point to the last recorded waveform sample
	unsigned short 	pulseDesIndex; 	//		  ; Pulse description index bit 0-7; Reserved bit 8-11; Edge of scan line bit 12; Scan direction bit 13; Mirror facet bit 14-15
	char 			intensity; 		//        ; Intensity of the pulse in DN
	char 			classification; //        ; Classification of the pulse
};



class PulseWaves
{

	// Private data members
	string plsFilePath_;            // String representing the fully qualified file name path
	string wvsFilePath_;            // String representing the fully qualified file name path of the corresponding waveform file
	pls_header *plsHeader_;         // Pointer to the Header of the WVS file
	//plsVlrArray_;                 // Pointer to the Variable Length Records (in reading order - Header/Key)
	//pulserec *plsPulseDes;        // Pointer to an array of structure holding all the Pulse descriptor VLR
	pls_pulserec *plsPulserec;      // Pointer to the records of the PLS file hold in the data member
	//plsPulseInd;                  // Pointer to the index of the records from the PLS file hold in plsPulseRec
	//plsPulseIndSel;               // Pointer to an index of the selected pulses defined by pulsewaves::getPulses
	//plsAvlrarray;                 // Pointer to the Append Variable Length Records (in reading order - Header/Key)
	wvs_header *wvsHeader_;         // Pointer to the header of the WVS file
	//wvsWaveRec;                   // Pointer to the records of the WVS file corresponding to the records in plsPulseRec
	//wvsWaveInd;

	// Private methods for reading the file
	void readHeader();
	void readVLR();
	void readData();
	void readAVLR();


public:

	// Default constructor
	PulseWaves(string);
	// Default destructor
	//~PulseWaves();

	// public methods for the header
	void displayHeaderInformation() const;
	void setPlsHeader();
	void setWvsHeader();
	void setPlsPulserec();
	pls_header 		getPlsHeader() const;
	string 			getSystemID() const;
	string 			getSoftwareID() const;
	boost::uint16_t getDay() const;
	boost::uint16_t getYear() const;
	boost::uint8_t 	getVersionMajor() const;
	boost::uint8_t 	getVersionMinor() const;
	boost::uint16_t getHeaderSize() const;
	boost::uint64_t getOffsetToPulses() const;
	boost::uint64_t getNumbOfPulses() const;
	boost::uint32_t getPulseFormat() const;
	boost::uint32_t getPulseAttrib() const;
	boost::uint32_t getPulseSize() const;
	boost::uint32_t getPulseCompress() const;
	boost::uint32_t getNumbOfVLR() const;
	boost::int32_t 	getNumbOfAVLR() const;
	double 			getTimeScale() const;
	double 			getTimeOffset() const;
	boost::uint64_t getTimeMin() const;
	boost::uint64_t getTMax() const;
	double 			getXScale() const;
	double 			getYScale() const;
	double 			getZScale() const;
	double 			getXOffset() const;
	double 			getYOffset() const;
	double 			getZOffset() const;
	double 			getXMin() const;
	double 			getXMax() const;
	double 			getYMin() const;
	double 			getYMax() const;
	double 			getZMin() const;
	double 			getZMax() const;

	// public methods for the vlr

	// public methods for the data block



};
