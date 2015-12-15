//
//  cAVlr.hpp
//  Project
//
//  Created by Antoine Cottin on 15/12/2015.
//
//

#ifndef cAVlr_hpp
#define cAVlr_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "PulseWavesDefs.hpp"


#pragma pack(push, r1, 1)
struct cAVlrHeader
{
    
public:
    
    I8       userID_[PLS_USER_ID_SIZE];
    U32      recordID_;
    U32      reserved_;
    I64      recordLengthBeforeFooter_;
    I8       description_[PLS_DESCRIPTION_SIZE];
    
    cAVlrHeader();
    ~cAVlrHeader(){};
    
    void read(std::fstream*);
    void print();
    
};
#pragma pack(pop, r1)


#endif /* cAVlr_hpp */
