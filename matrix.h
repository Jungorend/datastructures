#include <stdio.h>
#include <stdlib.h>

struct Matrix {
  int length;
  int* m;
};

void MatrixDestroy(struct Matrix *x);
void MatrixPrint(struct Matrix *x, int getValue(struct Matrix *x, int i, int j));

struct Matrix* DiagonalMatrixCreate(int size);
void DiagonalMatrixSet(struct Matrix *x, int i, int j, int value);
int DiagonalMatrixGet(struct Matrix *x, int i, int j);

struct Matrix* LowerTriMatrixCreate(int size);
void LowerTriMatrixSet(struct Matrix *x, int i, int j, int value);
int LowerTriMatrixGet(struct Matrix *x, int i, int j);
