// ####################################################
// #    Header to easily change console colours       #
// #               by Jonatan Ziegler                 #
// ####################################################


#pragma once
#ifndef _FRIENDLY_CONSOLE_
#define _FRIENDLY_CONSOLE

// library includes
#include <Windows.h>
//#include <bitset>


#define gotoxy fc::setCurserPos
#define getrandom_int fc::getRandom

// defines diffrent colors
#define BLACK 0x0000
#define BLUE_LIGHT 0x0001
#define GREEN_LIGHT 0x0002
#define CYAN_LIGHT 0x0003
#define RED_LIGHT 0x0004
#define MAGENTA_LIGHT 0x0005
#define YELLOW_LIGHT 0x0006
#define LIGHT_GRAY 0x0007
#define DARK_GRAY 0x0008
#define BLUE 0x0009
#define GREEN 0x000A
#define CYAN 0x000B
#define RED 0x000C
#define MAGENTA 0x000D
#define YELLOW 0x000E
#define WHITE 0x000F

namespace fc {


	// abbr. for unsigned short
	typedef unsigned short Color;

	// function prototypes
	void setTextColor(Color color);
	void setBackgroundColor(Color color);
	inline void clearScreen();
	void clearScreen(Color color);
	void setTitle(const char name[]);
	void setCurserPos(int x, int y);
	void setWindowSize(int with, int height);
	void setWindowPos(int x, int y);
	void setFontSize(int with, int height = 0); // experimental
	int getRandom(int min, int max);


}

#endif // !_FRIENDLY_CONSOLE_