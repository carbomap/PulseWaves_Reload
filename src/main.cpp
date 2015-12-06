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

	PulseWaves plsObj("../sample_data/riegl_example1.pls");

	boost::uint16_t toto = plsObj.getPulseSize();
	std::cout << toto << std::endl;

	return 0;
}
