#include "pch/pch.h"
#include "Screen/Screen.h"


void Screen::printScreen()
{
	fc::setCurserPos(0, 0);
	for (int x = 0; x < WIDTH; x++)
	{
		for(int y = 0; y < HEIGHT; y++)
		{
			std::cout << content[x][y];
		}
		std::cout << std::endl;
	}
}



