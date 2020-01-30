#include "Map.h"

Map::Map(Json::Value root)
{
	Json::Value matrix = root.get("Map", Json::arrayValue);
	h = matrix.size();
	w = (int) matrix[0].asString().size();

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
	w = map.w;
	h = map.h;

	for (int y = 0; y < h; ++y)
	{
		costs.push_back(std::vector<int>(map.costs[y]));
	}
}

std::vector<Point> Map::getNeighbors(int x, int y)
{
	std::cerr << "Map getNeighbors not yet implemented." << std::endl;
	exit(EXIT_FAILURE);
	return std::vector<Point>();
}

// alternatively, I could compare the two resulting hash codes.
bool Map::equals(Map& map)
{
	if (w != map.w || h != map.h)
	{
		return false;
	}
	
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (costs[y][x] != map.costs[y][x])
			{
				return false;
			}
		}
	}

	return true;
}

std::string Map::getHash()
{
	std::string hash = "";
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			hash += std::to_string(costs[y][x]);
		}
	}

	return hash;
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
