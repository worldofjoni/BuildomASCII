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
	std::string content = std::string(1, 184) + std::string(" Samuel Pasieka & Jonatan Ziegler");

	void run();
};

#endif