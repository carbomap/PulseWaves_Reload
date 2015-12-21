/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 PulseWaves.hpp
 
 PURPOSE:
 
 Header of the PulseWaves class.
 
 COPYRIGHT:
 
 (c) Antoine Cottin, Carbomap Ltd. - 12/2015
 
 This is free software; you can redistribute and/or modify it under the
 terms of the GNU Lesser General Licence as published by the Free Software
 Foundation. See the COPYING file for more information.
 
 This software is distributed WITHOUT ANY WARRANTY and without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 
 AUTHOR:
 
 a.cottin@carbomap.com  -  http://www.carbomap.com
 
 HISTORY:
 
 01/12/2015 - Created by Antoine C.
 15/12/2015 - Adding new interface methods - Antoine C.
                ::getHeader();
                ::getVlr();
                ::getPulse();
                ::getPulsePtr();
                ::printPulse();
                ::printPulses();
 
 -----------------------------------------------------------------------------
 */



#ifndef PulseWaves_hpp
#define PulseWaves_hpp



// C++
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <memory>

// Boost
#include <boost/cstdint.hpp>
#include <boost/lexical_cast.hpp>

// PulseWaves_Reload
#include "PulseWavesDefs.hpp"
#include "cVlr.hpp"
#include "cPlsHeader.hpp"
#include "cGeoKey.hpp"
#include "cPlsPulse.hpp"
#include "cAVlr.hpp"



class PulseWaves
{

	// Private data members
    std::string plsFilePath_;       // String representing the fully qualified PLS file name path
	std::string wvsFilePath_;       // String representing the fully qualified WVS file name path
    std::fstream* inPlsFile_;       // fstream pointer to the pls file
    cPlsHeader* plsHeader_;         // Pointer to an instance of the PLS HEADER file
    std::vector<U32> plsVlrID_;      // vector that contains the VLR ID in reading orfer
    std::vector<U32> plsVLRType_;      // vector that contains the VLR ID in reading orfer
    std::vector<cVlrHeader> plsVlrArr_;         // pointer to an array of VLR objects
    std::vector<cGeoKey> plsGeoKey_;            // pointer to an array containing the Geokeys
    std::vector<std::shared_ptr<cVlrHeader > > plsSuperVlrArr_;
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
//        plsVlrArr_ = 0;
        plsPulseArr_ = 0;
        plsAVlrArr_ = 0;
        
    };

    static void printSep();
    
    // method to get the file header
    cPlsHeader* getHeader();
    // method to get the vlr's ID array
    std::vector<U32> getVlrIDs();
    // method to get the vlr based on its ID
    std::shared_ptr<cVlrHeader> getVlr(I32);
    
    // method to get one pulse record based on its index
    plsPulseRec getPulses(I64) const;
    // method to get an array of pulse records based on an index array
    std::vector<plsPulseRec> getPulses(std::vector<I64>) const;
    
    // method to get one wave based on its index
    plsPulseRec getWaves(I64) const;
    // method to get an array of pulses based on an index array
    std::vector<plsPulseRec> getWaves(std::vector<I64>) const;
    
    
    void printPulse(I64) const;
    void printPulses() const;
    

    
};

#endif /* PulseWaves_hpp */
