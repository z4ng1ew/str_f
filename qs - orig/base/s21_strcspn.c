#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int flag = 0;

  while (*str1) {
    char *p = (char *)str2;
    while (*p) {
      if (*str1 == *p) flag = 1;
      p++;
    }
    if (!flag) count++;
    str1++;
  }
  return count;
}