#include <stdio.h>

/*
	Prints contents of array given size and contents.
*/
void printArr(int arr[], unsigned int arrSize)
{
	for (unsigned char i = 0; i < arrSize; i++)
	{
		printf("%i\n", arr[i]);
	}
}

void sort(int* y, unsigned int ySize)
{
	for (int i = 0; i < (ySize - 1); i++)
	{
		if (y[i] > y[i + 1])
		{
			int temp = y[i];
			y[i] = y[i + 1];
			y[i + 1] = temp;
		}
	}
}

void swap(int* x, int* y, unsigned int xPos)
{
	int temp = y[0];
	y[0] = x[xPos];
	x[xPos] = temp;
}

void dualSort(int* x, int* y, unsigned int xSize, unsigned int ySize)
{
	for (int i = 0; i < xSize; i++)
	{
		if (x[i] > y[0])
		{
			swap(x, y, i);
			sort(y, ySize);
		}
	}
}

int main()
{
	int x[] = {1, 4, 7, 8, 10};
	int y[] = {2, 3, 9};
	unsigned int xSize = sizeof(x) / sizeof(int), ySize = sizeof(y) / sizeof(int);
	
	dualSort(x, y, xSize, ySize);

	printArr(x, xSize);
	printf("\n");
	printArr(y, ySize);


	return 0;
}