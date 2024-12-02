/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
using namespace vex;

driveTrain::driveTrain(){}


driveTrain::driveTrain(
        motor* FrontLeft, motor* FrontRight,
        motor* BackLeft, motor* BackRight,
        inertial* Gyro,
        double robotlength,
        double gearratio,
        double wheelDiameter
) {
    gyro = Gyro;

    MotorOffset = robotlength/2;
    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);

    leftSide = new twoWheelSide(FrontLeft, BackLeft, gearratio, wheelDiameter);
    rightSide = new twoWheelSide(FrontRight, BackRight, gearratio, wheelDiameter);    
}

driveTrain::driveTrain(
        motor* FrontLeft, motor* FrontRight,
        motor* MiddleLeft, motor* MiddleRight,
        motor* BackLeft, motor* BackRight,
        inertial* Gyro,
        double robotlength,
        double gearratio,
        double wheelDiameter
) {
    gyro = Gyro;

    MotorOffset = robotlength/2;
    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);

    leftSide = new threeWheelSide(FrontLeft, MiddleLeft, BackLeft, gearratio, wheelDiameter);
    rightSide = new threeWheelSide(FrontRight, MiddleRight, BackRight, gearratio, wheelDiameter);    
}

driveTrain::driveTrain(
        motor* FrontLeft, motor* FrontRight,
        motor* FrontMiddleLeft, motor* FrontMiddleRight,
        motor* BackMiddleLeft, motor* BackMiddleRight,
        motor* BackLeft, motor* BackRight,
        inertial* Gyro,
        double robotlength,
        double gearratio,
        double wheelDiameter
) {
    gyro = Gyro;

    MotorOffset = robotlength/2;
    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);

    leftSide = new fourWheelSide(FrontLeft, FrontMiddleLeft, BackMiddleLeft, BackLeft, gearratio, wheelDiameter);
    rightSide = new fourWheelSide(FrontRight, FrontMiddleRight, BackMiddleRight, BackRight, gearratio, wheelDiameter);    
}

driveTrain::~driveTrain(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/


double driveTrain::getMotorAve(){
    return (leftSide->getMotorAve()+
            rightSide->getMotorAve()
            )/2;
}

void driveTrain::resetDrivePositions(){
    leftSide->resetDrivePositions();
    rightSide->resetDrivePositions();
}

void driveTrain::stopDriveTrain(brakeType Brake){
    leftSide->stopDriveSide(Brake);
    rightSide->stopDriveSide(Brake);
}

void driveTrain::setVelocities(double velocity, velocityUnits units){
    leftSide->setVelocity(velocity, units);
    rightSide->setVelocity(velocity, units);
}

double driveTrain::getHeading(int dir){
    double heading = 0;
    switch (dir){
    case 1: // looking left
        heading = 360 - gyro->heading();
        break;
    case 2: // looking right
        heading = gyro->heading();
        break;
    default:
        break;
    }
    return heading;
}


/*---------------------------------------------------------------------------*/
/*----------------------------Drivetrain Movements---------------------------*/
/*---------------------------------------------------------------------------*/

/*
void driveTrain::PointTurn(int dir, double theta, double v){
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

void driveTrain::sidePivot(int dir, double theta, double v){
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

void driveTrain::driveStraight(int dir, double desiredPos, double v){
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

void driveTrain::driveArc(int dir, double radius, double theta, double v){
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
*/

/*-------------------------------------------------------------------------------*/
/*----------------------------Driver Control Movements---------------------------*/
/*-------------------------------------------------------------------------------*/

bool driveTrain::withinDeadzone(int x){
    return ((x<deadzone) && (x> -deadzone));
}

int driveTrain::drive(double leftNS, double leftEW, double rightNS, double rightEW){

    double leftPower = 0;
    double rightPower = 0;
    if(withinDeadzone(leftNS)  && withinDeadzone(leftEW) && 
       withinDeadzone(rightNS) && withinDeadzone(rightEW))
    { //no joystick is telling the robot to move
        stopDriveTrain(hold);

    } else{ //if all joystick values are within the deadzone
        if(getControlMode() == tankDrive){
            leftPower = leftNS + leftEW;
            rightPower = rightNS - rightEW;
        } else if(getControlMode() == arcadeDrive) { 
            leftPower = leftNS + rightEW;
            rightPower = leftNS - rightEW;
        }  
    }

    leftSide->spin(fwd, leftPower, velocityUnits::pct);
    rightSide->spin(fwd, rightPower, velocityUnits::pct);  

    return 1;
}