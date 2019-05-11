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
void Empty::steppedOn()
{
	//std::cout << "darauf" << std::endl;

}

// gets called when in Block
void Empty::steppedIn()
{
	//std::cout << "darin" << std::endl;
}

// Copys Element
Empty* Empty::clone()
{
	return (new Empty(*this));
}

