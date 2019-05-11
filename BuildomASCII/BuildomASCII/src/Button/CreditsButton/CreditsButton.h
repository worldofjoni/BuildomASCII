#pragma once
#ifndef CREDITSBUTTON_H
#define CREDITSBUTTON_H

#include "Button/Button.h"

class CreditsButton : public Button
{
public:
	CreditsButton();

	int run() override;
};

#endif // !CREDITSBUTTON_H
