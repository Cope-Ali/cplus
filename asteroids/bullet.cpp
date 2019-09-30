/************************************************************
 * Source File:
 *    BULLET:
 * Author:
 *    Ali Cope
 * Description: Contains the implementations of the
 *  method bodies for the bullet class.
 ************************************************************************/

#include "bullet.h"
#include "uiDraw.h"

/*************************************
 *  BULLET: FIRE
 * fire bullet across screen
 * **********************************/
void Bullet::fire(const Point &point, float angle, Velocity shipVelocity)
{
  this->point = point;
  //double angleFire = 90.0-angle;

// this method makes the bullets fire in one of three directions
  velocity.setDx(shipVelocity.getDx() + (BULLET_SPEED * (-cos(M_PI / 180.0 * (90.0-angle)))));
  velocity.setDy(shipVelocity.getDy() + (BULLET_SPEED * (sin(M_PI / 180.0 * (90.0-angle)))));
  
  alive = true;
}

void Bullet::draw()
{
  if (alive && frameCount < 40)
  {
    if (point.getY() < -200) 
            point.setY(200);

        if(point.getY() > 200)
            point.setY(-200);

         if (point.getX() < -200) 
            point.setX(200);

        if(point.getX() > 200)
            point.setX(-200);
            
    drawDot(point);
    frameCount++;
  }
}