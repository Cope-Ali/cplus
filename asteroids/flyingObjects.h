/***********************************************************************
 * Header File:
 *    FLY:
 * Author:
 *    Ali Cope
 * Summary:
 *    Definition of FlyingObjects
 * base Class
 ************************************************************************/

#ifndef FLYINGOBJECTS_H
#define FLYINGOBJECTS_H

#include <iostream>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/*********************************************
 * FlyingObjects
 *
 *********************************************/
class FlyingObjects
{
protected:
    Point point;
    Velocity velocity;
    bool alive;

  public:
    // constructors
    FlyingObjects
  (){}
    // destructor
    virtual ~FlyingObjects
  (){}

    // getters
    Point getPoint() const {return point;}
    Velocity getVelocity() const { return velocity; }
    bool isAlive() const { return alive;}

    // setters
    void setPoint(const Point & point) {this->point = point;}
    void setVelocity(const Velocity & velocity) {this->velocity = velocity;}

    void kill(){alive=false;}
    
    void advance();
    virtual void draw() = 0;

  
};

#endif // FLYINGOBJECTS_H