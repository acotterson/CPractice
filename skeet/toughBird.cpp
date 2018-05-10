#include "toughBird.h"

ToughBird::ToughBird(int levelSpeed) : Bird(levelSpeed)
{
	_hits = 0;
	_velocity.setDx(levelSpeed + random(2, 5));
	if (_location.getY() > 0)
		_velocity.setDy(-levelSpeed - random(1, 3));
	else if (_location.getY() < 0)
		_velocity.setDy(levelSpeed + random(1, 3));
	else
		_velocity.setDy(0);
}

int ToughBird::hit()
{
	_hits++;
	if (_hits == 3)
	{
 		kill();
		return 3;		
	}
	else
		return 1;
}
