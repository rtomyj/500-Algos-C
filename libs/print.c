#include <stdio.h>
#include "print.h"

/*
	Prints contents of array given size and contents.
*/
void printArr(void *startingMemLocation, unsigned arrSize, INT_TYPE intType)
{
	printf("[");
	if (arrSize > 0)
	{
		switch (intType)
			{
				case INT:
					printf("%d", *(int *) startingMemLocation);
					break;
				case SHORT:
					printf("%d", *(short *) startingMemLocation);
					break;
				case CHAR:
					printf("%d", *(char *) startingMemLocation);
					break;

				default:
					break;
			}

		for (unsigned i = 1; i < arrSize; i++)
		{
			int *nextIntLocation;
			short *nextShortLocation;
			char *nextCharLocation;


			switch (intType)
			{
				case INT:
					nextIntLocation = (int *) startingMemLocation + i;
					printf(", %d", *nextIntLocation);
					break;
				case SHORT:
					nextShortLocation = (short* ) startingMemLocation + i;
					printf(", %d", *nextShortLocation);
					break;
				case CHAR:
					nextCharLocation = (char *) startingMemLocation + i;
					printf(", %d", *nextCharLocation);
					break;

				default:
					break;
			}
		}
	}
	printf("]\n");
}

void printSubArrs(subArr *subArrs, unsigned size)
{
	for (unsigned ind = 0; ind < size; ind++)
	{
		printArr(subArrs[ind].arr, subArrs[ind].size, INT);
	}
}