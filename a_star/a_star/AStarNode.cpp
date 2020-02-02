#include "AStarNode.h"

AStarNode::AStarNode(AStarNode node, int tileCost, float h, Point newPoint)
{
	AStarNode::h = h;
	g = node.g + tileCost;

	path = std::vector<Point>();
	for (int i = 0; i < node.path.size(); ++i)
	{
		path.push_back(Point(node.path[i]));
	}

	path.push_back(Point(newPoint));
}

AStarNode::AStarNode(int g, float h, std::vector<Point> oldPath, Point newPoint)
{
	AStarNode::g = g;
	AStarNode::h = h;
	
	path = std::vector<Point>();
	for (int i = 0; i < oldPath.size(); ++i)
	{
		path.push_back(Point(oldPath[i]));
	}

	path.push_back(Point(newPoint));
}

Point AStarNode::getPoint()
{
	return path[path.size() - 1];
}

float AStarNode::getCost()
{
	return (float) g + h;
}

std::vector<Point> AStarNode::getPath()
{
	return path;
}
