#include "pch/pch.h"
#include "StartScreen.h"

#include "Button/Button.h"

void StartScreen::run() 
{
	setBlank();
	/*placeWord(1, 1, playButton->word, playButton->wordSize);
	placeWord(1, 2, exitButton->word, exitButton->wordSize);*/

	placeWord(1, 1, playButton);
	placeWord(1, 2, exitButton);
	printScreen();


	

	playButton->run();

	Button* select = playButton;

	select->run();

}

StartScreen::~StartScreen()
{
	delete playButton;
	delete exitButton;
}

void StartScreen::placeWord(int px, int py, Button *button) {
	
	
	int x = px;
	for (int i = 0; i < button->wordSize; i++)
	{
		
		content[py][x] = button->word[i];
		x++;
		
		
	}
}