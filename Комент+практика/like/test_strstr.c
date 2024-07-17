#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Some_string.h"

void test_strstr_null_checks() {
  assert(s21_strstr(NULL, "test") == s21_NULL);
  assert(s21_strstr("test string", NULL) == s21_NULL);
  assert(s21_strstr(NULL, NULL) == s21_NULL);
  printf("NULL checks passed.\n");
}

void test_strstr_partial_match() {
  assert(s21_strstr("this is a test string", "testt") == s21_NULL);
  assert(s21_strstr("hello world", "worlf") == s21_NULL);
  printf("Partial match checks passed.\n");
}

void test_strstr_long_strings() {
  char long_haystack_with_needle[10007];
  memset(long_haystack_with_needle, 'a', 10000);
  strcpy(long_haystack_with_needle + 10000, "needle");

  char long_haystack_without_needle[10001];
  memset(long_haystack_without_needle, 'a', 10000);
  long_haystack_without_needle[10000] = '\0';

  assert(s21_strstr(long_haystack_with_needle, "needle") == long_haystack_with_needle + 10000);
  assert(s21_strstr(long_haystack_without_needle, "needle") == s21_NULL);
  printf("Long strings checks passed.\n");
}

int main() {
  test_strstr_null_checks();
  test_strstr_partial_match();
  test_strstr_long_strings();
  printf("All tests passed.\n");
  return 0;
}

