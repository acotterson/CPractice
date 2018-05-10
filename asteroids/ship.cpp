#include "ship.h"

// Put your ship methods here

Ship::Ship()
{
	_size = SHIP_SIZE;
	_location.setX(0.0);
	_location.setY(0.0);
	_velocity.setDx(0.0);
	_velocity.setDy(0.0);
}

void Ship::turnLeft()
{
	_angle += ROTATE_AMOUNT;
	if (_angle < 360)
		_angle += 360;
}

void Ship::turnRight()
{
	_angle -= ROTATE_AMOUNT;
	if (_angle > 360)
		_angle -= 360;
}

void Ship::thrust()
{
	_velocity.setDx((THRUST_AMOUNT * (cos((PI / 180.0) * (_angle + 90.0)))) + _velocity.getDx());
	_velocity.setDy((THRUST_AMOUNT * (sin((PI / 180.0) * (_angle + 90.0)))) +_velocity.getDy());
}

void Ship::advance()
{
	if (isAlive() == true)
		FlyingObject::advance();

}

void Ship::draw()
{
	drawShip(_location, _angle, _thrust);
}
