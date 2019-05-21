#pragma once
#ifndef POS_H
#define POS_H

struct Pos
{
	int x, y;
	Pos below();
};

#endif // !POS_H
