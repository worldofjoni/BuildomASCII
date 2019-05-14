#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "pch/pch.h"

class Button
{
private:

public:
	Button();
	virtual ~Button();

	int wordSize = 0;

	std::string word = "Base";

	virtual int run();

};

#include "Button/PlayStoryButton/PlayStoryButton.h"
#include "Button/ExitButton/ExitButton.h"
#include "Button/CreditsButton/CreditsButton.h"



#endif // !BUTTON_H
