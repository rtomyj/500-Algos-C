#include <stdio.h>
#include <stdlib.h>
#include "libs/algorithm.h"
#include "libs/print.h"


/*
	Originally we are given an array of index mapping to an operand, we can create an array of operands mapping to an index to hash operands. In the hashed arrays case, the indexes are operands found in the original array and the value will be the index it is found in the original array.

	Looping through the original array will get us <operandA>. Checking the hash will let us know if we have seen <operandB> given by equation operandA + operandB = sum. Since A+B=B+A we can both build the hash and check the hash in a single loop.
*/
void hashAndFind(int* items, unsigned int size, int sum)
{
	int max = findMax(items, size);
	int min = findMin(items, size);
	const unsigned hashLen = (max - min) + 2;
	printf("%i %i %i\n", max, min, hashLen);

	unsigned int hash[hashLen];	// hash array will map position number with the index that number is found in items

	for (unsigned int i = 0; i < hashLen; i++)	hash[i] = -1;	// inits hash with empty vals

	for (unsigned int i = 0; i < size; i++)
	{
		
		int operand = sum - items[i];
		int hashIndex = operand - min;
		hash[items[i] - min] = i;

		if (hashIndex >= 0 && hashIndex < hashLen && hash[hashIndex] != -1)
		{
			printf("Sum %i (index=%i) + %i (index=%i) = %i\n", items[i], i, operand, hash[hashIndex], sum);
			//break;
		}
	}
}

int main()
{
	int items[] = {8, 7, 2, 5, 3, 1, 10, -100, 110, 0, 0};
	const unsigned int size = sizeof(items) / sizeof(int);
	const int sum = 0;

	hashAndFind(items,size, sum);

	return 0;
}
