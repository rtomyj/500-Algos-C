#include <stdio.h>
#include <stdlib.h>
#include "libs/algorithm.h"
#include "libs/print.h"

/*
	The goal is to sort the functon then look at adjacent elements to see if they are equal. 
	If so then there are dups in the original array.
	
	Constant Sapce O(N).
*/
void sortThenFind(int items[], unsigned int size)
{
	qsort(items, size, sizeof(int), compareIntAsc);
	for (unsigned int i = 1; i < size; i++)
	{
		if (items[i -1] == items[i])
		{
			printf("Dup element is %i \n", items[i]);
			break;
		}
	}
}


/*
	Keeps an array that acts as a hash. All indices are going to unique unless there is a dup value.
	
	Not constant space. O(N) complexity.
*/
void hashAndGrab(int items[], unsigned int size, unsigned int maxN)
{
	const int max = findMax(items, size);
	unsigned short set[max];
	for (unsigned int i = 0; i < size; i++)
	{
		int hashIndex = items[i] - 1;
		
		if (set[hashIndex] == 1)	printf("Dup element is %i \n", items[i]);
		else	set[hashIndex] = 1;
	}
}


int main(){
	int items[] = { 1, 2, 3, 4, 2 };
	const unsigned int size = sizeof(items) / sizeof(int);
	sortThenFind(items, size);

	int items2[] = { 1, 2, 3, 4, 4 };
	const unsigned int size2 = sizeof(items2) / sizeof(int);
	hashAndGrab(items2, size2, 5);

}