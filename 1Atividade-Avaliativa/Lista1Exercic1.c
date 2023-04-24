#include <stdio.h>
#include <stdlib.h>
/*Leia quatro valores inteiros A, B, C e D. A seguir, calcule e mostre a diferença do
produto de A e B pelo produto de C e D segundo a fórmula: DIFERENCA = (A * B - C * D).
Apresente o resultado da seguinte forma:*/

int main()
{
    int a, b, c, d;
    float diferença;

    printf("Digite o valor de A:");
    scanf("%d", &a);
    printf("Digite o valor de B:");
    scanf("%d", &b);
    printf("Digite o valor de C:");
    scanf("%d", &c);
    printf("Digite o valor de D:");
    scanf("%d", &d);

    diferença = (a * b) - (c * d);

    printf("A diferença = %.1f", diferença);

    return 0;
}