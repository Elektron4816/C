#include "s21_matrix.h"

int check_true(matrix_t *any_matrix) {
  int res = 1;
  if (any_matrix->rows < 1 || any_matrix->columns < 1) {
    res = 0;
  }
  return res;
}