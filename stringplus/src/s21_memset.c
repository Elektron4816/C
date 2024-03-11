#include "s21_string.h"

void *s21_memset(void *dest, int c, size_t len) {
  char *str = (char *)dest;
  while (len > 0) {
    *str = (char)c;
    str++;
    len--;
  }
  return dest;
}
