#include "s21_math.h"

long double s21_tan(double i) {
  long double res;
  while (i > S21_PI || i < -S21_PI) {
    i += i > S21_PI ? -2 * S21_PI : 2 * S21_PI;
  }
  res = s21_sin(i) / s21_cos(i);
  return res;
}