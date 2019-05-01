#ifndef LEVEL_ELEMENT_H
#define LEVEL_ELEMENT_H


class LevelElement
{
public:
	char symbol;
	int id;
	bool deletable; // if an Element can be removed my player
	virtual void steppedOn() = 0;
	virtual void steppedIn() = 0;
	virtual LevelElement* clone() = 0; // copy function

};


#include "../LevelElement/Empty/Empty.h"
#include "../LevelElement/Solid/Solid.h"



#endif // !LEVEL_ELEMENT_H