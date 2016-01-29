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


// C++
#include <iostream>

// BOOST
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
#include <boost/filesystem.hpp>
#include <boost/timer/timer.hpp>

// PulseWaves_Reload
#include "../includes/PulseWaves.hpp"

int main(int argc, const char * argv[]) {

//	PulseWaves plsObj("../../sample_data/riegl_example1.pls");
    PulseWaves plsObj("/Users/antoine/Git/Pulsewaves_Origin/sample_data/Bertholdstein - Q560_9996619 - 150528_135821.pls");
    
    std::vector<U32> temp = plsObj.getVlrIDs();
    for (auto i : temp) {
        std::cout << i  << std::endl;
    }
    
    
    boost::timer::cpu_timer timer;

    I64 tr = 4378;
//    I32 nVlr = 2;
//    
//    for (int i = 0; i < 10; i++) {
//        cVlrHeader pVlr = plsObj.getVlr(i);
//        pVlr.print();
//        std::cout << sizeof(pVlr) << std::endl;
//    }
    
    for (U32 i = 0; i < plsObj.getHeader()->nVLR_; i++) {
        std::shared_ptr<cVlrHeader> pVlr = plsObj.getVlrByIndex(i);
        pVlr->cVlrHeader::print();
        pVlr->print();
    }

    
    plsPulseRec dum = plsObj.getPulses(3);
    std::shared_ptr<cVlrHeader> dd = plsObj.getVlrByID(200012);
//    dum.print();


    
    
    std::cout << timer.format() << '\n';
    
    
//    plsPulseRec* dumAddrs = plsObj.getPulsePtr(tr);
	return 0;
}
