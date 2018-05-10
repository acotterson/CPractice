#include "velocity.h"

Velocity::Velocity() : _dx(0.0f), _dy(0.0f)
{

}

Velocity::Velocity(float dx, float dy) : _dx(dx), _dy(dy)
{
}

float Velocity::getDx() const
{
	return _dx;
}

float Velocity::getDy() const
{
	return _dy;
}

void Velocity::setDx(float dx)
{
	_dx = dx;
}

void Velocity::setDy(float dy)
{
	_dy = dy;
}
