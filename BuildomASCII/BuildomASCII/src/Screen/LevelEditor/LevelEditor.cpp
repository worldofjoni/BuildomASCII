// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "LevelEditor.h"

#include "LevelElement/LevelElement.h"
#include "Screen/Build/Build.h"

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
			if (pos != this->level.start && pos != this->level.end ) this->level.at({ x,y })->deletable = true;
		}
	}

}

void LevelEditor::run()
{
	Build levelEditor(level, true);
	levelEditor.run();

	BdalManager fileManager;

	level = levelEditor.level;

	if (levelEditor.cancelEdit) return; // Cancel
		

	fc::setTextColor(BLUE_LIGHT);
	printScreen();
	int y = 1; // y-Offset
	for (int i = 0; i < LevelElement::countOfElements; i++, y++) // do not ask for empty
	{
		if (!levelEditor.elements[i]->canBePlacedByUser) // do not ask for stars or NodElEmpty
		{
			level.maxElements[i] = 0;
			y--;
			continue;
		}
		fc::setCursorPos(5, 5+y);
		std::cout << "Maximalanzahl f\x81r \"" << fc::color(levelEditor.elements[i]->getColor()) << levelEditor.elements[i]->symbol << fc::color(levelEditor.defaultTextColor)<< "\"[" << oldMaxElements[i] <<"]: ";
		std::string input;
		fc::showCursor();
		std::getline(std::cin, input);
		fc::hideCursor();
		if (input.length() == 0) input = std::to_string(oldMaxElements[i]);
		if (!isInt(input))
		{
			fc::setCursorPos(5 + 23, 5 + y);
			for (int i = 0; i <= input.length(); i++) std::cout << " ";
			i--, y--;
			continue;
		}
		level.maxElements[i] = std::stoi(input, nullptr);
	}

	std::string input = " ";
	std::string msg = std::string("Name der Datei (max 10 Zeichen) [") + name + std::string("]: ");
	do
	{
		do
		{
			fc::setCursorPos(5, 5 + y);
			std::cout << msg << std::string(input.length(), ' ');
			fc::setCursorPos(5 + msg.length(), 5 + y);
			fc::showCursor();
			std::getline(std::cin, input);
			if (input.length() == 0) input = name;
			fc::hideCursor();
		} while (!isFilename(input));

	} while (!fileManager.saveLevel(level, input, isEditing));
	

	
}

bool isInt(std::string str)
{
	if (str.length() >= 9) return false;

	for (int i = 0; i < str.length(); i++) if (str[i] < 0) return false;

	if (!(str[0] == '-' || isdigit(str[0]))) return false;
	
	for (int i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i])) return false;
	}
	return true;
}

bool isFilename(std::string str)
{
	if (str.length() >10) return false;

	for (int i = 0; i < str.length(); i++) if (str[i] < 0) return false;

	for (int i = 0; i<str.length(); i++)
	{
		if (isalnum(str[i]) == 0 && str[i] != '_')
			return false;
	}
	return true;
}