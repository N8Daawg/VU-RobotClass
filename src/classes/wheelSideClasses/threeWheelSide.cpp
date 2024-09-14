/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

threeWheelSide::threeWheelSide(
        vex::motor &Front,
        vex::motor &Middle,
        vex::motor &Back,
        double gearratio,
        double wheelDiameter
):twoWheelSide(Front, Back, gearratio, wheelDiameter) {
    mMotor = &Middle;
}

threeWheelSide::~threeWheelSide(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


double twoWheelSide::getMotorAve(){
    double ave = 0;
    if(fMotor->position(degrees)>0){ave += fMotor->position(degrees);
    } else {ave += (fMotor->position(degrees)*-1);}
    if(mMotor->position(degrees)>0){ave += mMotor->position(degrees);
    } else {ave += (mMotor->position(degrees)*-1);}
    if(bMotor->position(degrees)>0){ave += bMotor->position(degrees);
    } else {ave += (bMotor->position(degrees)*-1);}
    return ave/3;
}

void twoWheelSide::stopDriveSide(vex::brakeType Brake){
    fMotor->stop(Brake);
    mMotor->stop(Brake);
    bMotor->stop(Brake);
}

void twoWheelSide::setVelocities(double v){
    fMotor->setVelocity(v, pct);
    mMotor->setVelocity(v, pct);
    bMotor->setVelocity(v, pct);
}

/*---------------------------------------------------------------------------*/
/*----------------------------DriveSide Movements----------------------------*/
/*---------------------------------------------------------------------------*/

void twoWheelSide::Spin(vex::directionType dir, double velocity, vex::velocityUnits units){
    fMotor->spin(dir, velocity, units);
    mMotor->spin(dir, velocity, units);
    bMotor->spin(dir, velocity, units);
}

void twoWheelSide::SpinTo(double rotation, double velocity){
    fMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
    mMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
    bMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
}