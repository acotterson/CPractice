/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <limits>
#include <vector>
#include "uiInteract.h"
#include "uiDraw.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"

using namespace std;

class Game
{
	Point _bottomRight;
	Point _topLeft;
	vector <Rock*> _rocks;
	Ship _ship;
	vector<Bullet> _bullets;
public:
	float getClosestDistance(FlyingObject & obj1, FlyingObject & obj2) const;
	Game(Point topLeft, Point bottomRight, int diff);

	void createInitialRocks(int count);
	void advance();
	void handleInput(const Interface & ui);
	void cleanUpZombies();
	void draw(const Interface & ui);
	void gameEnd();
};

#endif /* GAME_H */
