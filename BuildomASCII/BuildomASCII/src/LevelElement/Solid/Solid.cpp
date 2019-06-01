// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Solid.h"
#include "Screen/Build/Build.h"


// Constructor
Solid::Solid(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = ownColor;
	fallable = false;
}

// gets called when on Block
void Solid::steppedOn(Build* build)
{
}

// gets Called when in Block
void Solid::steppedIn(Build* build)
{
	if (!build->level.at(build->previousPos.below())->fallable) build->playerGameOver = true;
	else build->currentPos = build->previousPos;
	
}

// Copys element
Solid* Solid::clone()
{
	return (new Solid(*this));
}
