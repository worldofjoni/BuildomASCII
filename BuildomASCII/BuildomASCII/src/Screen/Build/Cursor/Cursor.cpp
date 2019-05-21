#include "pch/pch.h"
#include "Cursor.h"


Cursor::Cursor(Level* level)
	:level(level)
{
	pos.x = level->start.x;
	pos.y = level->start.y;
}

// Moves Cursor in direction
void Cursor::move(Direction dir)
{
	switch (dir)
	{
	case NONE:
		break;
	case UP:
		if (pos.y > 0)
			pos.y--;
		break;
	case DOWN:
		if (pos.y < level->HEIGHT - 1)
			pos.y++;
		break;
	case LEFT:
		if (pos.x > 0)
			pos.x--;
		break;
	case RIGHT:
		if (pos.x < level->WIDTH - 1)
			pos.x++;
		break;
	default:
		break;
	}
}
