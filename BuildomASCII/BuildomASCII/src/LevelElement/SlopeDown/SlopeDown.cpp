#include "pch/pch.h"
#include "SlopeDown.h"

SlopeDown::SlopeDown(bool deletable)
{
	id = 3;
	symbol = '\\';
	this->deletable = deletable;
	color = BLACK;
	fallable = false;
}


void SlopeDown::steppedOn(Build *build)
{
	
}

void SlopeDown::steppedIn(Build* build)
{
	if (build->playerDirection == LEFT)
		build->movePlayer(0, -1);
		
	//else { build->playerGameOver = true; }
}

SlopeDown* SlopeDown::clone()
{
	return (new SlopeDown(*this));
}
