#include "pch/pch.h"
#include "SlopeUp.h"

SlopeUp::SlopeUp()
{
	id = 2;
	symbol = '/';
	deletable = true;
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
