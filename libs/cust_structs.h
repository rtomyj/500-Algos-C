#ifndef CUST_STRUCT_H
#define CUST_STRUCT_H
#include <stdlib.h>

typedef enum INT_TYPE
{
	INT = 0,
	SHORT = 1,
	CHAR = 2,
} INT_TYPE;

typedef struct subArr
{
	int* arr;
	unsigned size;
} subArr;

typedef struct dynamicArrMeta
{
	unsigned maxCap;
	unsigned step;
	unsigned nextUnused;
	unsigned sizeOfElement;
} dynamicArrMeta;

void *resizeDynArray(void *, dynamicArrMeta *);
dynamicArrMeta newDynamicArrMeta(unsigned, unsigned, unsigned);

#endif