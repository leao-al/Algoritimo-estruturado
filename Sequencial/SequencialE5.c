#include <stdio.h>

int main()
{
    int a, b, x;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    x = a + b;

    printf("valor de %d + valor de %d = valor de %d", a, b, x);

    return 0;
}
