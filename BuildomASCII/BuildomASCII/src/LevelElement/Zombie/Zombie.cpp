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

void Zombie::move(Build* build)
{
	if (build->level.at({ pos.x + dir, pos.y })->id != 0)
	{
		dir = (dir == RIGHT) ? LEFT : RIGHT;
	}
	if (build->level.at({ pos.x + dir, pos.y })->id == 0)
	{
		build->level.swap(pos, { pos.x + dir, pos.y });
		build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
		pos.x += dir;
		build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);

	}
	if (build->currentPos == pos)
		build->playerGameOver = true;
}

void Zombie::reset(Build* build)
{
	build->level.swap(pos, formPos);
	build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
	pos = formPos;
	build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
}
