#include "./s21_string.h"

int compare(const char *strA, const char *strB) {
  while (*strA && *strB) {
    if (*strA != *strB) {
      return 0;
    }
    strA++;
    strB++;
  }
  return (*strB == '\0');
}

char *s21_strstr(const char *strA, const char *strB) {
  if (*strA == 0 && *strB == 0) {
    exit(1);
  }
  while (*strA != '\0') {
    if ((*strA == *strB) && compare(strA, strB)) {
      return (char *)strA;
    }
    strA++;
  }
  return S21_NULL;
}
