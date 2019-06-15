#include "hash_set.h"

unsigned char checkSet(struct HashSet *hashSet, int value)
{
	unsigned hashValue = value % hashSet->hashSize;

	if (value == 0)
	{
		if (hashSet->set[hashValue] != 0)	return 2;	// collision
		if (hashSet->zeroHasBeenAdded == 1)	return 1;	// dup
		else	return 0;
	}
	else
	{
		if (hashSet->set[hashValue] != 0)
		{
			if (hashSet->set[hashValue] == value)	return  1;	// dup
			else	return 2;	// collision
		}
		else	return 0;
	}
}


unsigned char repopulateSetresizeSet(struct HashSet *hashSet)
{
	for (unsigned ind = 0; ind < hashSet->numberOfRecords; ind++)
	{
		if (checkSet(hashSet, hashSet->record[ind]) == 2)
		{
			return 2;
		}
		else hashSet->set[hashSet->record[ind] % hashSet->hashSize] = hashSet->record[ind];
	}

	int *record = (int *) realloc(hashSet->record, sizeof(int) * hashSet->hashSize);
	hashSet->record = record;

	return 0;
}

void resizeSet(struct HashSet *hashSet)
{
	hashSet->hashSize = hashSet->hashSize * 1.2 + 2;
	free(hashSet->set);
	
	hashSet->set = (int *) calloc(sizeof(int), hashSet->hashSize);
}


unsigned char insert(struct HashSet *hashSet, int value)
{
	unsigned char insertResult = 0;
	if ( (insertResult = checkSet(hashSet, value)) == 2)
	{
		resizeSet(hashSet);
		hashSet->record[hashSet->numberOfRecords] = value;
		++hashSet->numberOfRecords;

		while(1)
		{
			if (repopulateSetresizeSet(hashSet) == 0)	break;
			else	resizeSet(hashSet);
		}
	}
	else
	{
		hashSet->set[value % hashSet->hashSize] = value;
		hashSet->record[hashSet->numberOfRecords] = value;
		++hashSet->numberOfRecords;
	}

	if (value == 0)
	{
			hashSet->zeroHasBeenAdded = 1;
	}

	return insertResult;
}

struct HashSet * getHashSet()
{
	unsigned initSize = 5;
	struct HashSet *hashSet = (struct HashSet *) malloc(sizeof(struct HashSet));
	hashSet->set = (int *) calloc(sizeof(int), initSize);
	hashSet->record = (int *) malloc(sizeof(int) * initSize);
	hashSet->hashSize = initSize;
	hashSet->numberOfRecords = 0;
	hashSet->zeroHasBeenAdded = 0;

	return hashSet;
}