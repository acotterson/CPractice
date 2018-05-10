#include "flyingObject.h"
#include <iostream>
using namespace std;

void FlyingObject::advance()
{
   // cerr << "in advance" << endl;
   _location.setX(_location.getX() + _velocity.getDx());
    _location.setY(_location.getY() + _velocity.getDy());
    //   cerr << "ending advance" << endl;
}

void FlyingObject::kill()
{
	_alive = false;
}

bool FlyingObject::screenCheck()
{
	if (_location.getX() < 225 && _location.getX() > -225 && _location.getY() < 225 && _location.getY() > -225)
		return true;
	else
		return false;
}
