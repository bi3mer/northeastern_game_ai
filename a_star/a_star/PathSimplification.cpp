#include "PathSimplification.h"

std::vector<Point> PathSimplification::simplifyPath(std::vector<Point> path, Map map)
{
	std::vector<Point> simplifiedPath;
	simplifiedPath.push_back(path[0]);

	bool done = false;
	int index = 0;
	
	do
	{
		int endIndex = simplifyPathFromPoint(index, path, map);
		simplifiedPath.push_back(path[endIndex]);

		if (endIndex == path.size() - 1)
		{
			done = true;
		}
		else
		{
			index = endIndex;
		}
	}
	while(done == false);

	return simplifiedPath;
}

// returns index for furthest node in the path that it can simplify for.
int PathSimplification::simplifyPathFromPoint(int startIndex, std::vector<Point> path, Map map)
{
	Point start = path[startIndex];
	int endIndex = startIndex + 1; // next node must be valid
	
	for (; endIndex < path.size(); ++endIndex)
	{
		if (collissionExists(start, path[endIndex], map))
		{
			--endIndex;
			if (endIndex == startIndex) ++endIndex;
			break;
		}
	}

	if (endIndex == path.size()) --endIndex;
	return endIndex;
}

bool PathSimplification::collissionExists(Point start, const Point end, Map map)
{
	bool collisionExists = true;
	do 
	{
		Point point(0, 0);
		float distance = 10000000.0;

		for (int yMod = -1; yMod <= 1; ++yMod)
		{
			for (int xMod = -1; xMod <= 1; ++xMod)
			{
				if ((xMod == 0 && yMod != 0) || (xMod != 0 && yMod == 0))
				{
					int newX = start.x + xMod;
					int newY = start.y + yMod;

					if (newX < 0 || newX >= map.getWidth()) continue;
					if (newY < 0 || newY >= map.getHeight()) continue;

					Point tempP(newX, newY);
					float tempD = Utility::euclidianDistance(tempP, end);

					if (tempD < distance)
					{
						collisionExists = (map.getCost(tempP.x, tempP.y) == 0);
						distance = tempD;
						point = tempP;
					}
				}
			}
		}

		if (collisionExists == false)
		{
			start = point;
		}
	} 
	while (!start.equals(end) && collisionExists == false);

	return collisionExists;
}
