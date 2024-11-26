/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       structures.hpp                                            */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing autonomous programs                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

using namespace vex;

enum allianceColor {
    redAlliance,
    blueAlliance,
    neutral
};

struct coordinate
{
    double x;
    double y;
};

#endif