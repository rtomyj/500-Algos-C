#include <stdio.h>
#include "libs/algorithm.h"
#include "libs/print.h"

/*
	The Y array is always either sorted or one element is messing up the sort. If we resort the array then we can assume 
	the left most integer is the least. This will help us decide if we need to swap x[i] with y[0]. 
*/
void dualSort(int* x, int* y, unsigned int xSize, unsigned int ySize)
{
	for (int i = 0; i < xSize; i++)
	{
		if (x[i] > y[0])
		{
			swapElement(x, y, i, 0);
			reSort(y, ySize);
		}
	}
}


int main()
{
	int x[] = {1, 4, 7, 8, 10};
	int y[] = {2, 3, 9};
	unsigned int xSize = sizeof(x) / sizeof(int), ySize = sizeof(y) / sizeof(int);
	
	dualSort(x, y, xSize, ySize);

	printArr(x, xSize, INT);
	printArr(y, ySize, INT);

	return 0;
}