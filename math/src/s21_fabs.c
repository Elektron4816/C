#include "s21_math.h"

long double s21_fabs(double j) {
  if (j < 0) {
    j = j * (-1);
  } else {
    j = j;
  }
  return j;
}