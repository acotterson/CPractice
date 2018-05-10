/***********************************************************************
* Header File:
*    Velocity : Things related to the velocity of the lander
* Author:
*    Alec Otterson
* Summary:
*    Everything we need to know about the velocity of the lander.
************************************************************************/

#pragma once

#include <iostream>

class Velocity
{
private:
	float _dx;
	float _dy;
public:
	Velocity();
	Velocity(float dx, float dy);

	float getDx() const;
	float getDy() const;
	
	void setDx(float dx);
	void setDy(float dy);
};

