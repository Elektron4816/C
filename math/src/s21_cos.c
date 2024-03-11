#include "s21_math.h"

long double s21_cos(double i) {
  long double res;
  while (i > S21_PI || i < -S21_PI) {
    i += i > S21_PI ? -2 * S21_PI : 2 * S21_PI;
  }
  res = s21_sin((S21_PI / 2) - i);
  return res;
}