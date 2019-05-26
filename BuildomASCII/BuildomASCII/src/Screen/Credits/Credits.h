// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef CREDITS_H
#define CREDITS_H

#include "Screen/Screen.h"
#include "Button/Button.h"

class Credits : public Screen
{
public:
	

	Credits();
	virtual ~Credits();
	std::string gameName = "Buildom ASCII";
	std::string content =  std::string("Copyright \xb8 \b2019: Samuel Pasieka & Jonatan Ziegler");
	std::string music = R"(
Music from https://filmmusic.io:
"Garden Music" by Kevin MacLeod (https://incompetech.com)
Licence: CC BY (http://creativecommons.org/licenses/by/4.0/)
)";

	void run();
};

#endif