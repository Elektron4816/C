#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "./s21_string.h"
#define MAXSIZE 512

START_TEST(s21_strlen_test) {
  char str[MAXSIZE] = "Hello, world! and hello GROOT!";
  char str1[MAXSIZE] = "Hello, world! and hello GROOT!";
  ck_assert_int_eq(s21_strlen(str), strlen(str1));
  ck_assert_int_eq(s21_strlen("Hello, world!"), strlen("Hello, world!"));
  ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));
}
END_TEST

START_TEST(s21_strstr_test) {
  char str[MAXSIZE] = "This is an example!";
  char str1[MAXSIZE] = "This is an example!";
  char str2[MAXSIZE] = "Hello, world!";
  char str3[MAXSIZE] = "Hello, world!";
  ck_assert_pstr_eq(s21_strstr(str, "is"), strstr(str1, "is"));
  ck_assert_pstr_eq(s21_strstr(str, "!"), strstr(str1, "!"));
  ck_assert_pstr_eq(s21_strstr(str, "Q"), strstr(str1, " Q"));
  ck_assert_pstr_eq(s21_strstr(str, " "), strstr(str1, " "));
  ck_assert_pstr_eq(s21_strstr(str2, "Groot"), strstr(str3, " Groot"));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str[MAXSIZE] = "Hello, world! and hello GROOT!";
  char str1[MAXSIZE] = "Hello, world! and hello GROOT!";
  ck_assert_pstr_eq(s21_strchr(str, 'w'), strchr(str1, 'w'));
  ck_assert_pstr_eq(s21_strchr(str, ' '), strchr(str1, ' '));
  ck_assert_pstr_eq(s21_strchr(str, '!'), strchr(str1, '!'));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str[MAXSIZE] = "Hello, world! and hello GROOT!";
  char str1[MAXSIZE] = "Hello, world! and hello GROOT!";
  ck_assert_pstr_eq(s21_strrchr(str, 'o'), strrchr(str1, 'o'));
  ck_assert_pstr_eq(s21_strrchr(str, 'o'), strrchr(str1, 'o'));
  ck_assert_pstr_eq(s21_strrchr(str, 'o'), strrchr(str1, 'o'));
}
END_TEST

START_TEST(s21_strncat_test) {
  char str[MAXSIZE] = "Hello";
  char str1[MAXSIZE] = "Hello";
  ck_assert_pstr_eq(s21_strncat(str, ", world", 3),
                    strncat(str1, ", world", 3));
  ck_assert_pstr_eq(s21_strncat(str, ", world", 6),
                    strncat(str1, ", world", 6));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str[MAXSIZE];
  char str1[MAXSIZE];
  ck_assert_pstr_eq(s21_strncpy(str, "world", 6), strncpy(str1, "world", 6));
  ck_assert_pstr_eq(s21_strncpy(str, "\n hello!", 9),
                    strncpy(str1, "\n hello!", 9));
  ck_assert_pstr_eq(s21_strncpy(str, "cle ar", 7), strncpy(str1, "cle ar", 7));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char str[MAXSIZE] = "abcbcadef";
  char str1[MAXSIZE] = "abcbcadef";
  char str2[MAXSIZE] = "xxxbcadef";
  char str3[MAXSIZE] = "xxxbcadef";
  ck_assert_int_eq(s21_strcspn(str, "cba"), strcspn(str1, "cba"));
  ck_assert_int_eq(s21_strcspn(str2, "cba"), strcspn(str3, "cba"));
  ck_assert_int_eq(s21_strcspn(str, "zml"), strcspn(str1, "zml"));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char str[MAXSIZE] = "qwerty";
  char str2[MAXSIZE] = "qwerty";
  char str3[MAXSIZE] = "qwer";
  char str4[MAXSIZE] = "qrty";
  ck_assert_int_eq(s21_memcmp(str, str2, 7), memcmp(str, str2, 7));
  ck_assert_int_eq(s21_memcmp(str3, str, 7), memcmp(str3, str, 7));
  ck_assert_int_eq(s21_memcmp(str, str3, 7), memcmp(str, str3, 7));
  ck_assert_int_eq(s21_memcmp(str, str4, 7), memcmp(str, str4, 7));
}
END_TEST

START_TEST(s21_memset_test) {
  char str[MAXSIZE];
  char str1[MAXSIZE] = "qwerty";
  ck_assert_pstr_eq(s21_memset(str, '=', 10), memset(str, '=', 10));
  ck_assert_pstr_eq(s21_memset(str1, '*', 10), memset(str1, '*', 10));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char str[MAXSIZE] = "Hello";
  char str1[MAXSIZE] = "Hello";
  char str2[MAXSIZE];
  char str3[MAXSIZE];
  ck_assert_pstr_eq(s21_memcpy(str, ", world", 6), memcpy(str1, ", world", 6));
  ck_assert_pstr_eq(s21_memcpy(str2, "world", 6), memcpy(str3, "world", 6));
}
END_TEST

START_TEST(s21_memchr_test) {
  char str[MAXSIZE] = "Hello, world! and hello GROOT!";
  char str1[MAXSIZE] = "Hello, world! and hello GROOT!";
  ck_assert_pstr_eq(s21_memchr(str, 'w', 10), memchr(str1, 'w', 10));
  ck_assert_pstr_eq(s21_memchr(str, 'G', 10), memchr(str1, 'G', 10));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str[MAXSIZE] = "Find all vowels";
  char str1[MAXSIZE] = "Find all vowels";
  ck_assert_pstr_eq(s21_strpbrk(str, "ai"), strpbrk(str1, "ai"));
  ck_assert_pstr_eq(s21_strpbrk(str, "QaiZQWE"), strpbrk(str1, "QaiZQWE"));
  ck_assert_pstr_eq(s21_strpbrk(str, "Z"), strpbrk(str1, "Z"));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str[MAXSIZE] = "Hello, worlD";
  char str2[MAXSIZE] = "Hello, world";
  char str3[MAXSIZE] = "Hello, world";
  char str4[MAXSIZE] = "Hel, world";
  ck_assert_int_eq(s21_strncmp(str, str2, 12), strncmp(str, str2, 12));
  ck_assert_int_eq(s21_strncmp(str, str3, 12), strncmp(str, str3, 12));
  ck_assert_int_eq(s21_strncmp(str, str3, 5), strncmp(str, str3, 5));
  ck_assert_int_eq(s21_strncmp(str, str4, 10), strncmp(str, str4, 10));
}
END_TEST

START_TEST(s21_strerror_test) {
  ck_assert_pstr_eq(s21_strerror(3), strerror(3));
  ck_assert_pstr_eq(s21_strerror(41), strerror(41));
  ck_assert_pstr_eq(s21_strerror(30), strerror(30));
}

START_TEST(s21_to_upper_test) {
  char *str = {"hello, WORLD!"};
  char *res = s21_to_upper(str);
  ck_assert_pstr_eq(res, "HELLO, WORLD!");
  char *str2 = {"hello, world!"};
  char *res2 = s21_to_upper(str2);
  ck_assert_pstr_eq(res2, "HELLO, WORLD!");
  char *str3 = {"666!"};
  char *res3 = s21_to_upper(str3);
  ck_assert_pstr_eq(res3, "666!");
  char str4[MAXSIZE] = {0};
  char *res5 = s21_to_upper(str4);
  ck_assert_pstr_eq(res5, S21_NULL);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *str = {"hello, WORLD!"};
  char *res = s21_to_lower(str);
  ck_assert_pstr_eq(res, "hello, world!");
  char *str2 = {"HELLO, WORLD!"};
  char *res2 = s21_to_lower(str2);
  ck_assert_pstr_eq(res2, "hello, world!");
  char *str3 = {"666!"};
  char *res3 = s21_to_lower(str3);
  ck_assert_pstr_eq(res3, "666!");
  char str4[MAXSIZE] = {0};
  char *res4 = s21_to_lower(str4);
  ck_assert_pstr_eq(res4, S21_NULL);
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = {"Hello Groot!"};
  char *str = {"world "};
  char *res = s21_insert(src, str, 6);
  ck_assert_pstr_eq(res, "Hello world Groot!");
  char src2[MAXSIZE] = {};
  char *res2 = s21_insert(src2, str, 6);
  ck_assert_pstr_eq(res2, S21_NULL);
}
END_TEST

START_TEST(s21_trim_test) {
  char *src = "  ### Hello # World ###  ";
  char *trim = " #";
  char *res = s21_trim(src, trim);
  ck_assert_pstr_eq(res, "Hello # World");
  char src2[] = {0};
  char *res2 = s21_trim(src2, trim);
  ck_assert_pstr_eq(res2, S21_NULL);
}
END_TEST

START_TEST(s21_strtok_test) {
  char src[MAXSIZE] = "Hello world, Groot!";
  char trim[MAXSIZE] = " ,!";
  ck_assert_pstr_eq(s21_strtok(src, trim), strtok(src, trim));
}
END_TEST

START_TEST(s21_without_spec) {
  char str[MAXSIZE] = {0};
  s21_sprintf(str, "hello %% world");
  char buf[MAXSIZE] = {0};
  sprintf(buf, "hello %% world");
  ck_assert_pstr_eq(str, buf);
}
END_TEST

START_TEST(s21_test_d) {
  int d = 156;
  int d1 = -156;
  int d2 = 0;
  char str[MAXSIZE] = {0};
  s21_sprintf(str, "hello %05d %-10d % d %+d world", d, d1, d2, 363);
  char buf[MAXSIZE] = {0};
  sprintf(buf, "hello %05d %-10d % d %+d world", d, d1, d2, 363);
  ck_assert_pstr_eq(str, buf);
}
END_TEST

START_TEST(s21_test_f) {
  double f = 156.235;
  double f1 = -156.235;
  double f2 = 0.;
  double f3 = 1.;
  double f4 = 457.23235;
  char str[100] = {0};
  s21_sprintf(str, "hello %.3f %f %-+13f %+f %+015f world", f, f1, f2, f3, f4);
  char buf[100] = {0};
  sprintf(buf, "hello %.3f %f %-+13f %+f %+015f world", f, f1, f2, f3, f4);
  ck_assert_pstr_eq(str, buf);
}
END_TEST

START_TEST(s21_test_c) {
  char c = 'H';
  char str[100] = {0};
  s21_sprintf(str, "hello %c %-5c world", c, c);
  char buf[100] = {0};
  sprintf(buf, "hello %c %-5c world", c, c);
  ck_assert_pstr_eq(str, buf);
}
END_TEST

START_TEST(s21_test_s) {
  char *s = "All Fine";
  char str[100] = {0};
  s21_sprintf(str, "hello %s %-15s world", s, s);
  char buf[100] = {0};
  sprintf(buf, "hello %s %-15s world", s, s);
  ck_assert_pstr_eq(str, buf);
}
END_TEST

START_TEST(s21_test_o) {
  int o = 3463;
  char str[100] = {0};
  s21_sprintf(str, "hello %o %-6o %06o world", o, o, o);
  char buf[100] = {0};
  sprintf(buf, "hello %o %-6o %06o world", o, o, o);
  ck_assert_pstr_eq(str, buf);
}
END_TEST

START_TEST(s21_test_u) {
  unsigned int u = 6345;
  unsigned int u1 = -346;
  char str[100] = {0};
  s21_sprintf(str, "hello %u %u world", u, u1);
  char buf[100] = {0};
  sprintf(buf, "hello %u %u world", u, u1);
  ck_assert_pstr_eq(str, buf);
}

START_TEST(s21_test_h_and_l) {
  short int hd = 2345;
  long int ld = 113252342323;
  long double lf = 123456789.987654321;
  char str[100] = {0};
  s21_sprintf(str, "hello %hd %ld %Lf world", hd, ld, lf);
  char buf[100] = {0};
  sprintf(buf, "hello %hd %ld %Lf world", hd, ld, lf);
  ck_assert_pstr_eq(str, buf);
}
END_TEST

Suite *s21_string_suite_create(void) {
  Suite *s21_string = suite_create("s21_string");
  TCase *s21_string_test = tcase_create("s21_string_test");
  TCase *s21_sprintf_test = tcase_create("s21_sprintf_test");

  tcase_add_test(s21_string_test, s21_strlen_test);
  tcase_add_test(s21_string_test, s21_strstr_test);
  tcase_add_test(s21_string_test, s21_strchr_test);
  tcase_add_test(s21_string_test, s21_strrchr_test);
  tcase_add_test(s21_string_test, s21_strncat_test);
  tcase_add_test(s21_string_test, s21_strncpy_test);
  tcase_add_test(s21_string_test, s21_strcspn_test);
  tcase_add_test(s21_string_test, s21_memcmp_test);
  tcase_add_test(s21_string_test, s21_memset_test);
  tcase_add_test(s21_string_test, s21_memcpy_test);
  tcase_add_test(s21_string_test, s21_memchr_test);
  tcase_add_test(s21_string_test, s21_strpbrk_test);
  tcase_add_test(s21_string_test, s21_strncmp_test);
  tcase_add_test(s21_string_test, s21_strerror_test);
  tcase_add_test(s21_string_test, s21_to_upper_test);
  tcase_add_test(s21_string_test, s21_to_lower_test);
  tcase_add_test(s21_string_test, s21_insert_test);
  tcase_add_test(s21_string_test, s21_trim_test);
  tcase_add_test(s21_string_test, s21_strtok_test);

  tcase_add_test(s21_sprintf_test, s21_without_spec);
  tcase_add_test(s21_sprintf_test, s21_test_d);
  tcase_add_test(s21_sprintf_test, s21_test_f);
  tcase_add_test(s21_sprintf_test, s21_test_c);
  tcase_add_test(s21_sprintf_test, s21_test_s);
  tcase_add_test(s21_sprintf_test, s21_test_o);
  tcase_add_test(s21_sprintf_test, s21_test_u);
  tcase_add_test(s21_sprintf_test, s21_test_h_and_l);

  suite_add_tcase(s21_string, s21_string_test);
  suite_add_tcase(s21_string, s21_sprintf_test);
  return s21_string;
}

int main() {
  Suite *s21_string = s21_string_suite_create();
  SRunner *s21_string_suite_runner = srunner_create(s21_string);
  int failed_cnt;
  srunner_run_all(s21_string_suite_runner, CK_NORMAL);
  failed_cnt = srunner_ntests_failed(s21_string_suite_runner);
  srunner_free(s21_string_suite_runner);

  if (failed_cnt != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
