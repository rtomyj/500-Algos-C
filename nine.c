#include <stdio.h>
#include "libs/algorithm.h"
#include "libs/print.h"

void swapSort(int[], unsigned, int, unsigned*);
void sort(int[], unsigned, unsigned);

/*
	Main method.
	Completes algorithm 9.
*/
int main()
{
	int items[] = {0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0};
	const unsigned size = sizeof(items) / sizeof(int);

	sort(items, size, 0);	// sorts 0's, 1's and 2's in ascending order
	printArr(items, size, INT);

	sort(items, size, 1);	// sorts 0's, 1's and 2's in descending order
	printArr(items, size, INT);
	return 0;
}


/*
	Sorts an array that contains 0's, 1's and 2's.
	Sorting should use constant space and be done in linear time.
*/
void sort(int items[], unsigned size, unsigned asc)
{
	/*
		Default values for ascending sort.
	*/
	int leftMostValue = 0;
	int increment = 1;

	/*
		Changes values for descending sort.
	*/
	if (asc != 0)
	{
		leftMostValue = 2;
		increment = -1;
	}

	unsigned unsortedInd = 0;
	swapSort(items, size, leftMostValue, &unsortedInd);	// partially sorts array (either 0 (asc) or 2 (desc) are all sorted)
	swapSort(items, size, (leftMostValue + increment), &unsortedInd);	// array is sorted
}


/*
	Sorts an array partially by swapping a desired element with an index not yet sorted.
	Ideally to sort an array this method will be called multiple times.
	If there are n possible values for an element then this method should be called n-1 times.
*/
void swapSort(int items[], unsigned size, int lookingFor, unsigned* unsortedInd)
{
	for (int ind = *unsortedInd; ind < size; ind++)
	{
		/*
			Swaps current value with the value at the unsorted index if current value is the current wanted value.
		*/
		if (lookingFor == items[ind])
		{
			swapElement2(items, *unsortedInd, ind);
			++(*unsortedInd);	// array is partially sorted, increment index to get to new unsorted index
		}
	}
}