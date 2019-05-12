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

