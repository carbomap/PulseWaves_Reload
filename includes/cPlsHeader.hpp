//
//  cPlsHeader.hpp
//  Project
//
//  Created by Antoine Cottin on 09/12/2015.
//
//

#ifndef plsHeaderClass_hpp
#define plsHeaderClass_hpp

#include <stdio.h>
#include <fstream>
#include <boost/cstdint.hpp>
#include "PulseWavesDefs.hpp"

#pragma pack(push, r1, 1)
class cPlsHeader
{
    
public:
  
    I8      fileSignature[16];
    U32     globalParameter;
    U32     fileSourceID;
    U32     guid01;
    U16     guid02;
    U16     guid03;
    U8      guid04[8];
    I8      systemID[64];
    I8      generatingSoftware[64];
    U16     day;
    U16     year;
    U8      versionMajor;
    U8      versionMinor;
    U16     headerSize;
    I64 	dataOffet;
    I64 	nPulses;
    U32     pulseFormat;
    U32     pulseAttributes;
    U32     pulseSize;
    U32     pulseCompression;
    I64 	reserved;
    U32     nVLR;
    I32 	nAVLR;
    F64     scaleT;
    F64     offsetT;
    I64 	minT;
    I64 	maxT;
    F64     scaleX;
    F64 	scaleY;
    F64 	scaleZ;
    F64 	offsetX;
    F64 	offsetY;
    F64 	offsetZ;
    F64 	minX;
    F64 	maxX;
    F64 	minY;
    F64 	maxY;
    F64 	minZ;
    F64 	maxZ;
    

    
    cPlsHeader();
    ~cPlsHeader(){};
    
    // public methods for the header
    void read(std::fstream*);
    
    void print() const;
    
    void write() const;
    

    
};
#pragma pack(pop, r1)


#endif /* plsHeaderClass_hpp */
