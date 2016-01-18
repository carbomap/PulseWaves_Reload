//
//  cVector.cpp
//  PulseWaves_Reload
//
//  Created by Antoine Cottin on 25/12/2015.
//
//

#include "cVector.hpp"

#include <vector>
#include <cmath>


//cVector::cVector()
//{
//    
//    x_ = 0.;
//    y_ = 0.;
//    z_ = 0.;
//    
//}



cVector::cVector(cPoint origin, cPoint target)
{
    
    x_ = target.getX() - origin.getX();
    y_ = target.getY() - origin.getY();
    z_ = target.getZ() - origin.getZ();
    
}




cVector::cVector(F32 newX, F32 newY, F32 newZ)
{
    
    x_ = newX;
    y_ = newY;
    z_ = newZ;
    
}



void cVector::setX(F32 newX){ x_ = newX; }
void cVector::setY(F32 newY){ y_ = newY; }
void cVector::setZ(F32 newZ){ z_ = newZ; }
void cVector::setXYZ(F32 newX, F32 newY, F32 newZ){ x_ = newX; y_ = newY; z_ = newZ; }

F32 cVector::getX() const { return x_; }
F32 cVector::getY() const { return y_; }
F32 cVector::getZ() const { return z_; }
std::vector<F32> cVector::getXYZ() const
{
    
    std::vector<F32> vec;
    vec.push_back(x_);
    vec.push_back(y_);
    vec.push_back(z_);
    return vec;

}



std::vector<F32> cVector::det(cVector const* other) const
{
    
    F32 detX = (y_ * other->getZ()) - (z_ * other->getY());
    F32 detY = (z_ * other->getX()) - (x_ * other->getZ());
    F32 detZ = (x_ * other->getY()) - (y_ * other->getX());
    std::vector<F32> retVec;
    retVec.push_back(detX);
    retVec.push_back(detY);
    retVec.push_back(detZ);
    return retVec;
    
}



F32 cVector::dot(cVector const* other) const
{
    
    F32 retDot = (x_ * other->getX()) + (y_ * other->getY()) + (z_ * other->getZ());
    return retDot;
    
}



F32 cVector::length() const
{
    
    F32 retLength = sqrt( pow(x_, 2) + pow(y_, 2) + pow(z_, 2) );
    return retLength;
    
}



F32 cVector::horizLength() const
{
    
    F32 retLength = sqrt( pow(x_, 2) + pow(y_, 2));
    return retLength;
    
}



F32 cVector::getRadAngle(cVector const* other) const
{
    
    F32 retAng = acos( this->dot(other) / ( this->length() * other->length() ) );
    return retAng;
    
}



F32 cVector::getDegAngle(cVector const* other) const
{
    
    return this->getRadAngle(other) * (180. / M_PI);
    
}



void cVector::normalizeLength()
{
    
    F32 inv = 1. / this->length();
    x_ *= inv;
    y_ *= inv;
    z_ *= inv;
    
}



void cVector::normalizeLengthBy(F32 value)
{
    
    F32 inv = 1. / value;
    x_ *= inv;
    y_ *= inv;
    z_ *= inv;
    
}



void cVector::opposite()
{
    
    x_ *= -1.;
    y_ *= -1.;
    z_ *= -1.;
    
}



void cVector::scaleUp(cVector const* scaleVec)
{
    
    x_ *= scaleVec->getX();
    y_ *= scaleVec->getY();
    z_ *= scaleVec->getY();
    
}



void cVector::scaleDown(cVector const* scaleVec)
{
    
    x_ *= (1. / scaleVec->getX());
    y_ *= (1. / scaleVec->getY());
    z_ *= (1. / scaleVec->getZ());
    
}



void cVector::translate(cVector const* transVec)
{
    
    x_ += transVec->getX();
    y_ += transVec->getY();
    z_ += transVec->getZ();
    
}