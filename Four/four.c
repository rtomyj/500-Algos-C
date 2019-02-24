#include <stdio.h>

/*
	Merging in C isn't simple. This approach has two arrays being passed as arguments.
	One array will contain the contents to be sorted, the other will hold the sorted contents.
	Unsorted array is traversed and depending on how the user wants the binary array to be sorted
	at position i will be pushed to the left or right side of the sorted array.
*/
void method_one(unsigned char items[], unsigned char sizeArr, unsigned char sortedItems[], unsigned char leftMostValue)
{
	unsigned const char rightMostValue = (leftMostValue == 0) ? 1 : 0;	// determinse the right most value (!leftMostValue)
	unsigned char leftMostIndex = 0, rightMostIndex = sizeArr -1;	// starting positions for inserting left and right values in sorte darray
	
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
*/
void method_two(unsigned char items[], unsigned size, unsigned char leftMostValue)
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


/*
	Prints contents of array given size and contents.
*/
void printArr(unsigned char arr[], unsigned char arrSize)
{
	for (unsigned char i = 0; i < arrSize; i++)
	{
		printf("%i\n", arr[i]);
	}
}


int main()
{
	unsigned char items[] = { 1, 0, 1, 0, 1, 0, 0, 1 };
	const unsigned char arrSize = sizeof(items) / sizeof(char);
	unsigned char sortedItems[arrSize];

	//method_one(items, arrSize, sortedItems, 0);
	method_two(items, arrSize, 1);
	printArr(items, arrSize);

	return 0;
}