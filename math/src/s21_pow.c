#include "s21_math.h"

long double s21_pow(double x, double y) {
  double res = 0;
  int flag = 0;
  if (x < 0) {
    x = s21_fabs(x);
    flag = 1;
  }
  if (y < 0) {
    res = 1 / s21_exp(-y * s21_log(x));
  } else if (y == 0) {
    res = 1;
  } else {
    res = s21_exp(y * s21_log(x));
  }
  if (s21_fmod(y, 2) != 0 && flag) {
    res = -res;
  }
  return res;
}

// Добавить обработку при x < 0