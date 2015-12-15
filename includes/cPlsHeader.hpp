//
//  cPlsHeader.hpp
//  Project
//
//  Created by Antoine Cottin on 09/12/2015.
//
//

#ifndef plsHeaderClass_hpp
#define plsHeaderClass_hpp

// C++
#include <stdio.h>
#include <fstream>

// BOOST
#include <boost/cstdint.hpp>

// PulseWaves_Reload
#include "PulseWavesDefs.hpp"



#pragma pack(push, r1, 1)
class cPlsHeader
{
    
public:
  
    I8      fileSignature_[16];
    U32     globalParameter_;
    U32     fileSourceID_;
    U32     guid01_;
    U16     guid02_;
    U16     guid03_;
    U8      guid04_[8];
    I8      systemID_[64];
    I8      generatingSoftware_[64];
    U16     day_;
    U16     year_;
    U8      versionMajor_;
    U8      versionMinor_;
    U16     headerSize_;
    I64 	dataOffet_;
    I64 	nPulses_;
    U32     pulseFormat_;
    U32     pulseAttributes_;
    U32     pulseSize_;
    U32     pulseCompression_;
    I64 	reserved_;
    U32     nVLR_;
    I32 	nAVLR_;
    F64     scaleT_;
    F64     offsetT_;
    I64 	minT_;
    I64 	maxT_;
    F64     scaleX_;
    F64 	scaleY_;
    F64 	scaleZ_;
    F64 	offsetX_;
    F64 	offsetY_;
    F64 	offsetZ_;
    F64 	minX_;
    F64 	maxX_;
    F64 	minY_;
    F64 	maxY_;
    F64 	minZ_;
    F64 	maxZ_;
    

    
    cPlsHeader();
    ~cPlsHeader(){};
    
    // public methods for the header
    void read(std::fstream*);
    
    void print() const;
    
    void write() const;
    

    
};
#pragma pack(pop, r1)


#endif /* plsHeaderClass_hpp */
