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
    
    I8       userID_[PLS_USER_ID_SIZE];
    U32      recordID_;
    U32      reserved_;
    I64      recordLengthAfterHeader_;
    I8       description_[PLS_DESCRIPTION_SIZE];
    
    
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
    
    U32    size_;
    U32    reserved_;
    I8     instrument_[64];
    I8     serial_[64];
    F32    wavelength_;
    F32    outgoingPulseWidth_;
    U32    scanPattern_;
    U32    numberOfMirrorFacets_;
    F32    scanFrequency_;
    F32    scanMinAngle_;
    F32    scanMaxAngle_;
    F32    pulseFrequency_;
    F32    beamDiameterAtExit_;
    F32    beamDivergeance_;
    F32    minimalRange_;
    F32    maximalRange_;
    I8     description_[PLS_DESCRIPTION_SIZE];
    
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
    
    U32     size_;
    U32     reserved_;
    U8      type_;
    U8      channel_;
    U8      notUsed_;
    U8      bitsForDurationFromAnchor_;
    F32     scaleForDurationFromAnchor_;
    F32     offsetForDurationFromAnchor_;
    U8      bitsForNumberOfSegments_;
    U8      bitsForNumberOfSamples_;
    U16     numberOfSegments_;
    U32     numberOfSamples_;
    U16     bitsPerSample_;
    U16     lutIndex_;
    F32     sampleUnits_;
    U32     compression_;
    I8      description_[PLS_DESCRIPTION_SIZE];
    
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

    U32     size_;
    U32     reserved_;
    U32     opticalCenterToAnchorPoint_;
    U16     numberOfExtraWaveBytes_;
    U16     numberOfSamplings_;
    F32     sampleUnit_;
    U32     compression_;
    U32     scannerIndex_;
    I8      description_[PLS_DESCRIPTION_SIZE];

    cVlrPulseSampling();
    ~cVlrPulseSampling()
    {
        samplingRecordArr_ = 0;
    };

    virtual void read(std::fstream*);
    void read_SamplingRecords(std::fstream*);
    virtual void print() const;

private:
    
    cVlrSamplingRecord* samplingRecordArr_;
    

};
#pragma pack(pop)



// The Look-Up Table Record VLR descriptor
#pragma pack(push, 1)
class cLutRecord
{
    
public:
    
    U32     size_;
    U32     reserved_;
    U32     numberOfEntries_;
    U16     unitOfMeasurement_;
    U8      dataType_;
    U8      options_;
    U32     compression_;
    I8      description_[PLS_DESCRIPTION_SIZE];
    
    cLutRecord();
    ~cLutRecord()
    {
        lutTableArray_ = 0;
    }
    
    void read(std::fstream*);
    void readLutArray(std::fstream*);
    void print() const;
    void printLutArray() const;
    
private:
    
    F32* lutTableArray_;
    
};
#pragma pack(pop)



// The Look-Up Table VLR descriptor - 300,001 <= Record ID < 300,255
#pragma pack(push, 1)
class cLutHeader : public cVlrHeader
{
    
public:
    
    U32     size_;
    U32     reserved_;
    I32     numberOfTable_;
    I8      description_[PLS_DESCRIPTION_SIZE];
    
    cLutHeader();
    ~cLutHeader()
    {
        lutTableHeader_ = 0;
    }
    
    virtual void read(std::fstream*);
    void readLutTable(std::fstream*);
    virtual void print() const;
    
private:
    
    cLutRecord* lutTableHeader_;
    
    
};
#pragma pack(pop)


#endif /* vlrClass_hpp */
