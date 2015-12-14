//
//  cPlsPulse.hpp
//  Project
//
//  Created by Antoine Cottin on 13/12/2015.
//
//

#ifndef cPlsPulse_hpp
#define cPlsPulse_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "PulseWavesDefs.hpp"



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
    
    void read(std::fstream*);
    void print();
    
    
    
};




class plsPulseArray
{
    
private:
    
    I64             nPulses_;
    plsPulseRec*    plsPulseArr_;      // Pointer to an plsPulseRec array - which will hold part or all the records
    
public:
    
    plsPulseArray(std::fstream*);      // Default Constructor that loads all the records of the file
    plsPulseArray(std::fstream*, std::vector<I64>);   // Constructor that takes an array of index
    ~plsPulseArray()                   // Default Constructor
    {
        plsPulseArr_ = 0;
    }
    
    I64 getNPulses();               // Return the number of pulse in the object
    plsPulseRec getPulse(I64);      // Return a pulse record
    
};






#endif /* cPlsPulse_hpp */
