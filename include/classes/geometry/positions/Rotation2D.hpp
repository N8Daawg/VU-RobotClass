/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Rotation2D.hpp                                            */
/*    Author:       Evan Merrick                                              */
/*    Created:      Fri Sep 13 2024                                           */
/*    Description:  Stores a rotation value and a unit (rad/deg)              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef ROTATION2D_HPP
#define ROTATION2D_HPP


class Rotation2D
{
private:
    double value; //The value of the rotation in radians
public:

        /*
            ----------------
            --CONSTRUCTORS--
            ----------------
        */ 

        /** 
        * @brief Constructs a new Rotation2D Object
        * @param rotValue The value to be stored as rotation
        * @param inDegrees true if the value is in degrees, false if value is in radians
        */
        Rotation2D(double rotValue, bool inDegrees);


        /*
            ------------
            --MUTATORS--
            ------------
        */

        /** 
        * @brief Sets the value of rotation in degrees
        * @param rotValue The value to be stored as rotation
        */
        void setDegrees(double rotValue);

        /** 
        * @brief Sets the value of rotation in radians
        * @param rotValue The value to be stored as rotation
        */
        void setRadians(double rotValue);

        /** 
        * @brief Rotates the current rotation value by the given double
        * @param rotValue The value to be stored as rotation
        * @param inDegrees True if rotValue is in degrees, false if radians
        */
       void rotate(double rotValue, bool inDegrees);

        /** 
        * @brief Rotates the current rotation value by the given Rotation2D
        * @param rotValue The value to be stored as rotation
        */
       void rotate(Rotation2D rotValue);

        /*
            -------------
            --ACCESSORS--
            -------------
        */

        /** 
        * @brief Gets the value of rotation in degrees as a double
        */
        double Degrees();

        /** 
        * @brief Gets the value of rotation in radians as a double
        */
       double Radians();
};


#endif