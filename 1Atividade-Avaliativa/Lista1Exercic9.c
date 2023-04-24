#include <stdio.h>

/*Elabore um algoritmo que permita ao usuário realizar a compra de frutas. Assim,
apresente a lista de frutas disponíveis, abaixo, com seus respectivos valores. O algoritmo
deve permitir ao usuário retomar o menu frutas quantas vezes quiser, e solicitar a quantidade
de frutas. Ao final, apresente o valor total da compra.
1 => ABACAXI – 5,00 a unidade
2 => MAÇA – 1,00 a unidade
3 => PERA – 4,00 a unidade*/

int main()
{

    int opcao, quant;
    float valorTotal;
    do
    {

        printf("\nMenu de Frutas:");
        printf("\n1 - Abacaxi (R$ 5,00 a unidade)");
        printf("\n2 - Maca (R$ 1,00 a unidade)");
        printf("\n3 - Pera (R$ 4,00 a unidade)");
        printf("\n4 - Sair");
        printf("\nDigite a opcaoo desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite a quantidade desejada: ");
            scanf("%d", &quant);
            valorTotal += quant * 5;
            printf("\nAbacaxi adicionado ao carrinho com sucesso!\n");
            break;

        case 2:
            printf("\nDigite a quantidade desejada: ");
            scanf("%d", &quant);
            valorTotal += quant * 1;
            printf("\nMaca adicionada ao carrinho com sucesso!\n");
            break;
        case 3:
            printf("\nDigite a quantidade desejada: ");
            scanf("%d", &quant);
            printf("\nPera adicionada ao carrinho com sucesso!\n");
            break;

        case 4:
            printf("\nCompra realizada com sucesso! Valor total: R$ %.2f\n", valorTotal);
            break;

        default:
            printf("\nOpção invalida! Por favor, escolha uma opcao valida.\n");
        }

    } while (opcao != 4);

    return 0;
}