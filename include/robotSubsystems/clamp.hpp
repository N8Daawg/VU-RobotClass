/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       clamp.hpp                                                 */
/*    Author:       Nathan Beals                                              */
/*    Created:      Mon Dec 2 2024                                            */
/*    Description:  file for storing MOGO clamp class declerations            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CLAMP_HPP
#define CLAMP_HPP

using namespace vex;

class clamp
{
private:
    bool clampState = true;
    digital_out* MogoClamp;

public:
    clamp(digital_out* MC);
    ~clamp();

    // Clamp functionality
    
    void open();
    void close();
    void toggle();
};

#endif