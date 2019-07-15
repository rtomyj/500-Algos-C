
#ifndef HASH_SET_H
#define HASH_SET_H
#include <stdlib.h>
#include "cust_structs.h"


#include <stdlib.h>

typedef struct HashSet
{
	int *set;
	int *record;

	unsigned setSize;
	unsigned numberOfRecords;
	unsigned char zeroHasBeenAdded;
} HashSet;

typedef enum insertStatus
{
	SUCCESS = 0,
	DUP = 1,
	COLLISION = 2
} insertStatus;

void *resizeDynArray(void *, dynamicArrMeta *);
dynamicArrMeta newDynamicArrMeta(unsigned, unsigned, unsigned);

unsigned char checkSet(struct HashSet *, int);
unsigned char repopulateSet(struct HashSet *);
void resizeSet(struct HashSet *);
unsigned char insert(struct HashSet *, int);
struct HashSet * getHashSet();

#endif