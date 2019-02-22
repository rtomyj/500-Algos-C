#include <stdio.h>
// int sortedItems[ sizeof(items) / sizeof(int) ] = { 0 };

/*
	Merging in C isn't simple. This approach has two arrays being passed as arguments.
	One array will contain the contents to be sorted, the other will hold the sorted contents.
	Unsorted array is traversed and depending on how the user wants the binary array to be sorted
	at position i will be pushed to the left or right side of the sorted array.
*/
void method_one(int items[], int sizeArr, int sortedItems[], int leftMostValue)
{
	int rightMostValue = (leftMostValue == 0) ? 1 : 0;	// determinse the right most value (!leftMostValue)
	int leftMostIndex = 0, rightMostIndex = sizeArr -1;	// starting positions for inserting left and right values in sorte darray
	
	for (int i = 0; i < sizeArr; i++)
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
	Prints contents of array given size and contents.
*/
void printArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("%i\n", arr[i]);
	}
}

int main()
{
	int items[] = { 1, 0, 1, 0, 1, 0, 0, 1 };
	const int arrSize = sizeof(items) / sizeof(int);
	int sortedItems[arrSize];

	method_one(items, arrSize, sortedItems, 0);
	printArr(sortedItems, arrSize);

	return 0;
}