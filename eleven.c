#include <stdio.h>
#include "libs/algorithm.h"
#include "libs/print.h"

int main()
{
	int x[] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
	int y[] = {1, 8, 9, 10, 15};

	unsigned xSize = sizeof(x) / sizeof(int);
	unsigned ySize = sizeof(y) / sizeof(int);

	int emptyCells[xSize + ySize];

	unsigned xInd = 0, yInd = 0;
	unsigned currentEmptyCell = 0;
	unsigned maxEmptyCell = 0;


	while (yInd < ySize)
	{
		if (xInd == xSize)
		{
			if (currentEmptyCell < maxEmptyCell)
			{
				x[emptyCells[currentEmptyCell]] = y[yInd];
				++currentEmptyCell;
			}
			++yInd;
			continue;
		}

		int xEle = x[xInd];
		int yEle = y[yInd];

		if (xEle == 0)
		{
			emptyCells[maxEmptyCell] = xInd;
			++xInd;
			++maxEmptyCell;
		}
		else
		{
			if (xEle > yEle)
			{
				if (currentEmptyCell < maxEmptyCell)
				{
					x[emptyCells[currentEmptyCell]] = yEle;
					++yInd;
					++ currentEmptyCell;
				}
				else
				{
					swapElement(x, y, xInd, yInd);	
					++xInd;
				}
				
			}
			else
			{
				if (currentEmptyCell < maxEmptyCell)
				{
					x[emptyCells[currentEmptyCell]] = xEle;
					x[xInd] = 0;
					emptyCells[maxEmptyCell] = xInd;
					++maxEmptyCell;
					++currentEmptyCell;
				}	
				++xInd;
			}
			
		}
	}
	
	printArr(x, xSize, INT);

	return 0;
}