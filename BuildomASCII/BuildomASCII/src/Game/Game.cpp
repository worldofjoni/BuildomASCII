#include "pch/pch.h"
#include "Game.h"
#include "Screen/Screen.h"
#include "Screen/StartScreen/StartScreen.h"




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
	fc::setWindowSize(Screen::WIDTH, Screen::HEIGHT);
	fc::clearScreen(Screen::defaultBackgroundColor);
	fc::setTextColor(Screen::defaultTextColor);
	fc::hideCursor();
	fc::setCursorPos(0, 0);
}
