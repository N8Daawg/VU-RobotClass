/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       sensorUnit.hpp                                            */
/*    Author:       Nathan Beals                                              */
/*    Created:      Fri Dec 6                                                 */
/*    Description:  file for storing Odom Sensor managment class declerations */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef SENSORUNIT_HPP
#define SENSORUNIT_HPP
using namespace vex;

class sensorUnit
{
    private:
        inertial* gyro;

        rotation* NSPod;
        rotation* EWPod;

    public:

        /**
         * @brief creates a new odomUnit to manage drivetrain sensors
         * 
         * @param gyroscope the gyroscope for the sensor unit
         * @param pod1 The Pod facing North and South
         * @param pod2 The Pod facing East and West
         */
        sensorUnit(
            inertial* gyroscope,
            rotation* pod1,
            rotation* pod2
        );

        ~sensorUnit();

        /* GYRO FUNCTIONS */

        /**
         * @brief resets the gyroscope's heading value to 0.
         */
        void resetHeading(){gyro->resetHeading();}

        /**
         * @brief gets the current heading of the robot
         * @param dir specifies whether the robot is looking left or right
         */
        double getHeading(int dir);


        /* ODOM FUNCTIONS */
        double getPosNS();
};

#endif