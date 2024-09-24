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

#include "classes/twoWheelSide.hpp"
#include "classes/threeWheelSide.hpp"
class driveTrain{
    private:
        vex::motor* FR;
        vex::motor* BR;
        vex::motor* FL;
        vex::motor* BL;

        vex::inertial* gyro;

        double MotorOffset;
        double gearRatio;
        double wheelCircumference;
        double motorConversion;
        double deadzone = 0;

        twoWheelSide Lside;
        twoWheelSide Rside;

    public:
        driveTrain(
            vex::motor &FrontLeft,
            vex::motor &FrontRight,
            vex::motor &BackLeft,
            vex::motor &BackRight,
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
        double getMotorAve();
        
        /**
         * @brief resets Drivetrain encoders
        */
        void resetDrivePositions();

        /**
         * @brief stops all motors in the drivetrain
        */
        void stopDriveTrain(vex::brakeType Brake);

        /**
         * @brief sets velocities of all motors in drivetrain
        */
        void setVelocities(double v);

        double getHeading(int dir);

        /*-------------------------------------------------------------------------------*/
        /*----------------------------Driver Control Movements---------------------------*/
        /*-------------------------------------------------------------------------------*/

        /**
         * @brief checks weather the joysticks are outside of the robot's deadzone
         * @param x the input value of the controller that's being checked
         */
        bool withinDeadzone(int x);

        int drive(double leftNS, double leftEW, double rightNS, double rightEW);

};

#endif