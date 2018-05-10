#pragma once

#include "bird.h"

class StandardBird : public Bird
{
public:
	StandardBird(int levelSpeed) : Bird(levelSpeed) {}
	virtual void draw() { drawCircle(getPoint(), 15); }
	virtual int hit();
};