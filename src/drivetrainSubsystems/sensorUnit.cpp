/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       odomUnit.cpp                                              */
/*    Author:       Nathan Beals                                              */
/*    Created:      Fri Dec 6                                                 */
/*    Description:  file for storing Odom Sensor managment class code         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
using namespace vex;

sensorUnit::sensorUnit(
    inertial* gyroscope,
    rotation* pod1,
    rotation* pod2
) {
    gyro = gyroscope;
    NSPod = pod1;
    EWPod = pod2;


    gyro->resetHeading();
}

sensorUnit::~sensorUnit(){}


/* GYRO FUNCTIONS */

double sensorUnit::getHeading(int dir){
    double heading = 0;
    switch (dir){
        case 1: // looking left
            heading = 360 - gyro->heading();
            break;

        case 2: // looking right
            heading = gyro->heading();
            break;
            
        default:
            break;
    }

    if (heading==360){
        return 0;
    } else {
        return heading;
    }
}

double sensorUnit::getPosNS(){
    return NSPod->position(rotationUnits::deg);
}