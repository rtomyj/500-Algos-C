#include <stdio.h>
// int sortedItems[ sizeof(items) / sizeof(int) ] = { 0 };

/*
	Since merging in C is a pain, initializing the sorted array with the right most value first
	then adding the leftmost elements as needed is a better approach.
*/
void method_one(int items[], int sizeArr, int sortedItems[], int leftMostValue)
{
	int rightMostValue = (leftMostValue == 0) ? 1 : 0;
	int leftMostIndex = 0, rightMostIndex = sizeArr -1;

	
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


void printArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("%lu \n", arr[i]);
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