#include "hash_set.h"

unsigned char checkSet(struct HashSet *hashSet, int value)
{
	unsigned hashValue = value % hashSet->setSize;

	if (value == 0)
	{
		if (hashSet->set[hashValue] != 0)	return COLLISION;
		if (hashSet->zeroHasBeenAdded == 1)	return DUP;
		else	return SUCCESS;
	}
	else
	{
		if (hashSet->set[hashValue] != 0)
		{
			if (hashSet->set[hashValue] == value)	return  DUP;
			else	return COLLISION;
		}
		else	return SUCCESS;
	}
}


unsigned char repopulateSetresizeSet(struct HashSet *hashSet)
{
	for (unsigned ind = 0; ind < hashSet->numberOfRecords; ind++)
	{
		if (checkSet(hashSet, hashSet->record[ind]) == 2)
		{
			return COLLISION;
		}
		else hashSet->set[hashSet->record[ind] % hashSet->setSize] = hashSet->record[ind];
	}

	int *record = (int *) realloc(hashSet->record, sizeof(int) * hashSet->setSize);
	hashSet->record = record;

	return SUCCESS;
}

void resizeSet(struct HashSet *hashSet)
{
	hashSet->setSize = hashSet->setSize * 1.2 + 2;
	free(hashSet->set);
	
	hashSet->set = (int *) calloc(sizeof(int), hashSet->setSize);
}


unsigned char insert(struct HashSet *hashSet, int value)
{
	unsigned char insertResult = SUCCESS;
	if ( (insertResult = checkSet(hashSet, value)) == COLLISION)
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
		hashSet->set[value % hashSet->setSize] = value;
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
	hashSet->setSize = initSize;
	hashSet->numberOfRecords = 0;
	hashSet->zeroHasBeenAdded = 0;

	return hashSet;
}