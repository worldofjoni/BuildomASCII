// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef STORY_SELECT_H
#define STORY_SELECT_H

#include "Screen/Screen.h"
#include "BdalManager/BdalManager.h"

class StorySelect : public Screen
{
private:
	BdalManager fileManager;
	int gap = 2;
	const int MAX_NAMES_ON_LIST = 14;

	int x = 0;
	int input = 0;
	int nameCount = 0;

	Pos start = { 4, 8 };
	Pos current = { start.x - 1, start.y };

	int maxPage = 0;
	int currentPage = 0;
	int maxX = 0;
	void initScreen(int prevX = 0, int prevPage = 1);

public:

	void run();
	StorySelect();
	~StorySelect();
	StorySelect(const StorySelect& other) = delete;
	StorySelect(StorySelect&& other) = delete;
	StorySelect& operator=(const StorySelect& other) = delete;
	StorySelect& operator=(StorySelect&& other) = delete;
};

#endif // !STORY_SELECT_H
