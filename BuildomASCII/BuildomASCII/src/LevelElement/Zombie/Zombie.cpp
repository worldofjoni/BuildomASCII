// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Zombie.h"
#include "Screen/Build/Build.h"


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
	if ((build->level.at({ pos.x + dir, pos.y })->id != 0) || (build->level.end.x == pos.x + dir && build->level.end.y == pos.y) || (build->level.start.x == pos.x + dir && build->level.start.y == pos.y) || (pos.x + dir == build->level.WIDTH - 1 || pos.x + dir == 0))
	{
		dir = (dir == RIGHT) ? LEFT : RIGHT;
	}

	if (pos.x + dir != build->level.WIDTH - 1 && pos.x + dir != 0)
	{
		if (build->level.at({ pos.x + dir, pos.y })->id == 0)
		{

			build->level.swap(pos, { pos.x + dir, pos.y });
			build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
			pos.x += dir;
			build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);

			if ((build->level.at({ pos.x + dir, pos.y })->id == 10))
				dir = (dir == RIGHT) ? LEFT : RIGHT;
		}
	}

	checkPlayerCollision(build);

	if (pos.y + 1 == build->level.HEIGHT - 1)
		return;

	falling(build);
}

void Zombie::reset(Build* build)
{
	if (build->level.at(formPos)->id == id)
	{
		for (int i = 0; i < build->zombieList.size(); i++)
		{
			if (build->zombieList[i].pos == formPos)
				build->zombieList[i].pos = pos;
		}
	}
	build->level.swap(pos, formPos);
	build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
	pos = formPos;
	build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
}

void Zombie::checkPlayerCollision(Build* build)
{
	if (build->currentPos == pos)
		build->playerGameOver = true;
}

void Zombie::falling(Build* build)
{
	int fall = build->fallSpeed;
	while (build->level.at(pos.below())->id == 0 && fall != 0)
	{
		build->level.swap(pos, pos.below());
		build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);
		pos = pos.below();
		build->printOnLevel(build->level.at(pos)->symbol, pos, build->level.at(pos)->getColor(), build->level.at(pos)->backgroundColor);

		checkPlayerCollision(build);
		fall--;

		if (pos.y + 1 == build->level.HEIGHT - 1)
			return;
	}
}
