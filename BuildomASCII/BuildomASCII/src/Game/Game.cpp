// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#include "pch/pch.h"
#include "Game.h"
#include "Screen/Screen.h"
#include "Screen/StartScreen/StartScreen.h"
#include "BdalManager/BdalManager.h"



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
	fc::setFont(F_RASTERFONT);
	fc::setFontSize(8, 8);
	fc::setTitle("Buildom ASCII");
	fc::setWindowSize(Screen::WIDTH, Screen::HEIGHT);
	fc::clearScreen(Screen::defaultBackgroundColor);
	fc::setTextColor(Screen::defaultTextColor);
	fc::hideCursor();
	fc::setCursorPos(0, 0);
	checkForFiles();
	playMusic("music\\music.wav");
}


void Game::checkForFiles()
{
	BdalManager fileManager;
	
	fc::waitMs(200);
	char errorCode = fileManager.fileCheck();
	if(errorCode != 0){
		fc::playSound("asdasdasdasdasfdsgilkhjagopiudjgfölasdjfkadsa"); // for windows error sound
		std::cout << std::endl << "     FOLGENDE DATEIEN FEHLEN: " << std::endl;
		if (errorCode & 0b00000001) std::cout << "     STORY LEVEL" << std::endl;
		if (errorCode & 0b00000010)
		{
			std::cout << "     MUSIK" << std::endl;
			musicAllowed() = false;
		}
		std::cout << std::endl << "     DRUEKEN SIE ENTER";
		std::cin.ignore();

	}
}