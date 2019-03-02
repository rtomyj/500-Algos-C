#include <stdio.h>
#include "../algorithm.h"
#include "../print.h"

// constant space
void sortThenFind(int items[], unsigned int size)
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


void hashAndGrab(int items[], unsigned int size, unsigned int maxN)
{
	unsigned short set[maxN];
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
	//sortThenFind(items, size);
	hashAndGrab(items, size, 5);

}