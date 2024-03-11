#include "s21_math.h"

long double s21_asin(double x) {
  double res = 0;
  if (x <= 1 && x >= -1) {
    res = s21_atan(x / (s21_sqrt(1 - x * x)));
  } else {
    res = S21_NAN;
  }
  return res;
}