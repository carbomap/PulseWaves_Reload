/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 cVlr.cpp
 
 PURPOSE:
 
 Implementation for the VLR Header (cVlrHeader), VLR Scanner (cVlrScanner),
 VLR Sampling (cVlrSamplingRecord), VLR Pulse Sample (cVlrPulseSampling) and the
 VLR Lookup Table (cLutHeader, cLutRecord) classes.
 
 COPYRIGHT:
 
 (c) Antoine Cottin, Carbomap Ltd. - 12/2015
 
 This is free software; you can redistribute and/or modify it under the
 terms of the GNU Lesser General Licence as published by the Free Software
 Foundation. See the COPYING file for more information.
 
 This software is distributed WITHOUT ANY WARRANTY and without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 
 AUTHOR:
 
 a.cottin@carbomap.com  -  http://www.carbomap.com
 
 -----------------------------------------------------------------------------
*/



// Boost
#include <boost/lexical_cast.hpp>

// PulseWaves_Reload
#include "../includes/cVlr.hpp"



//-----------------------------------------------------------------------------
cVlrHeader::cVlrHeader()
{
    
}



//-----------------------------------------------------------------------------
void cVlrHeader::read(std::fstream* inFile)
{
    
    inFile->read((char *)&userID_, sizeof(userID_));
    inFile->read((char *)&recordID_, sizeof(recordID_));
    inFile->read((char *)&reserved_, sizeof(reserved_));
    inFile->read((char *)&recordLengthAfterHeader_, sizeof(recordLengthAfterHeader_));
    inFile->read((char *)&description_, sizeof(description_));
    
}



//-----------------------------------------------------------------------------
void cVlrHeader::print() const
{
    
    std::cout << "User ID: " << boost::lexical_cast<std::string>(userID_) << std::endl;
    std::cout << "Record ID: " << recordID_ << std::endl;
    std::cout << "Record Length After Header: " << recordLengthAfterHeader_ << std::endl;
    std::cout << "Description: " << boost::lexical_cast<std::string>(description_) << std::endl;
    
}



//-----------------------------------------------------------------------------
cVlrScanner::cVlrScanner()
{
    
}



//-----------------------------------------------------------------------------
void cVlrScanner::read(std::fstream* inFile)
{
    
    inFile->read((char *)&size_, sizeof(size_));
    inFile->read((char *)&reserved_, sizeof(reserved_));
    inFile->read((char *)&instrument_, sizeof(instrument_));
    inFile->read((char *)&serial_, sizeof(serial_));
    inFile->read((char *)&wavelength_, sizeof(wavelength_));
    inFile->read((char *)&outgoingPulseWidth_, sizeof(outgoingPulseWidth_));
    inFile->read((char *)&scanPattern_, sizeof(scanPattern_));
    inFile->read((char *)&numberOfMirrorFacets_, sizeof(numberOfMirrorFacets_));
    inFile->read((char *)&scanFrequency_, sizeof(scanFrequency_));
    inFile->read((char *)&scanMinAngle_, sizeof(scanMinAngle_));
    inFile->read((char *)&scanMaxAngle_, sizeof(scanMaxAngle_));
    inFile->read((char *)&pulseFrequency_, sizeof(pulseFrequency_));
    inFile->read((char *)&beamDiameterAtExit_, sizeof(beamDiameterAtExit_));
    inFile->read((char *)&beamDivergeance_, sizeof(beamDivergeance_));
    inFile->read((char *)&minimalRange_, sizeof(minimalRange_));
    inFile->read((char *)&maximalRange_, sizeof(maximalRange_));
    inFile->read((char *)&description_, sizeof(description_));

}



//-----------------------------------------------------------------------------
void cVlrScanner::print() const
{
    
    std::cout << "System identifier: " << boost::lexical_cast<std::string>(instrument_) << std::endl;
    std::cout << "System serial: " << boost::lexical_cast<std::string>(serial_) << std::endl;
    std::cout << "System wavelength: " << wavelength_ << " nm" << std::endl;
    std::cout << "System outgoing pulse width: " << outgoingPulseWidth_ << " nm" << std::endl;

    switch (scanPattern_)
    {
        case 0: {
            std::cout << "System scan pattern: Undefined" << std::endl;
            break;
        }
        case 1:
        {
            std::cout << "System scan pattern: Oscillating" << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "System scan pattern: Line" << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "System scan pattern: Conic" << std::endl;
            break;
        }
    }

    std::cout << "System number of mirror facets: " << numberOfMirrorFacets_ << std::endl;
    std::cout << "System scan frequency: " << scanFrequency_ << " hz" << std::endl;
    std::cout << "System minimum scan angle: " << scanMinAngle_ << " deg" << std::endl;
    std::cout << "System maximum scan angle: " << scanMaxAngle_ << " deg" << std::endl;
    std::cout << "System pulse frequency: " << pulseFrequency_ << " khz" << std::endl;
    std::cout << "System beam diameter at exit aperture: " << beamDiameterAtExit_ << " mm" << std::endl;
    std::cout << "System beam divergence: " <<beamDivergeance_ << " mrad" << std::endl;
    std::cout << "System minimum range: " << minimalRange_ << " m" << std::endl;
    std::cout << "System maximum range: " << maximalRange_ << " m" << std::endl;
    std::cout << "System description (id any): " << boost::lexical_cast<std::string>(description_) << std::endl;
    
}



//-----------------------------------------------------------------------------
cVlrSamplingRecord::cVlrSamplingRecord()
{
    
}



//-----------------------------------------------------------------------------
void cVlrSamplingRecord::read(std::fstream* inFile)
{
    
    inFile->read((char *)&size_, sizeof(size_));
    inFile->read((char *)&reserved_, sizeof(reserved_));
    inFile->read((char *)&type_, sizeof(type_));
    inFile->read((char *)&channel_, sizeof(channel_));
    inFile->read((char *)&notUsed_, sizeof(notUsed_));
    inFile->read((char *)&bitsForDurationFromAnchor_, sizeof(bitsForDurationFromAnchor_));
    inFile->read((char *)&scaleForDurationFromAnchor_, sizeof(scaleForDurationFromAnchor_));
    inFile->read((char *)&offsetForDurationFromAnchor_, sizeof(offsetForDurationFromAnchor_));
    inFile->read((char *)&bitsForNumberOfSegments_, sizeof(bitsForNumberOfSegments_));
    inFile->read((char *)&bitsForNumberOfSamples_, sizeof(bitsForNumberOfSamples_));
    inFile->read((char *)&numberOfSegments_, sizeof(numberOfSegments_));
    inFile->read((char *)&numberOfSamples_, sizeof(numberOfSamples_));
    inFile->read((char *)&bitsPerSample_, sizeof(bitsPerSample_));
    inFile->read((char *)&lutIndex_, sizeof(lutIndex_));
    inFile->read((char *)&sampleUnits_, sizeof(sampleUnits_));
    inFile->read((char *)&compression_, sizeof(compression_));
    inFile->read((char *)&description_, sizeof(description_));
    
}



//-----------------------------------------------------------------------------
void cVlrSamplingRecord::print() const
{
    
    std::cout << "Size: " << size_ << " bytes" << std::endl;

    if (type_ == 1) {
        std::cout << "Pulses is OUTGOING" << std::endl;
    }
    else
    {
        std::cout << "Pulses is RETURNING" << std::endl;
    }
    std::cout << "Sampling channel: " << static_cast<unsigned>(channel_) << std::endl;
    std::cout << "Sampling bits for duration from anchor: " << static_cast<unsigned>(bitsForDurationFromAnchor_) << std::endl;
    std::cout << "Sampling scale for duration from anchor: " << scaleForDurationFromAnchor_ << std::endl;
    std::cout << "Sampling offset for duration from anchor: " << offsetForDurationFromAnchor_ << std::endl;
    std::cout << "Sampling bits for number of segments: " << bitsForNumberOfSegments_ << std::endl;
    std::cout << "Sampling bits for number of samples : " << bitsForNumberOfSamples_ << std::endl;
    std::cout << "Sampling number of segments : " << numberOfSegments_ << std::endl;
    std::cout << "Sampling number of samples : " << numberOfSamples_ << std::endl;
    std::cout << "Sampling bits per sample : " << bitsPerSample_ << std::endl;
    std::cout << "Sampling lookup table : " << lutIndex_ << std::endl;
    std::cout << "Sampling sample unit : " << sampleUnits_ << " ns" << std::endl;
    std::cout << "Sampling compression : " << compression_ << std::endl;
    std::cout << "Sampling description : " << boost::lexical_cast<std::string>(description_) << std::endl;
    
}



//-----------------------------------------------------------------------------
cVlrPulseSampling::cVlrPulseSampling()
{
    
}



//-----------------------------------------------------------------------------
void cVlrPulseSampling::read(std::fstream* inFile)
{
    
    inFile->read((char *)&size_, sizeof(size_));
    inFile->read((char *)&reserved_, sizeof(reserved_));
    inFile->read((char *)&opticalCenterToAnchorPoint_, sizeof(opticalCenterToAnchorPoint_));
    inFile->read((char *)&numberOfExtraWaveBytes_, sizeof(numberOfExtraWaveBytes_));
    inFile->read((char *)&numberOfSamplings_, sizeof(numberOfSamplings_));
    inFile->read((char *)&sampleUnit_, sizeof(sampleUnit_));
    inFile->read((char *)&compression_, sizeof(compression_));
    inFile->read((char *)&scannerIndex_, sizeof(scannerIndex_));
    inFile->read((char *)&description_, sizeof(description_));
    
}



//-----------------------------------------------------------------------------
void cVlrPulseSampling::print() const
{
    
    std::cout << "Pulse optical center to anchor: " << opticalCenterToAnchorPoint_ << " (sampling unit)" << std::endl;
    std::cout << "Pulse number of extra bytes: " << numberOfExtraWaveBytes_ << " bytes" << std::endl;
    std::cout << "Pulse number of sampling: " <<numberOfSamplings_ << std::endl;
    std::cout << "Pulse samples unit: " << sampleUnit_ << " ns" << std::endl;
    std::cout << "Pulse scanner index : " << scannerIndex_ << std::endl;
    switch (compression_)
    {
        case 0: {
            std::cout << "Pulses are not compressed" << std::endl;
            break;
        }
        case 1:
        {
            std::cout << "Pulses are compressed" << std::endl;
            break;
        }
    }
    std::cout << "Pulse description: " << boost::lexical_cast<std::string>(description_) << std::endl;
    
                              
}



//-----------------------------------------------------------------------------
void cVlrPulseSampling::read_SamplingRecords(std::fstream* inFile)
{
    
    cVlrSamplingRecord* samplingRecordArr_ = new cVlrSamplingRecord[numberOfSamplings_];
    
    for (U16 w = 0; w < numberOfSamplings_; w++) {
        
        cVlrSamplingRecord* tempSamplingRecord = new cVlrSamplingRecord;
        tempSamplingRecord->read(inFile);
        tempSamplingRecord->print();

        std::cout << "########################################################" << std::endl;

        samplingRecordArr_[w] = *tempSamplingRecord;
    }

    
}



//-----------------------------------------------------------------------------
cLutHeader::cLutHeader() : cVlrHeader()
{
}



//-----------------------------------------------------------------------------
void cLutHeader::read(std::fstream* inFile)
{
    
    inFile->read((char *)&size_, sizeof(size_));
    inFile->read((char *)&reserved_, sizeof(reserved_));
    inFile->read((char *)&numberOfTable_, sizeof(numberOfTable_));
    inFile->read((char *)&description_, sizeof(description_));
    
}



//-----------------------------------------------------------------------------
void cLutHeader::readLutTable(std::fstream* inFile)
{
    
    cLutRecord* lutTableHeader_ = new cLutRecord[numberOfTable_];
    
    for (I32 i = 0; i < numberOfTable_; i++) {
        
        cLutRecord* tempLut = new cLutRecord;
        tempLut->read(inFile);
        tempLut->print();
        tempLut->readLutArray(inFile);
        
        lutTableHeader_[i] = *tempLut;
        
    }
    
}



//-----------------------------------------------------------------------------
void cLutHeader::print() const
{
    
    std::cout << "Number of Lookup Table: " << numberOfTable_ <<  std::endl;
    std::cout << "Description: " << description_ << std::endl;

}



//-----------------------------------------------------------------------------
cLutRecord::cLutRecord()
{
    
}



//-----------------------------------------------------------------------------
void cLutRecord::read(std::fstream* inFile)
{
    
    inFile->read((char *)&size_, sizeof(size_));
    inFile->read((char *)&reserved_, sizeof(reserved_));
    inFile->read((char *)&numberOfEntries_, sizeof(numberOfEntries_));
    inFile->read((char *)&unitOfMeasurement_, sizeof(unitOfMeasurement_));
    inFile->read((char *)&dataType_, sizeof(dataType_));
    inFile->read((char *)&options_, sizeof(options_));
    inFile->read((char *)&compression_, sizeof(compression_));
    inFile->read((char *)&description_, sizeof(description_));
    
}



//-----------------------------------------------------------------------------
void cLutRecord::readLutArray(std::fstream* inFile)
{
    
    F32 lLutTableArray_[numberOfEntries_];
    inFile->read((char *)&lLutTableArray_, sizeof(lLutTableArray_));
    
    lutTableArray_ = lLutTableArray_;
    
    this->printLutArray();
    
}



//-----------------------------------------------------------------------------
void cLutRecord::print() const
{
    
    std::cout << "Number of entries: " << numberOfEntries_ << std::endl;
    std::cout << "Unit of measurement: " << unitOfMeasurement_ << std::endl;
    
    if (dataType_ == 8) {std::cout << "Data type: 8 ('float')" << std::endl;};
        
    std::cout << "Description: " << description_ << std::endl;
        
}



//-----------------------------------------------------------------------------
void cLutRecord::printLutArray() const
{
    
    for(int i = 0; i < numberOfEntries_; i++)
    {
        if(i%10 != 0 || i == 0)
            std::cout << lutTableArray_[i] << "\t\t";
        else
            std::cout << lutTableArray_[i]<< std::endl;
    }
    
    std::cout << "" << std::endl;
    
}