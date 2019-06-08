#ifndef ALGO_H
#define ALGO_H
#include <stdio.h>
#include <stdlib.h>
#include "cust_structs.h"

void swapElement(int *, int *, unsigned, unsigned);
void swapElement2(int *, unsigned, unsigned);
void reSort(int *, unsigned);
int compareIntAsc(const void *, const void *);
int compareIntDesc(const void *, const void *);
int findMax(int *, unsigned);
int findMin(int *, unsigned);
struct subArr splice(int *, unsigned, unsigned, unsigned);

#endif
