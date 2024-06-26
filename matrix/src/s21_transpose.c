#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = ERROR;
  if (check_true(A)) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
        res = OK;
      }
    }
  } else {
    res = ERROR;
  }

  return res;
}