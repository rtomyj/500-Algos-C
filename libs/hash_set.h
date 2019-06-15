
#ifndef HASH_SET_H
#define HASH_SET_H
#include <stdlib.h>
#include "cust_structs.h"


#include <stdlib.h>

struct HashSet
{
	int *set;
	int *record;

	unsigned hashSize;
	unsigned numberOfRecords;
	unsigned char zeroHasBeenAdded;
} HashSet;

void *resizeDynArray(void *, dynamicArrMeta *);
dynamicArrMeta newDynamicArrMeta(unsigned, unsigned, unsigned);

unsigned char checkSet(struct HashSet *, int);
unsigned char repopulateSet(struct HashSet *);
void resizeSet(struct HashSet *);
unsigned char insert(struct HashSet *, int);
struct HashSet * getHashSet();

#endif