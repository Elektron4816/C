#include "s21_string.h"

void *s21_to_upper(const char *str) {
  size_t len = s21_strlen(str);
  char *buf = (char *)calloc(len + 1, sizeof(char));
  if (len == 0) {
    return S21_NULL;
  }
  int ptr, patt;
  int flag = 0;
  size_t i = 0;
  for (i = 0; i < len; i++) {
    flag = 0;
    for (ptr = 97, patt = 65; ptr <= 122 && i < len; ptr++, patt++) {
      if (str[i] == ptr) {
        buf[i] = patt;
      } else if ((str[i] > 122 && str[i] < 127) ||
                 (str[i] < 97 && str[i] > 0)) {
        flag = 1;
      }
    }
    if (flag) {
      buf[i] = str[i];
    }
  }
  return buf;
}
