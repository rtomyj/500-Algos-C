#include <stdio.h>
#include "print.h"

/*
	Prints contents of array given size and contents.
*/
void printArr(void* startingMemLocation, unsigned int arrSize, INT_TYPE intType)
{

	for (unsigned int i = 0; i < arrSize; i++)
	{
		int* nextIntLocation;
		short* nextShortLocation;
		char* nextCharLocation;

		switch (intType)
		{
			case INT:
				nextIntLocation = (int*) startingMemLocation
			 + i;
				printf("%d \n", *nextIntLocation);
				break;
			case SHORT:
				nextShortLocation = (short*) startingMemLocation
			 + i;
				printf("%d \n", *nextShortLocation);
				break;
			case CHAR:
				nextCharLocation = (char *) startingMemLocation
			 + i;
				printf("%d \n", *nextCharLocation);
				break;
		
			default:
				break;
		}
	}
}