#pragma once
#ifndef CREDITS_H
#define CREDITS_H

#include "Screen/Screen.h"
#include "Button/Button.h"

class Credits : public Screen
{
public:
	ExitButton exitButton;

	Credits();
	virtual ~Credits();

	void run();
};

#endif