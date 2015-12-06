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
#include "PulseWavesDefs.hpp"




using namespace std;


#pragma pack(push, r1, 1)
struct pls_header_strc{
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



#pragma pack(push, r1, 1)
struct wvs_header_strc{
	boost::int8_t       signature[16];
	boost::uint32_t     compression;
    boost::uint8_t      reserve[44];
};
#pragma pack(pop, r1)





//#pragma pack(push, r1, 1)
//struct vlr_header_strc{
//    boost::int8_t       userID[PLS_USER_ID_SIZE];
//    boost::uint32_t     recordID;
//    boost::uint32_t     reserved;
//    boost::int64_t      recordLengthAfterHeader;
//    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
//};
//#pragma pack(pop, r1)


struct pls_pulserec_strc{
	boost::int64_t      gpsTime; 		//        ; GPS time
    boost::int64_t      waveOffset; 	//        ; Bytes offset to wave record
	boost::int32_t      anchorX; 		//        ; Anchor point of the wave
	boost::int32_t      anchorY; 		//        ; Anchor point of the wave
	boost::int32_t      anchorZ; 		//        ; Anchor point of the wave
	boost::int32_t      targetX; 		//        ; Ending point of the wave
	boost::int32_t      targetY; 		//        ; Ending point of the wave
	boost::int32_t      targetZ; 		//        ; Ending point of the wave
	boost::int16_t      firstReturn; 	//        ; Duration in sampling units from the anchor point to the first recorded waveform sample
	boost::int16_t      lastReturn; 	//        ; Duration in sampling units from the anchor point to the last recorded waveform sample
	boost::uint16_t     pulseDesIndex; 	//		  ; Pulse description index bit 0-7; Reserved bit 8-11; Edge of scan line bit 12; Scan direction bit 13; Mirror facet bit 14-15
	boost::uint8_t      intensity; 		//        ; Intensity of the pulse in DN
	boost::uint8_t      classification; //        ; Classification of the pulse
};


#pragma pack(push, r1, 1)
struct avlr_header_strc{
    boost::int8_t       userID[PLS_USER_ID_SIZE];
    boost::uint32_t     recordID;
    boost::uint32_t     reserved;
    boost::int64_t      recordLengthBeforeFooter;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
};
#pragma pack(pop, r1)


// The Scanner VLR descriptor - 100,001 <= Record ID < 100,255
#pragma pack(push, r1, 1)
struct scanner_vlr_strc{
    boost::uint32_t     size;
    boost::uint32_t     reserved;
    boost::int8_t       instrument[64];
    boost::int8_t       serial[64];
    float               avelength;
    float               outgoingPulseWidth;
    boost::uint32_t     scanPattern;
    boost::uint32_t     numberOfMirrorFacets;
    boost::int32_t      scanFrequency;
    boost::int32_t      scanMinAngle;
    boost::int32_t      scanMaxAngle;
    boost::int32_t      pulseFrequency;
    float               beamDiameterAtExit;
    float               beamDivergeance;
    float               minimalRange;
    float               maximalRange;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
};
#pragma pack(pop, r1)


// The Pulse Sampling VLR descriptor - 200,001 <= Record ID < 200,255
#pragma pack(push, r1, 1)
struct pulseSampling_vlr_strc{
    boost::uint32_t     size;
    boost::uint32_t     reserved;
    boost::int32_t      opticalCenterToAnchorPoint;
    boost::uint16_t     numberOfExtraWaveBytes;
    boost::uint16_t     numberOfSamplings;
    float               sampleUnit;
    boost::uint32_t     compression;
    boost::uint32_t     scannerIndex;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
};
#pragma pack(pop, r1)


// The Look-Up Table VLR descriptor - 300,001 <= Record ID < 300,255
#pragma pack(push, r1, 1)
struct lookUpTable_vlr_strc{
    boost::uint32_t     size;
    boost::uint32_t     reserved;
    boost::uint32_t     numberOfTable;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
};
#pragma pack(pop, r1)


// The Look-Up Table Record VLR descriptor
#pragma pack(push, r1, 1)
struct lutRecord_vlr_strc{
    boost::uint32_t     size;
    boost::uint32_t     reserved;
    boost::uint32_t     numberOfEntries;
    boost::uint16_t     unitOfMeasurement;
    boost::uint8_t      dataType;
    boost::uint8_t      options;
    boost::uint32_t     compression;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
};
#pragma pack(pop, r1)



// The Sampling Record
#pragma pack(push, r1, 1)
struct samplingRecord_strc{
    boost::uint32_t     size;
    boost::uint32_t     reserved;
    boost::uint8_t      channel;
    boost::uint8_t      notUsed;
    boost::uint8_t      bitsForDurationFromAnchor;
    float               scaleForDurationFromAnchor;
    float               offsetForDurationFromAnchor;
    boost::uint8_t      bitsForNumberOfSegments;
    boost::uint8_t      bitsForNumberOfSamples;
    boost::uint16_t     numberOfSegments;
    boost::uint32_t     numberOfSamples;
    boost::uint16_t     bitsPerSample;
    boost::uint16_t     lutIndex;
    float               sampleUnits;
    boost::uint32_t     compression;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
};
#pragma pack(pop, r1)




class PulseWaves
{

	// Private data members
	string plsFilePath_;            // String representing the fully qualified file name path
	string wvsFilePath_;            // String representing the fully qualified file name path of the corresponding waveform file
	pls_header_strc *plsHeader_;         // Pointer to the Header of the WVS file
	//plsVlrArray_;                 // Pointer to the Variable Length Records (in reading order - Header/Key)
	//pulserec *plsPulseDes;        // Pointer to an array of structure holding all the Pulse descriptor VLR
	pls_pulserec_strc *plsPulserec_;      // Pointer to the records of the PLS file hold in the data member
	//plsPulseInd;                  // Pointer to the index of the records from the PLS file hold in plsPulseRec
	//plsPulseIndSel;               // Pointer to an index of the selected pulses defined by pulsewaves::getPulses
	//plsAvlrarray;                 // Pointer to the Append Variable Length Records (in reading order - Header/Key)
	wvs_header_strc *wvsHeader_;         // Pointer to the header of the WVS file
	//wvsWaveRec;                   // Pointer to the records of the WVS file corresponding to the records in plsPulseRec
	//wvsWaveInd;

	// Private methods for reading the file
    void printSep() const;
	void readHeader();
	void readVLR();
	void readData();
	void readAVLR();


public:

	// Default constructor
	PulseWaves(string);
	// Default destructor
    ~PulseWaves()
    {
        delete plsHeader_;
        delete plsPulserec_;
        delete wvsHeader_;
    };

	// public methods for the header
	void displayHeaderInformation() const;
	pls_header_strc getPlsHeader() const;
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

#endif /* PulseWaves_hpp */
