#include "pch/pch.h"
#include "Game.h"
#include "Screen/StartScreen/StartScreen.h"
//#include "StartScreen/StartScreen.h"



void Game::run()
{
	// Screen Setup
	setup();



	StartScreen startScreen;
	startScreen.run();



}


// Does setup stuff like screensize etc.
void Game::setup()
{
	//fc::setWindowSize(Screen::with, Screen.height);
	//fc::clearScreen(Screen::defaultBackgroundColor)
	//fc::setTextColor(Screen::defaultTextColor);
}
