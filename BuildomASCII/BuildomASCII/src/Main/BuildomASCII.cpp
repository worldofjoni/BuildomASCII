// BuildomASCII.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch/pch.h"
#include "Game/Game.h"

#include "Level/Level.h"
#include "Screen/Build/Build.h"

#include <Windows.h>

int main()
{
	
	Game game;

	game.run();


	// Test
	
	Level level(Screen::WIDTH - 2, Screen::HEIGHT - 10); // Space for Frame and menu bar
	level.setStartEnd({ 5, 5 }, { 90, 30 });
	// max count of elements
	int maxElements[LevelElement::countOfElements] = { -1, 10, 5, 5 };
	level.setMaxElements(maxElements);

	Build build(level);
	
	build.run();


}

