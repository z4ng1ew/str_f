#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  s21_size_t bytes = 0;

  while (bytes != n) {
    if (*(str1 + bytes) != *(str2 + bytes)) {
      diff = *(str1 + bytes) - *(str2 + bytes);
      break;
    }
    bytes++;
  }

  return diff;
}