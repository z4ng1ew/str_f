#include <stdio.h>
#include <string.h>
#include <assert.h>

void strtok_test_check_strings_delim_substring() {
  char str1[] = "ABCDEFGH";
  const char str_delim[] = "ABCD";
  char *tmp_str1 = strtok(str1, str_delim);
  char *expected_tokens[] = {"EFGH"};
  int i = 0;

  while (tmp_str1) {
    printf("Token: %s\n", tmp_str1);
    assert(strcmp(tmp_str1, expected_tokens[i++]) == 0);
    tmp_str1 = strtok(NULL, str_delim);
  }

  // Проверка, что все ожидаемые токены были найдены
  assert(i == sizeof(expected_tokens) / sizeof(expected_tokens[0]));
}

int main() {
    strtok_test_check_strings_delim_substring();
    printf("All tests passed.\n");
    return 0;
}
