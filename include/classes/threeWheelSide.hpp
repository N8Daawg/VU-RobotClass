/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef THREEWHEELSIDE_HPP
#define THREEWHEELSIDE_HPP

class threeWheelSide : public twoWheelSide{
    private:
        vex::motor* mMotor;

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