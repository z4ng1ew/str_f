#include "../s21_string.h"



char *s21_strtok(char *str, const char *delim) {
  static char *p_save_str;
  char *result = s21_NULL;
  char *tail;

  if (str != s21_NULL) {
    p_save_str = str;
  }

  else if (p_save_str != s21_NULL) {
    for (; *p_save_str && s21_strchr(delim, *p_save_str); p_save_str++);
  }

  if (*p_save_str != '\0') {
    result = p_save_str;
    tail = result + s21_strcspn(result, delim);

    if (*tail) {
      *(tail++) = '\0';
    }

    p_save_str = tail;
  }
  return result;
}
