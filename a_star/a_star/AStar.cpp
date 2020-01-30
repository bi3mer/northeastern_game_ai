#include "AStar.h"

std::vector<Point> AStar::findPath(Point start, Point destination, Map map)
{
	if (start.equals(destination))
	{
		return std::vector<Point> {destination};
	}

	std::queue<std::pair<int, AStarNode>> queue;
	queue.push(std::make_pair(0, AStarNode(0, 0, std::vector<Point>(), start)));

	std::unordered_set<std::string> usedPositions;
	usedPositions.insert(start.getHash());

	bool pathFound = false;
	std::vector<Point> path;

	while (pathFound == false)
	{
		if (queue.empty())
		{
			std::cerr << "Astar unable to find a valid path." << std::endl;
			return std::vector<Point>();
		}

		AStarNode parentNode = queue.front().second;
		Point parentPoint = parentNode.getPoint();
		queue.pop();

		if (parentPoint.equals(destination))
		{
			pathFound = true;
			path = parentNode.getPath();
		}
		else
		{
			std::vector<std::pair<int, Point>> newPoints = map.getTaxiCabNeighbors(parentPoint.x, parentPoint.y);

			for (int i = 0; i < newPoints.size(); ++i)
			{
				Point newPoint = newPoints[i].second;
				std::string hash = newPoint.getHash();
				
				if (usedPositions.find(hash) == usedPositions.end()) // make sure element not found
				{
					usedPositions.insert(hash);

					int pathCost = newPoints[i].first;
					std::cout << parentPoint.getHash() << " -> " <<pathCost << std::endl;
					AStarNode newNode(parentNode, pathCost, manhattanDistance(newPoint, destination), newPoint);
					queue.push(std::make_pair(newNode.getCost(), newNode));
				}
			}
		}
	}

	return path;
}

const float AStar::euclidianDistance(const Point p1, const Point p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

const float AStar::manhattanDistance(const Point p1, const Point p2)
{
	return abs(p2.x - p1.x) + abs(p2.y - p1.y);
}
