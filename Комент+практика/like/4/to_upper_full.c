#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Some_string.h"


void *s21_to_upper(const char *str) {
  char *buffer = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = strlen(str);
    buffer = malloc((len + 1) * sizeof(char));
    s21_size_t count = 0;
    for (; count < len; count++) {
      if (str[count] >= 'a' && str[count] <= 'z')
        buffer[count] = str[count] - 32;
      else
        buffer[count] = str[count];
    }
    buffer[count] = '\0';
  }
  return buffer;
}






int main() {
    // Тестовые строки
    const char *test_cases[] = {
        "Godbuy, world!",     // Стандартная строка со смешанными буквами
        "",                   // Пустая строка
        "lowercase",          // Строка из строчных букв
        "UPPERCASE",          // Строка из заглавных букв
        "1234abcdEFGH",       // Строка с буквами и цифрами
        "Special &^%$#@",     // Строка с пробелами и спецсимволами
        NULL                  // NULL значение
    };

    // Тестирование функции s21_to_upper
    for (int i = 0; i < 7; i++) {
        const char *input = test_cases[i];
        char *result = s21_to_upper(input);

        // Вывод результата
        if (input != NULL) {
            printf("Original: \"%s\" -> Upper: \"%s\"\n", input, result);
        } else {
            printf("Original: NULL -> Upper: NULL\n");
        }

        // Освобождение памяти
        if (result != NULL) {
            free(result);
        }
    }

    return 0;
}


/*
Вывод:

Original: "Godbuy, world!" -> Upper: "GODBUY, WORLD!"
Original: "" -> Upper: ""
Original: "lowercase" -> Upper: "LOWERCASE"
Original: "UPPERCASE" -> Upper: "UPPERCASE"
Original: "1234abcdEFGH" -> Upper: "1234ABCDEFGH"
Original: "Special &^%$#@" -> Upper: "SPECIAL &^%$#@"
Original: NULL -> Upper: NULL


*/











// int main (){

//     char Some_text[] = "Godbuy, world!";

//     for(int i = 0; Some_text[i] != '\0'; i++){
//         Some_text[i] = s21_to_upper((unsigned char) Some_text[i]);
//     }
//     printf("Сторока %s\n", Some_text);





//     char upper = 'a';

//     printf("Original: %c, toupper: %c\n", upper, s21_to_upper(upper));

//     return 0;
// }