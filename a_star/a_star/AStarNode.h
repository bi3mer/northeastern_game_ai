#include <vector>

#include "Point.h"

#pragma once

struct AStarNode
{
public:
	AStarNode(AStarNode node, int cost, int h, Point newPoint);
	AStarNode(int g, int h, std::vector<Point> path, Point newPoint);
	Point getPoint();
	int getCost();
	std::vector<Point> getPath();
private:
	int g;
	int h;
	std::vector<Point> path;
};



