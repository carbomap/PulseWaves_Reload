/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 cAVlr.hpp
 
 PURPOSE:
 
 Header for the cAVlr Class.
 
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
 
 15/12/2015 - Creation by Antoine C.
 
 -----------------------------------------------------------------------------
 */



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
