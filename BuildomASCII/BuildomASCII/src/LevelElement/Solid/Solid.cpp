#include "pch/pch.h"
#include "Solid.h"

// Constructor
Solid::Solid(bool deletable)
{
	id = 1;
	symbol = ownSym;
	this->deletable = deletable;
	color = BLACK;
	fallable = false;
}

// gets called when on block
void Solid::steppedOn(Build* build)
{
	

}



// gets Called when in Block
void Solid::steppedIn(Build* build)
{
	build->playerGameOver = true;
	
}


// Copys element
Solid* Solid::clone()
{
	return (new Solid(*this));
}

