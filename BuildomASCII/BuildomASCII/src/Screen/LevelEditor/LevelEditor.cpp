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

	}
}

void LevelEditor::run()
{
	Build levelEditor(level, true);
	levelEditor.run();

	level = levelEditor.level;

	if (levelEditor.cancelEdit) return; // Cancel
		

	fc::setTextColor(BLUE_LIGHT);
	printScreen();

	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		fc::setCursorPos(5, 5+i);
		std::cout << "Maximalanzahl f" <<(char)129 << "r \"" << fc::color(levelEditor.elements[i]->color) << levelEditor.elements[i]->symbol << fc::color(levelEditor.defaultTextColor)<< "\" : ";
		std::string input;
		std::cin >> input;
		if (!isInt(input))
		{
			fc::setCursorPos(5 + 23, 5 + i);
			for (int i = 0; i <= input.length(); i++) std::cout << " ";
			i--;
			continue;
		}
		level.maxElements[i] = std::stoi(input, nullptr);
	}

	std::string input;
	fc::setCursorPos(5, 5 + LevelElement::countOfElements);
	std::cout << "Name der Datei (max 10 Zeichen): ";
	std::cin >> input;

	// todo save Level With Name


	
}

bool isInt(std::string str)
{
	if (str.length() >= 9) return false;

	if (!(str[0] == '-' || isdigit(str[0]))) return false;

	for (int i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i])) return false;
	}
	return true;
}
