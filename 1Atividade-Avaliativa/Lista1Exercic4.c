#include <stdio.h>
#include <stdlib.h>

/*Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas
de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou
se está sobre um dos eixos cartesianos ou na origem (x = y = 0). Se o ponto estiver na origem,
escreva a mensagem “Origem”. Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou
“Eixo Y”, conforme for a situação*/

int main()
{

    float a, b;

    printf("Digite as coordenadas de A e B:");
    scanf("%f %f", &a, &b);

    if (a > 0 && b > 0)
    {
        printf("O ponto esta no Q1");
    }
    else if (a < 0 && b > 0)
    {
        printf("O ponto esta no Q2");
    }
    else if (a < 0 && b < 0)
    {
        printf("O ponto esta no Q3");
    }
    else if (a > 0 && b < 0)
    {
        printf("O ponto esta no Q4");
    }
    else if (a == 0 && b != 0)
    {
        printf("Eixo X");
    }
    else if (a != 0 && b == 0)
    {
        printf("Eixo Y");
    }
    else if (a == 0 && b == 0)
    {
        printf("Origem");
    }

    return 0;
}