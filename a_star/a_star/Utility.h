#pragma once
#include <iostream>
#include <vector>

#include "Point.h"
#include "Map.h"

namespace Utility
{
	const void printPointVector(const std::vector<Point> vec);
	const void printIntVector(const std::vector<int> vec);
	const bool solutionPathsEqual(std::vector<Point> given, std::vector<Point> actual);
	const bool equivalentSolutions(std::vector<Point> given, std::vector<Point> actual);
	const float solutionPathCost(std::vector<Point> path, Map map);
	const void printPathInMap(std::vector<Point> path, Map map);
	const bool containsPoint(std::vector<Point> path, Point point);

	const float euclidianDistance(const Point p1, const Point p2);
	const float manhattanDistance(const Point p1, const Point p2);
}