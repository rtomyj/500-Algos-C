#include <stdio.h>
#include "libs/print.h"
#include "libs/algorithm.h"

/*
	The problem is very simple.
	Multiplying two positive numbers result in a positive number.
	Multiplying two negative numbers result in a positive number.
	If we sort the array given we can compare the multiples of the two largest negative and positive numbers.
*/

int *findMaxMult(int *items, unsigned size)
{
	int min[2] = {0, 0}, max[2] = {0, 0};	// default values for min and max elements of array
	int *maxMult = malloc(sizeof(int) * 2);	// array holding max multiples
	

	/*
		Handles arrays with sizes less than 2
	*/
	if (size == 0)
	{
		maxMult[0] = 0;
		maxMult[1] = 0;
	}
	else if(size == 1)
	{
		maxMult[1] = items[0];
		maxMult[0] = 1;
	}
	/*
		Handles arrays with sizes of 2 and greater
	*/
	else
	{
		/*
			Cycles through array. Finds the max two elements and the min two elements.
			We don't need to sort the array since we only need one traversal (O(n)) to find the min/max elements.
		*/
		for (unsigned ind = 0; ind < size; ind++)
		{
			int item = items[ind];	// current element

			if (item < min[0])
			{
				min[1] = min[0];
				min[0] = item;
			}
			else if(item < min[1])	min[1] = item;
			else if (item > max[1])
			{
				max[0] = max[1];
				max[1] = item;
			}
			else if (item > max[0])	max[0] = item;
		}

		/*
			Compares the multiples of both the min elements and max elements to see which multiple is bigger
		*/
		if (min[0] * min[1] < max[0] * max[1])
		{
			maxMult[0] = max[0];
			maxMult[1] = max[1];
		}
		else
		{
			maxMult[0] = min[0];
			maxMult[1] = min[1];
		}
	}
	
	return maxMult;	// returns biggest multiple
}

int main()
{
	int items[] = {-10, -3, 5, 6, -2, 0};
	unsigned size = sizeof(items) / sizeof(int);

	printArr(findMaxMult(items, size), 2, INT);
	return 0;
}