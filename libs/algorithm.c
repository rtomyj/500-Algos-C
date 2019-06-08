#include "algorithm.h"

void swapElement(int *x, int *y, unsigned xPos, unsigned yPos)
{
	const int temp = y[yPos];
	y[yPos] = x[xPos];
	x[xPos] = temp;
}

void swapElement2(int *x, unsigned aPos, unsigned bPos)
{
	const int temp = x[aPos];
	x[aPos] = x[bPos];
	x[bPos] = temp;
}

void reSort(int *y, unsigned ySize)
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
	int l = *((int *)left);
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

int findMax(int *items, unsigned size)
{
	int max = items[0];
	for (unsigned i = 1; i < size; i++)
	{
		if (items[i] > max)	max = items[i];
	}

	return max;
}

int findMin(int *items, unsigned size)
{
	int min = items[0];
	for (unsigned i = 1; i < size; i++)
	{
		if (items[i] < min)	min = items[i];
	}

	return min;
}


struct subArr splice(int *items, unsigned size, unsigned start, unsigned end)
{
	int *sub = malloc( (end - start) * sizeof(int));
	unsigned subArrPos = 0;

	if (end > size) end = size;

	for (unsigned ind = start; ind < end; ind++)
	{
		sub[subArrPos] = items[ind];
		++subArrPos;
	}

	struct subArr subArr;
	subArr.arr = sub;
	subArr.size = subArrPos;

	return subArr;
}
