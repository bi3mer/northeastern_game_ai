#pragma once
#include <iostream>
#include <vector>

#include "Point.h"

namespace Utility
{
	const void printPointVector(const std::vector<Point> vec);
	const void printIntVector(const std::vector<int> vec);
	const bool solutionPathsEqual(std::vector<Point> given, std::vector<Point> actual);
	const bool equivalentSolutions(std::vector<Point> given, std::vector<Point> actual);
}