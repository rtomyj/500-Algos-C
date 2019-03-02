#include <stdio.h>
#include "../algorithm.h"
#include "../print.h"

void dualSort(int* x, int* y, unsigned int xSize, unsigned int ySize)
{
	for (int i = 0; i < xSize; i++)
	{
		if (x[i] > y[0])
		{
			swap(x, y, i, 0);
			sort(y, ySize);
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
	printf("\n");
	printArr(y, ySize, INT);

	return 0;
}