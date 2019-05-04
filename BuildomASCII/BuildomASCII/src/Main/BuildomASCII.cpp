// BuildomASCII.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch/pch.h"
#include "Game/Game.h"

#include "Level/Level.h"
#include "Screen/Build/Build.h"


int main()
{
	Game game;

	game.run();


	// TEst
	
	Level level(Screen::WIDTH-2, Screen::HEIGHT -10); // Space for Frame and menu bar

	Build build(level);
	
	build.run();


}

