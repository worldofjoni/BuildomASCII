#pragma once
#ifndef PLAY_CUSTOM_BUTTON_H
#define PLAY_CUSTOM_BUTTON_H

#include "Button/Button.h"

class PlayCustomButton : public Button
{
public:
	PlayCustomButton();
	

	int run() override;
};


#endif // !PLAY_CUSTOM_BUTTON_H
