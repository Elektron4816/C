#include "s21_string.h"

size_t s21_strcspn(const char *str, const char *charset) {
  size_t flag = S21_MAX;
  size_t len = s21_strlen(str);
  size_t len2 = s21_strlen(charset);
  for (size_t i = 0; i < len2; i++) {
    for (size_t j = 0; j < len; j++) {
      if (charset[i] == str[j]) {
        if (flag > j) {
          flag = j;
        }
      }
    }
  }
  return flag != S21_MAX ? flag : s21_strlen(str);
}
