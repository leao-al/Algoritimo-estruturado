#include <stdio.h>
#include <math.h>

int main()
{
    float numero;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    if (numero > 0)
    {
        printf("O numero ao quadrado e: %.2f\n", numero * numero);
        printf("A raiz quadrada do numero e: %.2f\n", sqrt(numero));
    }

    return 0;
}
