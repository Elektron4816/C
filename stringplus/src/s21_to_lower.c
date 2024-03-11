#include "s21_string.h"

void *s21_to_lower(const char *str) {
  size_t len = s21_strlen(str);
  char *buf = (char *)calloc(len + 1, sizeof(char));
  if (len == 0) {
    return S21_NULL;
  }
  int ptr, patt;
  int flag = 0;
  for (size_t i = 0; i < s21_strlen(str); i++) {
    flag = 0;
    for (ptr = 65, patt = 97; ptr <= 90 && i < s21_strlen(str); ptr++, patt++) {
      if (str[i] == ptr) {
        buf[i] = patt;
      } else if ((str[i] > 0 && str[i] < 65) || (str[i] > 90 && str[i] < 127)) {
        flag = 1;
      }
    }
    if (flag) {
      buf[i] = str[i];
    }
  }
  return buf;
}
