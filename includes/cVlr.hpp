//
//  cVlr.hpp
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


#pragma pack(push,1)
class cVlrHeader
{
    
public:
    
    I8       userID[PLS_USER_ID_SIZE];
    U32      recordID;
    U32      reserved;
    I64      recordLengthAfterHeader;
    I8       description[PLS_DESCRIPTION_SIZE];
    
    
//    virtual void readVLR(std::fstream&);
    
    cVlrHeader();
    ~cVlrHeader(){};

    
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
#pragma pack(pop)

//// The Scanner VLR descriptor - 100,001 <= Record ID < 100,255
#pragma pack(push, 1)
class cVlrScanner : public cVlrHeader
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
    F32    scanFrequency;
    F32    scanMinAngle;
    F32    scanMaxAngle;
    F32    pulseFrequency;
    F32    beamDiameterAtExit;
    F32    beamDivergeance;
    F32    minimalRange;
    F32    maximalRange;
    I8     description[PLS_DESCRIPTION_SIZE];
    
    cVlrScanner();
    ~cVlrScanner(){};
    
    virtual void read(std::fstream*);
    virtual void print() const;
    
};
#pragma pack(pop)



// The Sampling Record
#pragma pack(push, 1)
class cVlrSamplingRecord
{
    
public:
    
    U32     size;
    U32     reserved;
    U8      type;
    U8      channel;
    U8      notUsed;
    U8      bitsForDurationFromAnchor;
    F32     scaleForDurationFromAnchor;
    F32     offsetForDurationFromAnchor;
    U8      bitsForNumberOfSegments;
    U8      bitsForNumberOfSamples;
    U16     numberOfSegments;
    U32     numberOfSamples;
    U16     bitsPerSample;
    U16     lutIndex;
    F32     sampleUnits;
    U32     compression;
    I8      description[PLS_DESCRIPTION_SIZE];
    
    cVlrSamplingRecord();
    ~cVlrSamplingRecord(){};
    
    virtual void read(std::fstream*);
    virtual void print() const;
    
};
#pragma pack(pop)



// The Pulse Sampling VLR descriptor - 200,001 <= Record ID < 200,255
#pragma pack(push, 1)
class cVlrPulseSampling : public cVlrHeader, public cVlrSamplingRecord
{
    
public:

    U32     size;
    U32     reserved;
    U32     opticalCenterToAnchorPoint;
    U16     numberOfExtraWaveBytes;
    U16     numberOfSamplings;
    F32     sampleUnit;
    U32     compression;
    U32     scannerIndex;
    I8      description[PLS_DESCRIPTION_SIZE];

cVlrPulseSampling();
~cVlrPulseSampling()
    {
        samplingRecordArr_ = 0;
    };

virtual void read(std::fstream*);
virtual void print() const;
    
void read_SamplingRecords(std::fstream*);
    
private:
    
    cVlrSamplingRecord* samplingRecordArr_;
    

};
#pragma pack(pop)



// The Look-Up Table VLR descriptor - 300,001 <= Record ID < 300,255
#pragma pack(push, 1)
class cLutHeader : public cVlrHeader
{
    
public:
    
    U32     size;
    U32     reserved;
    I32     numberOfTable;
    I8      description[PLS_DESCRIPTION_SIZE];
    
    cLutHeader();
    ~cLutHeader(){};
    
    virtual void read(std::fstream*);
    virtual void print() const;
    
    
};
#pragma pack(pop)



// The Look-Up Table Record VLR descriptor
#pragma pack(push, 1)
class cLutRecord : public cLutHeader
{
    
public:

    U32     size;
    U32     reserved;
    U32     numberOfEntries;
    U16     unitOfMeasurement;
    U8      dataType;
    U8      options;
    U32     compression;
    I8      description[PLS_DESCRIPTION_SIZE];
    
    cLutRecord();
    ~cLutRecord(){};
    
    virtual void read(std::fstream*);
    virtual void print() const;
    
};
#pragma pack(pop)


#endif /* vlrClass_hpp */
