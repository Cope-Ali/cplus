/***********************************************************************
 * Header File:
 *    Lander:
 * Author:
 *    Ali Cope
 * Summary:
 *    Contains definition of lander class.
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"


#define DEFAULT_FUEL 500

/*********************************************
 * Lander
 *   
 *********************************************/
class Lander
{
  public:
    // constructors
    Lander(): point(0,0), alive(true), landed(false), fuel(DEFAULT_FUEL), thrust(0), gravity(0.0){} 

    // getters
    Point getPoint() const { return point; }
    Velocity getVelocity() const { return velocity; }
    bool isAlive() const { return alive; }
    bool isLanded() const { return landed; }
    int getFuel() const { return fuel; }
    bool canThrust() const { return thrust; }

    // setters
    void setLanded(bool landed) {this->landed = landed;}
    void setAlive(bool alive) {this ->alive = alive;}
    void setFuel(int fuel) {this->fuel = fuel;}

    void applyGravity(float gravity);
    void applyThrustLeft();
    void applyThrustRight();
    void applyThrustBottom();
    void advance();

    bool canThrust();
    void draw() const;

  private:
    Point point;       //location of lander
    Velocity velocity; //velocity of lander
    int fuel;          // number of fuel remaining
    bool alive;        //if lander is still alive
    bool landed;       //if lander has landed
    bool thrust;       //if lander can thrust
    float gravity;     // keeps lander movin downward
};

#endif // LANDER_H
