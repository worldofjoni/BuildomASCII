#include "pch/pch.h"

Pos Pos::below()
{
	return { x, y + 1 };
}
