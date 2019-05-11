#include "pch/pch.h"
#include "SlopeUp.h"

SlopeUp::SlopeUp(bool deletable)
{
	id = 2;
	symbol = '/';
	this->deletable = deletable;
	color = BLACK;
}



bool SlopeUp::steppedOn(Pos &pos)
{
	return false;
}

bool SlopeUp::steppedIn(Pos &pos)
{
	pos.y--;
	return false;
}

SlopeUp* SlopeUp::clone()
{
	return (new SlopeUp(*this));
}
