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
        vex::motor& Back,
        double gearratio,
        double wheelDiameter
) {
    fMotor = &Front;
    bMotor = &Back;

    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);
}

driveSide::~driveSide(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


double driveSide::getMotorAve(){
    double ave = 0;
    if(fMotor->position(degrees)>0){ave += fMotor->position(degrees);
    } else {ave += (fMotor->position(degrees)*-1);}
    if(bMotor->position(degrees)>0){ave += bMotor->position(degrees);
    } else {ave += (bMotor->position(degrees)*-1);}
    return ave/2;
}

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