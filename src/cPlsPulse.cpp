//
//  cPlsPulse.cpp
//  Project
//
//  Created by Antoine Cottin on 13/12/2015.
//
//

#include "../includes/cPlsPulse.hpp"



plsPulseRec::plsPulseRec()
{
    
}



void plsPulseRec::read(std::fstream* inFile)
{
    
    inFile->read((char *)&gpsTime_, sizeof(gpsTime_));
    inFile->read((char *)&waveOffset_, sizeof(waveOffset_));
    inFile->read((char *)&anchorX_, sizeof(anchorX_));
    inFile->read((char *)&anchorY_, sizeof(anchorY_));
    inFile->read((char *)&anchorZ_, sizeof(anchorZ_));
    inFile->read((char *)&targetX_, sizeof(targetX_));
    inFile->read((char *)&targetY_, sizeof(targetY_));
    inFile->read((char *)&targetZ_, sizeof(targetZ_));
    inFile->read((char *)&firstReturn_, sizeof(firstReturn_));
    inFile->read((char *)&lastReturn_, sizeof(lastReturn_));
    inFile->read((char *)&pulseDesIndex_, sizeof(pulseDesIndex_));
    inFile->read((char *)&intensity_, sizeof(intensity_));
    inFile->read((char *)&classification_, sizeof(classification_));
    
}



void plsPulseRec::print()
{
    
}





plsPulseArray::plsPulseArray(std::fstream* inFile)
{
    
}



plsPulseArray::plsPulseArray(std::fstream* inFile, std::vector<I64> inVector)
{
    
}



I64 plsPulseArray::getNPulses()
{
    return nPulses_;
}



plsPulseRec plsPulseArray::getPulse(I64)
{
    
}
