#include "pch/pch.h"
#include "SlopeDown.h"

SlopeDown::SlopeDown(bool deletable)
{
	id = 3;
	symbol = '\\';
	this->deletable = deletable;
	color = BLACK;
}


void SlopeDown::steppedOn()
{
}

void SlopeDown::steppedIn()
{
}

SlopeDown* SlopeDown::clone()
{
	return (new SlopeDown(*this));
}
