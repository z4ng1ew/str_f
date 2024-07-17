#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res_null = s21_NULL;
  char *p = (char *)str;
  int flag = 0;

  for (; *p; p++) {
    if ((*p < 32 || *p == 127) && (*p != c)) continue;
    if (*p == c && !flag) {
      flag = 1;
    } else if ((int)*p != c && flag) {
      break;
    }
  }
  if (c == 0) {
    res_null = p;
  }

  return (flag) ? (p - 1) : res_null;
}