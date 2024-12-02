/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       intake.hpp                                                */
/*    Author:       Nathan Beals                                              */
/*    Created:      Mon Dec 2 2024                                            */
/*    Description:  file for storing intake class code                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef INTAKE_HPP
#define INTAKE_HPP
using namespace vex;

class intake
{
private:
    //front intake
    motor* driver;
    digital_out* actuator;

    //motor* ringConveyorBelt;
public:
    intake(
        motor* DriveMotor,
        digital_out* ActuatingPiston
    );
    ~intake();

    void extend();
    void retract();

    void setVelocity(double velocity, velocityUnits units);
    void runIntake();
    void runReversedIntake();
    void stopIntake();

    void runConveyor();
};

#endif