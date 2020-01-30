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