#include <stdio.h>
#include "libs/print.h"

/*
	Merging in C isn't simple. This approach has two arrays being passed as arguments.
	One array will contain the contents to be sorted, the other will hold the sorted contents.
	
	Unsorted array is traversed. If sorting by 0 is desired then leftMostValue should be 0. If sorting starting with 1 is 
	desired then leftMostValue shoudld be 1.

	Not constant space. O(N) time.
*/
void useOppositeEnds(unsigned char items[], unsigned char sizeArr, unsigned char sortedItems[], unsigned char leftMostValue)
{
	unsigned const char rightMostValue = (leftMostValue == 0) ? 1 : 0;	// determinse the right most value (!leftMostValue)
	// starting positions for inserting left and right values in sorted darray
	unsigned char leftMostIndex = 0, rightMostIndex = sizeArr -1;
	
	for (unsigned char i = 0; i < sizeArr; i++)
	{
		if (items[i] == leftMostValue)
		{
			sortedItems[leftMostIndex] = leftMostValue;
			++leftMostIndex;
		}
		else
		{
			sortedItems[rightMostIndex] = rightMostValue;
			--rightMostIndex;
		}
		
	}

}


/*
	Fills the left most values on top fo the original array.
	Counts how many left most values there are and stores it in totalLeftMost.
	Fills the right most values starting at totalLeftMost position.

	Constant space. O(N) time.
*/
void fillAndCount(unsigned char items[], unsigned size, unsigned char leftMostValue)
{
	unsigned char totalLeftMost = 0;
	unsigned const char rightMostValue = (leftMostValue == 0) ? 1 : 0;

	for (unsigned char i = 0; i < size; i++)
	{
		if (items[i] == leftMostValue)
		{
			items[totalLeftMost] = leftMostValue;
			++totalLeftMost;
		}
	}

	for (unsigned int i = totalLeftMost; i < size; i++)
	{
		items[i] = rightMostValue;
	}
}



int main()
{
	unsigned char items[] = { 1, 0, 1, 0, 1, 0, 0, 1 };
	const unsigned char arrSize = sizeof(items) / sizeof(char);
	unsigned char sortedItems[arrSize];

	fillAndCount(items, arrSize, 0);
	printArr(items, arrSize, CHAR);
	useOppositeEnds(items, arrSize, sortedItems, 1);
	printArr(sortedItems, arrSize, CHAR);

	return 0;
}