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

motor FLeft = motor(PORT15, ratio18_1, true);
motor MidLeft = motor(PORT14, ratio18_1, true);
motor BLeft = motor(PORT13, ratio18_1, true);

motor FRight = motor(PORT12, ratio18_1, false);
motor MidRight = motor(PORT11, ratio18_1, false);
motor BRight = motor(PORT16, ratio18_1, false);

inertial Gyro = inertial(PORT5);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
