#include "s21_string.h"

int s21_memcmp(const void *s1, const void *s2, size_t len) {
  unsigned char *arr1;
  unsigned char *arr2;

  arr1 = (unsigned char *)s1;
  arr2 = (unsigned char *)s2;

  for (size_t i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      return (arr1[i] - arr2[i]);
    }
  }
  return 0;
}
