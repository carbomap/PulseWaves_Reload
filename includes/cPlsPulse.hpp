/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 cPlsPulse.hpp
 
 PURPOSE:
 
 Headers for the Pulse record (plsPulseRec) and the Pulse Array (plsPulseArray) classes.
 
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
 
 13/12/2015 - Created by Antoine C.
 
 -----------------------------------------------------------------------------
 */



#ifndef cPlsPulse_hpp
#define cPlsPulse_hpp


// C++
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

// PulseWaves_Reload
#include "PulseWavesDefs.hpp"
#include "cPlsHeader.hpp"



class plsPulseRec
{
    
public:
    
    I64      gpsTime_; 		// GPS time
    I64      waveOffset_; 	// Bytes offset to wave record
    I32      anchorX_; 		// Anchor point of the wave
    I32      anchorY_; 		// Anchor point of the wave
    I32      anchorZ_; 		// Anchor point of the wave
    I32      targetX_; 		// Ending point of the wave
    I32      targetY_; 		// Ending point of the wave
    I32      targetZ_; 		// Ending point of the wave
    I16      firstReturn_; 	// Duration in sampling units from the anchor point to the first recorded waveform sample
    I16      lastReturn_; 	// Duration in sampling units from the anchor point to the last recorded waveform sample
    U16     pulseDesIndex_; // Pulse description index bit 0-7; Reserved bit 8-11; Edge of scan line bit 12; Scan direction bit 13; Mirror facet bit 14-15
    U8      intensity_; 	// Intensity of the pulse in DN
    U8      classification_; // Classification of the pulse
    
    plsPulseRec();
    ~plsPulseRec(){};
    
    void getPulses(std::string, cPlsHeader*, I64);
    void read(std::fstream*);
    void print();
    
    
    
};




class plsPulseArray
{
    
private:
    
    I64             nPulses_;
    
    std::vector<plsPulseRec>*   plsPulseArr_;      // Pointer to an plsPulseRec array - which will hold part or all the records
    
    cPlsHeader*     pPlsHeader_;       // Pointer to the file header
    
public:
    
    plsPulseArray(std::fstream*, cPlsHeader*);      // Default Constructor that loads all the records of the file
    plsPulseArray(std::fstream*, std::vector<I64>);   // Constructor that takes an array of index
    ~plsPulseArray()                   // Default Constructor
    {
        plsPulseArr_ = 0;
    }
    
    I64 getNPulses();               // Return the number of pulse in the object
    plsPulseRec getPulse(I64) const;      // Return a pulse record
//    plsPulseRec* getPulseAddrs(I64);
    
};






#endif /* cPlsPulse_hpp */
