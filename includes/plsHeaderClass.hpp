//
//  plsHeaderClass.hpp
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

#pragma pack(push, r1, 1)
class plsHeaderClass
{
    
public:
  
    boost::int8_t	fileSignature[16];
    boost::uint32_t globalParameter;
    boost::uint32_t fileSourceID;
    boost::uint32_t guid01;
    boost::uint16_t guid02;
    boost::uint16_t guid03;
    boost::uint8_t 	guid04[8];
    boost::int8_t 	systemID[64];
    boost::int8_t 	generatingSoftware[64];
    boost::uint16_t day;
    boost::uint16_t year;
    boost::uint8_t 	versionMajor;
    boost::uint8_t 	versionMinor;
    boost::uint16_t headerSize;
    boost::int64_t 	dataOffet;
    boost::int64_t 	nPulses;
    boost::uint32_t pulseFormat;
    boost::uint32_t pulseAttributes;
    boost::uint32_t pulseSize;
    boost::uint32_t pulseCompression;
    boost::int64_t 	reserved;
    boost::uint32_t nVLR;
    boost::int32_t 	nAVLR;
    double 			scaleT;
    double 			offsetT;
    boost::int64_t 	minT;
    boost::int64_t 	maxT;
    double 			scaleX;
    double 			scaleY;
    double 			scaleZ;
    double 			offsetX;
    double 			offsetY;
    double 			offsetZ;
    double 			minX;
    double 			maxX;
    double 			minY;
    double 			maxY;
    double 			minZ;
    double 			maxZ;
    

    
    plsHeaderClass();
    ~plsHeaderClass(){};
    
    // public methods for the header
    void read(std::fstream*);
    
    void print() const;
    

    
};
#pragma pack(pop, r1)


#endif /* plsHeaderClass_hpp */
