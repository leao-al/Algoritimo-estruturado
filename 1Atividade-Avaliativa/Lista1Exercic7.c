#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário.
Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de
ordem zero, e, a partir do segundo termo, seu valor é dado pela soma dos dois termos
anteriores. Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.*/

int main()
{

    int valor, num1 = 0, num2 = 1, proxiNum;

    printf("Digite um numero maior que 0:");
    scanf("%d", &valor);

    if (valor == 0)
    {
        printf("0");
    }

    if (valor == 1)
    {
        printf("1");
    }

    for (int i = 2; i <= valor; i++)
    {
        proxiNum = num1 + num2;
        num1 = num2;
        num2 = proxiNum;
    }

    printf("Enesimo termo: %d", proxiNum);

    return 0;
}