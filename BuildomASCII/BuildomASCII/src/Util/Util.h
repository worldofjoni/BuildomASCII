#pragma once
#ifndef UTIL_H
#define UTIL_H

#include <conio.h>



struct Pos
{
	int x, y;
	Pos below();
};



namespace uts {
	char getCharLow();

}

#endif // !UTIL_H
