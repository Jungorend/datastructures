#include <stdio.h>
#include <stdlib.h>

struct Matrix {
  int length;
  int* m;
};

struct Matrix* MatrixCreate(int size);
void MatrixDestroy(struct Matrix *x);
void MatrixPrint(struct Matrix *x, int (*f)(struct Matrix *x, int i, int j));

void DiagonalMatrixSet(struct Matrix *x, int i, int j, int value);
int DiagonalMatrixGet(struct Matrix *x, int i, int j);
void DiagonalMatrixPrint(struct Matrix *x);

void LowerTriMatrixSet(struct Matrix *x, int i, int j, int value);
int LowerTriMatrixGet(struct Matrix *x, int i, int j);
