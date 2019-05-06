#pragma once
#ifndef PLAYSTORYBUTTON_H
#define PLAYSTORYBUTTON_H

#include "Button/Button.h"

class PlayStoryButton : public Button
{
public:
	PlayStoryButton();
	

	int run() override;
};


#endif // !PLAYSTORYBUTTON_H
