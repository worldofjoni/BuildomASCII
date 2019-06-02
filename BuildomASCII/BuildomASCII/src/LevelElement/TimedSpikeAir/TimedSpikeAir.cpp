// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "TimedSpikeAir.h"
#include "Screen/Build/Build.h"


TimedSpikeAir::TimedSpikeAir(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = RED;
	fallable = false;
	canBePlacedByUser = false;
}

void TimedSpikeAir::steppedOn(Build* build)
{
	if (build->spikey2) 
		build->playerGameOver = true;
}

void TimedSpikeAir::steppedIn(Build* build)
{
	if (!fallable) 
		build->playerGameOver = true;
}

TimedSpikeAir* TimedSpikeAir::clone()
{
	return (new TimedSpikeAir(*this));
}
