#include <stdio.h>
#include <string.h>
#include "Some_string.h"


char *s21_strtok(char *str, const char *delim) {

  static char * cur_position_tokenization; 
  char *res_position = s21_NULL; 
  char *delimiter_position;


  if (str != s21_NULL) {
    cur_position_tokenization = str; 
  }

    if (cur_position_tokenization != s21_NULL) {
      while (*cur_position_tokenization != '\0' && strchr(delim, *cur_position_tokenization)) { 
      cur_position_tokenization++; 
      } 



      if (*cur_position_tokenization != '\0') {
      
        res_position = cur_position_tokenization; 
        delimiter_position = res_position + strcspn(res_position, delim); 
        
        if (*delimiter_position != '\0') { 
        *delimiter_position = '\0';      
        delimiter_position++; 
        } 

        cur_position_tokenization = delimiter_position;

      }


    }
    
    return res_position; 

  }




int main() {
    char str[] = "Hello, world! Welcome to C programming.";
    char *token;
    

    /*

gcc strtok_full.c 

./a.out 


Hello
world
Welcome
to
C
programming
user@user-To-Be-Filled-By-O-E-M:~/Рабочий стол/Final_vers_str-master/Комент+прак
тика/like$ 

    */



    // Первый вызов strtok: указываем строку и разделители
    token = strtok(str, " ,.!");

    // Остальные вызовы strtok: передаем NULL вместо строки
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,.!"); // Указываем только разделители
    }

    return 0;
}
