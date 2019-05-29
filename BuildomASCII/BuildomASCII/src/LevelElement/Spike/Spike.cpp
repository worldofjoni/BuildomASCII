// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Spike.h"

Spike::Spike(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = RED;
	fallable = false;
	canBePlacedByUser = false;
}



void Spike::steppedOn(Build* build)
{
	build->playerGameOver = true;
}

void Spike::steppedIn(Build* build)
{
	build->playerGameOver = true;

}

Spike* Spike::clone()
{
	return (new Spike(*this));
}
