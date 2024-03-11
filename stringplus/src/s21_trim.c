#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  size_t len = s21_strlen(src);
  char *buf = (char *)calloc(len + 1, sizeof(char));
  if (len == 0) {
    return S21_NULL;
  }
  size_t i = 0;
  int flag = 1;
  while (src[i] && flag) {
    flag = 0;
    for (int j = 0; trim_chars[j]; j++) {
      if (src[i] == trim_chars[j]) {
        flag = 1;
        i++;
        break;
      }
    }
  }
  flag = 1;
  size_t k = len - 1;
  while (k > 0 && flag) {
    flag = 0;
    for (int j = 0; trim_chars[j]; j++) {
      if (src[k] == trim_chars[j]) {
        flag = 1;
        k--;
        break;
      }
    }
  }
  k = k - i;
  size_t l;
  for (l = 0; l <= k; i++, l++) {
    buf[l] = src[i];
  }
  return buf;
}