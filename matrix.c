#include "matrix.h"

struct Matrix* MatrixCreate(int size) {
  struct Matrix *x = malloc(sizeof(struct Matrix));
  x->length = size;
  x->m = malloc(x->length * sizeof(int));
  return x;
}

void MatrixDestroy(struct Matrix *x) {
  free(x->m);
  free(x);
  x = 0;
}

void MatrixPrint(struct Matrix *x, int (*f)(struct Matrix *x, int i, int j)) {
  for(int i = 0; i < x->length; i++) {
    for (int j = 0; j < x->length; j++) {
      printf("%d ", (*f)(x, i, j));
    }
    printf("\n");
  }
}

// Diagonal Matrix
void DiagonalMatrixSet(struct Matrix *x, int i, int j, int value) {
  if(i == j) {
    x->m[i-1] = value;
  }
}

int DiagonalMatrixGet(struct Matrix *x, int i, int j) {
  if (i == j)
    return x->m[i-1];
  else
    return 0;
}

// Lower Triangular Matrix
void LowerTriMatrixSet(struct Matrix *x, int i, int j, int value) {
  if(i >= j) {
    x->m[i*(i-1)/2 + j-1] = value;
  }
}

int LowerTriMatrixGet(struct Matrix *x, int i, int j) {
  if (i >= j) {
    return x->m[i*(i-1)/2 + j-1];
  } else
    return 0;
}
