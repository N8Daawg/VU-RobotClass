
#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "structures.hpp"
using namespace vex;


class Robot
{
private:
    coordinate coords;
    driveTrain* driveT;

public:
    Robot(double x, double y);
    Robot(
        motor* FL,
        motor* FR,
        motor* BL,
        motor* BR,
        inertial* Gyro,
        double robotlength,
        double gearratio,
        double wheelDiameter
    );

    Robot(
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
    );

    ~Robot();

    void switchControlMode(){
        driveT->switchControlMode();
    }
    
    int drive(double leftNS, double leftEW, double rightNS, double rightEW);
};

#endif