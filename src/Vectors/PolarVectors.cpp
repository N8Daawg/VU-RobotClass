/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       PolarVectors.cpp                                          */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sat Sep 7 2024                                            */
/*    Description:  file for storing Polar Vector class code                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "Vectors/PolarVectors.hpp"
#include "Vectors/CartesianVectors.hpp"
#include "math.h"

PolarVector::PolarVector(double m, double theta)
{
    M=m;
    Theta=theta;
}

PolarVector::~PolarVector()
{
}

double PolarVector::getMagnetude()
{
    return M;
}

double PolarVector::getAngle()
{
    return Theta;
}

/*---------------------------------------------------------------------------*/
/*------------------------------Vector Conversion----------------------------*/
/*---------------------------------------------------------------------------*/

/*
CartesianVector PolarVector::toCartesian(PolarVector v)
{
    return CartesianVector(M * cos(theta), M * sin(theta), 0);
}
*/
/*---------------------------------------------------------------------------*/
/*------------------------------Vector Operations----------------------------*/
/*---------------------------------------------------------------------------*/
/*
PolarVector PolarVector::add(PolarVector v1, PolarVector v2)
{
    return PolarVector();
}

PolarVector PolarVector::subtract(PolarVector v1, PolarVector v2)
{
    return PolarVector();
}

PolarVector PolarVector::crossProduct(PolarVector v1, PolarVector v2)
{
    return PolarVector();
}

PolarVector PolarVector::dotProduct(PolarVector v1, PolarVector v2)
{
    return PolarVector();
}
*/