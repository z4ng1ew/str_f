#include <stdio.h>
#include <string.h>

int main(){
    char string_One[] = "Buy!";
    char string_Two[] = "forever";

    size_t n = 7;

    int res = strncmp(string_One, string_Two, n);

    if(res == 0){
        printf("Первые %zu символы строки равны. \n", n);
    } else if (res < 0) {
        printf("Первые %zu символы  string_One меньше чем string_Two.\n", n);
    } else {
        printf("Первые %zu символы  string_One больше чем string_Two\n", n);
    }

    return 0;
}