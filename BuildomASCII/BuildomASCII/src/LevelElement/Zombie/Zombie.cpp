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
	int fall = build->fallSpeed;
	if ((build->level.at({ pos.x + dir, pos.y })->id != 0) || (build->level.end.x == pos.x + dir && build->level.end.y == pos.y) || build->level.start.x == pos.x + dir && build->level.start.y == pos.y )
	{
		dir = (dir == RIGHT) ? LEFT : RIGHT;
	}
	if (build->level.at({ pos.x + dir, pos.y })->id == 0 )
	{
		
			build->level.swap(pos, { pos.x + dir, pos.y });
			build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
			pos.x += dir;
			build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);

			if ((build->level.at({ pos.x + dir, pos.y })->id == 10))
			{
				dir = (dir == RIGHT) ? LEFT : RIGHT;
			}

		
	}
	if (build->currentPos == pos)
		build->playerGameOver = true;
	while (build->level.at(pos.below())->id == 0 && fall != 0)
	{
		build->level.swap(pos, pos.below());
		build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
		pos = pos.below();
		build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
		if (build->currentPos == pos)
			build->playerGameOver = true;
		fall--;
	}
}

void Zombie::reset(Build* build)
{
	build->level.swap(pos, formPos);
	build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
	pos = formPos;
	build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
}
