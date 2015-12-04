
CONTENTS OF THIS FILE
---------------------

* INTRODUCTION
* REQUIRED DEPENDENCIES
* INSTALLATION
  * Windows (Visual Studio)
  * Linux/Unix (Ubuntu/Mac OS)
* MAINTAINERS


INTRODUCTION
------------

- PulseWaves_Reload is an on-going initiative to make the read and write 
  of Pulsewaves (.pls and .wvs) cross-platform compatible. The code has 
  been compiled and tested under Windows and Unix environments, Visual 
  Studio, Eclipse and Xcode respectively. 
- Repository on github: https://github.com/carbomap/PulseWaves_Reload.git


REQUIREMENTS
------------

CMAKE (http://cmake.org)
  - CMake offers robust cross-platform build system in order to control the
    build and compilation process by using simple platform independent config
    file. 
  - For information on how to install CMake, see: https://cmake.org/install/

BOOST (http://boost.org)
  - The cross compatibility of Pulsewaves_Reload is achieved by relying on 
    the Boost (http://boost.org) library. At this point in time this is the 
    only library that needs to be installed. For detailed instructions on 
    how to install boost, please see htpp://boost.org. 
  - For Windows, 
    see: http://www.boost.org/doc/libs/1_55_0/more/getting_started/windows.html 
  - For Unix, open terminal and type:
    > sudo apt-get install libboost-dev-all
    > sudo apt-get install aptitude
    > aptitude search boost


INSTALLATION
----------------

WINDOWS (Visual Studio) using CMake gui 
  - Pull the code from https://github.com/carbomap/PulseWaves_Reload.git
  - Start CMake and point to the src and the build directory
  - Configure and select native C++ compiler (tested on Visual Studio 2012)
  - Configure again 
  - Generate and open the .sln file from the build folder 

UNIX/LINUX (Eclipse) using CMake command line 
  - Pull the code from: https://github.com/carbomap/PulseWaves_Reload.git
  - Start terminal and cd to "src" folder 
  - Enter cmake . 
  - Enter make 
  - Enter make all 

MAINTAINERS
----------------

  Antoine Cottin, Carbomap Ltd, Edinburgh           <info@carbomap.com>
  Puneet Chhabra, Heriot-Watt University, Edinburgh <psc31@hw.ac.uk>