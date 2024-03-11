#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t len) {
  char *str = (char *)src;
  char *target = (char *)dest;
  for (size_t i = 0; i < len; i++) {
    target[i] = str[i];
  }
  return dest;
}
