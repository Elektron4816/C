#include "s21_math.h"

long double s21_exp(double x) {
  double i = 1.0;
  double e = 1.0;
  double res = 1.0;
  while (s21_fabs(e) > 1e-10) {
    e = e * x / i;
    i++;
    res = res + e;
  }
  return res;
}
