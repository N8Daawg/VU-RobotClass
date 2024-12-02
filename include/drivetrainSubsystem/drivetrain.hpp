/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       drivetrain.hpp                                            */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class declerations            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

using namespace vex;

class driveTrain{
    private:
        inertial* gyro;

        wheelSide* leftSide;
        wheelSide* rightSide;

        double MotorOffset;
        double gearRatio;
        double wheelCircumference;
        double motorConversion;
        double deadzone = 0;

        // Classifications for User Control Modes
        enum UserControlMode {
            tankDrive,
            arcadeDrive
        };

        UserControlMode controlMode = tankDrive;
        void setControlMode(UserControlMode mode){controlMode = mode;}
        UserControlMode getControlMode() {return controlMode;}

    public:
        driveTrain();
        driveTrain(
            motor* FrontLeft, motor* FrontRight,
            motor* BackLeft, motor* BackRight,
            inertial* Gyro,
            double robotlength,
            double gearratio,
            double wheelDiameter
        );

        driveTrain(
            motor* FrontLeft, motor* FrontRight,
            motor* MiddleLeft, motor* MiddleRight,
            motor* BackLeft, motor* BackRight,
            inertial* Gyro,
            double robotlength,
            double gearratio,
            double wheelDiameter
        );

        driveTrain(
            motor* FrontLeft, motor* FrontRight,
            motor* FrontMiddleLeft, motor* FrontMiddleRight,
            motor* BackMiddleLeft, motor* BackMiddleRight,
            motor* BackLeft, motor* BackRight,
            inertial* Gyro,
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
        void setVelocities(double velocity, velocityUnits units);

        /**
         * @brief gets the current heading of the robot
         */
        double getHeading(int dir);

        /*-------------------------------------------------------------------------------*/
        /*----------------------------Driver Control Movements---------------------------*/
        /*-------------------------------------------------------------------------------*/

        /**
         * @brief toggles the drivetrain between Tank Drive and Arcade Drive Control Modes. Drive Train starts in Tank Drive Mode.
         */
        void switchControlMode(){
            if(controlMode == tankDrive){
                controlMode = arcadeDrive;
            } else {
                controlMode = tankDrive;
            }
        }

        /**
         * @brief checks weather the joysticks are outside of the robot's deadzone
         * @param x the input value of the controller that's being checked
         */
        bool withinDeadzone(int x);

        /**
         * @brief checks if the joystick inputs are correct and moves accordingly
         */
        int drive(double leftNS, double leftEW, double rightNS, double rightEW);

};

#endif