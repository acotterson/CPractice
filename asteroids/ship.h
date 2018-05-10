#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define PI 3.1415926535897

#include <cmath>
#include "flyingObject.h"


// Put your Ship class here
class Ship : public FlyingObject
{
private:
	int _angle;
	bool _thrust;
	int _size;
public:
	Ship();
	int getAngle() { return _angle; }
	int getSize() { return _size; }
	Velocity getVelocity() { return _velocity; }
	Point getPosition() { return _location; }

	void turnLeft();
	void turnRight();
	void thrust();
	void advance();
	void draw();
};

#endif /* ship_h */
