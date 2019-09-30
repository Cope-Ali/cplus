/************************************************************
 * Source File:
 *    BIRD:
 * Author:
 *    Ali Cope
 * Description: Contains the implementations of the
 *  method bodies for the bird class.
 ************************************************************************/

#include "bird.h"
#include "uiDraw.h"

#include <iostream>

NormalBird::NormalBird(const Point &point) : Bird(point)
{
    float dx = random(3, 6);
    float dy = random(1, 4);

    if (point.getY() > 0)
    {
        dy *= -1;
    }
    Velocity newVelocity;
    newVelocity.setDx(dx);
    newVelocity.setDy(dy);

    setVelocity(newVelocity);
}

void NormalBird::draw()
{
    if (alive)
    {
        drawCircle(point, BIRD_RADIUS);
    }
}

int NormalBird::hit()
{
    kill();
    return POINTS_NORMAL_BIRD;
}

SacredBird::SacredBird(const Point &point) : Bird(point)
{
    float dx = random(3, 6);
    float dy = random(1, 4);

    if (point.getY() > 0)
    {
        dy *= -1;
    }
    Velocity newVelocity;
    newVelocity.setDx(dx);
    newVelocity.setDy(dy);

    setVelocity(newVelocity);
}

void SacredBird::draw()
{
    if (alive)
    {
        drawSacredBird(point, BIRD_RADIUS);
    }
}

int SacredBird::hit()
{
    kill();
    return POINTS_SACRED_BIRD;
}

ToughBird::ToughBird(const Point &point) : Bird(point)
{
    float dx = random(2, 4);
    float dy = random(1, 3);
    hits = 3;

    if (point.getY() > 0)
    {
        dy *= -1;
    }
    Velocity newVelocity;
    newVelocity.setDx(dx);
    newVelocity.setDy(dy);

    setVelocity(newVelocity);
}

void ToughBird::draw()
{
    if (alive)
    {
        drawToughBird(point, BIRD_RADIUS, getHits());
    }
}

int ToughBird::hit()
{
    int hits = getHits();
    if (hits > 0)
    {
        setHits(hits -=1);
        alive = true;
        return POINTS_TOUGH_BIRD_HIT;
    }
    else
    {
        kill();
        return POINTS_TOUGH_BIRD_KILL;
    }
}


void ToughBird::setHits(int hits)
{
this->hits = hits;
}

SpecialBird::SpecialBird(const Point &point) : Bird(point)
{
    float dx = random(2, 6);
    float dy = random(1, 3);
    hits = 5;

    if (point.getY() > 0)
    {
        dy *= -1;
    }
    Velocity newVelocity;
    newVelocity.setDx(dx);
    newVelocity.setDy(dy);

    setVelocity(newVelocity);
}

void SpecialBird::draw()
{
    if (alive)
    {
        drawRect(point, 10, 5, random(30,150));
    }
}

int SpecialBird::hit()
{
    int hits = getHits();
    if (hits > 0)
    {
        setHits(hits -=1);
        return POINTS_SPECIAL_BIRD_HIT;
    }
    else
    {
        kill();
        return POINTS_SPECIAL_BIRD_KILL;
    }
}
void SpecialBird::setHits(int hits)
{
this->hits = hits;
}