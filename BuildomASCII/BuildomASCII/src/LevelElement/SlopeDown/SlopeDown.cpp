#include "pch/pch.h"
#include "SlopeDown.h"

SlopeDown::SlopeDown()
{
	id = 3;
	symbol = '\\';
	deletable = true;
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
