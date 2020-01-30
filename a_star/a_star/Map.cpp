#include "Map.h"

Map::Map(Json::Value root)
{
	Json::Value matrix = root.get("Map", Json::arrayValue);
	h = matrix.size();
	w = matrix[0].asString().size();

	for (int i = 0; i < h; ++i) 
	{
		std::vector<int> newVector;
		std::string row = matrix[i].asString();

		for (int j = 0; j < w; ++j)
		{
			if (row[j] == 'X')
			{
				newVector.push_back(0); // I've decided 0 to represent a wall.
			}
			else
			{
				newVector.push_back((int)row[j] - 48);
			}
		}

		costs.push_back(newVector);
	}
}

Map::Map(const Map& map)
{
	std::cerr << "Map copy constructor not yet implemented." << std::endl;
	exit(EXIT_FAILURE);
}

std::vector<Point> Map::getNeighbors(int x, int y)
{
	std::cerr << "Map getNeighbors not yet implemented." << std::endl;
	exit(EXIT_FAILURE);
	return std::vector<Point>();
}

std::string Map::getHash()
{
	std::cerr << "Map getHash not yet implemented." << std::endl;
	exit(EXIT_FAILURE);
	return std::string();
}

void Map::print()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			std::cout << costs[i][j];
		}

		std::cout << std::endl;
	}
}
