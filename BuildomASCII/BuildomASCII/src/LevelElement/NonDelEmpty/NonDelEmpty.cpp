#include "pch/pch.h"
#include "NonDelEmpty.h"
#include "Screen/Screen.h"

// Constructor
NonDelEmpty::NonDelEmpty(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = Screen::defaultTextColor;
	backgroundColor = WHITE;
	fallable = true;
}

// gets called when on block
void NonDelEmpty::steppedOn(Build *build)
{

}

// gets called when in Block
void NonDelEmpty::steppedIn(Build *build)
{
	
}

// Copys Element
NonDelEmpty* NonDelEmpty::clone()
{
	return (new NonDelEmpty(*this));
}

