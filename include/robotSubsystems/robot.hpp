/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot.hpp                                            */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing robot class declerations            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "structures.hpp"
using namespace vex;


class Robot
{
private:
    coordinate coords;
    driveTrain* driveT;
    clamp* mogoClamp;

public:
    Robot(
        driveTrain* dt,
        clamp* MC
    );

    ~Robot();

    /* Drive Controlls */

    void switchControlMode(){
        driveT->switchControlMode();
    }
    
    int drive(double leftNS, double leftEW, double rightNS, double rightEW);

    /* Subsystem Controlls */

    /* MOGO Clamp */

    void toggleMogoClamp();

    /* Intake Commands */

    /* Expansion */
};

#endif