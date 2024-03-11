#include "s21_math.h"

long double s21_floor(double k) {
  if (k == (long long int)k) {
    k = (long long int)k;
  } else if (k > 0) {
    k = (long long int)(k);
  } else {
    k = (long long int)(k - 1);
  }
  return k;
}