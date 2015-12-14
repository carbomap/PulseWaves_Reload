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
//struct wvs_header_strc{
//	boost::int8_t       signature[16];
//	boost::uint32_t     compression;
//    boost::uint8_t      reserve[44];
//};
//#pragma pack(pop, r1)


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
