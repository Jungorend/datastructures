#include "array.h"

int main() {
  int n,i;
  struct Array *arr1 = ArrayCreate();
  struct Array *arr2 = ArrayCreate();

  int test[5] = {1,3,5,9,10};
  int test2[7] = {2,4,6,7,11,12,13};
  ArrayAppendValues(arr1, test, 5);
  ArrayAppendValues(arr2, test2, 7);

  struct Array *arr3 = ArrayMerge(arr1, arr2);
  ArrayDisplay(arr3);


  return 0;
}
