#include <stdio.h>
#include <string.h>

int main() {
    char recipient[14] = "Goodbuy,  ";
    char sender[30] = "world, and hello future";

    strncat(recipient, sender, 5);

    printf("Результат: %s\n", recipient);

    return 0;
}