#include "lander.h"
#include "ground.h"

Lander::Lander() : _fuel(500), _alive(1), _landed(0)
{
}

Point Lander::getPoint() const
{
	return _location;
}

Velocity Lander::getVelocity() const
{
	return _velocity;
}

bool Lander::isAlive()
{
	return _alive;
}

bool Lander::isLanded()
{
	return _landed;
}

int Lander::getFuel()
{
	return _fuel;
}

bool Lander::canThrust()
{
	if (_fuel > 0)
		return true;
	else
		return false;
}

void Lander::setLanded(bool landed)
{
	_landed = landed;
}

void Lander::setAlive(bool alive)
{
	_alive = alive;
}

void Lander::setFuel(int fuel)
{
	_fuel = fuel;
}

void Lander::applyGravity(float gravity)
{
	if (gravity > 0.0)
		_velocity.setDy(_velocity.getDy() - gravity);
	else if (gravity == 0.0 && _velocity.getDy() < 0.0)
		_velocity.setDy(0.0);
}

void Lander::applyThrustLeft()
{
	if (_fuel >= 1) 
	{
		_velocity.setDx( _velocity.getDx() + 0.1);
		setFuel(getFuel() - 1);
	}
}

void Lander::applyThrustRight()
{
	if (_fuel >= 1) 
	{
		_velocity.setDx(_velocity.getDx() - 0.1);
		setFuel(getFuel() - 1);
	}
}

void Lander::applyThrustBottom()
{
	if (_fuel >= 3) 
	{
			_velocity.setDy( _velocity.getDy() + 0.3);
			setFuel(getFuel() - 3);		
	}
}

void Lander::advance()
{
	_location.setX( _location.getX() + _velocity.getDx());
	_location.setY( _location.getY() + _velocity.getDy());
}

void Lander::draw()
{
	drawLander(_location);
}