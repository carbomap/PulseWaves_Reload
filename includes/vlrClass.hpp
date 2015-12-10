//
//  vlrClass.hpp
//  pulsewaves_reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
//

#ifndef vlrClass_hpp
#define vlrClass_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/cstdint.hpp>
#include <boost/lexical_cast.hpp>
#include "PulseWavesDefs.hpp"


#pragma pack(push, r1, 1)
class vlrHeaderClass
{
    
public:
    
    I8       userID[PLS_USER_ID_SIZE];
    U32      recordID;
    U32      reserved;
    I64      recordLengthAfterHeader;
    I8       description[PLS_DESCRIPTION_SIZE];
    
    
//    virtual void readVLR(std::fstream&);
    
    vlrHeaderClass();
    ~vlrHeaderClass(){};

    
    // this method will test the type of VLR before
    static U32 whichVLR(std::fstream* inFile)
    {
        
        // when testing the VLR ID then at the end need to get back to the start
        U32 originCursorPos = inFile->tellg();
        
        I8 tUserID[16];
        inFile->read((char *)&tUserID, sizeof(tUserID));
        U32 tRecID;
        inFile->read((char *)&tRecID, sizeof(tRecID));
        U32 tReserved;
        inFile->read((char *)&tReserved, sizeof(tReserved));
        I64 tRecLength;
        inFile->read((char *)&tRecLength, sizeof(tRecLength));
        I8 tDescription[64];
        inFile->read((char *)&tDescription, sizeof(tDescription));
        
        // debug -> to mimic the read of the actual VLR - this line needs to be commented out
//        inFile->seekg(tRecLength, std::ios::cur);
        // uncomment this line once the full reader implemented
        inFile->seekg(originCursorPos, std::ios::beg);
        
        return tRecID;
        
    };
    
    virtual void read(std::fstream*);
    virtual void print() const;
    
    
private:
    
    // size of VLR header
    //U32 headerSize_ = 128;
    //U32 originCursorPos = 0;

    
};
#pragma pack(pop, r1)

//// The Scanner VLR descriptor - 100,001 <= Record ID < 100,255
#pragma pack(push, 1)
class vlrScannerClass : public vlrHeaderClass
{
    
public:
    
    U32    size;
    U32    reserved;
    I8     instrument[64];
    I8     serial[64];
    F32    wavelength;
    F32    outgoingPulseWidth;
    U32    scanPattern;
    U32    numberOfMirrorFacets;
    I32    scanFrequency;
    I32    scanMinAngle;
    I32    scanMaxAngle;
    I32    pulseFrequency;
    F32    beamDiameterAtExit;
    F32    beamDivergeance;
    F32    minimalRange;
    F32    maximalRange;
    I8     description[PLS_DESCRIPTION_SIZE];
    
    vlrScannerClass();
    ~vlrScannerClass(){};
    
    virtual void read(std::fstream*);
    virtual void print() const;
    
};
#pragma pack(pop,1)


#endif /* vlrClass_hpp */
