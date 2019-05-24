#pragma once
#ifndef CUSTOM_LEVELSELECT_H
#define CUSTOM_LEVELSELECT_H

#include "Screen/Screen.h"
#include "BdalManager/BdalManager.h"
#include "Button/Button.h"

class CustomLevelSelect : public Screen
{
private:

public:

	BdalManager fileManager;
	Button createCustomButton = Button("Neues Level erstellen", Button::runCreateCustomButton);

	int x = 0;

	int input;

	void run();

	CustomLevelSelect();
	~CustomLevelSelect();

	CustomLevelSelect(const CustomLevelSelect& other) = delete;
	CustomLevelSelect(CustomLevelSelect&& other) = delete;
	CustomLevelSelect& operator=(const CustomLevelSelect& other) = delete;
	CustomLevelSelect& operator=(CustomLevelSelect&& other) = delete;
};

#endif 
