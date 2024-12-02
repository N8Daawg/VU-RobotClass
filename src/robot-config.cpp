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

// Unique robot variables for management objects
double robotLength = 12;
double gearRatio = 1;
double wheelDiameter = 4;


// VEXcode device constructors
// DriveTrain Set up
motor FLeft = motor(PORT15, ratio18_1, true);
motor MidLeft = motor(PORT14, ratio18_1, true);
motor BLeft = motor(PORT13, ratio18_1, true);
motor FRight = motor(PORT12, ratio18_1, false);
motor MidRight = motor(PORT11, ratio18_1, false);
motor BRight = motor(PORT16, ratio18_1, false);
inertial Gyro = inertial(PORT5);


// Sensors Set up
aivision vis = aivision(PORT1, aivision::ALL_AIOBJS);

// Pneumatics Set up
digital_out MogoClamp = digital_out(Brain.ThreeWirePort.A);



// Management object constructors
driveTrain* drive = new driveTrain(
  &FLeft, &FRight, &MidLeft, &MidRight, &BLeft, &BRight, &Gyro, 
  robotLength, gearRatio, wheelDiameter);

clamp* MC = new clamp(&MogoClamp);


// Robot Object construction
Robot robot(drive, MC);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  vis.modelDetection(true);

  // Nothing to initialize
}
