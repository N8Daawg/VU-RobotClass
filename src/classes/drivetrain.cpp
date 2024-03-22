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

    Lside = new driveSide(*FL,*BL);
    Rside = new driveSide(*FR,*BR);

}

driveTrain::~driveTrain(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


void driveTrain::stopDriveTrain(vex::brakeType Brake){
    Lside->stopDriveSide(Brake);
    Rside->stopDriveSide(Brake);
}

void driveTrain::setVelocities(double v){
    Lside->setVelocities(v);
    Rside->setVelocities(v);
}


/*---------------------------------------------------------------------------*/
/*----------------------------Drivetrain Movements---------------------------*/
/*---------------------------------------------------------------------------*/


void driveTrain::driveStraight(double desiredPos, double v){

}

void driveTrain::PointTurn(double theta, double v){
    
}

void driveTrain::driveArc(double radius, double theta, double v){
    
}

void driveTrain::sidePivot(double theta, double v){
    
}