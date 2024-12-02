/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       intake.cpp                                                */
/*    Author:       Nathan Beals                                              */
/*    Created:      Mon Dec 2 2024                                            */
/*    Description:  file for storing intake class code                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
using namespace vex;

intake::intake(
    motor* DriveMotor,
    digital_out* ActuatingPiston
) {
    driver = DriveMotor;
    actuator = ActuatingPiston;
}

intake::~intake(){}

void intake::extend() {
    actuator->set(true);
}

void intake::retract() {
    actuator->set(false);
}

void intake::setVelocity(double velocity, velocityUnits units) {
    driver->setVelocity(velocity, units);
}

void intake::runIntake() {
    driver->spin(fwd);
}

void intake::runReversedIntake() {
    driver->spin(reverse);
}

void intake::stopIntake() {
    driver->stop(hold);    
}

void intake::runConveyor() {
}
