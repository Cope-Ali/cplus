#include "ship.h"

// Put your ship methods here


void Ship::draw()
{
    if (alive)
    {
        if (point.getY() < -200) 
            point.setY(200);

        if(point.getY() > 200)
            point.setY(-200);

         if (point.getX() < -200) 
            point.setX(200);
 
        if(point.getX() > 200)
            point.setX(-200);

        drawShip(point, angle, true);
    }
}

int Ship::hit()
{
    kill();
    return 0;
}

void Ship::rotateLeft()
{
    setAngle(getAngle()-ROTATE_AMOUNT);
}
void Ship::rotateRight()
{
    setAngle(getAngle()+ROTATE_AMOUNT);
}

void Ship::applyThrustUp()
{    

  velocity.setDx(velocity.getDx()+ THRUST_AMOUNT * (cos(M_PI / 180 * (angle + 90))));
  velocity.setDy(velocity.getDy()+ THRUST_AMOUNT * (sin(M_PI / 180 * (angle+90))));
}

void Ship::applyThrustDown()
{    

  velocity.setDx(velocity.getDx() - THRUST_AMOUNT * (cos(M_PI / 180 * (angle + 90))));
  velocity.setDy(velocity.getDy() - THRUST_AMOUNT * (sin(M_PI / 180 * (angle+90))));
}