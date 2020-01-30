#include "Point.h"

Point::Point(int x, int y)
{
	Point::x = x;
	Point::y = y;
}

Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
}

std::string Point::getHash()
{
	return std::to_string(x) + "," + std::to_string(y);
}

bool Point::equals(const Point& p)
{
	return x == p.x && y == p.y;
}
