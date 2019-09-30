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
#include <vector>



#define BULLET_SPEED 5.0

/*********************************************
 * BULLET
 *********************************************/
class Bullet : public FlyingObjects  //derived from Fly Class
{
private:
    float angle;
    int frameCount;

  public:
    // constructors
    Bullet () {
      alive = true;
      frameCount = 0;
      }
    virtual ~Bullet(){};
    void fire(const Point & point, float angle, Velocity velocity);
    virtual void draw();
    void setCount(int count){this->frameCount = count;}
    int getCount(){return frameCount;}
    std::vector <Bullet> bullets;

  };

#endif // BULLET_H