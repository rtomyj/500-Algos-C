#ifndef ALGO_H
#define ALGO_H
#include <stdio.h>
#include <stdlib.h>

struct subArr
{
	int* arr;
	unsigned size;
};

void swapElement(int*, int*, unsigned int, unsigned);
void swapElement2(int*, unsigned int, unsigned);
void reSort(int *, unsigned int);
int compareIntAsc(const void*, const void*);
int compareIntDesc(const void*, const void*);
int findMax(int*, unsigned int);
int findMin(int*, unsigned int);
struct subArr splice(int*, unsigned, unsigned, unsigned);

#endif
