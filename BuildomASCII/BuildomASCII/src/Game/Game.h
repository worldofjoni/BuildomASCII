// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef GAME_H
#define GAME_H


// main object containig everything happening in the game
class Game
{
private:
	void setup();
	void checkForFiles();
public:
	void run();
};

#endif // !GAME_H
