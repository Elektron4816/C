#include "s21_string.h"

char *s21_strtok(char *s1, const char *s2) {
  static char *last = 0;
  char *st = S21_NULL;
  if (s1) {
    last = s1;
  }
  if (last != 0 && *last != 0) {
    char *c = last;
    while (s21_strchr(s2, *c)) {
      ++c;
    }
    if (*c != 0) {
      st = c;
      while (*c && (s21_strchr(s2, *c) == 0)) {
        ++c;
      }
      if (*c == 0) {
        last = c;
      } else {
        *c = 0;
        last = c + 1;
      }
    }
  }
  return st;
}
