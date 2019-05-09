#include "pch/pch.h"
#include "Screen/Screen.h"


void Screen::printScreen()
{
	fc::setCursorPos(0, 0);
	for (int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			fc::setBackgroundColor(content[x][y].backgroundColor);
			fc::setTextColor(content[x][y].textColor);
			std::cout << content[x][y].content;
		}
		std::cout << std::endl;
	}
}

void Screen::setBlank()
{
	
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			content[x][y].content = ' ';
		}
		
	}
}




Pos Screen::writeAt(int x, int y, char c)
{
	content[x][y].content = c;
	return { x + 1, y };
}

Pos Screen::writeAt(Pos pos, char c)
{
	return writeAt(pos.x, pos.y, c);
}

Pos Screen::writeAt(int x, int y, const char str[])
{
	int len;
	for (len = 0; str[len] != '\0'; len++);

	for (int i = 0; i <= len; i++)
	{
		content[x + i][y].content = str[i];
	}
	return { x + len, y };

}

Pos Screen::writeAt(Pos pos, const char str[])
{
	return writeAt(pos.x, pos.y, str);
}

Pos Screen::writeAt(int x, int y, int num)
{
	Pos pos;
	if (num >= 0)
	{
		int dig = 0, num_ = num;

		// determines count of digets
		do
		{
			num_ /= 10;
			dig++;
		} while (num_);

		// seperates each digit and places it in content
		for (int i = 0; i < dig; i++)
		{ //48
			content[x + i][y].content = (num / (int)pow(10, dig - i - 1)) + 48;
			num %= (int)pow(10, dig - i - 1);
		}
		pos = { x + dig, y };

	}
	else
	{
		pos = { x, y };
	}


	return pos;
}

Pos Screen::writeAt(int x, int y, int num, unsigned int digis)
{
	Pos pos;
	if (num >= 0)
	{



		int dig = 0, num_ = num;

		// determines count of digets
		do
		{
			num_ /= 10;
			dig++;
		} while (num_);


		int empty = digis - dig; // empty digis (=' ')

		for (int i = 0; i < empty; i++)
		{
			content[x][y].content = ' ';
			x++;
		}

		// seperates each digit and places it in content
		for (int i = 0; i < dig; i++)
		{ //48
			content[x + i][y].content = (num / (int)pow(10, dig - i - 1)) + 48;
			num %= (int)pow(10, dig - i - 1);
		}
		pos = { x + dig, y };

	}
	else
	{
		pos = { x, y };
	}


	return pos;
}

Pos Screen::writeAt(Pos pos, int num, unsigned int digis)
{
	return writeAt(pos.x, pos.y, num, digis);
}


