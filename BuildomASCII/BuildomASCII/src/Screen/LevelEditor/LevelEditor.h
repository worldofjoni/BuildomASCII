#pragma once
#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include "Screen/Screen.h"
#include "Level/Level.h"
#include "pch/pch.h"
#include "BdalManager/BdalManager.h"

class LevelEditor : public Screen
{
private:
	Level level;
public:
	LevelEditor();
	void run();
};

bool isInt(std::string str);

#endif // !LEVEL_EDITOR_H
