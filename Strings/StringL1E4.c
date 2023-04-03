#include <stdio.h>
#include <string.h>

int main()
{
    char primeiro_nome[50];
    char nome_meio[50];
    char ultimo_nome[50];

    printf("Digite o seu primeiro nome: ");
    scanf("%s", primeiro_nome);

    printf("Digite o seu nome do meio: ");
    scanf("%s", nome_meio);
    printf("Digite o seu sobrenome: ");
    scanf("%s", ultimo_nome);

    char nome_completo[200];
    strcpy(nome_completo, primeiro_nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, nome_meio);
    strcat(nome_completo, " ");
    strcat(nome_completo, ultimo_nome);

    printf("Nome completo: %s", nome_completo);

    return 0;
}
