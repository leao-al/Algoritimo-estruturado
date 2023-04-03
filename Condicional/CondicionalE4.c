#include <stdio.h>

int main()
{
    float salario, prestacao;

    printf("Digite o valor do salario: ");
    scanf("%f", &salario);

    printf("Digite o valor da prestacao do emprestimo: ");
    scanf("%f", &prestacao);

    if (prestacao > 0.2 * salario)
    {
        printf("Emprestimo não concedido.");
    }
    else
    {
        printf("Emprestimo concedido.");
    }

    return 0;
}
