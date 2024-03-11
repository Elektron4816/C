#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (y == 0) {
    res = 0 / 0.0;
  } else {
    long int delim = x / y;
    res = x - delim * y;
  }

  return res;
}