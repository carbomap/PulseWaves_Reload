//
//  cGeoKey.hpp
//  Project
//
//  Created by Antoine Cottin on 11/12/2015.
//
//

#ifndef cGeoKey_hpp
#define cGeoKey_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "PulseWavesDefs.hpp"
#include "cVlr.hpp"


#pragma pack(push, 1)
class cGeoKeyHeader : public cVlrHeader
{
    
public:
    
    U16     gKeyDirectoryVersion_;
    U16     gKeyRevision_;
    U16     gKeyMinorRevision_;
    U16     gKeyNumberOfKeys_;
    
    cGeoKeyHeader();
    ~cGeoKeyHeader(){};
    
    void read(std::fstream*);
    void print() const;
    
};
#pragma pack(pop)



#pragma pack(push, 1)
class cGeoKey : public cGeoKeyHeader
{
    
public:
    
    U16     gKeyID_;
    U16     gKeyTiffTagLocation_;
    U16     gKeyCount_;
    U16     gKeyValueOffset_;
    
    cGeoKey();
    ~cGeoKey(){};
    
    void read(std::fstream*);
    void print() const;
    
    
//private:
//    
//    cGeoKey* cGeoKeyArr = new cGeoKey;
    
    
};
#pragma pack(pop)




#endif /* cGeoKey_hpp */
