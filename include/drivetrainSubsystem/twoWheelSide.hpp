/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef TWOWHEELSIDE_HPP
#define TWOWHEELSIDE_HPP

class twoWheelSide: public wheelSide{
    private:
        vex::motor* front;
        vex::motor* back;

        double gearRatio;
        double wheelCircumference;
        double motorConversion;

    public:
        twoWheelSide(
            vex::motor* Frontm,
            vex::motor* Backm,
            double gearratio,
            double wheelDiameter
        );

        ~twoWheelSide();

        /*---------------------------------------------------------------------------*/
        /*-----------------------Drivetrain Utility Functions------------------------*/
        /*---------------------------------------------------------------------------*/

        /**
         * @brief gets an average position of all motors
        */
        virtual double getMotorAveWrap();

        /**
         * @brief stops all motors in the drivetrain
        */
        virtual void stopDriveSideWrap(brakeType Brake);

        /**
         * @brief sets velocities of all motors in drivetrain
        */
        virtual void setVelocitiesWrap(double velocity);

        /*---------------------------------------------------------------------------*/
        /*----------------------------DriveSide Movements----------------------------*/
        /*---------------------------------------------------------------------------*/

        /**
         * @brief moves drivetrain forward to a certain point
         */
        virtual void spinToWrap(double rotation, double velocity);

        /**
         * @brief Spins motor in a direction at a specified velocity
         */
        virtual void spinWrap(directionType dir, double velocity, velocityUnits units);

};

#endif