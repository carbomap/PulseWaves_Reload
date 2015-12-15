/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 PulseWavesDefs.hpp
 
 PURPOSE:
 
 Header for some constant and typedef.
 
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
 
 01/12/2015 - Created by Antoine C.
 
 -----------------------------------------------------------------------------
 */



#ifndef PulseWavesDefs_hpp
#define PulseWavesDefs_hpp


// C++
#include <stdio.h>

// Boost
#include <boost/cstdint.hpp>


#define PLS_USER_ID_SIZE                                  16
#define PLS_DESCRIPTION_SIZE                              64
#define PLS_UNDEFINED                                     0
#define PLS_OUTGOING                                      1
#define PLS_RETURNING                                     2
#define PLS_OSCILLATING                                   1
#define PLS_LINE                                          2
#define PLS_CONIC                                         3
#define PLS_OPTICAL_CENTER_AND_ANCHOR_POINT_COINCIDE      0x0
#define PLS_OPTICAL_CENTER_AND_ANCHOR_POINT_FLUCTUATE     0x8FFFFFFF
#define PLS_PULSE_FORMAT_0                                0
#define PLS_PULSE_ATTRIBUTES_PULSE_SOURCE_ID_16BIT        0x00000001
#define PLS_PULSE_ATTRIBUTES_PULSE_SOURCE_ID_32BIT        0x00000002
#define PLS_PULSE_FORMAT_0_SIZE                           48
#define PLS_PULSE_ATTRIBUTES_PULSE_SOURCE_ID_16BIT_SIZE   2
#define PLS_PULSE_ATTRIBUTES_PULSE_SOURCE_ID_32BIT_SIZE   4
#define PLS_EMPTY_TABLE_ENTRY                             -2.0e+37f
#define PLS_TABLE_UNDEFINED                               0
#define PLS_TABLE_INTENSITY_CORRECTION                    1
#define PLS_TABLE_RANGE_CORRECTION                        2

typedef boost::int8_t       I8;
typedef boost::int16_t      I16;
typedef boost::int32_t      I32;
typedef boost::int64_t      I64;
typedef boost::uint8_t      U8;
typedef boost::uint16_t     U16;
typedef boost::uint32_t     U32;
typedef boost::uint64_t     U64;
typedef float               F32;
typedef double              F64;

#endif /* PulseWavesDefs_hpp */
