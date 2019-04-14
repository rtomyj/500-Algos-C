#include <stdio.h>
#include "libs/algorithm.h"
#include "libs/print.h"

void swapSort(int items[], unsigned size, int lookingFor, unsigned* unsortedIndex)
{
	for (int index = *unsortedIndex; index < size; index++)
	{
		if (lookingFor == items[index])
		{
			swapElement2(items, *unsortedIndex, index);
			++(*unsortedIndex);
		}
	}
}

void sort(int items[], unsigned size, unsigned asc)
{
	int lookingFor = 0;
	int increment = 1;

	if (asc != 0)
	{
		lookingFor = 2;
		increment = -1;
	}

	unsigned unsortedIndex = 0;
	swapSort(items, size, lookingFor, &unsortedIndex);

	lookingFor += increment;
	swapSort(items, size, lookingFor, &unsortedIndex);
}

int main()
{
	int items[] = {0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0};
	const unsigned size = sizeof(items) / sizeof(int);

	sort(items, size, 0);
	printArr(items, size, INT);

	sort(items, size, 1);
	printArr(items, size, INT);
	return 0;
}