#include "Utility.h"

const void Utility::printPointVector(const std::vector<Point> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << "(" << vec[i].x << ", " << vec[i].y << "), ";
	}

	std::cout << std::endl;
}

const void Utility::printIntVector(const std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ", ";
	}

	std::cout << std::endl;
}

const bool Utility::solutionPathsEqual(std::vector<Point> given, std::vector<Point> actual)
{
	if (given.size() != actual.size())
	{
		return false;
	}

	for (int i = 0; i < given.size(); ++i)
	{
		if (!given[i].equals(actual[i]))
		{
			return false;
		}
	}

	return true;
}

const bool Utility::equivalentSolutions(std::vector<Point> given, std::vector<Point> actual)
{
	// ensure same size solutions
	if (given.size() != actual.size())
	{
		return false;
	}

	// make sure both end on the same point
	return given[given.size() - 1].equals(actual[actual.size() - 1]);
}

const float Utility::solutionPathCost(std::vector<Point> path, Map map)
{
	float cost = 0.0;

	for (int i = 0; i < path.size(); ++i)
	{
		Point p = path[i];
		cost += map.getCost(p.x, p.y);
	}

	return cost;
}

const void Utility::printPathInMap(std::vector<Point> path, Map map)
{
	for (int y = map.getHeight() - 1; y >= 0; --y)
	{
		for (int x = 0; x < map.getWidth(); ++x)
		{
			Point p(x, y);
			if (containsPoint(path, p))
			{
				std::cout << "-";
			}
			else
			{
				std::cout << map.getCost(x, y);
			}
		}
		
		std::cout << std::endl;
	}
}

const bool Utility::containsPoint(std::vector<Point> path, Point point)
{
	bool contains = false;
	for (int i = 0; i < path.size(); ++i)
	{
		if (path[i].equals(point))
		{
			contains = true;
			break;
		}
	}

	return contains;
}

const float Utility::euclidianDistance(const Point p1, const Point p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

const float Utility::manhattanDistance(const Point p1, const Point p2)
{
	return abs(p2.x - p1.x) + abs(p2.y - p1.y);
}