#include <stdio.h>

int main()
{
    const double PI = 3.14159;
    double raio, area, volume;

    printf("Digite o valor do raio da esfera: ");
    scanf("%lf", &raio);

    volume = (4.0 / 3.0) * PI * (raio * raio * raio);
    area = 4 * PI * (raio * raio);

    printf("A area da superfície da esfera e: %.2lf\n", area);
    printf("O volume da esfera e: %.2lf", volume);

    return 0;
}
