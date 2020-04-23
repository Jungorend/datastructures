#include "array.h"

int main() {
  int n,i;
  struct Array *arr = ArrayCreate();

  int test[9] = {1,2,3,4,5,7,8,9,10};
  ArrayAppendValues(arr, test, 9);

  printf("Linear Search for 4: %d\n", ArrayLinearSearch(arr, 4));
  printf("Linear Search for 7: %d\n", ArrayLinearSearch(arr, 6));
  printf("Binary Search for 4: %d\n", ArrayBinarySearch(arr, 4));
  printf("Binary Search for 7: %d\n", ArrayBinarySearch(arr, 6));


  printf("Size of array: %d\nLength of Array: %d\n", arr->size, arr->length);
  ArrayDisplay(arr);

  return 0;
}
