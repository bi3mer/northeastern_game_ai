#include "Point.h"

Point::Point(int x, int y)
{
	Point::x = x;
	Point::y = y;
}

bool Point::equals(Point& p)
{
	return x == p.x && y == p.y;
}
