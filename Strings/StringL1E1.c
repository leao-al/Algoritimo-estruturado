#include <stdio.h>
#include <string.h>

int main()
{
    char nome_completo[100];
    int quantidade_caracteres;

    printf("Digite o nome completo do cliente: ");
    fgets(nome_completo, 100, stdin);

    quantidade_caracteres = strlen(nome_completo) - 1; // -1 para desconsiderar o caractere de quebra de linha

    printf("O nome completo do cliente possui %d caracteres.\n", quantidade_caracteres);

    return 0;
}
