// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Empty.h"
#include "Screen/Screen.h"

// Constructor
Empty::Empty(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = Screen::defaultTextColor;
	fallable = true;
	canBePlacedByUser = false;
}

// gets called when on Block
void Empty::steppedOn(Build *build)
{
}

// gets called when in Block
void Empty::steppedIn(Build *build)
{
}

// Copys Element
Empty* Empty::clone()
{
	return (new Empty(*this));
}
