#pragma once
#include <unordered_set>
#include <vector>
#include <queue>
#include <math.h>

#include "AStarNode.h"
#include "Utility.h"
#include "Point.h"
#include "Map.h"

namespace AStar
{
	std::vector<Point> findPath(Point start, Point destination, const Map map);
	const float euclidianDistance(const Point p1, const Point p2);
	const float manhattanDistance(const Point p1, const Point p2);
}
