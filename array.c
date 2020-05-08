#include "array.h"


/*
 * As part of learning data structures, the goal is to implement
 * a dynamic array that has some conveniences you'd see in a higher level language

 Right now you want to call create to initialize it, delete to remove it when done.
 */

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

void ArrayRemoveValue(struct Array *arr, int index) {
  while(index < 0)
    index = arr->length + index;
  for(;index < arr->length; index++) {
    arr->A[index] = arr->A[index+1];
  }
  arr->length = arr->length - 1;
}

// Returns the first instance of value, if none, -1.
int ArrayLinearSearch(struct Array *arr, int value) {
  for (int i =0; i < arr->length; i++) {
    if (arr->A[i] == value)
      return i;
  }
  return -1;
}

int ArrayBinarySearch(struct Array *arr, int value) {
  int h=arr->length-1;
  int l = 0;
  int mid;
  int output;

  while(l <= h) {
    mid = ((h-l) / 2) + l;
    output = arr->A[mid];

    if(output == value) {
      return mid;
    } else if (output > value) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

int ArrayMax(struct Array *arr) {
  int max = arr->A[0];
  for (int i=0; i < arr->length; i++) {
    if (arr->A[i] > max)
      max = arr->A[i];
  }
  return max;
}

int ArrayMin(struct Array *arr) {
  int min = arr->A[0];
  for (int i=0; i < arr->length; i++) {
    if(arr->A[i] < min)
      min = arr->A[i];
  }
  return min;
}

int ArraySum(struct Array *arr) {
  int result = 0;
  for(int i=0; i < arr->length; i++) {
    result = result + arr->A[i];
  }
  return result;
}

int ArrayAverage (struct Array * arr) {
  int sum = ArraySum(arr);
  return sum / arr->length;
}

bool ArrayIsSorted (struct Array * arr) {
  int x = arr->A[0];
  for (int i=1; i < arr->length; i++) {
    if(x > arr->A[i])
      return false;
    x = arr->A[i];
  }
  return true;
}
