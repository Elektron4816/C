#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  result->rows = rows;
  result->columns = columns;
  int res = ERROR;
  if (result->rows < 1 || result->columns < 1) {
    res = ERROR;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < result->rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        for (int j = 0; j < result->columns; j++) {
        }
      }
      res = OK;
    } else {
      res = ERROR;
    }
  }
  return res;
}
