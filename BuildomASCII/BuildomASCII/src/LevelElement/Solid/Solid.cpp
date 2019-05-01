#include "pch.h"
#include "Solid.h"

// Constructor
Solid::Solid()
{
	id = 1;
	symbol = 219;
	deletable = false;
}

// gets called when on block
void Solid::steppedOn()
{
	std::cout << "darauf" << std::endl;

}

// gets Called when in Block
void Solid::steppedIn()
{
	std::cout << "darin" << std::endl;
}


// Copys element
Solid* Solid::clone()
{
	return (new Solid(*this));
}

