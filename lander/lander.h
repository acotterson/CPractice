/***********************************************************************
* Header File:
*    Lander : Things related to the state of the lander
* Author:
*    Alec Otterson
* Summary:
*    Everything we need to know about the lander.
************************************************************************/

#pragma once

#include <iostream>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "ground.h"

class Lander
{
private:
	int _fuel;
	Velocity _velocity;
	Point _location;
	bool _alive;
	bool _landed;
public:
	Lander();

	Point getPoint() const;
	Velocity getVelocity() const;

	bool isAlive();
	bool isLanded();
	int getFuel();
	bool canThrust();


	void setLanded(bool);
	void setAlive(bool);
	void setFuel(int);

	void applyGravity(float);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();

	void advance();
	void draw();
};