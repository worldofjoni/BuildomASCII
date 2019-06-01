// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Star.h"
#include "Screen/Build/Build.h"

Star::Star(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = YELLOW;
	fallable = true;
	canBePlacedByUser = false;

}



void Star::steppedOn(Build* build)
{
	
}

void Star::steppedIn(Build* build)
{
	
	if (this->symbol == ownSym)
	{
		build->starsCollected++;
		this->symbol = Empty::ownSym;
		fc::beep(NOTE_H, 50);
		build->displayPlayer();
	}
	
	
}

Star* Star::clone()
{
	return (new Star(*this));
}
