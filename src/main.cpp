/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 main.cpp
 
 PURPOSE:
 
 main
 
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
 
 01/12/2015 - Creation by Antoine C.
 
 -----------------------------------------------------------------------------
 */


// BOOST
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
#include <boost/filesystem.hpp>
#include <boost/timer/timer.hpp>

#include <iostream>
#include "../includes/PulseWaves.hpp"

int main(int argc, const char * argv[]) {

//	PulseWaves plsObj("../../sample_data/riegl_example1.pls");
    PulseWaves plsObj("/Users/antoine/Processing_Temp_Folder/Bertholdstein_process_need_sptaial_indexing/q560/Bertholdstein - Q560_9996619 - 150528_133849 - originalpoints.pls");
    
    boost::timer::cpu_timer timer;

    cPlsHeader* pPlsHeader = plsObj.getHeader();
 
    for (I64 i = 0; i < pPlsHeader->nPulses_; i++) {
//        plsObj.printPulse(tr);
        plsPulseRec dum = plsObj.getPulses(i);
//        dum.print();
    }

    
    
    std::cout << timer.format() << '\n';
    
    
//    plsPulseRec* dumAddrs = plsObj.getPulsePtr(tr);
	return 0;
}
