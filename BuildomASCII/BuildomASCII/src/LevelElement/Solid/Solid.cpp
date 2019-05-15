#include "pch/pch.h"
#include "Solid.h"

// Constructor
Solid::Solid(bool deletable)
{
	id = 1;
	symbol = 219;
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
	if (!build->level.map[build->previousPos.x][build->previousPos.y + 1]->fallable)
		build->playerGameOver = true;
	else
		build->currentPos = build->previousPos;
	
}


// Copys element
Solid* Solid::clone()
{
	return (new Solid(*this));
}

