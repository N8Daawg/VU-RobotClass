/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef STANDARDDRIVE_HPP
#define STANDARDDRIVE_HPP
#include "classes/wheelSideClasses/twoWheelSide.hpp"
#include "classes/wheelSideClasses/threeWheelSide.hpp"

class standardDrive : public driveTrain{
    private:
        vex::inertial* gyro;

        double MotorOffset;
        double gearRatio;
        double wheelCircumference;
        double motorConversion;
        double deadzone = 0;

        twoWheelSide* Lside;
        twoWheelSide* Rside;

    public:
        standardDrive(
            vex::motor &FrontLeft,
            vex::motor &FrontRight,
            vex::motor &BackLeft,
            vex::motor &BackRight,
            vex::inertial &Gyro,
            double robotlength,
            double gearratio,
            double wheelDiameter
        );

        ~standardDrive();

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

        /*---------------------------------------------------------------------------*/
        /*----------------------------Drivetrain Movements---------------------------*/
        /*---------------------------------------------------------------------------*/

        /**
         * @brief spins the drivetrain on its axis
         * @param theta the degree in degrees of the turn
         * @param v the speed to move at
        */
        void PointTurn(int dir, double theta, double v);

        /**
         * @brief spins the drivetrain left on its axis
         * @param theta the degree in degrees of the turn
         * @param v the speed to move at
        */
        void sidePivot(int dir, double theta, double v);

        /**
         * @brief moves the drivetrain forward
         * @param desiredPos the distance to move in inches
         * @param v the speed to move at
        */
        void driveStraight(int dir, double desiredPos, double v);

        /**
         * @brief moves the drivetrain in an arc
         * @param radius the radius of the turn
         * @param theta the degree in degrees of the turn
         * @param v the speed to move at
        */
        void driveArc(int dir, double radius, double theta, double v);

        /*-------------------------------------------------------------------------------*/
        /*----------------------------Driver Control Movements---------------------------*/
        /*-------------------------------------------------------------------------------*/

        /**
         * @brief wrapper for controlling movement in driver control period
         * @param leftEW value of the controller's left stick's x axis
         * @param leftNS value of the controller's left stick's y axis
         * @param rightEW value of the controller's right stick's x axis
         * @param rightNS value of the controller's right stick's y axis
         */
        int drive(double leftNS, double leftEW, double rightNS, double rightEW);

};

#endif