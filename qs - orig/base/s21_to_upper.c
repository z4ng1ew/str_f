#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *buffer = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    buffer = malloc((len + 1) * sizeof(char));
    s21_size_t count = 0;
    for (; count < len; count++) {
      if (str[count] >= 'a' && str[count] <= 'z')
        buffer[count] = str[count] - 32;
      else
        buffer[count] = str[count];
    }
    buffer[count] = '\0';
  }
  return buffer;
}
