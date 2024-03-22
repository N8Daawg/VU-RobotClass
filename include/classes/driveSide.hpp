/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef DRIVESIDE_HPP
#define DRIVESIDE_HPP

class driveSide{
    private:
        vex::motor* fMotor;
        vex::motor* bMotor;

    public:
        driveSide(
            vex::motor& Front,
            vex::motor& Back
        );

        ~driveSide();

        /*---------------------------------------------------------------------------*/
        /*-----------------------Drivetrain Utility Functions------------------------*/
        /*---------------------------------------------------------------------------*/

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

        void Spin(vex::directionType dir, double voltage, vex::voltageUnits units);

        void SpinTo(double rotation, double velocity);
};

#endif