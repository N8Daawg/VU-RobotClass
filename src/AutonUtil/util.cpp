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
    FL.stop(Brake);FR.stop(Brake);
    BL.stop(Brake);BR.stop(Brake);
}

void setVelocities(double v){
    FL.setVelocity(v, velocityUnits::pct);FR.setVelocity(v, velocityUnits::pct);
    BL.setVelocity(v, velocityUnits::pct);BR.setVelocity(v, velocityUnits::pct);
}