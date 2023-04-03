#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50], sobrenome[50], cpf[12];

    printf("Digite seu nome completo: ");
    scanf("%s", nome);

    printf("Digite seu sobrenome: ");
    scanf("%s", sobrenome);

    printf("Digite seu CPF (somente números): ");
    scanf("%s", cpf);

    // gera a senha de acesso
    char primeira_letra_sobrenome = sobrenome[0];
    char tres_primeiros_numeros_cpf[4];
    strncpy(tres_primeiros_numeros_cpf, cpf, 3);
    tres_primeiros_numeros_cpf[3] = '\0'; // adiciona um caractere nulo ao final da string

    // concatena os dados em uma única string
    char senha[50];
    strcpy(senha, nome);
    strcat(senha, "_");
    strncat(senha, &primeira_letra_sobrenome, 1);
    strcat(senha, tres_primeiros_numeros_cpf);

    printf("Sua senha de acesso: %s", senha);

    return 0;
}
