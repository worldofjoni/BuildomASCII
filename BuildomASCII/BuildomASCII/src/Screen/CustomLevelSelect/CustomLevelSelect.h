#pragma once
#ifndef LEVELSELECT
#define LEVELSELECT

#include "Screen/Screen.h"
#include "Button/Button.h"

class CustomLevelSelect : public Screen
{
public:
	CreateNewCustomButton createCustomButton;
	PlayCustomButton playCustomButton;

	int x = 0, y = 0;


	void run();
};

#endif // !LEVELSELECT
