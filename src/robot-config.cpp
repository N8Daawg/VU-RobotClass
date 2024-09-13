/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot-config.cpp                                          */
/*    Author:       auto genorated                                            */
/*    Created:      Sun Feb. 18 2024                                          */
/*    Description:  creates global instances of all vex devices               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors

// DriveTrain Set up
motor FrontLeft = motor(PORT19, ratio18_1, true);
motor BackLeft = motor(PORT10, ratio18_1, true);
motor FrontRight = motor(PORT15, ratio18_1, false);
motor BackRight = motor(PORT17, ratio18_1, false);
inertial Gyro = inertial(PORT21);

standardDrive drive(FrontLeft, FrontRight, BackLeft, BackRight, Gyro, 12, 1, 4);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
