#include <stdio.h>

int main()
{
    char nome[50];
    double salarioFixo, totalVendas, comissao, salarioTotal;

    printf("Digite o nome do vendedor: ");
    fgets(nome, 50, stdin);

    printf("Digite o salario fixo do vendedor: ");
    scanf("%lf", &salarioFixo);

    printf("Digite o total de vendas efetuadas pelo vendedor: ");
    scanf("%lf", &totalVendas);

    comissao = totalVendas * 0.15;
    salarioTotal = salarioFixo + comissao;

    printf("O vendedor %s recebera R$ %.2lf no final do mes.", nome, salarioTotal);

    return 0;
}
