/*
	Since all we need to do is find one occurence of a subarray with 0 sum, we don't need to store all occurences and we
	can break out once we find the first occurence.

	The best way to think about this problem is to visualize a graph where the y value is the sum of all preceeding items.

	For instance: [2, -1, 3, -2, 1]
	Will yield:

								#
								#		#
						#		#	#	#
						#	#	#	#	#
						__________
	x-val			1	2	3	4	5
	Looking at the graph we can see that the delta (change in value) of 0 is given using the elements [-1, 3, -2].

	In other words: starting at x value 1 where the sum (y value) is 2, if we add -1, 3, and -2, we will get the sum
	(y value) of 2 again. So the sub array [-1, 3, -2] produces the net change of 0 (zero sum).
'''

'''
	Finds sub array with zero sum for a given sequence and returns it.
*/

#include <stdio.h>
#include "libs/print.h"
#include "libs/algorithm.h"
#include "libs/hash_set.h"


unsigned char doesZeroSumSubArrExist(int *items, unsigned size)
{
	int sum = 0;	// running sum of all seen items through traversal
	struct HashSet *set = getHashSet();	// keeps track of all sums

	/*
		Iterates through all values of array.
		Keeps a total of all the sums.
		If the set already holds the sum (DUP) then there is a sub array with zero sum.
	*/
	for (unsigned ind = 0; ind < size; ind++)
	{
		int item = items[ind];

		if (item == 0)	return 1;	// if an element in itmes array is 0 then it is its own 0 sum subarray

		sum += item;

		if (insert(set, sum) == DUP)	return 1;	// returns 1 (true) if sum was already in set
	}

	return 0;	// returns 0 (false) if element sum doesn't repeat while iterating through array (no zero sum sub array)
}


int main()
{
	int items[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
	unsigned size = sizeof(items) / sizeof(int);

	unsigned char result = doesZeroSumSubArrExist(items, size);

	if (result == 1)
	{
		printf("Zero sum sub array exists\n");
	}
	return 0;
}