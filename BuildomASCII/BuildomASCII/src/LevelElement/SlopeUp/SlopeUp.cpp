#include "pch/pch.h"
#include "SlopeUp.h"

SlopeUp::SlopeUp(bool deletable)
{
	id = 2;
	symbol = '/';
	this->deletable = deletable;
	color = BLACK;
}



void SlopeUp::steppedOn()
{
}

void SlopeUp::steppedIn()
{
}

SlopeUp* SlopeUp::clone()
{
	return (new SlopeUp(*this));
}
