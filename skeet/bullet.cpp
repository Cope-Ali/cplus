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
void Bullet::fire(const Point &point, float angle)
{
  this->point = point;

  velocity.setDx(BULLET_SPEED * (-cos(M_PI / 180 * angle)));
  velocity.setDy(BULLET_SPEED * (sin(M_PI / 180 * angle)));

  alive = true;
}

void Bullet::draw()
{
  if (alive)
  {
    drawDot(point);
  }
}