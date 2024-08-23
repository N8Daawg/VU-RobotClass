/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Voids.cpp                                                 */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  Positional drivetrain functions                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "AutonUtil/util.hpp"


void setbrakes(brakeType Brake){
    FrontLeft.stop(Brake);FrontRight.stop(Brake);
    BackLeft.stop(Brake);BackRight.stop(Brake);
}

void setVelocities(double v){
    FrontLeft.setVelocity(v, velocityUnits::pct);FrontRight.setVelocity(v, velocityUnits::pct);
    BackLeft.setVelocity(v, velocityUnits::pct);BackRight.setVelocity(v, velocityUnits::pct);
}