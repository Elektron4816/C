#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = ERROR;
  int ok = 0;
  if (check_true(A) && check_true(B)) {
    if (A->columns == B->rows) {
      ok = A->columns;
      res = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < ok; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            res = OK;
          }
        }
      }
    } else {
      res = CALCULATION_ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}