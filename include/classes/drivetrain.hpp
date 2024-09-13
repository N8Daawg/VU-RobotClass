/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP
#include "wheelSideClasses/twoWheelSide.hpp"
#include "wheelSideClasses/threeWheelSide.hpp"


class driveTrain{
    private:
        vex::inertial* gyro;

        double MotorOffset;
        double gearRatio;
        double wheelCircumference;
        double motorConversion;
        double deadzone = 0;

    public:
        driveTrain(
            vex::inertial &Gyro,
            double robotlength,
            double gearratio,
            double wheelDiameter
        );

        ~driveTrain();

        /*---------------------------------------------------------------------------*/
        /*-----------------------Drivetrain Utility Functions------------------------*/
        /*---------------------------------------------------------------------------*/

        /**
         * @brief gets an average position of all motors
        */
        virtual double getMotorAve() = 0;
        
        /**
         * @brief resets Drivetrain encoders
        */
        virtual void resetDrivePositions() = 0;

        /**
         * @brief stops all motors in the drivetrain
        */
        virtual void stopDriveTrain(vex::brakeType Brake) = 0;

        /**
         * @brief sets velocities of all motors in drivetrain
        */
        virtual void setVelocities(double v) = 0;

        double getHeading(int dir);

        /*-------------------------------------------------------------------------------*/
        /*----------------------------Driver Control Movements---------------------------*/
        /*-------------------------------------------------------------------------------*/

        /**
         * @brief checks weather the joysticks are outside of the robot's deadzone
         * @param x the input value of the controller that's being checked
         */
        bool withinDeadzone(int x);

};

#endif