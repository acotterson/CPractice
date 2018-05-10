#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "velocity.h"
#include "point.h"

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock
class Rock : public FlyingObject
{
protected:
	int _spinSpeed;
	int _angle;
	int _size;
public:
	void advance();
	int getSize() { return _size; }
	virtual void draw() {}
};

class BigRock : public Rock
{
public:
	BigRock(Point startPosition, Velocity startVelocity);
	void draw();
};

class MediumRock : public Rock
{
public:
	MediumRock(Point position, Velocity velocity, int y);
	void draw();
};

class SmallRock : public Rock
{
public:
	SmallRock(Point position, Velocity velocity, int x);
	void draw();
};
#endif /* rocks_h */
