#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  if (src != s21_NULL) {
    if (src && str && (s21_strlen(src) >= start_index)) {
      new_str = calloc((s21_strlen(src) + s21_strlen(str) + 1), 1);
      if (new_str) {
        s21_strncpy(new_str, src, start_index);
        new_str[start_index] = '\0';
        s21_strcat(new_str, str);
        s21_strcat(new_str, src + start_index);
      }
    }
  }
  return new_str;
}