//
//  PulseWaves.hpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Antoine Cottin. All rights reserved.
//

#ifndef PulseWaves_hpp
#define PulseWaves_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

#endif /* PulseWaves_hpp */

using namespace std;


#pragma pack(push, r1, 1)
struct pls_header{
//    __int8_t fileSignature[16];
//    __uint32_t globalParameter;
//    __uint32_t fileSourceID;
//    __uint32_t guid01;
//    __uint16_t guid02;
//    __uint16_t guid03;
//    __uint8_t guid04[8];
//    __int8_t systemID[64];
//    __int8_t generatingSoftware[64];
//    __uint16_t day;
//    __uint16_t year;
//    __uint8_t versionMajor;
//    __uint8_t versionMinor;
//    __uint16_t headerSize;
//    __int64_t dataOffet;
//    __int64_t nPulses;
//    __uint32_t pulseFormat;
//    __uint32_t pulseAttributes;
//    __uint32_t pulseSize;
//    __uint32_t pulseCompression;
//    __int64_t reserved;
//    __uint32_t nVLR;
//    __int32_t nAVLR;
//    double scaleT;
//    double offsetT;
//    __int64_t minT;
//    __int64_t maxT;
//    double scaleX;
//    double scaleY;
//    double scaleZ;
//    double offsetX;
//    double offsetY;
//    double offsetZ;
//    double minX;
//    double maxX;
//    double minY;
//    double maxY;
//    double minZ;
//    double maxZ;
    char fileSignature[16];
    unsigned int globalParameter;
    unsigned int fileSourceID;
    unsigned int guid01;
    unsigned short guid02;
    unsigned short guid03;
    char guid04[8];
    char systemID[64];
    char generatingSoftware[64];
    unsigned short day;
    unsigned short year;
    unsigned char versionMajor;
    unsigned char versionMinor;
    unsigned short headerSize;
    long long dataOffet;
    long long nPulses;
    unsigned int pulseFormat;
    unsigned int pulseAttributes;
    unsigned int pulseSize;
    unsigned int pulseCompression;
    long long reserved;
    unsigned int nVLR;
    int nAVLR;
    double scaleT;
    double offsetT;
    long long minT;
    long long maxT;
    double scaleX;
    double scaleY;
    double scaleZ;
    double offsetX;
    double offsetY;
    double offsetZ;
    double minX;
    double maxX;
    double minY;
    double maxY;
    double minZ;
    double maxZ;
};
#pragma pack(pop, r1)


struct wvs_header{
    char signature[16];
    unsigned long compression;
    char reserve[44];
};



struct pls_pulserec{
    long long gpsTime; //           ; GPS time
    long long waveOffset; //        ; Bytes offset to wave record
    long anchorX; //                ; Anchor point of the wave
    long anchorY; //                ; Anchor point of the wave
    long anchorZ; //                ; Anchor point of the wave
    long targetX; //                ; Ending point of the wave
    long targetY; //                ; Ending point of the wave
    long targetZ; //                ; Ending point of the wave
    short firstReturn; //           ; Duration in sampling units from the anchor point to the first recorded waveform sample
    short lastReturn; //            ; Duration in sampling units from the anchor point to the last recorded waveform sample
    unsigned short pulseDesIndex; //; Pulse description index bit 0-7; Reserved bit 8-11; Edge of scan line bit 12; Scan direction bit 13; Mirror facet bit 14-15
    char intensity; //              ; Intensity of the pulse in DN
    char classification; //         ; Classification of the pulse
};



class PulseWaves
{
    
    // Private data members
    string plsFilePath_;            // String representing the fully qualified file name path
    string wvsFilePath_;            // String representing the fully qualified file name path of the corresponding waveform file
    pls_header *plsHeader_;         // Pointer to the Header of the WVS file
    //plsVlrArray_;                 // Pointer to the Variable Length Records (in reading order - Header/Key)
    //pulserec *plsPulseDes;        // Pointer to an array of structure holding all the Pulse descriptor VLR
    pls_pulserec *plsPulserec_;      // Pointer to the records of the PLS file hold in the data member
    //plsPulseInd;                  // Pointer to the index of the records from the PLS file hold in plsPulseRec
    //plsPulseIndSel;               // Pointer to an index of the selected pulses defined by pulsewaves::getPulses
    //plsAvlrarray;                 // Pointer to the Append Variable Length Records (in reading order - Header/Key)
    wvs_header *wvsHeader_;         // Pointer to the header of the WVS file
    //wvsWaveRec;                   // Pointer to the records of the WVS file corresponding to the records in plsPulseRec
    //wvsWaveInd;
    
    // Private methods for reading the file
    void readHeader();
    void readVLR();
    void readData();
    void readAVLR();

    
public:
    
    // Default constructor
    PulseWaves(string);
    // Default destructor
    //~PulseWaves();
    
    // public methods for the header
    void displayHeaderInformation() const;
    pls_header getPlsHeader() const;
    string getSystemID() const;
    string getSoftwareID() const;
    unsigned short getDay() const;
    unsigned short getYear() const;
    unsigned char getVersionMajor() const;
    unsigned char getVersionMinor() const;
    unsigned short getHeaderSize() const;
    long long getOffsetToPulses() const;
    long long getNumbOfPulses() const;
    unsigned int getPulseFormat() const;
    unsigned int getPulseAttrib() const;
    unsigned int getPulseSize() const;
    unsigned int getPulseCompress() const;
    unsigned int getNumbOfVLR() const;
    int getNumbOfAVLR() const;
    double getTimeScale() const;
    double getTimeOffset() const;
    long long getTimeMin() const;
    long long getTMax() const;
    double getXScale() const;
    double getYScale() const;
    double getZScale() const;
    double getXOffset() const;
    double getYOffset() const;
    double getZOffset() const;
    double getXMin() const;
    double getXMax() const;
    double getYMin() const;
    double getYMax() const;
    double getZMin() const;
    double getZMax() const;
    
    // methods to intantiate the class pointers
    void setPlsHeader();
    void setPlsRecord();
    void setWvsHeader();
    
    // public methods for the vlr
    
    // public methods for the data block

    
    
};
