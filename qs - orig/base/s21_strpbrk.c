#include "../s21_string.h"

char *s21_strpbrk(const char *str, const char *sym) {
  char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    char *ptr = s21_strchr(str, sym[i]);

    if (ptr != s21_NULL) {
      res = ptr;
      break;
    }
  }
  return res;
}