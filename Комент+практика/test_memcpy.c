#include <stdio.h>
#include <string.h>

/*

memcpy (memory copy) - функция копирования памяти.

mem - сокращение от "memory" (память).
cpy - сокращение от "copy" (копировать).
*/


int main(){
    int orig_ar[7] = {11, 22, 33, 44, 55, 66, 77}; //копируемый массив
    int passed_ar[7] = {0}; //массив в который копируют 1-ый оргинальный массив

    printf("Исходный массив orig: ");
    for(int i = 0; i < 7; i++){
        printf("%d ", orig_ar[i]);
    }
    printf("\n");


    memcpy(passed_ar, orig_ar, 7*sizeof(int)); //копируем 7 эл-ов типа int


    printf("Mассив назначения passed_ar: "); 

    for(int i =0; i < 7; i++){
        printf("%d ", orig_ar[i] );  //Вывод массива назначения
    }
    printf("\n");

    return 0;

}