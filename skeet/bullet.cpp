#include "bullet.h"

Bullet::Bullet()
{

}

void Bullet::fire(Point point, float angle)
{
	_location.setX(point.getX());
	_location.setY(point.getY());
	_velocity.setDx(BULLET_SPEED * (-cos(pi / 180.0 * angle)));
	_velocity.setDy(BULLET_SPEED * (sin(pi / 180.0 * angle)));
}
