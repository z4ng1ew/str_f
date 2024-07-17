#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {



  s21_size_t i; 


  for (i = 0; i < n; i++) {


    if (src[i]) { 

      dest[i] = src[i]; 



    } else {

      dest[i] = '\0'; 
    }


  }

  return dest; 
}
