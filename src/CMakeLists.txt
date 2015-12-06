CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
PROJECT(pulsewaves_reload)
FIND_PACKAGE(Boost)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} includes) 
ADD_EXECUTABLE(pulsewaves_reload PulseWaves.cpp vlrClass.cpp main.cpp ../includes/PulseWaves.hpp ../includes/PulseWavesDefs.hpp ../includes/vlrClass.hpp)
TARGET_LINK_LIBRARIES(pulsewaves_reload ${Boost_LIBRARY_DIR})

