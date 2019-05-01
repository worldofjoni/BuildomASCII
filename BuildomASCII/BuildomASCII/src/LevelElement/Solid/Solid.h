#ifndef SOLID_H
#define SOLID_H

#include "../LevelElement.h"

class Solid : public LevelElement
{
private:

public:
	Solid();
	void steppedOn() override;
	void steppedIn() override;
	Solid* clone() override;
	
};







#endif // !SOLID_H