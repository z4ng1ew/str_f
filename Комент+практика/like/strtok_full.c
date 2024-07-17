#include <stdio.h>
#include <string.h>

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
