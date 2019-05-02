#include "pch/pch.h"
#include "Curser.h"


Curser::Curser(Level* level)
	:level(level)
{
}

// Moves Curser in direction
void Curser::move(Direction dir)
{
	switch (dir)
	{
	case NONE:
		break;
	case UP:
		if (y > 0)
			y--;
		break;
	case DOWN:
		if (y < level->HEIGHT - 1)
			y++;
		break;
	case LEFT:
		if (x > 0)
			x--;
		break;
	case RIGHT:
		if (x < level->WIDTH - 1)
			x++;
		break;
	default:
		break;
	}
}
