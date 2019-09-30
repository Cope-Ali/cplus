/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"
#include "flyingObjects.h"

using namespace std;
#define OFF_SCREEN_BORDER_AMOUNT 5

Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
  Point newPoint;
  newPoint.setRandom();
  Ship ship();
  score = 0;
  while (rocks.size() < 5)
  {
    rocks.push_back(new BigRock());
  }
}

/*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
void Game::advance()
{
  advanceBullets();
  advanceRocks();
  advanceShip();

  handleCollisions();
  cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
  // Move each of the bullets forward if it is alive
  for (int i = 0; i < bullets.size(); i++)
  {
    if (bullets[i].isAlive())
    {
      // this bullet is alive, so tell it to move forward
      bullets[i].advance();

      if (!isOnScreen(bullets[i].getPoint()))
      {
        // the bullet has left the screen
        bullets[i].kill();
      }
    }
  }
}

void Game::advanceShip()
{
  //make sure ship is alive
  if (ship.isAlive())
  {
    //move ship
    ship.advance();
  }
}

void Game::advanceRocks()
{
  // Move each of the rocks forward if it is alive
  for (int i = 0; i < rocks.size(); i++)
  {
    rocks[i]->advance();
  }
}

/*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
void Game::handleInput(const Interface &ui)

{
  if (ui.isUp())
  {
    ship.applyThrustUp();
  }

  if (ui.isDown())
  {
    ship.applyThrustDown();
  }
  if (ui.isLeft())
  {
    ship.rotateLeft();
  }

  if (ui.isRight())
  {
    ship.rotateRight();
  }

  // Check for "Spacebar
  if (ui.isSpace())
  {
    Bullet newBullet;
    newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getVelocity());

    bullets.push_back(newBullet);
  }
}

/*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
void Game::draw(const Interface &ui)
{
if (ship.isAlive())
{
  //Rocks vector draw loop
  for (int i = 0; i < rocks.size(); i++)
  {
    if (rocks[i] != NULL && rocks[i]->isAlive())
    {
      rocks[i]->draw();
    }
  }

  // draw ship
  ship.draw();

  // draw bullets if they are alive
  for (int i = 0; i < bullets.size(); i++)
  {
    if (bullets[i].isAlive())
    {
      bullets[i].draw();
    }
  } 

   // Put the score on the screen
    Point scoreLocation;
    scoreLocation.setX(topLeft.getX() + 5);
    scoreLocation.setY(topLeft.getY() - 5);

    drawNumber(scoreLocation, score);
}
}
/*****************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 ****************************************************************/
bool Game::isOnScreen(const Point &point)
{
  return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/*****************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock and a bullet, 
 * or ship and rock?
 *****************************************************************/
void Game::handleCollisions()
{
  // now check for a hit (if it is close enough to any live bullets)
  for (int i = 0; i < bullets.size(); i++)
  {
    if (bullets[i].isAlive())
    {
      // this bullet is alive, see if its too close
      for (int r = 0; r < rocks.size(); r++)
      {
        if (rocks[r] != NULL && getClosestDistance(*rocks[r], bullets[i]) <= rocks[r]->getRadius())
        {
          score += bullets[i].getCount()*(20 - rocks[r]->getRadius());
          bullets[i].kill();

          //causes seg fault
          if (rocks[r]->getRadius() > 8)
          {
            //create first medium rock
            MediumRock *mRock1 = new MediumRock;
            //set to point of large rock
            mRock1->setPoint(rocks[r]->getPoint());
            //set velocity to one up
            Velocity m1Velocity;
            m1Velocity.setDx(rocks[r]->getVelocity().getDx());
            m1Velocity.setDy(rocks[r]->getVelocity().getDy() + 1);
            mRock1->setVelocity(m1Velocity);

            //create second rock
            MediumRock *mRock2 = new MediumRock;
            //set to point of large rock
            mRock2->setPoint(rocks[r]->getPoint());
            //set velocity to one down
            Velocity m2Velocity;
            m2Velocity.setDx(rocks[r]->getVelocity().getDx());
            m2Velocity.setDy(rocks[r]->getVelocity().getDy() - 1);
            mRock2->setVelocity(m2Velocity);

            //create small rock
            SmallRock *sRock1 = new SmallRock;
            //set small rock to point of large rock
            sRock1->setPoint(rocks[r]->getPoint());
            //set velocity to two to the right
            Velocity s1Velocity;
            s1Velocity.setDx(rocks[r]->getVelocity().getDx() + 2);
            s1Velocity.setDy(rocks[r]->getVelocity().getDy());
            sRock1->setVelocity(s1Velocity);

            //push rocks into vector
            rocks.push_back(mRock1);
            rocks.push_back(mRock2);
            rocks.push_back(sRock1);

            // destroy large rock
            rocks[r]->hit();
          }

          else if (rocks[r]->getRadius() > 4)
          {

            //create small rock
            SmallRock *sRock1 = new SmallRock;
            //set small rock to point of medium rock
            sRock1->setPoint(rocks[r]->getPoint());
            //set velocity to three to the right
            Velocity s1Velocity;
            s1Velocity.setDx(rocks[r]->getVelocity().getDx() + 3);
            s1Velocity.setDy(rocks[r]->getVelocity().getDy());
            sRock1->setVelocity(s1Velocity);

            //create small rock
            SmallRock *sRock2 = new SmallRock;
            //set small rock to point of medium rock
            sRock2->setPoint(rocks[r]->getPoint());
            //set velocity to three to the left
            Velocity s2Velocity;
            s2Velocity.setDx(rocks[r]->getVelocity().getDx() - 3);
            s2Velocity.setDy(rocks[r]->getVelocity().getDy());
            sRock2->setVelocity(s2Velocity);

            //push rocks into vector
            rocks.push_back(sRock1);
            rocks.push_back(sRock2);

            //destroy medium rock
            rocks[r]->hit();
          }

          else
          {
            //destroy small rock
            rocks[r]->hit();
          }
        }
        else
        {
          //accuracy counts! Loose points for missed shots
          if(bullets[i].getCount() > 39)
            score --;
        }
      }
    }
  }

  // loop through each asteroid check to see if it hit the ship
  for (int r = 0; r < rocks.size(); r++)
  {
    if (getClosestDistance(*rocks[r], ship) <= rocks[r]->getRadius())
    {
      ship.kill();
    }
  }
}

/**************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, take rocks out of the list)
 ****************************************************************/
void Game::cleanUpZombies()
{

  //clean up bullets that are dead or have exsisted for more than 40 frames//

  vector<Bullet>::iterator bulletIt = bullets.begin();
  while (bulletIt != bullets.end())
  {
    Bullet bullet = *bulletIt;
    if (!bullet.isAlive() || bullet.getCount() >= 40)
    {
      bulletIt = bullets.erase(bulletIt);
    }
    else
    {
      bulletIt++;
    }
  }

  // clean up dead asteroids
  vector<Rock *>::iterator rockIt = rocks.begin();
  while (rockIt != rocks.end())
  {
    Rock *pRock = *rockIt;
    if (!pRock->isAlive())
    {
      rockIt = rocks.erase(rockIt);
    }
    else
    {
      *rockIt++;
    }
  }
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game::getClosestDistance(const FlyingObjects &obj1, const FlyingObjects &obj2) const
{
  // find the maximum distance traveled
  float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
  dMax = max(dMax, abs(obj2.getVelocity().getDx()));
  dMax = max(dMax, abs(obj2.getVelocity().getDy()));
  dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

  float distMin = std::numeric_limits<float>::max();
  for (float i = 0.0; i <= dMax; i++)
  {
    Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                 obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
    Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                 obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

    float xDiff = point1.getX() - point2.getX();
    float yDiff = point1.getY() - point2.getY();

    float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

    distMin = min(distMin, distSquared);
  }

  return sqrt(distMin);
}
