#include "bullet.h"

// Put your bullet methods here

void Bullet::fire(Point point, float angle, Velocity velocity)
{
	_location.setX(point.getX());
	_location.setY(point.getY());
	_velocity.setDx((5 * (cos((PI / 180.0) * (angle + 90)))) + velocity.getDx());
	_velocity.setDy((5 * (sin((PI / 180.0) * (angle + 90.0)))) + velocity.getDy());
}

void Bullet::advance()
{
		if (getLife() > 0)
			drainLife();
		else
			kill();
		if (isAlive())
		{
			// this bullet is alive, so tell it to move forward
			FlyingObject::advance();
		}
}
