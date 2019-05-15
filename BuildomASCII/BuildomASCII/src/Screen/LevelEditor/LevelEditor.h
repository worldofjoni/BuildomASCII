#pragma once
#ifndef LEVEL_EDITOR_H
#define LEVEL_EDITOR_H

#include "Screen/Screen.h"
#include "Level/Level.h"
class LevelEditor : public Screen
{
private:
	Level level;
public:
	LevelEditor();
	Level run();
};



#endif // !LEVEL_EDITOR_H
