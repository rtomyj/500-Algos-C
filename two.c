#include <stdio.h>
#include "libs/print.h"
#include "libs/algorithm.h"

struct map
{
	int key;
	int value;
};

struct subArr findZeroSum(int *items, unsigned size)
{
	int sum;
	struct map graph[size + 1];
	graph[0].key = 0;
	graph[0].value = -1;
	unsigned current = 1;
	struct subArr subArr;

	for (unsigned ind = 0; ind < size; ind++)
	{
		int item = items[ind];
		if (item == 0)
		{
			int* zeroSum = malloc( sizeof(int) );
			subArr.arr = zeroSum;
			subArr.size = 1;
			return subArr;
		}
		sum += item;

		graph[current].


	}

	subArr.size = 0;
	return subArr;
}

int main()
{
	int items[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
	unsigned size = sizeof(items) / sizeof(int);

	struct subArr subArr = findZeroSum(items, size);
	printArr(subArr.arr, subArr.size, INT);

	return 0;
}