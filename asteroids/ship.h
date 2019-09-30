#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObjects.h"
#include "uiDraw.h"
#include "velocity.h"
#include "point.h"

// Put your Ship class here
/************************************************
 * SHIP
 * **********************************************/
class Ship : public FlyingObjects //derived from Flying Objects Class
{
  public:
    //constructors
    Ship() {}
    Ship(const Point &point)
    {
        alive = true;
        Point randPoint;
        randPoint.setRandom();
        setPoint(randPoint);
        angle = 180.0;
        Velocity velocity(0,0);
        setVelocity(velocity);
    }
    virtual ~Ship() {}
    int hit();
    double angle;
    virtual void draw();
    void rotateLeft();
    void rotateRight();
    void applyThrustUp();
    void applyThrustDown();
    void setAngle(double angle) { this->angle = angle; }
    double getAngle(){return angle;}
};

#endif /* ship_h */
