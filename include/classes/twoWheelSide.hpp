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

class twoWheelSide{
    private:
        vex::motor* fMotor;
        vex::motor* bMotor;

        double gearRatio;
        double wheelCircumference;
        double motorConversion;

    public:
        twoWheelSide(
            vex::motor &Front,
            vex::motor &Back,
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
        double getMotorAve();

        /**
         * @brief stops all motors in the drivetrain
        */
        void stopDriveSide(vex::brakeType Brake);

        /**
         * @brief sets velocities of all motors in drivetrain
        */
        void setVelocities(double v);

        /*---------------------------------------------------------------------------*/
        /*----------------------------DriveSide Movements----------------------------*/
        /*---------------------------------------------------------------------------*/

        /**
         * @brief Spins motor in a direction at a specified velocity
         */
        void Spin(vex::directionType dir, double velocity, vex::velocityUnits units);

        void SpinTo(double rotation, double velocity);
};

#endif