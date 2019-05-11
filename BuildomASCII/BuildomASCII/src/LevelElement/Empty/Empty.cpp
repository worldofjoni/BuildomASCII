#include "pch/pch.h"
#include "Empty.h"
#include "Screen/Screen.h"

// Constructor
Empty::Empty(bool deletable)
{
	id = 0;
	symbol = ' ';
	this->deletable = deletable;
	color = Screen::defaultTextColor;
}

// gets called when on block
bool Empty::steppedOn(Pos &pos)
{
	pos.y++;
	return false;
	//std::cout << "darauf" << std::endl;

}

// gets called when in Block
bool Empty::steppedIn(Pos &pos)
{
	return false;
	//std::cout << "darin" << std::endl;
}

// Copys Element
Empty* Empty::clone()
{
	return (new Empty(*this));
}

