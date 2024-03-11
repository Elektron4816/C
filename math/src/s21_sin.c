#include "s21_math.h"

long double s21_sin(double i) {
  while (i > S21_PI || i < -S21_PI) {
    i += i > S21_PI ? -2 * S21_PI : 2 * S21_PI;
  }
  i = (long double)i;
  double res = i;
  double k = 1;
  double tmp = i;

  while (s21_fabs(res / tmp) > 1e-20) {
    res = -1 * res * i * i / (2 * k * (2 * k + 1));
    k = k + 1;
    tmp = tmp + res;
  }
  return tmp;
}