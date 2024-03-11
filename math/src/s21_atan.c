#include "s21_math.h"

long double s21_get_atan(double x) {
  double res = x;
  double tmp = x;
  for (int i = 1; i < 50; i++) {
    tmp = -1 * tmp * x * x * (2 * i - 1) / (2 * i + 1);
    res += tmp;
  }
  return res;
}

long double s21_atan(double x) {
  double res = 0;
  if (x < 1.0 && x > -1.0) {
    res = s21_get_atan(x);
  } else if (x == 1.0) {
    res = S21_PI / 4;
  } else if (x == -1.0) {
    res = -S21_PI / 4;
  } else if (x > 1.0) {
    res = S21_PI / 2 - s21_get_atan(1 / x);
  } else if (x < -1.0) {
    res = -S21_PI / 2 - s21_get_atan(1 / x);
  }
  return res;
}