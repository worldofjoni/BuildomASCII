#include "pch/pch.h"
#include "Solid.h"

// Constructor
Solid::Solid(bool deletable)
{
	id = 1;
	symbol = 219;
	this->deletable = deletable;
	color = BLACK;
}

// gets called when on block
bool Solid::steppedOn(Pos &pos)
{
	return false;

}



// gets Called when in Block
bool Solid::steppedIn(Pos &pos)
{
	return true;
}


// Copys element
Solid* Solid::clone()
{
	return (new Solid(*this));
}

