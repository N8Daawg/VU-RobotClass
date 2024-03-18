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

class driveTrain
{
private:
    vex::motor* FL;
    vex::motor* FR;
    vex::motor* BL;
    vex::motor* BR;
    vex::inertial* gyro;
public:
    driveTrain(
        vex::motor& FrontLeft,
        vex::motor& FrontRight,
        vex::motor& BackLeft,
        vex::motor& BackRight,
        vex::inertial& Gyro
    );

    ~driveTrain();

    /**
     * @brief stops all motors in the drivetrain
    */
    void stopDriveTrain(vex::brakeType Brake);
};


#endif


