#include "s21_math.h"

long double s21_sqrt(double x) {
  double res = 0;

  if (x == 0) {
    res = 0.0;
  } else if (x < 0) {
    res = 0.0 / 0.0;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}
