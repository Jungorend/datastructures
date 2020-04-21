#include <stdlib.h>
#include <stdio.h>

/*
 * As part of learning data structures, the goal is to implement
 * a dynamic array that has some conveniences you'd see in a higher level language
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

int main() {
  struct Array *arr;
  int n,i;
  printf("Enter size of array: ");
  scanf("%d", &arr->size);
  arr->A = (int *) malloc(arr->size * sizeof(int));
  arr->length = 0;

  printf("Enter how many numbers: ");
  scanf("%d",&n);
  checkOverflow(arr, n);
  arr->length = arr->length + n;

  printf("Enter all elements: ");
  for(i=0;i<n;i++) {
    scanf("%d", &arr->A[i]);
  }



  printf("Size of array: %d\nLength of Array: %d\n", arr->size, arr->length);

  Display(*arr);

  return 0;
}
