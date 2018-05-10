#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40



// Put your Bullet class here
#include "flyingObject.h"
#include <cmath>
#include "ship.h"
#define PI 3.1415926535897

class Bullet : public FlyingObject
{
private:
	int _life;
public:
	Bullet() { _life = 40; }
	int getLife() { return _life; }
	void drainLife() { _life -= 1; }
	void draw() { drawDot(getPoint()); }
	void fire(Point point, float angle, Velocity velocity);
	void advance();
};



#endif /* bullet_h */
