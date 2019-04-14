#include "algorithm.h"

void swapElement(int* x, int* y, unsigned int xPos, unsigned yPos)
{
	const int temp = y[yPos];
	y[yPos] = x[xPos];
	x[xPos] = temp;
}

void swapElement2(int *x, unsigned int aPos, unsigned bPos)
{
	const int temp = x[aPos];
	x[aPos] = x[bPos];
	x[bPos] = temp;
}

void reSort(int* y, unsigned int ySize)
{
	for (int i = 0; i < (ySize - 1); i++)
	{
		if (y[i] > y[i + 1])
		{
			swapElement(y, y, i, i + 1);
		}
	}
}

int compareIntAsc(const void* left, const void* right)
{
	int l = *((int*)left);
	int r = *((int *)right);
	if (l < r)	return -1;
	else if (l > r) return 1;
	return 0;

}

int compareIntDesc(const void *left, const void *right)
{
	int l = *((int *)left);
	int r = *((int *)right);
	if (l > r)
		return -1;
	else if (l < r)
		return 1;
	return 0;
}

int findMax(int* items, unsigned int size)
{
	int max = items[0];
	for (unsigned int i = 1; i < size; i++)
	{
		if (items[i] > max)	max = items[i];
	}

	return max;
}

int findMin(int* items, unsigned int size)
{
	int min = items[0];
	for (unsigned int i = 1; i < size; i++)
	{
		if (items[i] < min)	min = items[i];
	}

	return min;
}