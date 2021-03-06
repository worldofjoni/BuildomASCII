// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright �2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

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
	int gap = 2;
	const int MAX_NAMES_ON_LIST = 14;

	int x = 0;
	int input = 0;
	int nameCount = 0;

	int maxPage = 0;
	int currentPage = 0;
	int maxX = 0;

	std::string names[100];
	

	Pos start = { 4, 8 };
	Pos current = { start.x - 1, start.y };

	bool confirmDelete();
	void initScreen(int prevX = 0, int prevPage = 1);

public:

	void run();
};

#endif 
