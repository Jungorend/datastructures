#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// The starting array size
#define ARRAY_INITIAL_SIZE 16

struct Array {
  int *A;
  int size;
  int length;
};

struct Array* ArrayCreate();
void ArrayDisplay(struct Array *arr);
void ArrayCheckOverflow(struct Array *arr, int newValues);
void ArrayDelete(struct Array *arr);
void ArrayAppend(struct Array *arr, int value);
void ArrayAppendValues(struct Array *arr, int value[], int numOfValues);
void ArrayInsert(struct Array *arr, int index, int value);
void ArrayRemoveValue(struct Array *arr, int index);
int ArrayLinearSearch(struct Array *arr, int value);
int ArrayBinarySearch(struct Array *arr, int value);
int ArrayMax(struct Array *arr);
int ArrayMin(struct Array *arr);
int ArraySum(struct Array *arr);
int ArrayAverage(struct Array *arr);
bool ArrayIsSorted(struct Array *arr);
struct Array* ArrayMerge(struct Array *arr1, struct Array *arr2);
