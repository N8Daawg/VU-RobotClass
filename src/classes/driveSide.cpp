/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

driveSide::driveSide(
        vex::motor& Front,
        vex::motor& Back
) {
    fMotor = &Front;
    bMotor = &Back;
}

driveSide::~driveSide(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/

void driveSide::stopDriveSide(vex::brakeType Brake){
    fMotor->stop(Brake);bMotor->stop(Brake);
    
}