#include "cust_structs.h"

void *resizeDynArray(void *array, dynamicArrMeta *meta)
{
	if(meta->nextUnused == meta->maxCap)
	{
		meta->maxCap += meta->step;
		array = realloc(array, meta->maxCap * meta->sizeOfElement);
		meta->totalSize = meta->sizeOfElement * meta->maxCap;
	}

	return array;
}


dynamicArrMeta newDynamicArrMeta(unsigned cap, unsigned step, unsigned sizeOfElement)
{
	dynamicArrMeta meta;
	meta.maxCap = cap;
	meta.step = step;
	meta.sizeOfElement = sizeOfElement;
	meta.nextUnused = 0;
	meta.totalSize = sizeOfElement * cap;

	return meta;
}


/* 
unsigned char checkStatus(struct hash *hash, int value)
{
	unsigned char insertResult = 0;	// 0 - insertion success, 1 - value was already in hash (dup), 2 - collision

	if (value == 0)
	{
		if (hash->zeroHasBeenAdded == 1)	insertResult = 1;
		else	hash->zeroHasBeenAdded = 1;
	}
	else
	{
		if (hash->hash[value % hash->hashSize] != 0)
		{
			if (hash->hash[value % hash->hashSize] == value)
			{
				insertResult = 1;	// dup
			}
			else	insertResult = 2;	// collision
		}
		else
		{
			if (hash->zeroHasBeenAdded == 1)	insertResult = 2;	// collision
		}
	}

	return insertResult;
}

unsigned char repopulateHash(struct hash *hash)
{
	for (unsigned ind = 0; ind < hash->recordIndex; ind++)
	{
		printf("%d --- %d, ", hash->record[ind], hash->record[ind]);
		if (checkStatus(hash, hash->record[ind]) == 2){
			return 2;
		}
		else hash->hash[hash->record[ind] % hash->hashSize] = hash->record[ind];
	}

	int *record = (int *) malloc(sizeof(int) * hash->hashSize);
	
	for (unsigned ind = 0; ind < hash->recordIndex; ind++)
	{
		record[ind]= hash->record[ind];
	}

	free(hash->record);
	hash->record = record;

	return 0;
}

void resizeHash(struct hash *hash)
{
	hash->hashSize = hash->hashSize * 1.4 + 2;
	free(hash->hash);
	
	hash->hash = (int *) calloc(sizeof(int), hash->hashSize);
}


unsigned char insert(struct hash *hash, int value)
{
	unsigned char insertResult = 0;

	insertResult = checkStatus(hash, value);

	if (checkStatus(hash, value) == 2)
	{
		resizeHash(hash);

		hash->record[hash->recordIndex] = value;
		hash->recordIndex++;

		while(1)
		{
			if (repopulateHash(hash) == 0)	break;
			else	resizeHash(hash);
		}

		printArr(hash->hash, hash->hashSize, INT);
	}
	else
	{
		hash->hash[value % hash->hashSize] = value;
		hash->record[hash->recordIndex] = value;
		hash->recordIndex++;
		printArr(hash->hash, hash->hashSize, INT);
	}

	return insertResult;
}
*/