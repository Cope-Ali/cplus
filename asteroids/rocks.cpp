#include "rocks.h"
#include "uiDraw.h"

// Put your Rock methods here

//BIG_ROCK
BigRock::BigRock()
{
    alive = true;
    //start at a random point
    point.setRandom();
    // get a random dx and dy for velocity
    float dx = cos(random(-1, 1) * (M_PI / 2));
    float dy = cos(random(-1, 1) * (M_PI / 2));
    // randomly change direction
    int num1 = random(1, 4);
    if (num1 = 2)
        dx *= -1;
    int num2 = random(1, 4);
    if (num2 = 2)
        dy *= -1;
    //set random velocity
    Velocity newVelocity;
    newVelocity.setDx(dx);
    newVelocity.setDy(dy);
    setVelocity(newVelocity);
    setRadius(BIG_ROCK_SIZE);
}

void BigRock::draw()
{
    if(alive)
    {
    if (point.getY() < -200)
        point.setY(200);

    if (point.getY() > 200)
        point.setY(-200);

    if (point.getX() < -200)
        point.setX(200);

    if (point.getX() > 200)
        point.setX(-200);

    setSpin(getSpin() + BIG_ROCK_SPIN);
    drawLargeAsteroid(point, spin);
    }
}

int BigRock::hit()
{
   

   kill();
    return 0;
}

MediumRock::MediumRock()
{
    alive = true;
    setRadius(MEDIUM_ROCK_SIZE);
}

void MediumRock::draw()
{
    if (alive)
    {
        if (point.getY() < -200)
            point.setY(200);

        if (point.getY() > 200)
            point.setY(-200);

        if (point.getX() < -200)
            point.setX(200);

        if (point.getX() > 200)
            point.setX(-200);

        setSpin(getSpin() + MEDIUM_ROCK_SPIN);

        drawMediumAsteroid(point, spin);
    }
}

int MediumRock::hit()
{
    
    kill();
    return 0;
}

//SMALL ROCK
SmallRock::SmallRock()
{
    alive=true;
    setRadius(SMALL_ROCK_SIZE);
}

void SmallRock::draw()
{
    if (alive)
    {
        setSpin(getSpin() + SMALL_ROCK_SPIN);
        drawSmallAsteroid(point, spin);
    }
}

int SmallRock::hit()
{
    kill();
    return 0;
}