/**************************************************************
 * Source File:
 *    Lander : The representation of the lander
 * Author:
 *    Ali Cope
 * Summary:
 * Description: Contains the implementations of the
 *  method bodies and all of the functions of the lander. 
 *    Including moving it around the screen. 
 ************************************************************************/
#include "lander.h"
#include "uiDraw.h"
#include "point.h"
#include "velocity.h"



void Lander::applyGravity(float gravity)
{
    velocity.setDy(velocity.getDy()-gravity);
}

void Lander::applyThrustLeft()
{
if (canThrust())
{
    velocity.setDx(velocity.getDx()+0.1);
    fuel --;
}
}

void Lander::applyThrustRight()
{
 if (canThrust())
 {
    velocity.setDx(velocity.getDx()-0.1);
    fuel --;
 }
}

void Lander::applyThrustBottom()
{
    if (canThrust() && fuel > 3)
    {
    velocity.setDy(velocity.getDy()+0.3);
    fuel -=3;
    }
}

void Lander::advance()
{
    point.addX(velocity.getDx()); //get direction from velocity
    point.addY(velocity.getDy()); //get direction from velocity
}

void Lander::draw() const
{
if (isAlive())
{
    drawLander(point);
}
}

bool Lander::canThrust()
{
    return (isAlive() && !isLanded() && fuel > 0);
}