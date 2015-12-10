//
//  PulseWaves.cpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
//

#include "../includes/PulseWaves.hpp"
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
//#include <map>

using namespace std;


//-----------------------------------------------------------

PulseWaves::PulseWaves(string inFile)
{
	
    
    plsFilePath_ = inFile;
    // instantiation of the fstream class object
    
    std::fstream inPlsFile;
    
    inPlsFile_ = &inPlsFile;

    inPlsFile_->open(plsFilePath_.c_str(), std::ios::in | std::ios::binary);
    
    // checking if the file exist
    if (inPlsFile_->fail())
    {
        
        std::cout << "ERROR: Cannot open the file..." << std::endl;
        exit(1);
    
    }
    else
    {
        
        this->readHeader();
        this->readVLR();
        this->readData();
        this->readAVLR();

    }
    
    inPlsFile_->close();
    
    
};






//-----------------------------------------------------------
// Private methods for reading the file
void PulseWaves::printSep() const
{
    std::cout << "##################################################" << std::endl;
};



void PulseWaves::readHeader()
{

	// getting header structure
	plsHeaderClass* plsHeader = new plsHeaderClass;
    plsHeader->read(inPlsFile_);
    plsHeader->print();

    plsHeader_ = plsHeader;

};



void PulseWaves::readVLR()
{

    vlrHeaderClass* vlrHeaderArr = new vlrHeaderClass[plsHeader_->nVLR];
    
    // reading the VLR
    for (int i = 0; i < plsHeader_->nVLR; i++)
    {
        // getting the VLR ID record number
        U32 recID = vlrHeaderClass::whichVLR(inPlsFile_);
        
        cout << "Record ID:" << recID << std::endl;
        // instantiate the correct VLR class
        if (100001 >= recID && recID < 100255)
        {
            printSep();
            cout << "Scanner descriptor found..." << std::endl;
        }
        else if (200001 >= recID && recID < 200255)
        {
            printSep();
            cout << "Pulse sampling descriptor found..." << std::endl;
        }
        else if (200001 <= recID && recID < 200255)
        {
            printSep();
            cout << "Pulse sampling descriptor found..." << std::endl;
        }
        else
        {
            printSep();
            cout << "Generic VLR descriptor found..." << std::endl;
        }
        // read the class
        
        // assigned the instance to the object array
        //vlrHeaderArr[i] =
        
    }
    
//    this->printSep();
//    
//    // Creating a map to hold the VLR header records
//    std::map<int, vlrHeader_strc> vlrHeaderMap;
//    // for testing just now
//    std::map<std::string, boost::variant<scanner_vlr_strc, pulseSampling_vlr_strc, lookUpTable_vlr_strc, lutRecord_vlr_strc, samplingRecord_strc> > vlrRecordMap ;
//    
//    // instantiation of the fstream class object
//    std::fstream plsFile;
//    plsFile.open(plsFilePath_.c_str(), std::ios::in | std::ios::binary);
//    
//    // pointing the cursor at the beginning of the VLR Block
//    plsFile.seekg(plsHeader_->headerSize, ios::beg);
//
//    vlr_header_strc vlsHeader;
//    
//    // reading the VLR
//    for (int i = 0; i < plsHeader_->nVLR; i++) {
//        plsFile.read((char *)&vlsHeader, sizeof(vlsHeader));
//        
//        vlrHeaderMap.insert ( std::pair<int,vlr_header_strc>(i,vlsHeader) );
//        
//        // for the time being as no actual VLR record is read, just jump to the next vlr Header
//        plsFile.seekg(vlsHeader.recordLengthAfterHeader, ios::cur);
//        
//    }
//    
//    // Closing the file pointer
//    plsFile.close();
    
};


void PulseWaves::readData()
{

};


void PulseWaves::readAVLR()
{

};
