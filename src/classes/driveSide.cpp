/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

driveSide::driveSide(
        vex::motor& Front,
        vex::motor& Back
) {
    fMotor = &Front;
    bMotor = &Back;
}

driveSide::~driveSide(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/

void driveSide::stopDriveSide(vex::brakeType Brake){
    fMotor->stop(Brake);
    bMotor->stop(Brake);
}

void driveSide::setVelocities(double v){
    fMotor->setVelocity(v, pct);
    bMotor->setVelocity(v, pct);
}

/*---------------------------------------------------------------------------*/
/*----------------------------DriveSide Movements----------------------------*/
/*---------------------------------------------------------------------------*/

void driveSide::Spin(vex::directionType dir, double voltage, vex::voltageUnits units){
    fMotor->spin(dir, voltage, units);
    bMotor->spin(dir, voltage, units);
}

void driveSide::SpinTo(double rotation, double velocity){
    fMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
    bMotor->spinTo(rotation, degrees, velocity, velocityUnits::pct);
}