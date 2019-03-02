#ifndef PRINT_H
#define PRINT_H
typedef enum INT_TYPE {
	INT = 0,
	SHORT = 1,
	CHAR = 2,
} INT_TYPE;

void printArr(void*, unsigned int, INT_TYPE);

#endif