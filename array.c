#include <stdlib.h>
#include <stdio.h>

#define ARRAY_INITIAL_SIZE 16

/*
 * As part of learning data structures, the goal is to implement
 * a dynamic array that has some conveniences you'd see in a higher level language

 Right now you want to call create to initialize it, delete to remove it when done.
 */

struct Array {
  int *A;
  int size;
  int length;
};

void ArrayDisplay(struct Array *arr) {
  int i;
  printf("Elements are\n");
  for(i=0;i<arr->length;i++) {
    printf("%d ", arr->A[i]);
  }
}

void ArrayCheckOverflow(struct Array *arr, int newValues) {
  // This function checks to see if the newValues worth of elements
  // will cause it to access un-allocated space, and if so resolves it
  if(arr->size < (arr->length + newValues)) {
    int *tmpA;
    int tmpSize = arr->size;
    int newlength = arr->length + newValues;
    while(tmpSize < newlength) {
      tmpSize = tmpSize * tmpSize;
    }

    // Copy over to a temporary array and then replace it
    tmpA = (int *)malloc(tmpSize * sizeof(int));
    for(int i = 0; i < arr->length; i++) {
      tmpA[i] = arr->A[i];
    }

    free(arr->A);
    arr->A = tmpA;
    arr->size = tmpSize;
  }
}

struct Array* ArrayCreate() {
  struct Array *arr = (struct Array*)malloc(sizeof(struct Array));
  arr->size = ARRAY_INITIAL_SIZE;
  arr->length = 0;
  arr->A = (int *)malloc(arr->size * sizeof(int));
  return arr;
}

void ArrayDelete(struct Array *arr) {
  free(arr->A);
  free(arr);
}

void ArrayAppend(struct Array *arr, int value) {
  ArrayCheckOverflow(arr, 1);
  arr->A[arr->length] = value;
  arr->length++;
}

void ArrayAppendValues(struct Array *arr, int value[], int numOfValues) {
  ArrayCheckOverflow(arr, numOfValues);
  for(int i =0; i < numOfValues; i++) {
    arr->A[arr->length] = value[i];
    arr->length++;
  }
}

void ArrayInsert(struct Array *arr, int index, int value) {
  if(index >= arr->length) {
    ArrayAppend(arr, value);
    return;
  }
  // Convert negative indices to their positive equivalent
  while(index < 0) {
    index = arr->length + index + 1;
  }

  ArrayCheckOverflow(arr,1);
  int i = arr->length - 1;
  while(i >= index) {
    arr->A[i+1] = arr->A[i];
    i--;
  }
  arr->A[index] = value;
  arr->length++;
}

int main() {
  int n,i;
  struct Array *arr = ArrayCreate();

  int test[5] = {1,2,3,4,5};
  ArrayAppendValues(arr, test, 5);
  ArrayAppendValues(arr, test, 5);
  ArrayInsert(arr, -12, 100);

  printf("Size of array: %d\nLength of Array: %d\n", arr->size, arr->length);

  ArrayDisplay(arr);

  return 0;
}
