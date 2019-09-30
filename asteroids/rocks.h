#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObjects.h"
#include "point.h"
#include "uiDraw.h"
#include "velocity.h"
#include <vector>

// Define the following classes here:
/***************************************************
 * ROCK
 * ************************************************/
class Rock : public FlyingObjects // derived from Flying Objects Class
{
  public:
    //constructors
    Rock(){}
    Rock(const Point & point)
    {
        alive=true;
        this-> point = point;
    }
    virtual ~Rock(){};
    // setters
    virtual int hit() = 0;
    virtual void draw() = 0;
    void setRadius(int radius) {this->radius = radius;}
    int getRadius(){return radius;}
    int getSpin(){return spin;}
    void setSpin(int spin){this->spin = spin;}

    protected:
    std::vector <Rock *> rocks;
    int spin;
    int radius;
    
};

/************************************************
* BigRock
*************************************************/
class BigRock : public Rock
{
    public:
    BigRock();
    int hit ();
    void draw();
    
};

/************************************************
* MediumRock
*************************************************/
class MediumRock : public Rock
{
    public:
    MediumRock();
    MediumRock(const Point & point);
    virtual int hit ();
    virtual void draw();
};

/************************************************
* SmallRock
*************************************************/
class SmallRock : public Rock
{
    public:
    SmallRock();
    SmallRock(const Point & point);
    virtual int hit ();
    virtual void draw();
};


#endif /* rocks_h */
