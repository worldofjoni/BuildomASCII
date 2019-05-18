#pragma once
#ifndef MANUALBUTTON_H
#define MANUALBUTTON_H

#include "Button/Button.h"

class ManualButton : public Button
{
public:
	ManualButton();
	

	int run() override;
};


#endif // !MANUALBUTTON_H
