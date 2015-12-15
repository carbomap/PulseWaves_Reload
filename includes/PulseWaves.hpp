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
#include "cPlsPulse.hpp"
#include "cAVlr.hpp"


//#pragma pack(push, r1, 1)
//class cWvsHeader
//{
//public:
//
//	I8      signature[16];
//	U32     compression;
//  U8      reserve[44];
//
//cWvsHeader();
//~cWvsHeader();
//
//void read(std::fstream*);
//void print() const;
//};
//#pragma pack(pop, r1)




class PulseWaves
{

	// Private data members
    std::string plsFilePath_;       // String representing the fully qualified PLS file name path
	std::string wvsFilePath_;       // String representing the fully qualified WVS file name path
    std::fstream* inPlsFile_;       // fstream pointer to the pls file
    cPlsHeader* plsHeader_;         // Pointer to an instance of the PLS HEADER file
    cVlrHeader* plsVlrArr_;         // pointer to an array of VLR objects
    plsPulseArray* plsPulseArr_;    // Pointer to the Pulse Array
    cAVlrHeader* plsAVlrArr_;       // Pointer to an array that holds the AVLR records
    
	// Private methods for reading the file
    
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
        plsVlrArr_ = 0;
        plsPulseArr_ = 0;
        plsAVlrArr_ = 0;
        
    };

    static void printSep();
    
    cPlsHeader* getHeader();
    cVlrHeader* getVlr(I32);
    plsPulseRec getPulse(I64) const;
    plsPulseRec* getPulsePtr(I64);
    
    void printPulse(I64) const;
    void printPulses() const;
    

    
};

#endif /* PulseWaves_hpp */
