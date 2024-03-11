#include "s21_string.h"

char *s21_strpbrk(const char *str, const char *patt) {
  int flag = 0;
  while (*str) {
    if (s21_strchr(patt, *str)) {
      flag = 1;
      break;
    } else {
      str++;
    }
  }
  return flag == 1 ? (char *)str : S21_NULL;
}
