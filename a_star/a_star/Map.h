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
	const int getCost(int x, int y);
	const std::vector<std::pair<int, Point>> getTaxiCabNeighbors(const int x, const int y);
	const std::vector<std::pair<int, Point>> getNeighbors(const int x, const int y);
	const bool equals(Map& map);
	const std::string getHash();
	const void print();
	const int getHeight();
	const int getWidth();
private:
	int w;
	int h;

	std::vector<std::vector<int>> costs;
};