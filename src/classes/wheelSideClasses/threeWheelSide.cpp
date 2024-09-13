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
