#pragma once
struct Point
{
public:
	int x;
	int y;

	Point(int x, int y);
	bool equals(Point& p);
};

