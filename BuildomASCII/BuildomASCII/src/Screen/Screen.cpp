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



