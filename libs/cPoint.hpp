//
//  cPoint.hpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 25/12/2015.
//
//

#ifndef cPoint_hpp
#define cPoint_hpp

// C++
#include <stdio.h>

// PulseWaves_Reload
#include "../includes/PulseWaves.hpp"


class cPoint
{
    
private:
    
    F32     x_;    // X's point coordinate
    F32     y_;    // Y's point coordinate
    F32     z_;    // Z's point coordinate
    
public:
    
    cPoint();                      // Default constructor - no value pass - all set to 0s
    cPoint(F32,F32,F32);           // Constructor where the initial values are passed
    cPoint(cPoint const&  other):
    x_(other.x_),y_(other.y_),z_(other.z_)
    {}; // Copy constructor
    
    ~cPoint(){};                   // Destructor
    
    // Setters
    void setX(F32);
    void setY(F32);
    void setZ(F32);
    void setXYZ(F32,F32,F32);
    
    // Getters
    F32 getX() const;
    F32 getY() const;
    F32 getZ() const;
    std::vector<F32> getXYZ() const;
    
    // Public methods
    
    
};




#endif /* cPoint_hpp */
