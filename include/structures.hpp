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

// Alliance Color IDs
enum allianceColor {
    neutral,
    redAlliance,
    blueAlliance,
};

// AI Classification Competition Element IDs
enum gameElements {
  mobileGoal,
  redRing,
  blueRing,
};

struct coordinate
{
  double x;
  double y;
};

#endif