#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// faça um programa que determine e mostre os cinco primeiros multiplos de 3 considerando números maiores que 0//


int main() {
setlocale(LC_ALL, "portuguese");


    int num;


    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("Os primeiros multiplos de %d sao:\n", num);

    for (int i = 1; i <= 5; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}

