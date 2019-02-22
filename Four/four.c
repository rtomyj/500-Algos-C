#include <stdio.h>
// int sortedItems[ sizeof(items) / sizeof(int) ] = { 0 };

/*
	Since merging in C is a pain, initializing the sorted array with the right most value first
	then adding the leftmost elements as needed is a better approach.
*/
int* method_one(int items[], int leftMostValue)
{
	int rightMostValue = (leftMostValue == 0) ? 1 : 0;
	const int sizeArr = sizeof(items);
	int total = 0;
	static int sortedItems[ sizeArr ];	// static keyword allows arrays to be returned by method

	for (int i = 0; i < sizeArr; i++)
	{
		sortedItems[i] = rightMostValue;
	}
	
	for (int i = 0; i < sizeArr; i++)
	{
		if (items[i] == leftMostValue)
		{
			sortedItems[total] = leftMostValue;
			++total;
		}
	}
	return sortedItems;

}


void printArr(int arr[])
{
	for (int i = 0; i < sizeof(arr); i++)
	{
		printf("%lu \n", arr[i]);
	}
}

int main()
{
	int items[8] = { 1, 0, 1, 0, 1, 0, 0, 1 };

	int* sortedItems = method_one(items, 1);
	printArr(sortedItems);

	return 0;
}