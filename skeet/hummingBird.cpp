#include "hummingBird.h"

HummingBird::HummingBird(int levelSpeed) : Bird(levelSpeed)
{

	_velocity.setDx(levelSpeed + random(2, 5));
	if (_location.getY() > 0)
		_velocity.setDy(-levelSpeed - random(5, 15));
	else if (_location.getY() < 0)
		_velocity.setDy(levelSpeed + random(5, 15));
	else
		_velocity.setDy(0);

}

int HummingBird::hit()
{
	kill();
	return 15;
}
