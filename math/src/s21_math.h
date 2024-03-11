#ifndef _S21_MATH_H_
#define _S21_MATH_H_

#define EXP 2.71828182845904523536028747135266250
#define S21_PI 3.14159265358979323846264338327950288
#define S21_NAN __builtin_nanf("0x7fc00000")
#define S21_INF __builtin_huge_valf()

#include <stdio.h>

int s21_abs(int j);
long double s21_fabs(double j);
long double s21_floor(double k);
long double s21_ceil(double k);
long double s21_sin(double i);
long double s21_cos(double i);
long double s21_tan(double i);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

#endif
