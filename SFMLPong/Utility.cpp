#include "Utility.hpp"

bool isInside(float left, float right, float top, float bot, float x, float y)
{
	if (x > left && x < right && y > top && y < bot)
		return true;
	else
		return false;
}