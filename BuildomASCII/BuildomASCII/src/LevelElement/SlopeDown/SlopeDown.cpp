#include "pch/pch.h"
#include "SlopeDown.h"

SlopeDown::SlopeDown(bool deletable)
{
	id = 3;
	symbol = '\\';
	this->deletable = deletable;
	color = BLACK;
}


void SlopeDown::steppedOn(Build *build)
{
	
}

void SlopeDown::steppedIn(Build* build)
{
	if (build->playerDirection == LEFT) { build->currentPos.y--; }
	else { build->playerGameOver = true; }
}

SlopeDown* SlopeDown::clone()
{
	return (new SlopeDown(*this));
}
