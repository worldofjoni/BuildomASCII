// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef WIN_SCREEN_H
#define WIN_SCREEN_H

#include "Screen/Screen.h"
#include "Screen/Build/Build.h"

class WinScreen : public Screen
{
public:

	std::string logo = R"(
  _____ _____ ______ _____ 
 / ____|_   _|  ____/ ____|
| (___   | | | |__ | |  __ 
 \___ \  | | |  __|| | |_ |
 ____) |_| |_| |___| |__| |
|_____/|_____|______\_____|
)";

	std::string star = R"(
\|/
-@-
/|\
)";

	WinScreen(Build* old);
	virtual ~WinScreen();
	fc::Color frameColor = RED_LIGHT;
	fc::Color backgroundColor = WHITE;
	fc::Color textColor = RED_LIGHT;
	fc::Color logoColor = RED;

	void run();
};

#endif