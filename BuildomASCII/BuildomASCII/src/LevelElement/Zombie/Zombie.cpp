// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Zombie.h"

Zombie::Zombie(bool deletable)
{
	id = ownId;
	symbol = ownSym;
	key = ownKey;
	this->deletable = deletable;
	color = BLUE;
	fallable = false;
	canBePlacedByUser = false;

}



void Zombie::steppedOn(Build* build)
{
	build->playerGameOver = true;

}

void Zombie::steppedIn(Build* build)
{
	build->playerGameOver = true;


}

Zombie* Zombie::clone()
{
	return (new Zombie(*this));
}
