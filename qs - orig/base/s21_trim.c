#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *buffer = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    s21_size_t len = s21_strlen(src);
    int left = 0, n = len, flg = 0;
    for (s21_size_t i = 0; i < len && flg == 0; i++) {
      if (s21_strchr(trim_chars, src[i]) == s21_NULL) {
        left = i;
        flg = 1;
      } else {
        n--;
      }
    }
    flg = 0;
    for (int j = len - 1; j > left && flg == 0; j--) {
      if (s21_strchr(trim_chars, src[j]) == s21_NULL)
        flg = 1;
      else
        n--;
    }
    if (n < 0) n = 0;

    buffer = (char *)malloc(sizeof(char) * (n + 1));
    s21_memcpy(buffer, src + left, n);
    buffer[n] = '\0';
  }
  return buffer;
}
