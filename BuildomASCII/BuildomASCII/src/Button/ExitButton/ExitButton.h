#pragma once
#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "Button/Button.h"

class ExitButton : public Button
{
public:
	ExitButton();

	void run() override;
};

#endif // !EXITBUTTON_H
