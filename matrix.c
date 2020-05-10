#include "matrix.h"


void MatrixDestroy(struct Matrix *x) {
  free(x->m);
  free(x);
  x = 0;
}

// This function takes the the <X>MatrixGet function for whatever you want to display
// So for a Diagonal, DiagonalMatrixGet
// It will then display appropriately for that matrix
void MatrixPrint(struct Matrix *x, int getValue(struct Matrix *x, int i, int j)) {
  for(int i = 0; i < x->length; i++) {
    for (int j = 0; j < x->length; j++) {
      printf("%d ", getValue(x, i, j));
    }
    printf("\n");
  }
}

// Diagonal Matrix
struct Matrix* DiagonalMatrixCreate(int size) {
  struct Matrix *x = malloc(sizeof(struct Matrix));
  x->length = size;
  x->m = malloc(x->length * sizeof(int));
  return x;
}
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
struct Matrix* LowerTriMatrixCreate(int size) {
  struct Matrix *x = malloc(sizeof(struct Matrix));
  x->length = size * (size - 1) / 2;
  x->m = malloc(x->length * sizeof(int));
  return x;
}

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
