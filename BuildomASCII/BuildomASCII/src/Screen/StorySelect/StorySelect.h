#pragma once
#ifndef STORY_SELECT_H
#define STORY_SELECT_H

#include "Screen/Screen.h"
#include "BdalManager/BdalManager.h"

class StorySelect : public Screen
{
private:
	BdalManager fileManager;

	int x = 0;
	int gap = 2;
	int input = 0;
	int nameCount = 0;

	Pos start = { 4, 8 };
	Pos current = { start.x - 1, start.y };


	void initScreen(int prevX = 0);

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
