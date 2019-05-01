// BuildomASCII.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include "../Game/Game.h"

#include "../Level/Level.h"
#include "../Build/Build.h"


int main()
{
	Game game;

	game.run();


	// TEst
	
	Level level(Screen::WIDTH, Screen::HEIGHT -20);

	Build build(level);
	
	build.run();


}

