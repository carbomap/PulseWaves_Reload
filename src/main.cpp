//
//  main.cpp
//  ppwaves
//
//  Created by Antoine Cottin on 01/12/2015.
//  Copyright © 2015 Carbomap. All rights reserved.
//

#include <iostream>
#include "../includes/PulseWaves.hpp"

int main(int argc, const char * argv[]) {

//	PulseWaves plsObj("../../sample_data/riegl_example1.pls");
    PulseWaves plsObj("/Users/antoine/Processing_Temp_Folder/Bertholdstein_process_need_sptaial_indexing/q560/Bertholdstein - Q560_9996619 - 150528_133849 - originalpoints.pls");
    
    I64 tr = 4324;
    plsObj.printPulse(tr);
    plsPulseRec dum = plsObj.getPulse(tr);
    plsPulseRec* dumAddrs = plsObj.getPulsePtr(tr);
	return 0;
}
