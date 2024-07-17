#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *buf = dest;

  while (*buf != '\0') {
    buf++;
  }

  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    *buf++ = src[i];
  }

  *buf = '\0';

  return dest;
}