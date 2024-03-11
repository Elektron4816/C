#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = ERROR;
  if (check_true(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows != 1) {
        matrix_t B = {0};
        s21_create_matrix(A->rows, A->columns, &B);
        for (int i = 0, sign = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            calculate_minor(A->matrix, B.matrix, i, j, A->rows);
            sign = ((i + j) % 2 == 0) ? 1 : (-1);
            result->matrix[i][j] =
                sign * calculate_determinant(&B, A->rows - 1);
            res = OK;
          }
        }
        s21_remove_matrix(&B);
      } else {
        result->matrix[0][0] = 1;
      }
    } else {
      res = CALCULATION_ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}
