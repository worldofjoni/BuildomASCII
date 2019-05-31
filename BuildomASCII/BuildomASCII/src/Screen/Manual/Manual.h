// ***********************************************************
// *                      Buildom ASCII                      *
// *    Copyright ©2019: Samuel Pasieka & Jonatan Ziegler    *
// ***********************************************************

#pragma once
#ifndef MANUAL_H
#define MANUAL_H

#include "Screen/Screen.h"
#include "Button/Button.h"
#include "LevelElement/LevelElement.h"

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
Ziel des Spiels ist es, eine Brücke über vorgegebene Hindernisse zu bauen und dabei 
das begrenzte Material optimal zu nutzen, damit eine Figur vom Start das Ziel erreichen kann.


Tastenbelegung

W     : Cursor nach oben
A     : Cursor nach links
S     : Cursor nach unten
D     : Cursor nach rechts
ESC   : Verlassen
ENTER : Starten
LEER  : Block plazieren
BACK  : Löschen
Sonstige Tasten siehe Menüblaken


Blöcke

# : solider Block auf dem die Figur laufen kann, jedoch stirbt, wenn sie gegen ihn läuft

# : Treppe, mit der die Figur um 1 nach oben laufen kann, wenn sie von links kommt, 
    jedoch hindurchläuft, wenn sie von rechts kommt

# : genau wie vorheriger, jedoch andersherum

# : bei Berührung ändert die Figur ihre Richtung

# : bei Berührung stirbt die Figur

# : kann von der Figur eingesammelt werden und gibt Punkte (max. 3)

# : Block, durch den die Figur hindurchlaufen, auf dem jedoch kein anderer plaziert werden kann

# : Block, der zwischen # und # wechselt

# : Block, der zwischen # und einem leeren Block wechselt

# : wandert hin und her, bei Berührung stirbt die Figur
)";
	static const int elLen = 15;
	LevelElement* elements[elLen] = {new Solid(false), new SlopeUp(false), new SlopeDown(false), new ChangeDir(false), new Spike(false), new Star(false), new NonDelEmpty(false), new TimedSpike(false), new Spike(false), new Solid(false), new TimedSpikeAir(false), new Spike(false), new Zombie(false)};



public:
	Manual();
	// destructor
	~Manual();
	Manual(const Manual& other) = delete;
	Manual(Manual&& other) = delete;
	Manual& operator=(const Manual& other) = delete;
	Manual& operator=(Manual&& other) = delete;

	void run();
};



#endif