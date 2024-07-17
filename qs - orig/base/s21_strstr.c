#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  if (haystack != result) {
    char *dest = (char *)haystack;
    int flag = 0;
    int len_needle = (int)s21_strlen(needle);

    while (*dest) {
      if (dest[0] == needle[flag]) {
        flag += 1;

      } else if (flag > 0) {
        break;
      }
      dest += 1;
    }

    if (len_needle == 0)
      result = (char *)haystack;

    else if (flag == len_needle) {
      result = dest - len_needle;
    }
  }

  return result;
}