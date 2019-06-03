#ifndef CUST_STRUCT_H
#define CUST_STRUCT_H

typedef enum INT_TYPE
{
	INT = 0,
	SHORT = 1,
	CHAR = 2,
} INT_TYPE;

typedef struct subArr
{
	int *arr;
	unsigned size;
} subArr;

#endif