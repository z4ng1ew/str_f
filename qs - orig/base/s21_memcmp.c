#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int flg = 0;
  const unsigned char *buf1 = str1;
  const unsigned char *buf2 = str2;
  for (s21_size_t i = 0; i < n && flg == 0; i++) {
    if (buf1[i] != buf2[i]) flg = buf1[i] - buf2[i];
  }
  return flg;
}