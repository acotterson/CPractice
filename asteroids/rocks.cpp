#include "rocks.h"

// Put your Rock methods here

BigRock::BigRock(Point startPosition, Velocity startVelocity)
{
	_location = startPosition;
	_velocity = startVelocity;
	_angle = random(0, 360);
	_spinSpeed = BIG_ROCK_SPIN;
	_size = BIG_ROCK_SIZE;
}

void BigRock::draw()
{
	drawLargeAsteroid(_location, _angle);

}

void Rock::advance()
{
	FlyingObject::advance();
	_angle += _spinSpeed;

	if (_angle > 360)
		_angle -= 360;
}

MediumRock::MediumRock(Point position, Velocity velocity, int y)
{
	_location = position;
	_velocity.setDx(velocity.getDx());
	_velocity.setDy(velocity.getDy() + y);
	_angle = random(0, 360);
	_spinSpeed = MEDIUM_ROCK_SPIN;
	_size = MEDIUM_ROCK_SIZE;
}

void MediumRock::draw()
{
	drawMediumAsteroid(_location, _angle);
}

SmallRock::SmallRock(Point position, Velocity velocity, int x)
{
	_location = position;
	_velocity.setDx(velocity.getDx() + x);
	_velocity.setDy(velocity.getDy());
	_angle = random(0, 360);
	_spinSpeed = SMALL_ROCK_SPIN;
	_size = SMALL_ROCK_SIZE;
}

void SmallRock::draw()
{
	drawSmallAsteroid(_location, _angle);
}
