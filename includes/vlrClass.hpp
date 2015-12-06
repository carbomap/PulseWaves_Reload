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
#include <fstream>
#include <boost/cstdint.hpp>
#include "PulseWavesDefs.hpp"


class vlrHeaderClass
{
    
private:
    
    boost::int8_t       userID[PLS_USER_ID_SIZE];
    boost::uint32_t     recordID;
    boost::uint32_t     reserved;
    boost::int64_t      recordLengthAfterHeader;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
    
    
    virtual void readVLR();
    
    
public:
    
    // this method will test the type of VLR before
    boost::uint32_t whichVLR();
    
    virtual boost::uint32_t getRecordID() = 0;
    virtual boost::int8_t getDescription() = 0;
    virtual void printDescription();
    
};


// The Scanner VLR descriptor - 100,001 <= Record ID < 100,255
class vlrScannerClass : vlrHeaderClass
{
    boost::uint32_t     size;
    boost::uint32_t     reserved;
    boost::int8_t       instrument[64];
    boost::int8_t       serial[64];
    float               avelength;
    float               outgoingPulseWidth;
    boost::uint32_t     scanPattern;
    boost::uint32_t     numberOfMirrorFacets;
    boost::int32_t      scanFrequency;
    boost::int32_t      scanMinAngle;
    boost::int32_t      scanMaxAngle;
    boost::int32_t      pulseFrequency;
    float               beamDiameterAtExit;
    float               beamDivergeance;
    float               minimalRange;
    float               maximalRange;
    boost::int8_t       description[PLS_DESCRIPTION_SIZE];
    
    virtual void readVLR(std::fstream);
    
};



#endif /* vlrClass_hpp */
