/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Autons.h                                                  */
/*    Author:       Nathan Beals                                              */
/*    Created:      Sun March 17 2024                                         */
/*    Description:  file for storing drivetrain class code                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

using namespace vex;

#ifndef WHEELSIDE_HPP
#define WHEELSIDE_HPP

class wheelSide
{
private:
    int numOfWheels;

    virtual double getMotorAveWrap(){}
    virtual void stopDriveSideWrap(brakeType Brake){}
    virtual void setVelocitiesWrap(double velocity){}

    virtual void spinToWrap(double rotation, double velocity){}
    virtual void spinWrap(directionType dir, double velocity, velocityUnits units){}
    
public:
    wheelSide();
    wheelSide(int wheels);
    ~wheelSide();
    int getNumOfWheels();

    /*---------------------------------------------------------------------------*/
    /*-----------------------Drivetrain Utility Functions------------------------*/
    /*---------------------------------------------------------------------------*/

    /**
     * @brief gets an average position of all motors
    */
    double getMotorAve(){return getMotorAveWrap();}

    /**
     * @brief stops all motors in the drivetrain
    */
    void stopDriveSide(brakeType Brake){stopDriveSideWrap(Brake);}

    /**
     * @brief sets velocities of all motors in drivetrain
    */
    void setVelocities(double velocity){setVelocitiesWrap(velocity);}

    /*---------------------------------------------------------------------------*/
    /*----------------------------DriveSide Movements----------------------------*/
    /*---------------------------------------------------------------------------*/

    /**
     * @brief Spins motor in a direction at a specified velocity
     */
    void spin(vex::directionType dir, double velocity, vex::velocityUnits units){
        spinWrap(dir, velocity, units);
    }

    /**
     * @brief moves drivetrain forward to a certain point
     */
    void spinTo(double rotation, double velocity){
        spinToWrap(rotation, velocity);
    }
};

#endif