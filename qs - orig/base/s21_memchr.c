#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int k = -1;

  for (s21_size_t i = 0; i < n && k == -1; i++) {
    if (*((char *)str + i) == c) k = i;
  }

  if (k == -1)
    str = s21_NULL;
  else
    str = (char *)str + k;

  return (void *)((char *)str);
}