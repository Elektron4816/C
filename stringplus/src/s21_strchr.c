#include "s21_string.h"

char *s21_strchr(const char *string, int ch) {
  size_t i;
  for (i = 0; i < s21_strlen(string); i++) {
    if (*(string + i) == ch) {
      break;
    }
  }
  return ch == string[i] ? (char *)string + i : S21_NULL;
}
