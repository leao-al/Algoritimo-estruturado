#include <stdio.h>
#include <stdlib.h>
/*Faça um programa que leia 10 inteiros e imprima sua média*/

int main()
{
    int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10;
    float media;

    printf("Digite o valor de numero 1:");
    scanf("%d", &val1);
    printf("Digite o valor de numero 2:");
    scanf("%d", &val2);
    printf("Digite o valor de numero 3:");
    scanf("%d", &val3);
    printf("Digite o valor de numero 4:");
    scanf("%d", &val4);
    printf("Digite o valor de numero 5:");
    scanf("%d", &val5);
    printf("Digite o valor de numero 6:");
    scanf("%d", &val6);
    printf("Digite o valor de numero 7:");
    scanf("%d", &val7);
    printf("Digite o valor de numero 8:");
    scanf("%d", &val8);
    printf("Digite o valor de numero 9:");
    scanf("%d", &val9);
    printf("Digite o valor de numero 10:");
    scanf("%d", &val10);

    media = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10);
    printf("Media: %.2f", media);

    return 0;
}