#include "s21_string.h"

int s21_strncmp(const char *s1, const char *s2, size_t n) {
  char *str1 = (char *)s1;
  char *str2 = (char *)s2;
  size_t i;
  unsigned int flag = 0;
  for (i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      flag = str1[i] - str2[i];
      break;
    }
  }
  return flag;
}
