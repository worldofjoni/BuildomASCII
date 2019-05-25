#include "pch/pch.h"
#include "Empty.h"
#include "Screen/Screen.h"

// Constructor
Empty::Empty(bool deletable)
{
	id = 0;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = Screen::defaultTextColor;
	fallable = true;
}

// gets called when on block
void Empty::steppedOn(Build *build)
{
	//build->currentPos.y += 2;
	////std::cout << "darauf" << std::endl;

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

