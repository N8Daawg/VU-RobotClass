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
#include "driveSide.hpp"

class driveTrain{
    private:
        vex::motor* FL;
        vex::motor* FR;
        vex::motor* BL;
        vex::motor* BR;
        vex::inertial* gyro;

        driveSide* Lside;
        driveSide* Rside;

    public:
        driveTrain(
            vex::motor& FrontLeft,
            vex::motor& FrontRight,
            vex::motor& BackLeft,
            vex::motor& BackRight,
            vex::inertial& Gyro
        );

        ~driveTrain();
        
        
        /*---------------------------------------------------------------------------*/
        /*-----------------------Drivetrain Utility Functions------------------------*/
        /*---------------------------------------------------------------------------*/


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
         * @brief moves the drivetrain forward
         * @param desiredPos the distance to move in inches
         * @param v the speed to move at
        */
        void driveStraight(double desiredPos, double v);

        /**
         * @brief spins the drivetrain on its axis
         * @param theta the degree in degrees of the turn
         * @param v the speed to move at
        */
        void PointTurn(double theta, double v);

        /**
         * @brief moves the drivetrain in an arc
         * @param radius the radius of the turn
         * @param theta the degree in degrees of the turn
         * @param v the speed to move at
        */
        void driveArc(double radius, double theta, double v);

        /**
         * @brief spins the drivetrain left on its axis
         * @param theta the degree in degrees of the turn
         * @param v the speed to move at
        */
        void sidePivot(double theta, double v);

};

#endif