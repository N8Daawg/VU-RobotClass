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
#include "twoWheelSide.hpp"
#include "threeWheelSide.hpp"

class driveTrain{
    private:
        vex::motor* FL;
        vex::motor* FR;
        vex::motor* BL;
        vex::motor* BR;
        vex::inertial* gyro;

        double MotorOffset;
        double gearRatio;
        double wheelCircumference;
        double motorConversion;
        double deadzone = 0;

        twoWheelSide* Lside;
        twoWheelSide* Rside;

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
         * @brief checks weather the joysticks are outside of the robot's deadzone
         * @param x the input value of the controller that's being checked
         */
        bool withinDeadzone(int x);

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