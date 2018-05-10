#pragma once

#include "flyingObject.h"
#include <cmath>
#include "rifle.h"
const double pi = 3.1415926535897;


#define BULLET_SPEED 10.0

class Bullet : public FlyingObject
{
public:
	Bullet();

	void draw() { drawDot(getPoint()); }
	void fire(Point point, float angle );
};