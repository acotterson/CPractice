#include "bird.h"

Bird::Bird(int levelSpeed)
{
	_location.setX(-400.0f);
	_location.setY(random(-400.0, 400.0));
	_velocity.setDx(levelSpeed + random(3, 7));
	if (_location.getY() > 0)
		_velocity.setDy(levelSpeed + random(-5, -1));
	else if (_location.getY() < 0)
		_velocity.setDy(levelSpeed + random(1, 5));
	else
		_velocity.setDy(0);
}

int Bird::hit()
{
	return 0;
}
