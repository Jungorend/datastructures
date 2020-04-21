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

void Display(struct Array arr) {
  int i;
  printf("Elements are\n");
  for(i=0;i<arr.length;i++) {
    printf("%d ", arr.A[i]);
  }
}

void checkOverflow(struct Array *arr, int newValues) {
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

struct Array* create() {
  struct Array *arr = (struct Array*)malloc(sizeof(struct Array));
  arr->size = ARRAY_INITIAL_SIZE;
  arr->length = 0;
  arr->A = (int *)malloc(arr->size * sizeof(int));
  return arr;
}

void delete(struct Array *arr) {
  free(arr->A);
  free(arr);
}

void append(struct Array *arr, int value[], int numOfValues) {
  checkOverflow(arr, numOfValues);
  for(int i =0; i < numOfValues; i++) {
    arr->A[arr->length] = value[i];
    arr->length++;
  }
}

int main() {
  int n,i;
  struct Array *arr = create();

  /*
  printf("Enter how many numbers: ");
  scanf("%d",&n);
  checkOverflow(arr, n);
  arr->length = arr->length + n;

  printf("Enter all elements: ");
  for(i=0;i<n;i++) {
    scanf("%d", &arr->A[i]);
  }
  */

  int test[5] = {1,2,3,4,5};
  append(arr, test, 5);
  append(arr, test, 5);
  printf("Size of array: %d\nLength of Array: %d\n", arr->size, arr->length);

  Display(*arr);

  return 0;
}
