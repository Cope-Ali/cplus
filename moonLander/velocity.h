/***********************************************************************
 * Header File:
 *    Velocity:
 * Author:
 *    Ali Cope
 * Summary:
 *    Definition of Velocity Class
 ************************************************************************/


#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>
#include "point.h"

/*********************************************
 * Velocity
 *********************************************/
class Velocity
{ 
public:
   // constructors
    Velocity()           : dx(0.0), dy(0.0) {}
    Velocity(float dx, float dy);

   // getters
  float getDx()     const {return dx;       }
  float getDy()     const {return dy;       }

   // setters
   void setDx(float dx);
   void setDy(float dy);     
 

private:
  float dx;            //horizontal direction
  float dy;            //vertical direction

};


#endif // POINT_H
