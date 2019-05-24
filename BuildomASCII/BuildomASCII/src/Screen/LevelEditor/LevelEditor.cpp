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

	for (int x = 0; x < level.WIDTH; x++)
	{
		for (int y = 0; y < level.HEIGHT; y++)
		{
			level.at({ x,y })->deletable = true;
		}
	}

}

void LevelEditor::run()
{
	Build levelEditor(level, true);
	levelEditor.run();

	level = levelEditor.level; //ToDO: convert deletable to notDeletable

	if (levelEditor.cancelEdit) return; // Cancel
		

	fc::setTextColor(BLUE_LIGHT);
	printScreen();

	for (int i = 1; i < LevelElement::countOfElements; i++) // do not ask for empty
	{
		fc::setCursorPos(5, 5+i);
		std::cout << "Maximalanzahl f\x81r \"" << fc::color(levelEditor.elements[i]->getColor()) << levelEditor.elements[i]->symbol << fc::color(levelEditor.defaultTextColor)<< "\"[" << oldMaxElements[i] <<"]: ";
		std::string input;
		fc::showCursor();
		std::getline(std::cin, input);
		fc::hideCursor();
		if (input.length() == 0) input = std::to_string(oldMaxElements[i]);
		if (!isInt(input))
		{
			fc::setCursorPos(5 + 23, 5 + i);
			for (int i = 0; i <= input.length(); i++) std::cout << " ";
			i--;
			continue;
		}
		level.maxElements[i] = std::stoi(input, nullptr);
	}

	std::string input = " ";
	std::string msg = std::string("Name der Datei (max 10 Zeichen) [") + name + std::string("]: ");
	do
	{
		fc::setCursorPos(5, 5 + LevelElement::countOfElements);
		std::cout << msg << std::string(input.length(), ' ');
		fc::setCursorPos(5 + msg.length(), 5 + LevelElement::countOfElements);
		fc::showCursor();
		std::getline(std::cin, input);
		if (input.length() == 0) input = name;
		fc::hideCursor();
	} while (!isFilename(input));
	
	// save Level With Name
	BdalManager fileManager;
	fileManager.saveLevel(level, input);


	
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
		if (isalnum(str[i]) == 0) 
			return false;
	}
	return true;
}