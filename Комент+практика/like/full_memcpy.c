#include "Some_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {


  for (s21_size_t byteIndex = 0; byteIndex < n; byteIndex++) { 

    *((char *)dest + byteIndex) = *((char *)src + byteIndex); 
    
  }
  
  return dest; 
}


int main(){
    int orig_ar[7] = {11, 22, 33, 44, 55, 66, 77}; 
    int passed_ar[7] = {0}; 

    printf("Исходный массив orig: ");
    for(int i = 0; i < 7; i++){
        printf("%d ", orig_ar[i]);
    }
    printf("\n");


    s21_memcpy(passed_ar, orig_ar, 7*sizeof(int));


    printf("Mассив назначения passed_ar: "); 

    for(int i =0; i < 7; i++){
        printf("%d ", orig_ar[i] );  
    }
    printf("\n");

    return 0;

}