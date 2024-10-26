/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       CartesianVectors.hpp                                      */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sat Sep 7 2024                                            */
/*    Description:  file for storing Cartesian Vector class code              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef CARTESIANVECTORS_HPP
#define CARTESIANVECTORS_HPP

class CartesianVector
{
#include "Vectors/PolarVectors.hpp"
private:
    double x;
    double y;
    double z;

public:
    CartesianVector(double X, double Y);

    CartesianVector(double X, double Y, double Z);

    ~CartesianVector();

    double getX();

    double getY();

    double getZ();

    /*---------------------------------------------------------------------------*/
    /*------------------------------Vector Conversion----------------------------*/
    /*---------------------------------------------------------------------------*/

    //PolarVector toPolar(CartesianVector v);

    /*---------------------------------------------------------------------------*/
    /*------------------------------Vector Operations----------------------------*/
    /*---------------------------------------------------------------------------*/

    CartesianVector add(CartesianVector v1, CartesianVector v2);

    CartesianVector subtract(CartesianVector v1, CartesianVector v2);

    CartesianVector crossProduct(CartesianVector v1, CartesianVector v2);

    double dotProduct(CartesianVector v1, CartesianVector v2);
};

#endif