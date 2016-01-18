/*
 -----------------------------------------------------------------------------
 
 FILE NAME:
 
 cVector.hpp
 
 PURPOSE:
 
 Header of the customize vector class.
 
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
 
 25/12/2015 - Created by Antoine C. was waiting for Santa
 
 -----------------------------------------------------------------------------
 */



#ifndef cVector_hpp
#define cVector_hpp


// C++
#include <stdio.h>
#include <vector>

// PulseWaves_Reload
#include "../includes/PulseWavesDefs.hpp"
#include "cPoint.hpp"



class cVector
{
    
public:
    
    F32     x_;    // X's vector coordinate
    F32     y_;    // Y's vector coordinate
    F32     z_;    // Z's vector coordinate
    
    
    cVector():x_(0.),y_(0.),z_(0.){};                      // Default constructor - no value pass - all set to 0s
    cVector(F32,F32,F32);           // Constructor where the initial values are passed
    cVector(cPoint, cPoint);        // Constructor that uses 2 points class to create the vector
    cVector(cVector const&  other):
    x_(other.x_),y_(other.y_),z_(other.z_)
    {}; // Copy constructor
    
    ~cVector(){};                   // Destructor
    
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
    std::vector<F32> det(cVector const*) const;
    F32 dot(cVector const*) const;
    F32 length() const;
    F32 horizLength() const;
    F32 getRadAngle(cVector const*) const;
    F32 getDegAngle(cVector const*) const;
    void normalizeLength();
    void normalizeLengthBy(F32);
    void opposite();
    void scaleUp(cVector const*);
    void scaleDown(cVector const*);
    void translate(cVector const*);
    
    // overloading operator
    cVector operator+(const cVector &v) const
    {
        return cVector(x_ + v.x_, y_ + v.y_, z_ + v.z_);
    };
    
    cVector operator +=(const cVector &v)
    {
        x_ += v.x_; y_ += v.y_; z_ += v.z_;
        return *this;
    };
    
};

#endif /* cVector_hpp */
