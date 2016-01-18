//
//  cPoint.cpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 25/12/2015.
//
//

#include "cPoint.hpp"



cPoint::cPoint()
{
    
    x_ = 0.;
    y_ = 0.;
    z_ = 0.;
    
}



cPoint::cPoint(F32 newX, F32 newY, F32 newZ)
{
    
    x_ = newX;
    y_ = newY;
    z_ = newZ;
    
}



void cPoint::setX(F32 newX){ x_ = newX; }
void cPoint::setY(F32 newY){ y_ = newY; }
void cPoint::setZ(F32 newZ){ z_ = newZ; }
void cPoint::setXYZ(F32 newX, F32 newY, F32 newZ){ x_ = newX; y_ = newY; z_ = newZ; }

F32 cPoint::getX() const { return x_; }
F32 cPoint::getY() const { return y_; }
F32 cPoint::getZ() const { return z_; }
std::vector<F32> cPoint::getXYZ() const
{
    
    std::vector<F32> vec;
    vec.push_back(x_);
    vec.push_back(y_);
    vec.push_back(z_);
    return vec;
    
}
