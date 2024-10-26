#include "vex.h"
using namespace vex;

wheelSide::wheelSide()
{
    numOfWheels=0;
}

wheelSide::wheelSide(int wheels)
{
    numOfWheels=wheels;
}

wheelSide::~wheelSide(){}

int wheelSide::getNumOfWheels(){return numOfWheels;}
