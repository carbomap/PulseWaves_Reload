//
//  cPlsPulse.cpp
//  Project
//
//  Created by Antoine Cottin on 13/12/2015.
//
//

#include "../includes/cPlsPulse.hpp"
#include "../includes/cPlsHeader.hpp"



//-----------------------------------------------------------------------------
plsPulseRec::plsPulseRec()
{
    
}



//-----------------------------------------------------------------------------
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



//-----------------------------------------------------------------------------
void plsPulseRec::print()
{
    std::cout << "GPS time: " << gpsTime_ << std::endl;
    std::cout << "Waveform offset " << waveOffset_ << " bytes" << std::endl;
    std::cout << "Anchor X: " << anchorX_ << std::endl;
    std::cout << "Anchor Y: " << anchorY_ << std::endl;
    std::cout << "Anchor Z: " << anchorZ_ << std::endl;
    std::cout << "Target X: " << targetX_ << std::endl;
    std::cout << "Target Y: " << targetY_ << std::endl;
    std::cout << "Target Z: " << targetZ_ << std::endl;
    std::cout << "First return: " << firstReturn_ << " (sample unit)" << std::endl;
    std::cout << "Last return: " << lastReturn_ << " (sample unit)"<< std::endl;
    std::cout << "Pulse description: " << pulseDesIndex_ << std::endl;
    std::cout << "Intensity : " << intensity_ << std::endl;
    std::cout << "Classification: " << classification_ << std::endl;
    
}



//-----------------------------------------------------------------------------
plsPulseArray::plsPulseArray(std::fstream* inFile, cPlsHeader* pPlsHeader)
{
    
    // Assigning the header pointer to the data member
    pPlsHeader_ = pPlsHeader;
    nPulses_ = pPlsHeader->nPulses_;
    plsPulseRec* plsPulseArr_ = new plsPulseRec[pPlsHeader_->nPulses_];
    
    std::cout << "Reading " << pPlsHeader->nPulses_ << " pulse records" << std::endl;
    
    for (I64 i = 0; i < nPulses_; i++) {
        plsPulseRec* tempPulse = new plsPulseRec;
        tempPulse->read(inFile);
        plsPulseArr_[i] = *tempPulse;
    }
    
}



//-----------------------------------------------------------------------------
plsPulseArray::plsPulseArray(std::fstream* inFile, std::vector<I64> inVector)
{
    
}



//-----------------------------------------------------------------------------
I64 plsPulseArray::getNPulses()
{
    return nPulses_;
}



//-----------------------------------------------------------------------------
plsPulseRec plsPulseArray::getPulse(I64 index)
{
    return plsPulseArr_[index];
}
