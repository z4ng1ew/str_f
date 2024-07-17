#include "Some_string.h"
#include <string.h>
void *s21_memchr(const void *str, int c, s21_size_t n) {
  
  int found_ind = -1; 

  for (s21_size_t cur_ind = 0; cur_ind < n &&  found_ind == -1; cur_ind++) {
    
    if (*((char *)str + cur_ind) == c){  
    found_ind = cur_ind; 
    }

  } 

  if (found_ind == -1) {
    str = s21_NULL;
  }
  
  else {
    str = (char *)str +  found_ind; 
  } 
  return (void *)str; 
}




int main () {

    const char string[] = "Godbuy, world!";

    char g = ',';

    size_t s = 10;

    char *res = (char *)s21_memchr(string, g, s);  

    if (res != NULL) {
        printf("Символ '%c' найден в строке \"%s\" на позици: %ld\n", g, string, res  - string); 
        printf("%c\n", *res);
    }else {
        printf("Символ '%c' не найден в первых %zu байтах строки \"%s\"\n", g, s, string);
    }

 return 0;
}
