/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"


driveTrain::driveTrain(
        vex::motor& FrontLeft,
        vex::motor& FrontRight,
        vex::motor& BackLeft,
        vex::motor& BackRight,
        vex::inertial& Gyro
) {
    FL = &FrontLeft;
    FR = &FrontRight;
    BL = &BackLeft;
    BR = &BackRight;
    gyro = &Gyro;
}

driveTrain::~driveTrain(){}

void driveTrain::stopDriveTrain(vex::brakeType Brake){
    FL->stop(Brake);FR->stop(Brake);
    BL->stop(Brake);BR->stop(Brake);
}