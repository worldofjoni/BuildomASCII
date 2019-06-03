// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "LevelEditor.h"

#include "LevelElement/LevelElement.h"
#include "Screen/Build/Build.h"


// constructor for new level
LevelEditor::LevelEditor()
{
	setBlank();

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		level.maxElements[i] = -1;
		oldMaxElements[i] = -1;
	}

	//only 3 for Star
	level.maxElements[Star::ownId] = Build::maxStars;
}

// constructor for editing of existing level
LevelEditor::LevelEditor(Level level, std::string name)
	:level(level), name(name), isEditing(true)
{
	setBlank();
	
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		oldMaxElements[i] = this->level.maxElements[i];
		this->level.maxElements[i] = -1;
	}
	// but only 3 for star
	this->level.maxElements[Star::ownId] = Build::maxStars;

	for (int x = 0; x < level.WIDTH; x++)
	{
		for (int y = 0; y < level.HEIGHT; y++)
		{
			Pos pos = { x,y };
			if (pos != this->level.start && pos != this->level.end) 
				this->level.at({ x,y })->deletable = true; // allow to delete (all) elements
		}
	}

}

void LevelEditor::run()
{
	Build levelEditor(level, true);
	levelEditor.run(); // user builds level

	BdalManager fileManager;

	level = levelEditor.level;

	if (levelEditor.cancelEdit) 
		return; // cancel
		
	printScreen();

	// ++ ask for maxElements ++
	Pos start = { 5, 5 };
	int y = 1; // y-Offset
	std::string input = "";
	for (int i = 0; i < LevelElement::countOfElements; i++, y++) // do not ask for empty
	{
		if (!levelEditor.elements[i]->canBePlacedByUser) // do not ask if !canBePlacedByUser
		{
			level.maxElements[i] = 0;
			y--;
			continue;
		}

		fc::setCursorPos(5, 5+y);
		std::cout << "Maximalanzahl f\x81r \"" << fc::color(levelEditor.elements[i]->getColor()) << levelEditor.elements[i]->symbol << fc::color(levelEditor.defaultTextColor)<< "\"[" << oldMaxElements[i] <<"]: ";
		Pos userWritePos = {0, start.y+y};
		fc::getCursorPosition(userWritePos.x, userWritePos.y);
		fc::showCursor();
		std::getline(std::cin, input);
		fc::hideCursor();
		if (input.length() == 0) input = std::to_string(oldMaxElements[i]); // if nothing is written keep old value
		// input validation
		if (!isInt(input))
		{
			fc::setCursorPos(userWritePos.x, userWritePos.y);
			for (int i = 0; i <= input.length(); i++) std::cout << " "; // clear old user input
			i--, y--;
			continue;
		}
		level.maxElements[i] = std::stoi(input, nullptr); // store user input
	}

	// ++ ask for filename ++
	input = " ";
	std::string msg = std::string("Name der Datei (max 20 Zeichen) [") + name + std::string("]: ");
	do
	{
		do
		{
			fc::setCursorPos(5, 5 + y);
			std::cout << msg << std::string(input.length(), ' ');
			fc::setCursorPos(5 + msg.length(), 5 + y);
			fc::showCursor();
			std::getline(std::cin, input);
			if (input.length() == 0) 
				input = name; // if nothing is written keep old name
			fc::hideCursor();
		} while (!isFilename(input));

	} while (!fileManager.saveLevel(level, input, isEditing));
	
}