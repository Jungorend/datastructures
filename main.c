#include "linkedlist.h"

int main() {
  int A[6] = {10,13,5,4,3,2};
  struct LL *l = createLL(A,6);

  LLDisplay(l);
  return 0;
}
