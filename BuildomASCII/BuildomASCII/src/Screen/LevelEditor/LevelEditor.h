// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

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
	bool isEditing = false; // or creating new
	std::string name = "myLevel"; // default name
	int oldMaxElements[LevelElement::countOfElements]; // store max elements, because real value has to be set to -1 for editing
public:
	LevelEditor();
	LevelEditor(Level level, std::string name); // for editing levels
	void run();
};

#endif // !LEVEL_EDITOR_H
