#include "pch/pch.h"
#include "Game.h"
#include "Screen/Screen.h"
#include "Screen/StartScreen/StartScreen.h"
#include "BdalManager/BdalManager.h"



void Game::run()
{
	checkForFiles();

	// Screen Setup
	setup();



	StartScreen startScreen;
	startScreen.run();



}


// Does setup stuff like screensize etc.
void Game::setup()
{
	fc::setTitle("Buildom ASCII");
	fc::setWindowSize(Screen::WIDTH, Screen::HEIGHT);
	fc::clearScreen(Screen::defaultBackgroundColor);
	fc::setTextColor(Screen::defaultTextColor);
	fc::hideCursor();
	fc::setCursorPos(0, 0);
	fc::playSoundRepeat("music\\music.wav");
}


void Game::checkForFiles()
{
	BdalManager fileManager;
	std::cout << "Checking for missing Files: ";
	fc::waitMs(200);
	char errorCode = fileManager.fileCheck();

	switch (errorCode)
	{
	case 's':
		std::cout << "MISSING STORY LEVEL";
		fc::waitMs(1500);
		break;
	case 'm':
		std::cout << "MISSING MUSIC";
		fc::waitMs(1500);
		break;
	default:
		std::cout << "OK";
		break;
	}
	fc::waitMs(200);
}