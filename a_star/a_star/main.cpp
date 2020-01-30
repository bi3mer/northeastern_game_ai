// a_star.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <json/json.h>
#include <iostream>
#include <fstream>

#include "Utility.h"
#include "AStar.h"
#include "Point.h"
#include "Map.h"

Json::Value getJsonFromFile(const std::string& fileName)
{
	std::ifstream infile(fileName);

	if (infile.good() == false)
	{
		std::cout << "File \"" << fileName << "\" cannot be found." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Parsing \"" << fileName << "\"" << std::endl;
	infile.open(fileName);

	Json::CharReaderBuilder builder;
	JSONCPP_STRING errors;
	Json::Value root;

	if (!Json::parseFromStream(builder, infile, &root, &errors))
	{
		std::cout << "Unable to parse file." << std::endl;
		std::cout << errors << std::endl;
		infile.close();
		exit(NULL);
	}

	infile.close();

	return root;
}

Point buildPoint(const Json::Value root, const std::string& key)
{
	const Json::Value arr = root.get(key, Json::arrayValue);
	return Point(arr[0].asInt(), arr[1].asInt());
}

std::vector<Point> buildSolutionPath(const Json::Value root)
{
	std::vector<Point> solutionPath;
	for (int i = 0; i < (int) root.size(); ++i)
	{
		const Json::Value arr = root[i];
		solutionPath.push_back(Point(arr[0].asInt(), arr[1].asInt()));
	}

	return solutionPath;
}

int main()
{
	//std::string mapFile = "..\\data\\Problem1.json";
	std::string mapFile = "..\\data\\Problem2.json";
	//std::string mapFile = "..\\data\\Problem3.json";

	//std::string solutionFile = "..\\data\\Solution1.json";
	std::string solutionFile = "..\\data\\Solution2.json";
	//std::string solutionFile = "..\\data\\Solution3.json";

	Json::Value jsonSolution = getJsonFromFile(solutionFile);
	Json::Value jsonMap = getJsonFromFile(mapFile);

	Point destination = buildPoint(jsonMap, "Destination");
	Point start = buildPoint(jsonMap, "Start");
	Map map(jsonMap);

	std::vector<Point> solutionPath = buildSolutionPath(jsonSolution);
	std::vector<Point> path = AStar::findPath(start, destination, map);

	if (Utility::equivalentSolutions(solutionPath, path))
	{
		std::cout << "AStar found an equivalent solution path!" << std::endl;
	}
	else
	{
		std::cout << "AStar was unable to find an equivalent solution path." << std::endl;;
	}

	std::cout << std::endl << "AStar found: " << std::endl;
	Utility::printPointVector(path);

	std::cout << std::endl << "Given path: " << std::endl;
	Utility::printPointVector(solutionPath);

	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
