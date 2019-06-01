// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "ChangeDir.h"

ChangeDir::ChangeDir(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = YELLOW_LIGHT;
	fallable = true;
}



void ChangeDir::steppedOn(Build* build)
{

}

void ChangeDir::steppedIn(Build* build)
{
	build->playerDirection = (build->playerDirection == RIGHT) ? LEFT : RIGHT;
}

ChangeDir* ChangeDir::clone()
{
	return (new ChangeDir(*this));
}
