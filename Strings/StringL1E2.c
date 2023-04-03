#include <stdio.h>
#include <string.h>

int main()
{
    char cor[25];

    printf("Digite o nome de uma cor (branco, verde ou amarelo): ");
    fgets(cor, 25, stdin);

    if (cor[strlen(cor) - 1] == '\n')
    {
        cor[strlen(cor) - 1] = '\0';
    }

    if (strcmp(cor, "branco") == 0)
    {
        printf("Cor valida: branco.\n");
    }
    else if (strcmp(cor, "verde") == 0)
    {
        printf("Cor valida: verde.\n");
    }
    else if (strcmp(cor, "amarelo") == 0)
    {
        printf("Cor valida: amarelo.\n");
    }
    else
    {
        printf("Cor invalida.\n");
    }

    return 0;
}
