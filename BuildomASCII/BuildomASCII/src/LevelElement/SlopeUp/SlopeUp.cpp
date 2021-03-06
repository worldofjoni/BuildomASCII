// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "SlopeUp.h"
#include "Screen/Build/Build.h"

SlopeUp::SlopeUp(bool deletable)
{
	id = ownId;
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
	
}

SlopeUp* SlopeUp::clone()
{
	return (new SlopeUp(*this));
}
