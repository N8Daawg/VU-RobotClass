/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

driveTrain::driveTrain(
        vex::inertial &Gyro,
        double robotlength,
        double gearratio,
        double wheelDiameter
) {
    gyro = &Gyro;

    MotorOffset = robotlength/2;
    gearRatio = gearratio;
    wheelCircumference = wheelDiameter*M_PI;

    motorConversion = gearRatio*(wheelCircumference)*(360);

}

driveTrain::~driveTrain(){}

/*---------------------------------------------------------------------------*/
/*-----------------------Drivetrain Utility Functions------------------------*/
/*---------------------------------------------------------------------------*/

double driveTrain::getHeading(int dir){
    switch (dir){
    case 1: // looking left
        return 360 - gyro->heading();
        break;
    case 2: // looking right
        return gyro->heading();
        break;
    default:
        return 0;
        break;
    }
}

/*-------------------------------------------------------------------------------*/
/*----------------------------Driver Control Movements---------------------------*/
/*-------------------------------------------------------------------------------*/

bool driveTrain::withinDeadzone(int x)
{
    return ((x<deadzone) && (x> -deadzone));
}