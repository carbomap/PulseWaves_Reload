/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 cAVlr.cpp
 
 PURPOSE:
 
 Class for the Append Variable Length Record
 
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