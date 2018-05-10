#pragma once

#include "bird.h"

class SacredBird : public Bird
{
public:
	SacredBird(int levelSpeed) : Bird(levelSpeed) {}
	virtual void draw() { drawSacredBird(getPoint(), 15); }
	virtual int hit();
};