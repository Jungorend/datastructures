#include "matrix.h"

int main() {
  struct Matrix *x = MatrixCreate(5);

  DiagonalMatrixSet(x, 1,1,1);
  DiagonalMatrixSet(x, 2,2,2);
  DiagonalMatrixSet(x, 4,4,4);
  DiagonalMatrixSet(x, 5,5,7);

  MatrixPrint(x, DiagonalMatrixGet);

  MatrixDestroy(x);

  return 0;
}
