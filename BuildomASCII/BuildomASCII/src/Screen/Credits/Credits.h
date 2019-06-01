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
	void run();

private:
	int contentWidth = 80;
	int contentHeight = 29;
	std::string content =
R"(
+------------------------------------------------------------------------------+
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                 Buildom ASCII                                |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|           Github: https://github.com/worldofjoni/BuildomASCII                |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|    Copyright # 2019: Samuel Pasieka & Jonatan Ziegler, All Rights Reserved   |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
|                        Music from https://filmmusic.io:                      |
|            "Garden Music" by Kevin MacLeod (https://incompetech.com)         |
|           Licence: CC BY (http://creativecommons.org/licenses/by/4.0/)       |
|                                                                              |
+------------------------------------------------------------------------------+
)";																	 

};

#endif