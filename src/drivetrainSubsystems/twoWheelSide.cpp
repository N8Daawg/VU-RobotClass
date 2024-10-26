/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       twoWheelSide.cpp                                          */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing WheelSide class code                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
using namespace vex;

twoWheelSide::twoWheelSide(
        vex::motor* frontm,
        vex::motor* backm,
        double gearratio,
        double wheelDiameter
):wheelSide(2) {
    front = frontm;
    back = backm;

    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);
}

twoWheelSide::~twoWheelSide(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


double twoWheelSide::getMotorAveWrap(){
    double ave = 0;
    if(front->position(degrees)>0){ave += front->position(degrees);
    } else {ave -= front->position(degrees);}
    if(back->position(degrees)>0){ave += back->position(degrees);
    } else {ave -= back->position(degrees);}
    return ave/getNumOfWheels();
}

void twoWheelSide::stopDriveSideWrap(brakeType Brake){
    front->stop(brake);
    back->stop(brake);
}

void twoWheelSide::setVelocitiesWrap(double velocity){
    front->setVelocity(velocity, pct);
    back->setVelocity(velocity, pct);
}

/*---------------------------------------------------------------------------*/
/*----------------------------DriveSide Movements----------------------------*/
/*---------------------------------------------------------------------------*/

void twoWheelSide::spinWrap(vex::directionType dir, double velocity, vex::velocityUnits units){
    front->spin(dir, velocity, units);
    back->spin(dir, velocity, units);
}

void twoWheelSide::spinToWrap(double rotation, double velocity){
    front->spinTo(rotation, degrees, velocity, velocityUnits::pct);
    back->spinTo(rotation, degrees, velocity, velocityUnits::pct);
}
