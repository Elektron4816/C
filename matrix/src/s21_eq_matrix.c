#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res_eq = FAILURE;
  if (check_true(A) && check_true(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      res_eq = SUCCESS;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          if (fabs((A->matrix)[i][j] - (B->matrix)[i][j]) > 1e-7) {
            res_eq = FAILURE;
            break;
          }
        }
      }
    }
  }
  return res_eq;
}
