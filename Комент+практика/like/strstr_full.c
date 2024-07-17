#include <stdio.h>
#include <string.h>
#include "Some_string.h"





char *s21_strstr(const char *haystack, const char *needle) { 

  char *matching_word = s21_NULL;

  if (haystack != matching_word) { 


    int len_needle = strlen(needle);

    if (len_needle == 0) {  
    
      matching_word = (char *)haystack; 

    } else {
      while (*haystack != '\0' &&  matching_word == s21_NULL) { 

        
        if (*haystack == *needle) { 


          const char *h = haystack;
          const char *n = needle; 

          while (*h != '\0' && *n != '\0' && (*h == *n)) { 


            h++; 
            n++;
          }

          if (*n  == '\0') { 


            matching_word = (char *)haystack; 
          }

        }
        haystack++; 
      }
    }
  }
  
  return matching_word; 
} 



int main() {
const char *hayst = "Goodbuy, world!";
const char *need = " wo";

/*
user@user-To-Be-Filled-By-O-E-M:~/Рабочий стол/Final_vers_str-master/Комент+прак
тика/like$ ./a.out 
Found:  world!
*/

char *result = s21_strstr(hayst, need);

if(result != NULL){
    printf("Found: %s\n", result);
}else {
    printf("Not found\n");
}


   return 0;
}