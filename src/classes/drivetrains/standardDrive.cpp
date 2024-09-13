/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/ 
#include "vex.h"

standardDrive::standardDrive(
        vex::motor &FrontLeft,
        vex::motor &FrontRight,
        vex::motor &BackLeft,
        vex::motor &BackRight,
        vex::inertial &Gyro,
        double robotlength,
        double gearratio,
        double wheelDiameter
):driveTrain(Gyro, robotlength, gearratio, wheelDiameter) {
    twoWheelSide Lside(*FL,*BL, gearRatio, wheelDiameter);
    twoWheelSide Rside(*FR,*BR, gearRatio, wheelDiameter);
}

standardDrive::~standardDrive(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


double standardDrive::getMotorAve(){
    return (Lside->getMotorAve()+Rside->getMotorAve())/2;
}

void standardDrive::resetDrivePositions(){
    FL->resetPosition();FR->resetPosition();
    BL->resetPosition();BR->resetPosition();
}

void standardDrive::stopDriveTrain(vex::brakeType Brake){
    Lside->stopDriveSide(Brake);
    Rside->stopDriveSide(Brake);
}

void standardDrive::setVelocities(double v){
    Lside->setVelocities(v);
    Rside->setVelocities(v);
}

/*---------------------------------------------------------------------------*/
/*----------------------------Drivetrain Movements---------------------------*/
/*---------------------------------------------------------------------------*/


void standardDrive::PointTurn(int dir, double theta, double v){
    setVelocities(v);resetDrivePositions();
    bool complete = false; gyro->resetRotation();double errorOffset=4;
    double ave; double head; double goal = theta*MotorOffset/motorConversion;

    while(!complete){
        switch (dir) {
        case 1: // Left turn
            FL->spin(reverse);FR->spin(forward);
            BL->spin(reverse);BR->spin(forward);
            break;
        case 2: // right turn
            FL->spin(forward);FR->spin(reverse);
            BL->spin(forward);BR->spin(reverse);
            break;
        default:
            stopDriveTrain(hold);
            complete=true;
            break;
        }
        ave = getMotorAve(); head = getHeading(dir);
        if ((theta-errorOffset < head < theta+errorOffset) ||
            (goal-errorOffset < ave < goal+errorOffset)){
                complete = true;
        }
    }
    stopDriveTrain(hold);
}

void standardDrive::sidePivot(int dir, double theta, double v){
    setVelocities(v);resetDrivePositions();
    bool complete = false; Gyro.resetRotation();double errorOffset=4;
    double ave; double head; double goal = theta*MotorOffset/motorConversion;
    
    while (!complete){
        switch (dir) {
        case 1: // Left turn
            FR->spin(forward);BR->spin(forward);
            ave = Rside->getMotorAve(); 
            break;
        case 2: // right turn
            FL->spin(forward);BL->spin(forward);
            ave = Lside->getMotorAve();
            break;
        default:
            stopDriveTrain(hold);
            complete=true;
            break;
        }
        head = getHeading(dir);
        if ((theta-errorOffset < head < theta+errorOffset) ||
            (goal-errorOffset < ave < goal+errorOffset)){
                complete = true;
        }
    }
    stopDriveTrain(hold);    
}

void standardDrive::driveStraight(int dir, double desiredPos, double v){
    setVelocities(v);resetDrivePositions();
    bool complete = false; double ave; double errorOffset = 4; 
    double goal = desiredPos/motorConversion;

    while(!complete){
        switch (dir){
        case 1: // forward movement
            FL->spin(forward);FR->spin(forward);
            BL->spin(forward);BR->spin(forward);
            break;
        case 2:
            FL->spin(reverse);FR->spin(reverse);
            BL->spin(reverse);BR->spin(reverse);
            break;
        default:
            stopDriveTrain(hold);
            complete=true;
            break;
        }
        ave = getMotorAve();
        if (goal-errorOffset < ave < goal+errorOffset){
                complete = true;
        }
    }

    stopDriveTrain(hold);
}

void standardDrive::driveArc(int dir, double radius, double theta, double v){
    resetDrivePositions();
    bool complete = false; double ave; double head; double errorOffset = 4; double goal = (theta*radius)/motorConversion; 
    double leftspeed; double rightspeed; double leftRadius; double rightRadius;
    
    switch(dir){
        case 1: // left
            leftRadius = radius-MotorOffset;
            rightRadius = radius+MotorOffset;
            break;
        case 2: // right
            leftRadius = radius+MotorOffset;
            rightRadius = radius-MotorOffset;
            break;
        default:
            leftRadius=1;
            rightRadius=1;
            break;
    }

    leftspeed = v*(leftRadius/radius);rightspeed = v*(rightRadius/radius);
    Lside->setVelocities(leftspeed); Rside->setVelocities(rightspeed);
    
    while(!complete){
        FL->spin(fwd);FR->spin(fwd);
        BL->spin(fwd);BR->spin(fwd);
        ave = ((Lside->getMotorAve()*radius/leftRadius)+ 
               (Rside->getMotorAve()*radius/rightRadius))/2;
        head = getHeading(dir);
        
        if ((theta-errorOffset < head < theta+errorOffset) ||
            (goal-errorOffset < ave < goal+errorOffset)){
                complete = true;
        }
    }
    stopDriveTrain(hold);
}

/*-------------------------------------------------------------------------------*/
/*----------------------------Driver Control Movements---------------------------*/
/*-------------------------------------------------------------------------------*/

int standardDrive::drive(double leftNS, double leftEW, double rightNS, double rightEW){
    if(withinDeadzone(leftNS)  && withinDeadzone(leftEW) && 
       withinDeadzone(rightNS) && withinDeadzone(rightEW))
    { //if all joystick values are within the deadzone

        double leftPower = leftNS + leftEW;
        double rightPower = rightNS - rightEW;
        
        Lside->Spin(fwd, leftPower, velocityUnits::pct);
        Rside->Spin(fwd, rightPower, velocityUnits::pct);

    } else{ //no joystick is telling the robot to move
        stopDriveTrain(hold);
    }
    return 1;
}