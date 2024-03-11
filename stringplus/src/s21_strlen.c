#include "s21_string.h"

size_t s21_strlen(const char *str) {
  int len = 0;
  for (; *(str + len); len++)
    ;

  return len;
}
