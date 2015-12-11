//
//  cVlr.cpp
//  pulsewaves_reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
//

#include "../includes/cVlr.hpp"
#include <boost/lexical_cast.hpp>


cVlrHeader::cVlrHeader()
{
    
}



void cVlrHeader::read(std::fstream* inFile)
{
    
    inFile->read((char *)&userID, sizeof(userID));
    inFile->read((char *)&recordID, sizeof(recordID));
    inFile->read((char *)&reserved, sizeof(reserved));
    inFile->read((char *)&recordLengthAfterHeader, sizeof(recordLengthAfterHeader));
    inFile->read((char *)&description, sizeof(description));
    
}



void cVlrHeader::print() const
{
    
    std::cout << "User ID: " << boost::lexical_cast<std::string>(userID) << std::endl;
    std::cout << "Record ID: " << recordID << std::endl;
    std::cout << "Record Length After Header: " << recordLengthAfterHeader << std::endl;
    std::cout << "Description: " << boost::lexical_cast<std::string>(description) << std::endl;
    
}


cVlrScanner::cVlrScanner()
{
    
}


void cVlrScanner::read(std::fstream* inFile)
{
    
    inFile->read((char *)&size, sizeof(size));
    inFile->read((char *)&reserved, sizeof(reserved));
    inFile->read((char *)&instrument, sizeof(instrument));
    inFile->read((char *)&serial, sizeof(serial));
    inFile->read((char *)&wavelength, sizeof(wavelength));
    inFile->read((char *)&outgoingPulseWidth, sizeof(outgoingPulseWidth));
    inFile->read((char *)&scanPattern, sizeof(scanPattern));
    inFile->read((char *)&numberOfMirrorFacets, sizeof(numberOfMirrorFacets));
    inFile->read((char *)&scanFrequency, sizeof(scanFrequency));
    inFile->read((char *)&scanMinAngle, sizeof(scanMinAngle));
    inFile->read((char *)&scanMaxAngle, sizeof(scanMaxAngle));
    inFile->read((char *)&pulseFrequency, sizeof(pulseFrequency));
    inFile->read((char *)&beamDiameterAtExit, sizeof(beamDiameterAtExit));
    inFile->read((char *)&beamDivergeance, sizeof(beamDivergeance));
    inFile->read((char *)&minimalRange, sizeof(minimalRange));
    inFile->read((char *)&maximalRange, sizeof(maximalRange));
    inFile->read((char *)&description, sizeof(description));

}

void cVlrScanner::print() const
{
    
    std::cout << "System identifier: " << boost::lexical_cast<std::string>(instrument) << std::endl;
    std::cout << "System serial: " << boost::lexical_cast<std::string>(serial) << std::endl;
    std::cout << "System wavelength: " << wavelength << " nm" << std::endl;
    std::cout << "System outgoing pulse width: " << outgoingPulseWidth << " nm" << std::endl;

    switch (scanPattern)
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

    std::cout << "System number of mirror facets: " << numberOfMirrorFacets << std::endl;
    std::cout << "System scan frequency: " << scanFrequency << " hz" << std::endl;
    std::cout << "System minimum scan angle: " << scanMinAngle << " deg" << std::endl;
    std::cout << "System maximum scan angle: " << scanMaxAngle << " deg" << std::endl;
    std::cout << "System pulse frequency: " << pulseFrequency << " khz" << std::endl;
    std::cout << "System beam diameter at exit aperture: " << beamDiameterAtExit << " mm" << std::endl;
    std::cout << "System beam divergence: " <<beamDivergeance << " mrad" << std::endl;
    std::cout << "System minimum range: " << minimalRange << " m" << std::endl;
    std::cout << "System maximum range: " << maximalRange << " m" << std::endl;
    std::cout << "System description (id any): " << description << std::endl;
    
}



cVlrPulseSampling::cVlrPulseSampling()
{
    
}



void cVlrPulseSampling::read(std::fstream* inFile)
{
    
}



void cVlrPulseSampling::print() const
{
    
}