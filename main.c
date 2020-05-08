#include "array.h"

int main() {
  int n,i;
  struct Array *arr = ArrayCreate();

  int test[9] = {1,2,3,4,5,7,8,9,10};
  ArrayAppendValues(arr, test, 9);

  if(ArrayIsSorted(arr))
    printf("Sorted\n");
  else
    printf("Not Sorted\n");


  ArrayAppendValues(arr, test, 2);
  if(ArrayIsSorted(arr))
    printf("Sorted\n");
  else
    printf("Not Sorted\n");

  return 0;
}
