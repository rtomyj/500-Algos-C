#include <stdio.h>
#include <stdlib.h>

int sortAsc(const void *, const void *);
int sortDesc(const void *, const void *);
void printArray(const int[], const unsigned);

int main()
{
	int numbers[6] = {8, 7, 2, 5, 3, 1};
	qsort(numbers, sizeof(numbers) / sizeof(*numbers), sizeof(*numbers), sortAsc);
	qsort(numbers, sizeof(numbers) / sizeof(*numbers), sizeof(*numbers), sortDesc);
	printArray(numbers, sizeof(numbers));
	return 0;
}

int sortAsc(const void* left, const void* right)
{
	int l = *((int*)left);
	int r = *((int *)right);
	if (l < r)	return -1;
	else if (l > r) return 1;
	return 0;

}

int sortDesc(const void *left, const void *right)
{
	int l = *((int *)left);
	int r = *((int *)right);
	if (l > r)
		return -1;
	else if (l < r)
		return 1;
	return 0;
}

void printArray(const int numbers[], const unsigned arrSize)
{
	unsigned numElements = arrSize/sizeof(*numbers);

	for (unsigned i = 0; i < numElements; i++)
	{
		printf("%d\t", numbers[i]);
	}
}