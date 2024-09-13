/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Rotation2D.cpp                                            */
/*    Author:       Evan Merrick                                              */
/*    Created:      Fri Sep 13 2024                                           */
/*    Description:  All the code for representing a rotation value            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "Rotation2D.hpp"
#include "math.h"

//Constructors
Rotation2D::Rotation2D(double rotValue, bool inDegrees) 
{
    if(inDegrees) setDegrees(rotValue);
    else value = rotValue;
}

//Mutators
void Rotation2D::setDegrees(double rotValue)
{
    value = rotValue * (M_PI/180.0); //Convert degrees to radians and set the instance value to that
}

void Rotation2D::setRadians(double rotValue)
{
    value = rotValue;
}

void Rotation2D::rotate(double rotValue, bool inDegrees)
{
    Rotation2D temp2D(rotValue, inDegrees);
    value += temp2D.Radians();
}

void Rotation2D::rotate(Rotation2D rotValue)
{
    value += rotValue.Radians();
}

//Accessors
double Rotation2D::Degrees()
{
    return value * (180/M_PI);
}

double Rotation2D::Radians()
{
    return value;
}