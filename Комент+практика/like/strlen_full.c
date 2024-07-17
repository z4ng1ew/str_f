#include <stdio.h>
#include <string.h>
#include "Some_string.h"

// s21_size_t s21_strlen(const char *str) {
//   s21_size_t len = 0;
//   for (; str[len]; len++);
//   return len;
// }




s21_size_t s21_strlen(const char *str) {
  s21_size_t str_length = 0; 
  
  
  while (str[str_length] != '\0') {
    str_length++;  
  }
  
  return str_length;  
}


int main (){

    const char *myString = "Hello, world!";
    s21_size_t length = s21_strlen(myString);
    printf("The length of the string \"%s\" is: %llu\n", myString, length); //%llu — это спецификатор формата для вывода значений типа unsigned long long в функции printf.
/*
l — указывает, что значение типа long.
ll — указывает, что значение типа long long.
u — указывает, что значение типа unsigned (без знака).
*/
    //13
    return 0;
}