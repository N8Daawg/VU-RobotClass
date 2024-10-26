/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       PolarVectors.hpp                                          */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sat Sep 7 2024                                            */
/*    Description:  file for storing Polar Vector class code                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef POLARVECTORS_HPP
#define POLARVECTORS_HPP

class PolarVector
{
#include "Vectors/CartesianVectors.hpp"
private:
    double M;
    double Theta;

public:
    PolarVector(double m, double theta);

    ~PolarVector();

    double getMagnetude();

    double getAngle();

    /*---------------------------------------------------------------------------*/
    /*------------------------------Vector Conversion----------------------------*/
    /*---------------------------------------------------------------------------*/

    //CartesianVector toCartesian(PolarVector v);

    /*---------------------------------------------------------------------------*/
    /*------------------------------Vector Operations----------------------------*/
    /*---------------------------------------------------------------------------*/
    /*
    PolarVector add(PolarVector v1, PolarVector v2);

    PolarVector subtract(PolarVector v1, PolarVector v2);

    PolarVector crossProduct(PolarVector v1, PolarVector v2);

    PolarVector dotProduct(PolarVector v1, PolarVector v2);
    */
};

#endif