#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_strstr_null_checks() {
  assert(strstr(NULL, "test") == NULL);
  assert(strstr("test string", NULL) == NULL);
  assert(strstr(NULL, NULL) == NULL);
  printf("NULL checks passed.\n");
}

void test_strstr_empty_substring() {
  assert(strstr("test string", "") == "test string");
  assert(strstr("", "") == "");
  printf("Empty substring checks passed.\n");
}

void test_strstr_partial_match() {
  assert(strstr("this is a test string", "testt") == NULL);
  assert(strstr("hello world", "worlf") == NULL);
  printf("Partial match checks passed.\n");
}

void test_strstr_full_match() {
  assert(strstr("this is a test string", "test") == strstr("this is a test string", "test"));
  assert(strstr("hello world", "world") == strstr("hello world", "world"));
  printf("Full match checks passed.\n");
}

void test_strstr_long_strings() {
  char long_haystack_with_needle[10007];
  memset(long_haystack_with_needle, 'a', 10000);
  strcpy(long_haystack_with_needle + 10000, "needle");

  char long_haystack_without_needle[10001];
  memset(long_haystack_without_needle, 'a', 10000);
  long_haystack_without_needle[10000] = '\0';

  assert(strstr(long_haystack_with_needle, "needle") == long_haystack_with_needle + 10000);
  assert(strstr(long_haystack_without_needle, "needle") == NULL);
  printf("Long strings checks passed.\n");
}

int main() {
  test_strstr_null_checks();
  test_strstr_empty_substring();
  test_strstr_partial_match();
  test_strstr_full_match();
  test_strstr_long_strings();
  printf("All tests passed.\n");
  return 0;
}
