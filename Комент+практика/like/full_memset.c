
#include "Some_string.h"

// void *s21_memset(void *str, int c, s21_size_t n) {
//     unsigned char *p = (unsigned char *)str; // Приведение указателя str к типу unsigned char *, чтобы работать с памятью побайтово.

//     s21_size_t i = 0; // Инициализация переменной i, которая будет отслеживать количество пройденных байт.

//     while (i < n) { // Условие цикла: продолжаем, пока i меньше n.
//         *p = (unsigned char)c; // Устанавливаем текущий байт значением c, приведенным к unsigned char.
//         p++; // Переходим к следующему байту, увеличивая указатель p.
//         i++; // Увеличиваем счетчик пройденных байт.
//     }

//     return str; // Возвращаем исходный указатель str.
// }







void *s21_memset(void *str, int c, s21_size_t n) { 

  unsigned char *byte_ptr = (unsigned char *)str; 

  for (s21_size_t i = 0; i < n; i++) { 
    *byte_ptr++ = c; 
  }

  return str; 
}



int main(){
    char arr[10];


    s21_memset(arr, 'd', sizeof(arr));

    arr[9] = '\0';

    printf("Result %s\n", arr);

    return 0;
}