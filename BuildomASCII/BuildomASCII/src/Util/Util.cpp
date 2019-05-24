#include "pch/pch.h"
#include "Util.h"

Pos Pos::below()
{
	return { x, y + 1 };
}
