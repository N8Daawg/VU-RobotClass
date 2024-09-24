/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       twoWheelSide.cpp                                          */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing WheelSide class code                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

twoWheelSide::twoWheelSide(
        vex::motor &Front,
        vex::motor &Back,
        double gearratio,
        double wheelDiameter
) {
    fMotor = &Front;
    bMotor = &Back;

    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);
}

twoWheelSide::twoWheelSide(){
    fMotor = nullptr;
    bMotor = nullptr;

    gearRatio = 0;
    wheelCircumference = 0;

    motorConversion = 0;   
}

twoWheelSide::~twoWheelSide(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


double twoWheelSide::getMotorAve(){
    double ave = 0;
    if(fMotor->position(degrees)>0){ave += fMotor->position(degrees);
    } else {ave += (fMotor->position(degrees)*-1);}
    if(bMotor->position(degrees)>0){ave += bMotor->position(degrees);
    } else {ave += (bMotor->position(degrees)*-1);}
    return ave/2;
}

void twoWheelSide::stopDriveSide(vex::brakeType Brake){
    fMotor->stop(Brake);
    bMotor->stop(Brake);
}

void twoWheelSide::setVelocities(double v){
    fMotor->setVelocity(v, pct);
    bMotor->setVelocity(v, pct);
}

/*---------------------------------------------------------------------------*/
/*----------------------------DriveSide Movements----------------------------*/
/*---------------------------------------------------------------------------*/

void twoWheelSide::Spin(vex::directionType dir, double velocity, vex::velocityUnits units){
    fMotor->spin(dir, velocity, units);
    bMotor->spin(dir, velocity, units);
}

void twoWheelSide::SpinTo(double rotation, double velocity){
    fMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
    bMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
}