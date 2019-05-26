#pragma once
#ifndef CUSTOM_LEVELSELECT_H
#define CUSTOM_LEVELSELECT_H

#include "Screen/Screen.h"
#include "BdalManager/BdalManager.h"
#include "Button/Button.h"

class CustomLevelSelect : public Screen
{
private:
	BdalManager fileManager;
	Button createCustomButton = Button("Neues Level erstellen", Button::runCreateCustomButton);

	int x = 0;
	int gap = 2;
	int input = 0;
	int nameCount = 0;
	std::string names[100];

	Pos start = { 4, 4 };
	Pos current = { start.x - 1, start.y };

	bool confirm();
	void initScreen(int prevX = 0);

public:

	void run();
	CustomLevelSelect();
	~CustomLevelSelect();
	CustomLevelSelect(const CustomLevelSelect& other) = delete;
	CustomLevelSelect(CustomLevelSelect&& other) = delete;
	CustomLevelSelect& operator=(const CustomLevelSelect& other) = delete;
	CustomLevelSelect& operator=(CustomLevelSelect&& other) = delete;
};

#endif 
