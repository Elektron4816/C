#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t i = 0;
  int p = s21_strlen(dest);
  while (i < n) {
    dest[p] = src[i];
    i++;
    p++;
  }
  return dest;
}
