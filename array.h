#include <stdlib.h>
#include <stdio.h>

// The starting array size
#define ARRAY_INITIAL_SIZE 16

struct Array {
  int *A;
  int size;
  int length;
};

void ArrayDisplay(struct Array *arr);
void ArrayCheckOverflow(struct Array *arr, int newValues);
struct Array* ArrayCreate();
void ArrayDelete(struct Array *arr);
void ArrayAppend(struct Array *arr, int value);
void ArrayAppendValues(struct Array *arr, int value[], int numOfValues);
void ArrayInsert(struct Array *arr, int index, int value);
void ArrayRemoveValue(struct Array *arr, int index);
int ArrayLinearSearch(struct Array *arr, int value);
