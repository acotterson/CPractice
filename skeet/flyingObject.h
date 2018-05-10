#pragma once

#include <iostream>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "rifle.h"

class FlyingObject
{
protected:
	Point _location;
	Velocity _velocity;
	bool _alive;
public:
	FlyingObject()  { _alive = true; }
	Point getPoint() { return _location; }
	Velocity getVelocity() { return _velocity; }
	bool isAlive() { return _alive; }
	
	void setPoint(Point location) { _location = location; }
	void setVelocity(Velocity velocity) { _velocity = velocity; }
	void advance();
	void kill();
};

