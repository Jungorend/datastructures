#include "array.h"

int main() {
  int n,i;
  struct Array *arr = ArrayCreate();

  int test[5] = {1,2,3,4,5};
  ArrayAppendValues(arr, test, 5);
  ArrayAppendValues(arr, test, 5);
  ArrayInsert(arr, -3, 100);
  ArrayRemoveValue(arr, -1);

  printf("Size of array: %d\nLength of Array: %d\n", arr->size, arr->length);
  ArrayDisplay(arr);

  return 0;
}
