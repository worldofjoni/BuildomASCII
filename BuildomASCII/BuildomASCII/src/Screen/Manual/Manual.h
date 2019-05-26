// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef MANUAL_H
#define MANUAL_H

#include "Screen/Screen.h"
#include "Button/Button.h"

class Manual : public Screen
{
private:
	static int calls;
	std::string content_ = 
R"(
Du wunderst dich wo die Anleitung ist?
Ganz einfach: die hat jetzt Urlaub
Jetzt musst du es alleine schaffen

Ob sie wieder zurück kommt?
Weiß ich nicht.
Sie war auch sehr beleidigt, denn so oft wurde sie noch NIE gebraucht!!
Sie meinte wenn du sie beim letzten mal nicht verstandest wist du sie nie verstehen.
)";

	std::string	content =
R"(
WIP
)";


public:
	Manual();
	

	void run();
};



#endif