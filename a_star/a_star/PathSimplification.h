#pragma once
#include <vector>
#include <limits>

#include "Utility.h"
#include "Point.h"
#include "Map.h"

namespace PathSimplification
{
	std::vector<Point> simplifyPath(std::vector<Point> path, Map map);
	int simplifyPathFromPoint(int startindex, std::vector<Point> path, Map map);
	bool collissionExists(Point start, const Point end, Map map);
}

