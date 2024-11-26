#include "vex.h"
using namespace vex;

Robot::Robot(double x, double y) {
    coords.x = x;
    coords.y = y;
    driveT = new driveTrain();
}

Robot::Robot(
    motor* FL,
    motor* FR,
    motor* BL,
    motor* BR,
    inertial* Gyro,
    double robotlength,
    double gearratio,
    double wheelDiameter
) {
    coords.x=0;
    coords.y=0;
    driveT = new driveTrain(FL, FR, BL, BR, Gyro, 
        robotlength, gearratio, wheelDiameter);
}

Robot::Robot(
    motor* FL,
    motor* FR,
    motor* ML,
    motor* MR,
    motor* BL,
    motor* BR,
    inertial* Gyro,
    double robotlength,
    double gearratio,
    double wheelDiameter
) {
    coords.x=0;
    coords.y=0;
    driveT = new driveTrain(FL, FR, ML, MR, BL, BR, Gyro, 
        robotlength, gearratio, wheelDiameter);
}

Robot::~Robot(){}

int Robot::drive(double leftNS, double leftEW, double rightNS, double rightEW) {
    return driveT->drive(leftNS, leftEW, rightNS, rightEW);
}
