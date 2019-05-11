#include "pch/pch.h"
#include "SlopeDown.h"

SlopeDown::SlopeDown(bool deletable)
{
	id = 3;
	symbol = '\\';
	this->deletable = deletable;
	color = BLACK;
}


bool SlopeDown::steppedOn(Pos &pos)
{
	return false;
}

bool SlopeDown::steppedIn(Pos &pos)
{
	return true;
}

SlopeDown* SlopeDown::clone()
{
	return (new SlopeDown(*this));
}
