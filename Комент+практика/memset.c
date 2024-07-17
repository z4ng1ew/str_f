#include <stdio.h>
#include <string.h>

int main(){
    char arr[10];


    memset(arr, 'а', sizeof(arr));

    arr[9] = '\0';

    printf("Result %s\n d", arr);

    return 0;
}