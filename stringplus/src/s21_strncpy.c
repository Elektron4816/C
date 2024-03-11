#include "./s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  size_t i;
  for (i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}
