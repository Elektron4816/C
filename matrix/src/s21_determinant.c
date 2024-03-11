#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = ERROR;
  if (check_true(A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
        res = OK;
      } else if (A->rows == 2) {
        *result = (A->matrix[0][0] * A->matrix[1][1] -
                   A->matrix[0][1] * A->matrix[1][0]);
        res = OK;
      } else {
        *result = calculate_determinant(A, A->rows);
        res = OK;
      }
    } else {
      res = CALCULATION_ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}

double calculate_determinant(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t minor = {0};
  double result = 0;
  s21_create_matrix(size, size, &minor);

  for (int sign = 1, i = 0; i < size; i++, sign *= (-1)) {
    calculate_minor(A->matrix, minor.matrix, 0, i, size);
    result += sign * A->matrix[0][i] * calculate_determinant(&minor, size - 1);
  }
  s21_remove_matrix(&minor);

  return result;
}

void calculate_minor(double **A, double **minor, int excluded_row,
                     int excluded_column, int size) {
  for (int i = 0, row = 0; row < size; row++) {
    for (int j = 0, column = 0; column < size; column++) {
      if (row != excluded_row && column != excluded_column) {
        minor[i][j++] = A[row][column];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}