#include <json/json.h>
#include <iostream>>
#include <string>
#include <vector>

#include "Point.h"

#pragma once
class Map
{
public:
	Map(Json::Value root);
	Map(const Map& map);
	int getCost(int x, int y);
	std::vector<Point> getNeighbors(int x, int y);
	std::string getHash();
	void print();
private:
	int w;
	int h;

	std::vector<std::vector<int>> costs;
};


