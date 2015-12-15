//
//  cAVlr.cpp
//  Project
//
//  Created by Antoine Cottin on 15/12/2015.
//
//

#include "../includes/cAVlr.hpp"



//-----------------------------------------------------------------------------
cAVlrHeader::cAVlrHeader()
{
    
}



//-----------------------------------------------------------------------------
void cAVlrHeader::read(std::fstream* inFile)
{
    
    inFile->read((char *)&userID_, sizeof(userID_));
    inFile->read((char *)&recordID_, sizeof(recordID_));
    inFile->read((char *)&recordLengthBeforeFooter_, sizeof(recordLengthBeforeFooter_));
    inFile->read((char *)&description_, sizeof(description_));
    
}



//-----------------------------------------------------------------------------
void cAVlrHeader::print()
{
    
    std::cout << "AVLR User ID: " << userID_ << std::endl;
    std::cout << "AVLR Record ID: " << std::endl;
    std::cout << "AVLR Record Length Before Footer: " << std::endl;
    std::cout << "AVLR Description: " << description_ << std::endl;
    
}