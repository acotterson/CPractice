#pragma once
#include "bird.h"

class HummingBird : public Bird
{
public:
	HummingBird(int levelSpeed);
	virtual void draw() { drawSacredBird(getPoint(), 4); }
	virtual int hit();
};