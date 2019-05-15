#include "pch/pch.h"
#include "LevelEditor.h"

#include "LevelElement/LevelElement.h"

LevelEditor::LevelEditor()
{
	setBlank();
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		level.maxElements[i] = -1;

	}
}

Level LevelEditor::run()
{
	Build levelEditor(level, true);
	levelEditor.run();// ToDo better escapeing

	level = levelEditor.level;

		

	fc::setTextColor(BLUE_LIGHT);
	for (int i = 0; i < LevelElement::countOfElements; i++)
	{
		printScreen(); // Todo: make this faster (no complete PRinting); ToDo: Wicht Element is which? 
		fc::setCursorPos(5, 5);
		std::cout << "Count for LevelElement num [" << i << "]: ";
		std::cin >> level.maxElements[i]; // ToDo: if it is no int
	}
	




	return level;
}
