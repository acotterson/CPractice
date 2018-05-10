#pragma once

#include "bird.h"

class ToughBird : public Bird
{
private:
	int _hits;
public:
	ToughBird(int levelSpeed);
	virtual void draw() { drawToughBird(getPoint(), 15, 3 - _hits); }
	virtual int hit();
};