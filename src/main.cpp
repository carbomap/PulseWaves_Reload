//
//  main.cpp
//  ppwaves
//
//  Created by Antoine Cottin on 02/12/2015.
//  Copyright © 2015 Antoine Cottin. All rights reserved.
//

#include <iostream>
#include "PulseWaves.hpp"

int main(int argc, const char * argv[]) {
    
     PulseWaves plsObj("/Users/antoine/Processing_Temp_Folder/Bertholdstein_process_need_sptaial_indexing/q560/Bertholdstein - Q560_9996619 - 150528_133849 - originalpoints.pls");
    
    unsigned int tt;
    std::cout << sizeof(tt) << std::endl;
    
    unsigned short toto = plsObj.getPulseSize();
    std::cout << toto << std::endl;
    
    return 0;
}
