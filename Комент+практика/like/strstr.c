#include <stdio.h>
#include <string.h>
#include "Some_string.h"


#include "Some_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *matching_word = s21_NULL;
  int error = 0;

  if (haystack == s21_NULL || needle == s21_NULL) {
    error = 1;
  } else {
    int len_needle = strlen(needle);

    if (len_needle == 0) {  
      matching_word = (char *)haystack; 
    } else {
      while (*haystack != '\0' && matching_word == s21_NULL) { 
        if (*haystack == *needle) { 
          const char *h = haystack;
          const char *n = needle; 

          while (*h != '\0' && *n != '\0' && (*h == *n)) { 
            h++; 
            n++;
          }

          if (*n == '\0') { 
            matching_word = (char *)haystack; 
          }
        }
        haystack++; 
      }
    }
  }

  if (error) {
    matching_word = s21_NULL;
  }

  return matching_word; 
}


/*

user@user-To-Be-Filled-By-O-E-M:~/Рабочий стол/Final_vers_str-master/Комент+прак
тика/like$ gcc -g -o test_strstr test_strstr.c strstr.c
user@user-To-Be-Filled-By-O-E-M:~/Рабочий стол/Final_vers_str-master/Комент+прак
тика/like$ ./test_strstr
NULL checks passed.
Partial match checks passed.
Long strings checks passed.
All tests passed.
user@user-To-Be-Filled-By-O-E-M:~/Рабочий стол/Final_vers_str-master/Комент+прак
тика/like$ 



*/