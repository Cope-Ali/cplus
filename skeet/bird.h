/***********************************************************************
 * Header File:
 *    BIRD: Dirivitive of FLY class
 * Author:
 *    Ali Cope
 * Summary:
 *    Definition of Bird Class
 ************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#define BIRD_RADIUS 15
#define BIRD_X_SPEED_MIN 3.0
#define BIRD_X_SPEED_MAX 6.0
#define BIRD_Y_SPEED_MIN 0.0
#define BIRD_Y_SPEED_MAX 4.0

#define POINTS_NORMAL_BIRD 1
#define POINTS_SACRED_BIRD -10
#define POINTS_TOUGH_BIRD_HIT 1
#define POINTS_TOUGH_BIRD_KILL 3
#define POINTS_SPECIAL_BIRD_HIT 2
#define POINTS_SPECIAL_BIRD_KILL 3

#include "flyingObjects.h"

/*********************************************
 * BIRD
 *********************************************/
class Bird : public FlyingObjects  //derived from FlyingObjects Class
{

  public:
    // constructors

    Bird(const Point & point) { 
      alive = true;
      setPoint(point);
      }  
    virtual ~Bird(){};
    // setter
    
    virtual int hit() = 0;
    virtual void draw()=0;

  private:
    int score;
};

class NormalBird : public Bird
{
  public:
  NormalBird(const Point & point);
  virtual void draw();
  virtual int hit();
};

class SacredBird : public Bird
{
  public:
  SacredBird(const Point & point);
  virtual void draw();
  virtual int hit();
};

class ToughBird : public Bird
{
  private:
  int hits;

  public:
  ToughBird(const Point & point);
  virtual void draw();
  virtual int hit();
  int getHits() const {return hits;}
  void setHits(int hits);

};

class SpecialBird : public Bird
{
  private:
  int hits;

  public:
  SpecialBird(const Point & point);
  virtual void draw();
  virtual int hit();
  int getHits() const {return hits;}
  void setHits(int hits);
};


#endif // BIRD_H