#include "AStar.h"

struct CompareFirst
{
	constexpr bool operator()(std::pair<int, AStarNode> const& a, std::pair<int, AStarNode> const& b) const noexcept
	{
		return a.first > b.first;
	}
};


std::vector<Point> AStar::findPath(Point start, Point destination, Map map)
{
	if (start.equals(destination))
	{
		return std::vector<Point> {destination};
	}

	std::priority_queue<std::pair<int, AStarNode>, std::vector<std::pair<int, AStarNode>>, CompareFirst> queue;
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

		AStarNode parentNode = queue.top().second;
		Point parentPoint = parentNode.getPoint();
		queue.pop();

		std::vector<std::pair<int, Point>> newPoints = map.getTaxiCabNeighbors(parentPoint.x, parentPoint.y);
		for (int i = 0; i < newPoints.size(); ++i)
		{
			Point newPoint = newPoints[i].second;
			std::string hash = newPoint.getHash();

			if (newPoint.equals(destination))
			{
				pathFound = true;
				path = parentNode.getPath();
				path.push_back(newPoint);
				break;
			}
			else if(usedPositions.find(hash) == usedPositions.end()) // make sure point hasn't been seen before
			{
				usedPositions.insert(hash);

				int pathCost = newPoints[i].first;
				AStarNode newNode(parentNode, pathCost, Utility::euclidianDistance(newPoint, destination), newPoint);
				queue.push(std::make_pair(newNode.getCost(), newNode));
			}
		}
	}

	return path;
}


