#pragma once

#include "flyingObject.h"

class Bird : public FlyingObject
{
public:
	Bird() {}
	Bird(int);
	 virtual void draw() = 0;
	 virtual int hit() = 0;
};
