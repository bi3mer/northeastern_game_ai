#pragma once
#include <string>

struct Point
{
public:
	int x;
	int y;

	Point(int x, int y);
	Point(const Point& p);
	std::string getHash();
	bool equals(const Point& p);
};

