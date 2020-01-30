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

// not doing error checking. I'll let it crash if it gets here without having
// already had error checking. For this I need to re-orient the Y value since
// the map is oriented from the bottom left.
const int Map::getCost(int x, int y)
{
	return costs[(size_t) h - 1 - y][x];
}

// implemented for all eight directions
const std::vector<std::pair<int, Point>> Map::getNeighbors(const int x, const int y)
{
	std::vector<std::pair<int, Point>> neighbors;

	for (int yMod = -1; yMod <= 1; ++yMod)
	{
		for (int xMod = -0; xMod <=1; ++xMod)
		{
			if (xMod == 0 && yMod == 0) continue;

			int newX = x + xMod;
			int newY = y + yMod;

			if (newX < 0 || newX >= w) continue;
			if (newY < 0 || newY >= h) continue;

			int cost = getCost(newX, newY);
			if (cost > 0)
			{
				neighbors.push_back(std::make_pair(cost, Point(newX, newY)));
			}
		}
	}

	return neighbors;
}

// alternatively, I could compare the two resulting hash codes.
const bool Map::equals(Map& map)
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

const std::string Map::getHash()
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

const void Map::print()
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
