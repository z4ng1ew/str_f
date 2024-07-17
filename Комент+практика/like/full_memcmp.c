#include <stdio.h>
#include "Some_string.h"
#include <string.h>

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int compare_res = 0; 

  const unsigned char *ptr_byte1 = str1; 
  const unsigned char *ptr_byte2 = str2; 

  for (s21_size_t i = 0; i < n && compare_res == 0; i++) {


    if (ptr_byte1[i] != ptr_byte2[i]) { 
      compare_res = ptr_byte1[i] - ptr_byte2[i];
    };
  }
  return compare_res; 
}


int main () {

    const char stringOne[7] = "orange";
    const char stringTwo[8] = "pear";

    size_t lenghtOne = strlen(stringOne);
    size_t lenghtTwo = strlen(stringTwo);

    int res;
    if(lenghtOne < lenghtTwo){
        res = memcmp(stringOne, stringTwo, lenghtOne);
    }else {
     res = memcmp(stringOne, stringTwo, lenghtTwo);
    }


    if(res == 0) {
        printf("Строки \"%s\" и \"%s\" одинаковые по содержанию.\n", stringOne, stringTwo);
    } else if (res < 0) {
        printf("Строка \"%s\" меньше строки \"%s\" в лексикографическом порядке.\n", stringOne, stringTwo);
    } else {
        printf("Строка \"%s\" больше строки \"%s\" в лексикографическом порядке.\n", stringOne, stringTwo);
    }

    return 0;
}