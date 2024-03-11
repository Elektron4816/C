#include "s21_math.h"

long double s21_acos(double x) {
  double res = 0.0;

  if (x >= -1 && x <= 1) {
    res = S21_PI / 2 - s21_asin(x);
  } else {
    res = S21_NAN;
    ;
  }

  return res;
}