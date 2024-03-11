#ifndef _S21_STRING_H_

#define _S21_STRING_H_
#define _DEFAULT_SOURCE
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define S21_NULL ((void *)0)
#define S21_MAX 18446744073709551615UL
#define BUFFER_SIZE 512

struct flag {
  int flag_null;
  int flag_space;
  int flag_space_for_lenght;
  int flag_plus;
  int flag_dot;
  int dot_lenght;
  int dot_lenght_for_d;
  int flag_dot_for_d;
  int flag_minus;
  int flag_length_h;
  int flag_length_l;
  int flag_length_upper_l;
  int flag_unsigned;
};

size_t s21_strlen(const char *string);
char *s21_strstr(const char *strA, const char *strB);
char *s21_strchr(const char *string, int ch);
char *s21_strrchr(const char *string, int ch);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str, const char *charset);
int s21_memcmp(const void *s1, const void *s2, size_t len);
void *s21_memset(void *dest, int c, size_t len);
void *s21_memcpy(void *dest, const void *src, size_t len);
void *s21_memchr(const void *str, int c, size_t n);
char *s21_strpbrk(const char *str, const char *patt);
int s21_strncmp(const char *s1, const char *s2, size_t n);
char *s21_strerror(int errnum);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);
char int_to_string(char *buf, long int n);
char float_to_string(char *buf, double n, struct flag flag);
char dec_to_oct(char *buf, int n);
void get_param(char *str, char *ch, int i, long result, va_list factor,
               int *res_i, struct flag flag);
void int_spec(char *str, int i, long result, va_list factor, int *res_func_i,
              struct flag flag);
void oct_spec(char *str, int i, long result, va_list factor, int *res_func_i,
              struct flag flag);
void string_spec(char *str, int i, long result, va_list factor, int *res_func_i,
                 struct flag flag);
void float_spec(char *str, int i, long result, va_list factor, int *res_func_i,
                struct flag flag);
void char_spec(char *str, int i, long result, va_list factor, int *res_func_i,
               struct flag flag);
void normal_d(char *str, char *tmp, int i, long result, struct flag flag,
              int len_d);
void revers_d(char *str, char *tmp, int i, long result, struct flag flag,
              int len_d);
void revers_string(char *str, char *s, int i, long result, int len_s);
void normal_string(char *str, char *s, int i, long result, int len_s);
void revers_char(char *str, int i, char c, long result);
void normal_char(char *str, int i, char c, long result);
void revers_oct(char *str, int i, char *tmp_o, long result, int len_o,
                struct flag flag);
void normal_oct(char *str, int i, char *tmp_o, long result, int len_o,
                struct flag flag);
void revers_float(char *str, int i, char *tmp_f, long result, int len_f,
                  struct flag flag);
void normal_float(char *str, int i, char *tmp_f, long result, int len_f,
                  struct flag flag);

#endif  //_S21_STRING_H_
