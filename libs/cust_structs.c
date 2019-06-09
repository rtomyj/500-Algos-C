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