/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       CartesianVectors.hpp                                      */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sat Sep 7 2024                                            */
/*    Description:  file for storing Cartesian Vector class code              */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "Vectors/CartesianVectors.hpp"
#include "math.h"

CartesianVector::CartesianVector(
    double X,
    double Y
    )
{
    x = X;
    y = Y;
}

CartesianVector::CartesianVector(double X, double Y, double Z)
{
    x = X;
    y = Y;
    z = Z;
}

CartesianVector::~CartesianVector()
{
}

double CartesianVector::getX()
{
    return x;
}

double CartesianVector::getY()
{
    return y;
}

double CartesianVector::getZ()
{
    return z;
}

/*---------------------------------------------------------------------------*/
/*------------------------------Vector Conversion----------------------------*/
/*---------------------------------------------------------------------------*/

/*
PolarVector CartesianVector::toPolar(CartesianVector v)
{
    return PolarVector(sqrt(pow(x, 2) + pow(y, 2)), atan2(y, x));
}
*/

/*---------------------------------------------------------------------------*/
/*------------------------------Vector Operations----------------------------*/
/*---------------------------------------------------------------------------*/

CartesianVector CartesianVector::add(CartesianVector v1, CartesianVector v2)
{
    return CartesianVector(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

CartesianVector CartesianVector::subtract(CartesianVector v1, CartesianVector v2)
{
    return CartesianVector(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

CartesianVector CartesianVector::crossProduct(CartesianVector v1, CartesianVector v2)
{
    return CartesianVector(
        (v1.getY() * v2.getZ()) - (v1.getZ() * v2.getY()),
        (v1.getX() * v2.getZ()) - (v1.getZ() * v2.getX()),
        (v1.getX() * v2.getY()) - (v1.getY() * v2.getX())
        );
}

double CartesianVector::dotProduct(CartesianVector v1, CartesianVector v2)
{
    return ((v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ()));
}
