#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(-3), abs(-3));
  ck_assert_int_eq(s21_abs(-235), abs(-235));
  ck_assert_int_eq(s21_abs(-1313431), abs(-1313431));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-34255), abs(-34255));
}
END_TEST

START_TEST(s21_fabs_test) {
  ck_assert_double_eq(s21_fabs(-3.14), fabs(-3.14));
  ck_assert_double_eq(s21_fabs(-2356.45456), fabs(-2356.45456));
  ck_assert_double_eq(s21_fabs(0.0), fabs(0.0));
}

START_TEST(s21_ceil_test) {
  ck_assert_double_eq(s21_ceil(-3.14), ceil(-3.14));
  ck_assert_double_eq(s21_ceil(-3.58), ceil(-3.58));
  ck_assert_double_eq(s21_ceil(-1.0), ceil(-1.0));
  ck_assert_double_eq(s21_ceil(0.0), ceil(0.0));
  ck_assert_double_eq(s21_ceil(1.0), ceil(1.0));
  ck_assert_double_eq(s21_ceil(3.14), ceil(3.14));
  ck_assert_double_eq(s21_ceil(3.58), ceil(3.58));
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_double_eq(s21_floor(-3.14), floor(-3.14));
  ck_assert_double_eq(s21_floor(-3.58), floor(-3.58));
  ck_assert_double_eq(s21_floor(-1.0), floor(-1.0));
  ck_assert_double_eq(s21_floor(0.0), floor(0.0));
  ck_assert_double_eq(s21_floor(1.0), floor(1.0));
  ck_assert_double_eq(s21_floor(3.14), floor(3.14));
  ck_assert_double_eq(s21_floor(3.58), floor(3.58));
}
END_TEST

START_TEST(s21_sin_test) {
  ck_assert_float_eq(s21_sin(3), sin(3));
  ck_assert_float_eq(s21_sin(3.14), sin(3.14));
  ck_assert_float_eq(s21_sin(0.0), sin(0.0));
  ck_assert_float_eq(s21_sin(-3.14), sin(-3.14));
}
END_TEST

START_TEST(s21_cos_test) {
  ck_assert_float_eq(s21_cos(3), cos(3));
  ck_assert_float_eq(s21_cos(3.14), cos(3.14));
  ck_assert_float_eq(s21_cos(0.0), cos(0.0));
  ck_assert_float_eq(s21_cos(-3.14), cos(-3.14));
  ck_assert_float_eq(s21_cos(10.34), cos(10.34));
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_float_eq(s21_tan(3), tan(3));
  ck_assert_float_eq(s21_tan(3.14), tan(3.14));
  ck_assert_float_eq(s21_tan(0.0), tan(0.0));
  ck_assert_float_eq(s21_tan(-3.14), tan(-3.14));
  ck_assert_float_eq(s21_tan(14.23), tan(14.23));
}
END_TEST

START_TEST(s21_exp_test) {
  ck_assert_float_eq(s21_exp(3), exp(3));
  ck_assert_float_eq(s21_exp(3.14), exp(3.14));
  ck_assert_float_eq(s21_exp(0.0), exp(0.0));
  ck_assert_float_eq(s21_exp(-3.14), exp(-3.14));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_float_eq(s21_log(3), log(3));
  ck_assert_float_eq(s21_log(3.14), log(3.14));
  ck_assert_float_eq(s21_log(0.0), log(0.0));
  ck_assert_float_eq(s21_log(1), log(1));
  ck_assert_float_nan(s21_log(-1));
  ck_assert_float_eq(s21_log(99999), log(99999));
}
END_TEST

START_TEST(s21_pow_test) {
  ck_assert_float_eq(s21_pow(2, 10), pow(2, 10));
  ck_assert_float_eq(s21_pow(3.14, 7), pow(3.14, 7));
  ck_assert_float_eq(s21_pow(0.0, 0.0), pow(0.0, 0.0));
  ck_assert_float_eq(s21_pow(-3, -3), pow(-3, -3));
  ck_assert_float_eq(s21_pow(4.0, -2.0), pow(4.0, -2.0));
}
END_TEST

START_TEST(s21_sqrt_test) {
  ck_assert_float_eq(s21_sqrt(121), sqrt(121));
  ck_assert_float_eq(s21_sqrt(121.121), sqrt(121.121));
  ck_assert_float_eq(s21_sqrt(1.0), sqrt(1.0));
  ck_assert_float_nan(s21_sqrt(-4));
  ck_assert_float_eq(s21_sqrt(2346236), sqrt(2346236));
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_float_eq(s21_fmod(11, 4), fmod(11, 4));
  ck_assert_float_eq(s21_fmod(34.34, 7), fmod(34.34, 7));
  ck_assert_float_eq(s21_fmod(34.34, 7.5), fmod(34.34, 7.5));
  ck_assert_float_eq(s21_fmod(-34.34, 7.5), fmod(-34.34, 7.5));
  ck_assert_float_eq(s21_fmod(-34.34, -7.5), fmod(-34.34, -7.5));
  ck_assert_float_eq(s21_fmod(34.34, -7.5), fmod(34.34, -7.5));
}
END_TEST

START_TEST(s21_atan_test) {
  ck_assert_float_eq(s21_atan(1.0), atan(1.0));
  ck_assert_float_eq(s21_atan(-1.0), atan(-1.0));
  ck_assert_float_eq(s21_atan(0.0), atan(0.0));
  ck_assert_float_eq(s21_atan(-3.14), atan(-3.14));
  ck_assert_float_eq(s21_atan(3.14), atan(3.14));
  ck_assert_float_eq(s21_atan(54321.54321), atan(54321.54321));
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_float_eq(s21_asin(1.0), asin(1.0));
  ck_assert_float_eq(s21_asin(-1.0), asin(-1.0));
  ck_assert_float_eq(s21_asin(0.0), asin(0.0));
  ck_assert_float_eq(s21_asin(0.5), asin(0.5));
  ck_assert_float_eq(s21_asin(-0.5), asin(-0.5));
  ck_assert_float_nan(s21_asin(14));
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_float_eq(s21_acos(1.0), acos(1.0));
  ck_assert_float_eq(s21_acos(-1.0), acos(-1.0));
  ck_assert_float_eq(s21_acos(0.314), acos(0.314));
  ck_assert_float_eq(s21_acos(-0.314), acos(-0.314));
  ck_assert_float_eq(s21_acos(0), acos(0));
  ck_assert_float_nan(s21_acos(14));
}
END_TEST

// Функция создания набора тестов.
Suite *s21_math_suite_create(void) {
  Suite *s21_math = suite_create("s21_math");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *s21_math_test = tcase_create("s21_math_test");
  // Добавление теста в группу тестов.
  tcase_add_test(s21_math_test, s21_abs_test);
  tcase_add_test(s21_math_test, s21_fabs_test);
  tcase_add_test(s21_math_test, s21_ceil_test);
  tcase_add_test(s21_math_test, s21_floor_test);
  tcase_add_test(s21_math_test, s21_sin_test);
  tcase_add_test(s21_math_test, s21_cos_test);
  tcase_add_test(s21_math_test, s21_tan_test);
  tcase_add_test(s21_math_test, s21_exp_test);
  tcase_add_test(s21_math_test, s21_log_test);
  tcase_add_test(s21_math_test, s21_pow_test);
  tcase_add_test(s21_math_test, s21_sqrt_test);
  tcase_add_test(s21_math_test, s21_fmod_test);
  tcase_add_test(s21_math_test, s21_atan_test);
  tcase_add_test(s21_math_test, s21_asin_test);
  tcase_add_test(s21_math_test, s21_acos_test);
  // Добавление теста в тестовый набор.
  suite_add_tcase(s21_math, s21_math_test);

  return s21_math;
}

int main(void) {
  Suite *s21_math = s21_math_suite_create();
  SRunner *s21_math_suite_runner = srunner_create(s21_math);
  int failed_count;
  srunner_run_all(s21_math_suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  failed_count = srunner_ntests_failed(s21_math_suite_runner);
  srunner_free(s21_math_suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}