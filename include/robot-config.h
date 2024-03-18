/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot-config.h                                            */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun Feb. 18 2024                                          */
/*    Description:  declerations of robot motors and devices                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "classes/drivetrain.hpp"
using namespace vex;
//#include "classes/drivetrain.hpp"

extern brain Brain;

// VEXcode devices

// Drivetrain Setup
extern motor FL;
extern motor BL;
extern motor FR;
extern motor BR;
extern inertial Gyro;

extern driveTrain drive;

// CATA Setup
extern motor CataLeft;
extern motor CataRight;

// Intake Setup
extern motor Intake;
extern pneumatics pneumaticIntake;

// wall Setup
extern pneumatics pneumaticWing;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
