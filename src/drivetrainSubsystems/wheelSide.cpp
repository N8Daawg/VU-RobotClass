#include "vex.h"
using namespace vex;



wheelSide::wheelSide(int wheels)
{
    numOfWheels=wheels;
}

wheelSide::~wheelSide(){}

int wheelSide::getNumOfWheels(){return numOfWheels;}
