#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"

START_TEST(test_1) {
  char string[255] = "sin(1)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, sin(1));
}
END_TEST

START_TEST(test_2) {
  char string[255] = "4/-2+3*-2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, -8.000000);
}
END_TEST

START_TEST(test_4) {
  char string[255] = "1.56+2.44-1*2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(test_5) {
  char string[255] = "sin(1)+cos(1)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, sin(1) + cos(1));
}
END_TEST

START_TEST(test_6) {
  char string[255] = "asin(0.5)-acos(0.5)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, asin(0.5) - acos(0.5));
}
END_TEST

START_TEST(test_7) {
  char string[255] = "2^3+-6=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(test_8) {
  char string[255] = "tan(0.2)/atan(0.5)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, tan(0.2) / atan(0.5));
}
END_TEST

START_TEST(test_9) {
  char string[255] = "ln(10)+(2-3)/log(10)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 1.3025850);
}
END_TEST

START_TEST(test_10) {
  char string[255] = "sqrt(121)+5mod2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 12);
}
END_TEST

START_TEST(test_11) {
  char string[255] = "3^4-sin(1)-2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 78.158529);
}
END_TEST

START_TEST(test_12) {
  char string[255] = "cos(1)+2^4+3=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 19.540302);
}
END_TEST

START_TEST(test_13) {
  char string[255] = "sin(1+1)*-2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, -1.818595);
}
END_TEST

START_TEST(test_14) {
  char string[255] = "asin(1)/cos(1)/2/sin(1)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 1.727484);
}
END_TEST

START_TEST(test_15) {
  char string[255] = "asin(1)*cos(1)*2*sin(1)=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 1.428321);
}
END_TEST

START_TEST(test_16) {
  char string[255] = "2--2+(3-+2)++4*+3=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 17);
}
END_TEST

START_TEST(test_17) {
  char string[255] = "((2+3)-(sin(1)+4)*2^3)/2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, -14.365884);
}
END_TEST

START_TEST(test_18) {
  char string[255] = "2/log(1)=";
  double result = 0;
  int check_error = 0;
  result = main_func(string, 0, &check_error);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(check_error, 0);
}
END_TEST

START_TEST(test_19) {
  char string[255] = "asin(2)=";
  double result = 0;
  int check_error = 0;
  result = main_func(string, 0, &check_error);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(check_error, 2);
}
END_TEST

START_TEST(test_20) {
  char string[255] = "acos(2)=";
  double result = 0;
  int check_error = 0;
  result = main_func(string, 0, &check_error);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(check_error, 2);
}
END_TEST

START_TEST(test_21) {
  char string[255] = "2^-2=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 0.25);
}
END_TEST

START_TEST(test_22) {
  char string[255] = "+2-7=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, -5);
}
END_TEST

START_TEST(test_23) {
  char string[255] = "-2+3.4=";
  double result = 0;
  result = main_func(string, 0, 0);
  ck_assert_int_eq(result, 1.4);
}
END_TEST

START_TEST(test_24) {
  char string[255] = "/4-2=";
  double result = 0;
  int check_error = 0;
  result = main_func(string, 0, &check_error);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(check_error, 1);
}
END_TEST

START_TEST(test_25) {
  char string[255] = "34**7=";
  double result = 0;
  int check_error = 0;
  result = main_func(string, 0, &check_error);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(check_error, 1);
}
END_TEST

Suite *calc_suite_create(void) {
  Suite *calc = suite_create("calc");
  TCase *calc_test = tcase_create("calc_test");

  tcase_add_test(calc_test, test_1);
  tcase_add_test(calc_test, test_2);
  tcase_add_test(calc_test, test_4);
  tcase_add_test(calc_test, test_5);
  tcase_add_test(calc_test, test_6);
  tcase_add_test(calc_test, test_7);
  tcase_add_test(calc_test, test_8);
  tcase_add_test(calc_test, test_9);
  tcase_add_test(calc_test, test_10);
  tcase_add_test(calc_test, test_11);
  tcase_add_test(calc_test, test_12);
  tcase_add_test(calc_test, test_13);
  tcase_add_test(calc_test, test_14);
  tcase_add_test(calc_test, test_15);
  tcase_add_test(calc_test, test_16);
  tcase_add_test(calc_test, test_17);
  tcase_add_test(calc_test, test_18);
  tcase_add_test(calc_test, test_19);
  tcase_add_test(calc_test, test_20);
  tcase_add_test(calc_test, test_21);
  tcase_add_test(calc_test, test_22);
  tcase_add_test(calc_test, test_23);
  tcase_add_test(calc_test, test_24);
  tcase_add_test(calc_test, test_25);
  suite_add_tcase(calc, calc_test);
  return calc;
}

int main() {
  Suite *calc = calc_suite_create();
  SRunner *calc_suite_runner = srunner_create(calc);
  int failed_cnt;
  srunner_run_all(calc_suite_runner, CK_NORMAL);
  failed_cnt = srunner_ntests_failed(calc_suite_runner);
  srunner_free(calc_suite_runner);

  if (failed_cnt != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}