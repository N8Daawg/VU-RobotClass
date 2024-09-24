/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Fri August 23 2024                                        */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef THREEWHEELSIDE_HPP
#define THREEWHEELSIDE_HPP

class threeWheelSide{
    private:
        vex::motor* fMotor;
        vex::motor* mMotor;
        vex::motor* bMotor;
        double gearRatio;
        double wheelDiameter;

    public:
        threeWheelSide(
            vex::motor &Front,
            vex::motor &Middle,
            vex::motor &Back,
            double gearratio,
            double wheelDiameter
        );

        ~threeWheelSide();

        /*---------------------------------------------------------------------------*/
        /*-----------------------Drivetrain Utility Functions------------------------*/
        /*---------------------------------------------------------------------------*/

};

#endif