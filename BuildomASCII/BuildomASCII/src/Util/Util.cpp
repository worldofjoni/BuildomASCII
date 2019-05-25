#include "pch/pch.h"
#include "Util.h"

Pos Pos::below()
{
	return { x, y + 1 };
}

bool Pos::isOnLevelBorder()
{
	if (x == 0 || y == 0 || x == Level::WIDTH - 1 || y == Level::HEIGHT - 1) return true;
	return false;
}

bool Pos::operator==(Pos other)
{
	return (x == other.x && y == other.y);
}

bool Pos::operator!=(Pos other)
{
	return !((*this) == other);
}

char getCharLow()
{
	char input = 0;
	input = _getch();
	if (input >= 0)
	{
		if (isupper(input) && isalpha(input))
		{
			input = _tolower(input);
		}
	}
	return input;
}