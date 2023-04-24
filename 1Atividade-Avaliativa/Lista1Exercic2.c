#include <stdio.h>
#include <math.h>
/*Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no
plano, p1(x1, y1) e p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais
após a vírgula, segundo a fórmula:*/

int main()
{
    int a1, a2, b1, b2;
    float distancia;

    printf("Diga o valor de A da primeira coordenada:");
    scanf("%d", &a1);
    printf("Diga o valor de B da primeira coordenada:");
    scanf("%d", &b1);

    printf("Diga o valor de A da segunda coordenada:");
    scanf("%d", &a2);
    printf("Diga o valor de B da segunda coordenada:");
    scanf("%d", &b2);

    distancia = sqrt(pow((a2 - a1), 2) + pow((b2 - b1), 2));
    printf("A disancia = %.1f", distancia);

    return 0;
}