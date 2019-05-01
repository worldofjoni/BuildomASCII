#ifndef LEVEL_ELEMENT_H
#define LEVEL_ELEMENT_H


class LevelElement
{
public:
	char Symbol;
	int id;
	virtual void steppedOn() = 0;
	virtual void steppedIn() = 0;


};







#endif // !LEVEL_ELEMENT_H