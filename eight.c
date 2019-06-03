/*
	This algorithm is similar to something like, "Find the longest sub array with sum = x". The trick is to imagine
	a graph and find the two points that when connected have a slope of 0 (ie no change).

	For example: Given sequence [1, 0, 1, 1, 0, 1, 0] we can map the occurence of 0 with -1 and 1 with +1. We also must
	start at a certain value - 0 in our case:
		0 -> -1
		1 -> +1
		sum -> 0

	Obviously the greatest sub array with even number of 0's and 1's of the above sequence
	is [0, 1, 1, 0, 1, 0]. Drawing the graph we get

		3
		2		| | | |#| |#| |
		1		|#| |#|#|#|#|#|
		0		-------------
		-1

	The y value of index 1 is 0 and the y value of index 6 is 1... Connecting the points we get a change of 1.
	Not quite what we wanted. But index 0 has a y value of 1 which is a pattern we can use.

	In other words sum[0] == sum[6] (no change) so there is a sub array from range [1, 6] ([0 + 1, 6])
	that has equal 0's and 1's.
*/

#include <stdio.h>
#include "libs/print.h"

struct subArr getMaxLenSubarr(int* items, unsigned size)
{
	int sum = 0;
	int SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[size * 2][2];
	int sumValue[] = {-1, 1};

	for (int ind = 0; ind < size * 2; ind++)	SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][0] = -1;

	SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[size][0] = 0;

	for (int ind = 0; ind < size; ind++)
	{
		int val = items[ind];
		sum += sumValue[val];
		int offset = sum + size;

		if (SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[offset][0] == -1)
		{
			SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[offset][0] = ind + 1;
			SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[offset][1] = -1;
		}
		else	SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[offset][1] = ind + 1;
	}

	int maxLen = 0;
	int left = 0, right = 0;
	for (int ind = 0; ind < size * 2; ind++)
	{
		if (SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][0] != -1
				&& SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][1] != -1
				&& SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][1] - SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][0] > maxLen)
		{
			maxLen = SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][1] - SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][0];
			left = SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][0];
			right = SUM_OFFSET_maps_LEFT_RIGHT_OCCURANCE[ind][1];
		}
	}

	int subArr[maxLen];
	for (int ind = 0; ind < maxLen; ind++)	subArr[ind] = items[ind + left];

	struct subArr ra;
	ra.arr = subArr;
	ra.size = maxLen;
	return ra;

}

int main()
{
	int items[] = {1, 0, 1, 1, 0, 1, 0};
	unsigned size = sizeof(items) / sizeof(int);
	struct subArr ra = getMaxLenSubarr(items, size);
	printArr(ra.arr, ra.size, INT);

	int items2[] = {0, 0, 0, 0, 0, 0, 0};
	size = sizeof(items2) / sizeof(int);
	ra = getMaxLenSubarr(items2, size);
	printArr(ra.arr, ra.size, INT);

	return 0;
}