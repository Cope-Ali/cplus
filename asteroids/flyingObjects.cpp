/************************************************************
 * Source File:
 *    FLY:
 * Author:
 *    Ali Cope
 * Description: Contains the implementations of the
 *  method bodies for the flyingObjects
 * class.
 ************************************************************************/


#include "flyingObjects.h"
#include "point.h"
#include "velocity.h"

#include <iostream>



/*************************************
 *  FLY: ADVANCE
 * advance flying object
 * **********************************/
void FlyingObjects::advance() 
{ 
    
    point.addX(velocity.getDx()); //get direction from velocity
    point.addY(velocity.getDy()); //get direction from velocity
}

