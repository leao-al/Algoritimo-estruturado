#include <stdio.h>
#include <math.h>
/*Faça um programa que calcule e mostre a área da superfície e o volume de uma esfera
sendo fornecido o valor de seu raio (R). A fórmula para calcular o volume é: (4/3) * pi * R³. A
fórmula para calcular a área é: 4 * pi * R². Considere (atribua) para pi o valor 3.14159. Use o
conceito de constante Dica: Ao utilizar a fórmula, procure usar (4/3.0) ou (4.0/3), pois algumas
linguagens (dentre elas o C++), assumem que o resultado da divisão entre dois inteiros é
outro inteiro*/

int main()
{
    int raio;
    const float PI = 3.14159;
    float volume, areaDaSuperfi;

    printf("Digite o valor do raio da esfera:\n");
    scanf("%d", &raio);

    volume = (4.0 / 3) * PI * pow(raio, 3);
    areaDaSuperfi = 4 * PI * pow(raio, 2);

    printf("\nA area da superficie da esfera e de %.2f unidades de area.\n", areaDaSuperfi);
    printf("O volume da esfera e de %.2f unidades de volume.\n", volume);

    return 0;
}