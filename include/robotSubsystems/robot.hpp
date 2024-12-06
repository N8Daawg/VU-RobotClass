/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot.hpp                                                 */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing robot class declerations                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "structures.hpp"
using namespace vex;


class Robot {
    private:
        coordinate coords;
        driveTrain* driveT;
        clamp* mogoClamp;
        intake* frontIntake;
        
    public:
        Robot(
            driveTrain* dt,
            clamp* MC,
            intake* I
        );

        ~Robot();

        /* Drive Controlls */

        /**
         * @brief Switch between Arcade drive and tank drive
         */
        void switchControlMode(){
            driveT->switchControlMode();
        }
        
        /**
         * 
         */
        int drive(double leftNS, double leftEW, double rightNS, double rightEW);

        /* Subsystem Controlls */

        /* MOGO Clamp */

        /**
         * 
         */
        void toggleMogoClamp();

        /* Intake Commands */

        /**
         * 
         */
        void runIntake();

        /**
         * 
         */
        void runReversedIntake();

        /* Expansion */
};

#endif