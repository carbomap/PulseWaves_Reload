//
//  PulseWaves.hpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
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
#include "cVlr.hpp"
#include "cPlsHeader.hpp"
#include "cGeoKey.hpp"


//#pragma pack(push, r1, 1)
//struct pls_header_strc{
//	boost::int8_t	fileSignature[16];
//	boost::uint32_t globalParameter;
//	boost::uint32_t fileSourceID;
//	boost::uint32_t guid01;
//	boost::uint16_t guid02;
//	boost::uint16_t guid03;
//	boost::uint8_t 	guid04[8];
//	boost::int8_t 	systemID[64];
//	boost::int8_t 	generatingSoftware[64];
//	boost::uint16_t day;
//	boost::uint16_t year;
//	boost::uint8_t 	versionMajor;
//	boost::uint8_t 	versionMinor;
//	boost::uint16_t headerSize;
//	boost::int64_t 	dataOffet;
//	boost::int64_t 	nPulses;
//	boost::uint32_t pulseFormat;
//	boost::uint32_t pulseAttributes;
//	boost::uint32_t pulseSize;
//	boost::uint32_t pulseCompression;
//	boost::int64_t 	reserved;
//	boost::uint32_t nVLR;
//	boost::int32_t 	nAVLR;
//	double 			scaleT;
//	double 			offsetT;
//	boost::int64_t 	minT;
//	boost::int64_t 	maxT;
//	double 			scaleX;
//	double 			scaleY;
//	double 			scaleZ;
//	double 			offsetX;
//	double 			offsetY;
//	double 			offsetZ;
//	double 			minX;
//	double 			maxX;
//	double 			minY;
//	double 			maxY;
//	double 			minZ;
//	double 			maxZ;
//};
//#pragma pack(pop, r1)
//
//
//
//#pragma pack(push, r1, 1)
//struct wvs_header_strc{
//	boost::int8_t       signature[16];
//	boost::uint32_t     compression;
//    boost::uint8_t      reserve[44];
//};
//#pragma pack(pop, r1)


//struct pls_pulserec_strc{
//	boost::int64_t      gpsTime; 		//        ; GPS time
//    boost::int64_t      waveOffset; 	//        ; Bytes offset to wave record
//	boost::int32_t      anchorX; 		//        ; Anchor point of the wave
//	boost::int32_t      anchorY; 		//        ; Anchor point of the wave
//	boost::int32_t      anchorZ; 		//        ; Anchor point of the wave
//	boost::int32_t      targetX; 		//        ; Ending point of the wave
//	boost::int32_t      targetY; 		//        ; Ending point of the wave
//	boost::int32_t      targetZ; 		//        ; Ending point of the wave
//	boost::int16_t      firstReturn; 	//        ; Duration in sampling units from the anchor point to the first recorded waveform sample
//	boost::int16_t      lastReturn; 	//        ; Duration in sampling units from the anchor point to the last recorded waveform sample
//	boost::uint16_t     pulseDesIndex; 	//		  ; Pulse description index bit 0-7; Reserved bit 8-11; Edge of scan line bit 12; Scan direction bit 13; Mirror facet bit 14-15
//	boost::uint8_t      intensity; 		//        ; Intensity of the pulse in DN
//	boost::uint8_t      classification; //        ; Classification of the pulse
//};
//
//
//#pragma pack(push, r1, 1)
//struct avlr_header_strc{
//    boost::int8_t       userID[PLS_USER_ID_SIZE];
//    boost::uint32_t     recordID;
//    boost::uint32_t     reserved;
//    boost::int64_t      recordLengthBeforeFooter;
//    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
//};
//#pragma pack(pop, r1)

//
//
//// The Look-Up Table VLR descriptor - 300,001 <= Record ID < 300,255
//#pragma pack(push, r1, 1)
//struct lookUpTable_vlr_strc{
//    boost::uint32_t     size;
//    boost::uint32_t     reserved;
//    boost::uint32_t     numberOfTable;
//    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
//};
//#pragma pack(pop, r1)
//
//
//// The Look-Up Table Record VLR descriptor
//#pragma pack(push, r1, 1)
//struct lutRecord_vlr_strc{
//    boost::uint32_t     size;
//    boost::uint32_t     reserved;
//    boost::uint32_t     numberOfEntries;
//    boost::uint16_t     unitOfMeasurement;
//    boost::uint8_t      dataType;
//    boost::uint8_t      options;
//    boost::uint32_t     compression;
//    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
//};
//#pragma pack(pop, r1)
//
//
//
//// The Sampling Record
//#pragma pack(push, r1, 1)
//struct samplingRecord_strc{
//    boost::uint32_t     size;
//    boost::uint32_t     reserved;
//    boost::uint8_t      channel;
//    boost::uint8_t      notUsed;
//    boost::uint8_t      bitsForDurationFromAnchor;
//    float               scaleForDurationFromAnchor;
//    float               offsetForDurationFromAnchor;
//    boost::uint8_t      bitsForNumberOfSegments;
//    boost::uint8_t      bitsForNumberOfSamples;
//    boost::uint16_t     numberOfSegments;
//    boost::uint32_t     numberOfSamples;
//    boost::uint16_t     bitsPerSample;
//    boost::uint16_t     lutIndex;
//    float               sampleUnits;
//    boost::uint32_t     compression;
//    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
//};
//#pragma pack(pop, r1)




class PulseWaves
{

	// Private data members
    std::string plsFilePath_;       // String representing the fully qualified PLS file name path
	std::string wvsFilePath_;       // String representing the fully qualified WVS file name path
    std::fstream* inPlsFile_;       // fstream pointer to the pls file
    cPlsHeader* plsHeader_;     // Pointer to an instance of the PLS HEADER file
    cVlrHeader* plsVlrArr_;     // pointer to an array of VLR objects
    cGeoKey* cGeoKeyArr_;       // Pointer to an array of GeoKey object
    
	// Private methods for reading the file
    void printSep() const;
    void readHeader();
	void readVLR();
	void readData();
	void readAVLR();


public:

	// Default constructor
	PulseWaves(std::string);
	// Default destructor
    ~PulseWaves()
    {
        inPlsFile_ = 0;
        plsHeader_ = 0;
    };


};

#endif /* PulseWaves_hpp */
