// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

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
		if (y < HEIGHT - 1) std::cout << std::endl;
	}
	fc::setCursorPos(0, 0);
}

void Screen::setBlank()
{
	
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			content[x][y].content = ' ';
			content[x][y].backgroundColor = defaultBackgroundColor;
			content[x][y].textColor = defaultTextColor;
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

void Screen::writeMultiline(Pos pos, std::string str, int width)
{
	str = str.substr(1, str.length()); // to deleate the first \n
	int i = 0, x = pos.x, y = pos.y;
	while (i < str.length())
	{
		while (str[i] != '\n' && (x+i) < Screen::WIDTH)
		{
			switch (str[i])
			{
			case '�':
				content[x + i][y].content = 132;
				break;
			case '�':
				content[x + i][y].content = 148;
				break;
			case '�':
				content[x + i][y].content = 129;
				break;
			case '�':
				content[x + i][y].content = 142;
				break;
			case '�':
				content[x + i][y].content = 153;
				break;
			case '�':
				content[x + i][y].content = 154;
				break;
			case '�':
				content[x + i][y].content = 225;
				break;
			default:
				content[x + i][y].content = str[i];
				break;
			}
			i++;
		}
		str = str.substr((str[i] == '\n') ? i + 1 : i, str.length());
		i = 0;
		y++;
	}

}

void Screen::copyContent(Pixel old[WIDTH][HEIGHT])
{
	for(int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			content[x][y] = old[x][y];
		}
	}
}


