#include "s21_string.h"

char *s21_strrchr(const char *string, int ch) {
  int i = s21_strlen(string);
  if (i != 0) {
    while (string[i] != ch) {
      i--;
    }
  }
  return ch == string[i] ? (char *)string + i : S21_NULL;
}
