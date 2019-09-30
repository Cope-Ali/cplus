/************************************************************
 * Source File:
 *    Velocity:
 * Author:
 *    Ali Cope
 * Description: Contains the implementations of the
 *  method bodies for the velocity class.
 ************************************************************************/


#include "velocity.h"
#include <iostream>

/***************************************
* VELOCITY: CONSTRUCTOR WITH DX, DY
* Initialize the velocity pass to the position
**************************************/
Velocity::Velocity(float dx, float dy) : dx(0.0), dy(0.0)
{
    setDx(dx);
    setDy(dy);
}

/*************************************
 *  VELOCITY: SET DX
 * set the dx velocity
 * **********************************/
void Velocity::setDx(float dx) 
{ 
    this->dx = dx; 
}

/*************************************
 *  VELOCITY: SET DY
 * set the dy velocity
 * **********************************/
void Velocity::setDy(float dy) 
{ 
    this->dy = dy; 
}
