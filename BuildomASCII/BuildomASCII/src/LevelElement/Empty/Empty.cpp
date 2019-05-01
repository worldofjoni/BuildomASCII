#include "pch.h"
#include "Empty.h"

// Constructor
Empty::Empty()
{
	id = 0;
	symbol = ' ';
	deletable = true;
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

