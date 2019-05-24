#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "pch/pch.h"

class Button
{
private:

public:
	Button(const char str[], int (*run)());
	std::string name;

	int (*run)();
	

	static int runPlayButton();
	static int runCustomSelectButton();
	static int runExitButton();
	static int runCreditsButton();
	static int runManualButton();
	static int runCreateCustomButton();

};




#endif // !BUTTON_H
