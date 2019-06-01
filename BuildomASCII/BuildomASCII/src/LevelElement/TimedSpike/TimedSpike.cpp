// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "TimedSpike.h"
#include "Screen/Build/Build.h"

TimedSpike::TimedSpike(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = RED;
	fallable = false;
	canBePlacedByUser = false;
	backgroundColor = Solid::ownColor;

}



void TimedSpike::steppedOn(Build* build)
{
	if (build->spikey)
	{
		build->playerGameOver = true;
	}
}

void TimedSpike::steppedIn(Build* build)
{
	build->playerGameOver = true;
	
}

TimedSpike* TimedSpike::clone()
{
	return (new TimedSpike(*this));
}
