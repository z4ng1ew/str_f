#include "Some_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  
  char *end_of_line = dest; 

  while (*end_of_line != '\0') { 
    end_of_line++;
  } 

  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    *end_of_line++ = src[i]; 
  } 

  *end_of_line = '\0'; 

  return dest; 
}


int main() {
    char recipient[14] = "Goodbuy,  ";
    char sender[30] = "world, and hello future";

    s21_strncat(recipient, sender, 5);

    printf("Результат: %s\n", recipient);

    return 0;
}