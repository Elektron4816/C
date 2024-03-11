#include "s21_math.h"

int s21_abs(int j) {
  if (j < 0) {
    j = j * (-1);
  } else {
    j = j;
  }
  return j;
}