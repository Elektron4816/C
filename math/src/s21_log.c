#include "s21_math.h"

long double s21_log(double x) {
  double lg = 1.0;
  int i = 0;
  double res = 0.0;
  if (x > 0.0) {
    for (int k = 0; k < 10; k++) {
      lg = res;
      res = lg + 2 * (x - s21_exp(lg)) / (x + s21_exp(lg));
    }
    res = res + i;
  } else if (x == 0) {
    res = -S21_INF;
  } else {
    res = S21_NAN;
  }
  return res;
}