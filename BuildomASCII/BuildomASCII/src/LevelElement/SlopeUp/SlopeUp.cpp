#include "pch/pch.h"
#include "SlopeUp.h"

SlopeUp::SlopeUp(bool deletable)
{
	id = 2;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = BLACK;
	fallable = false;
}



void SlopeUp::steppedOn(Build* build)
{
	
}

void SlopeUp::steppedIn(Build* build)
{
	if (build->playerDirection == RIGHT)
		build->movePlayer(0, -1);
	//else { build->playerGameOver = true; }
	
}

SlopeUp* SlopeUp::clone()
{
	return (new SlopeUp(*this));
}
