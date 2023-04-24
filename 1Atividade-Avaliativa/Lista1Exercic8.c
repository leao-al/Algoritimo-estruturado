#include <stdio.h>
#include <stdlib.h>

/*Elabore um programa que faça a leitura de vários números inteiros até que se digite
um número negativo. O programa tem de retornar o maior e o menor número lido*/

int main()
{
    int num, maiorNum = 0, menorNum = 99999;

    while (num > -1)
    {
        printf("Digite um numero:");
        scanf("%d", &num);

        if (num > maiorNum)
            maiorNum = num;

        if (num < menorNum)
            menorNum = num;
    }

    printf("O maior numero e:%d\n", maiorNum);
    printf("O menor numero e:%d", menorNum);

    return 0;
}