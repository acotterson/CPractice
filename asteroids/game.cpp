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
using namespace std;


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(FlyingObject &obj1, FlyingObject &obj2) const
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
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

Game::Game(Point topLeft, Point bottomRight, int diff)
{
	_topLeft = topLeft;
	_bottomRight = bottomRight;
	if (diff == 5)
		createInitialRocks(25);
	else if (diff == 4)
		createInitialRocks(20);
	else if (diff == 3)
		createInitialRocks(15);
	else if (diff == 2)
		createInitialRocks(10);
	else
		createInitialRocks(5);
}

void Game::createInitialRocks(int count)
{
	for (int i = 0; i < count; i++)
	{
		Point startingPoint;
		startingPoint.setX(random(_topLeft.getX(), _bottomRight.getX()));
		startingPoint.setY(random(_bottomRight.getY(), _topLeft.getY()));

		Velocity startingVelocity;
		startingVelocity.setDx(random(-1.0, 1.0));
		startingVelocity.setDy(random(-1.0, 1.0));

		Rock* theRock = new BigRock(startingPoint, startingVelocity);

		_rocks.push_back(theRock);
	}
}

void Game::advance()
{
	for (int j = 0; j < _bullets.size(); j++)
	{
			_bullets[j].advance();
	}

	_ship.advance();
	for (int i = 0; i < _rocks.size(); i++)
	{
		if (getClosestDistance(*_rocks[i], _ship) < _rocks[i]->getSize() || getClosestDistance(*_rocks[i], _ship) < _ship.getSize())
		{
			_rocks[i]->kill();
			_ship.kill();
		}
		for (int j = 0; j < _bullets.size(); j++)
			if (getClosestDistance(*_rocks[i], _bullets[j]) < _rocks[i]->getSize())
			{

				if (_rocks[i]->getSize() == 16)
				{
					Rock* theRock = new MediumRock(_rocks[i]->getPoint(), _rocks[i]->getVelocity(), 1);

					_rocks.push_back(theRock);

					Rock* theRock1 = new MediumRock(_rocks[i]->getPoint(), _rocks[i]->getVelocity(), -1);

					_rocks.push_back(theRock1);

					Rock* theRock2 = new SmallRock(_rocks[i]->getPoint(), _rocks[i]->getVelocity(), 2);

					_rocks.push_back(theRock2);

					_rocks[i]->kill();
				}

				else if (_rocks[i]->getSize() == 8)
				{
					Rock* theRock = new SmallRock(_rocks[i]->getPoint(), _rocks[i]->getVelocity(), 3);

					_rocks.push_back(theRock);

					Rock* theRock1 = new SmallRock(_rocks[i]->getPoint(), _rocks[i]->getVelocity(), -3);

					_rocks.push_back(theRock1);

					_rocks[i]->kill();
				}

				else
					_rocks[i]->kill();

				_bullets[j].kill();
			}
		if (_rocks[i]->isAlive() == true)
			_rocks[i]->advance();
	}

	if (!_ship.isAlive())
		gameEnd();
	cleanUpZombies();
}

void Game::handleInput(const Interface & ui)
{
	if (ui.isLeft())
	{
		_ship.turnLeft();
	}

	if (ui.isRight())
	{
		_ship.turnRight();
	}

	if (ui.isUp())
	{
		_ship.thrust();
	}

	// Check for "Spacebar
	if (ui.isSpace() && _ship.isAlive())
	{
		Bullet newBullet;
		newBullet.fire(_ship.getPoint(), _ship.getAngle(), _ship.getVelocity());

		_bullets.push_back(newBullet);
	}
}

void Game::cleanUpZombies()
{
	// cerr << "zombiesStart" << endl;
	// check for dead bird
/*	if (_ship != NULL && !_ship->isAlive())
	{
		// the bird is dead, but the memory is not freed up yet

		// TODO: Clean up the memory used by the bird
		delete _ship;
		_ship = NULL;
	}*/

	vector<Rock*>::iterator rockIt = _rocks.begin();
	while (rockIt != _rocks.end())
	{
		Rock* pRock = *rockIt;
		// Asteroids Hint:
		// If we had a list of pointers, we would need this line instead:
		//Bullet* pBullet = *bulletIt;

		if (!pRock->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete[] pRock;
			pRock = NULL;

			// remove from list and advance
			rockIt = _rocks.erase(rockIt);
		}
		else
		{
			rockIt++; // advance
		}
	}
	// Look for dead bullets
	vector<Bullet>::iterator bulletIt = _bullets.begin();
	while (bulletIt != _bullets.end())
	{
		Bullet bullet = *bulletIt;
		// Asteroids Hint:
		// If we had a list of pointers, we would need this line instead:
		//Bullet* pBullet = *bulletIt;

		if (!bullet.isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...


			// remove from list and advance
			bulletIt = _bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}
	// cerr << "zombiesEnd" << endl;
}

void Game::draw(const Interface & ui)
{
	if (_ship.screenCheck() == true && _ship.isAlive())
		_ship.draw();
	else if (!_ship.isAlive())
		drawText(Point(), "You have lost!");

	if (_ship.isAlive() && _rocks.size() == 0)
		drawText(Point(), "Congratulations! You have won!");

	for (int i = 0; i < _rocks.size(); i++)
		if (_rocks[i]->screenCheck() == true)
			_rocks[i]->draw();

	for (int i = 0; i < _bullets.size(); i++)
		if (_bullets[i].screenCheck() == true && _bullets[i].isAlive() == true)
			_bullets[i].draw();
}

void Game::gameEnd()
{
	for (int i = 0; i < _rocks.size(); i++)
		_rocks[i]->kill();
	for (int i = 0; i < _bullets.size(); i++)
		_bullets[i].kill();
	cleanUpZombies();
}
