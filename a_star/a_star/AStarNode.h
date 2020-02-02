#include <vector>

#include "Point.h"

#pragma once

struct AStarNode
{
public:
	AStarNode(AStarNode node, int cost, float h, Point newPoint);
	AStarNode(int g, float h, std::vector<Point> path, Point newPoint);
	Point getPoint();
	float getCost();
	std::vector<Point> getPath();
private:
	int g;
	float h;
	std::vector<Point> path;
};



