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

	virtual void run();

};



#endif // !BUTTON_H
