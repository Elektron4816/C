#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = ERROR;
  if (check_true(A)) {
    if (A->rows != A->columns) {
      res = CALCULATION_ERROR;
    } else {
      double det = 0.0;
      res = s21_determinant(A, &det);
      if (fabs(det) < 1e-6 || res != OK) {
        res = CALCULATION_ERROR;
      } else {
        matrix_t B = {0};
        matrix_t C = {0};
        s21_calc_complements(A, &B);
        s21_transpose(&B, &C);
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->rows; j++) {
            result->matrix[i][j] = C.matrix[i][j] / det;
          }
        }
        s21_remove_matrix(&C);
        s21_remove_matrix(&B);
        res = OK;
      }
    }
  } else {
    res = ERROR;
  }
  return res;
}