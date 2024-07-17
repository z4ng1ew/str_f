#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *p;
  char *result = s21_NULL;
  int flg = 0;
  for (p = str; *p != '\0' && !flg; ++p) {
    if (*p == c) {
      result = (char *)p;
      flg = 1;
    }
  }
  return result;
}