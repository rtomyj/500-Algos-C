#include <stdio.h>

/*
	Prints contents of array given size and contents.
*/
void printArr(int arr[], unsigned int arrSize)
{
	for (unsigned int i = 0; i < arrSize; i++)
	{
		printf("%i\n", arr[i]);
	}
}


void swap(int* x, int* y, unsigned int xPos, unsigned yPos)
{
	int temp = y[yPos];
	y[yPos] = x[xPos];
	x[xPos] = temp;
}

void sort(int* y, unsigned int ySize)
{
	for (int i = 0; i < (ySize - 1); i++)
	{
		if (y[i] > y[i + 1])
		{
			swap(y, y, i, i + 1);
		}
	}
}

// constant space
void method_one(int items[], unsigned int size)
{
	sort(items, size);
	for (unsigned int i = 1; i < size; i++)
	{
		if (items[i -1] == items[i])
		{
			printf("Dup element is %i \n", items[i]);
			break;
		}
	}
}


void method_two(int items[], unsigned int size, unsigned int maxN)
{
	unsigned short set[maxN];
	for (unsigned int i = 0; i < size; i++)
	{
		int hashIndex = items[i] % maxN;
		if (set[hashIndex] == 1)
		{
			printf("Dup element is %i \n", items[i]);
		}
		else
		{
			set[hashIndex] = 1;
		}
	}
}

int main(){
	int items[] = { 1, 2, 3, 4, 2 };
	const unsigned int size = sizeof(items) / sizeof(int);
	//method_one(items, size);
	method_two(items, size, 4);

}