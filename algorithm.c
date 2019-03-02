#include "algorithm.h"

void swap(int* x, int* y, unsigned int xPos, unsigned yPos)
{
	int temp = y[yPos];
	y[yPos] = x[xPos];
	x[xPos] = temp;
}

void sort(int* y, unsigned int ySize)
{
	for (int i = 0; i < (ySize - 1); i++)
	{
		if (y[i] > y[i + 1])
		{
			swap(y, y, i, i + 1);
		}
	}
}