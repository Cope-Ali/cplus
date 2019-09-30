/***********************************************************************
 * Header File:
 *    BULLET: Dirivitive of FLY class
 * Author:
 *    Ali Cope
 * Summary:
 *    Definition of Bullet Class
 ************************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "flyingObjects.h"



#define BULLET_SPEED 10.0

/*********************************************
 * BULLET
 *********************************************/
class Bullet : public FlyingObjects  //derived from Fly Class
{
private:
    float angle;

  public:
    // constructors
    Bullet () {
      alive = true;
      }
    virtual ~Bullet(){};
    void fire(const Point & point, float angle);
    virtual void draw();
  };

#endif // BULLET_H