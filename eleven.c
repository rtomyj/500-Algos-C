#include <stdio.h>
#include "libs/algorithm.h"
#include "libs/print.h"

/*
	Main functionality.
	Completes algorithm 11.
*/
int main()
{
	int x[] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
	int y[] = {1, 8, 9, 10, 15};

	unsigned xSize = sizeof(x) / sizeof(int);
	unsigned ySize = sizeof(y) / sizeof(int);

	int emptyCells[xSize - ySize];	// indices of all 0's (empty cells) found in x

	unsigned xInd = 0, yInd = 0;	// which indexes in lists (x, y) algorithm is currently comparing
	unsigned currentEmptyCell = 0;	// which element to use from emptyCells array
	unsigned maxEmptyCell = 0;	// how many empty cells have been seen in x and added to emptyCells

	/*
		Compares all elements of x with elements of y.
		Terminates once all elements of y have been compared and merged into x
	*/
	while (yInd < ySize)
	{
		/*
			Condition is met once all elements of x have been traversed.
			This happens when the y list has elements greater than all elements of x. All remaining elements of y are added 
			to unused indexes of x.
		*/
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

		/*
			Current elements.
		*/
		int xEle = x[xInd];
		int yEle = y[yInd];

		/*
			Unused spot in x is found. 
			Must be traversed over.
		*/
		if (xEle == 0)
		{
			emptyCells[maxEmptyCell] = xInd;
			++xInd;
			++maxEmptyCell;
		}
		/*
			Comparison will be done to element of x with element of y.
		*/
		else
		{
			if (xEle > yEle)
			{
				/*
					If there is an emptyCell in x then put the y element into the left most empty cell.
				*/
				if (currentEmptyCell < maxEmptyCell)
				{
					x[emptyCells[currentEmptyCell]] = yEle;
					++yInd;
					++ currentEmptyCell;
				}
				/*
					If there is no emptyCell then swap the x element with the y element.
					After the swap, the y element is the greater of the two and we are ok to increment the x index.
				*/
				else
				{
					swapElement(x, y, xInd, yInd);	
					++xInd;
				}
				
			}
			else
			{
				/*
					The x value is less than the y value meaning we still need to find a spot for the y element (don't increment y).
					If there is an emptyCell then the x element needs to go to the left most emptyCell.
					Otherwise, x is already sorted and no swap is needed but the x index needs to be incremented.
				*/
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