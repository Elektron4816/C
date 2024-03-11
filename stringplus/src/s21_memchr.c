#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  int flag = 0;
  size_t i;
  char *pstr = (char *)str;
  for (i = 0; i < n; i++) {
    if (*(pstr + i) == c) {
      flag = 1;
      break;
    }
  }
  return flag ? (char *)str + i : S21_NULL;
}
