#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  size_t src_len = s21_strlen(src);
  size_t str_len = s21_strlen(str);
  if (src_len < start_index || src_len == 0) {
    return S21_NULL;
  }
  char *buf = (char *)calloc((src_len + str_len + 1), sizeof(char));
  size_t i, j = 0, i_str = 0;
  for (i = 0; i <= src_len; i++) {
    if (i == start_index) {
      for (i_str = 0; i_str < str_len; i_str++) {
        buf[j] = str[i_str];
        j++;
      }
    }
    buf[j] = src[i];
    j++;
  }
  return buf;
}
