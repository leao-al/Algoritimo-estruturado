#include <stdio.h>
#include <string.h>

int main()
{
    char nome_completo[100];
    char email[50];
    char endereco[100];

    char backup_nome[100], backup_email[50], backup_endereco[100];

    printf("Digite o seu nome completo: ");
    fgets(nome_completo, 100, stdin); // lê a entrada do usuário

    printf("Digite o seu e-mail: ");
    fgets(email, 50, stdin); // lê a entrada do usuário

    printf("Digite o seu endereco: ");
    fgets(endereco, 100, stdin); // lê a entrada do usuário

    if (nome_completo[strlen(nome_completo) - 1] == '\n')
    {
        nome_completo[strlen(nome_completo) - 1] = '\0';
    }
    if (email[strlen(email) - 1] == '\n')
    {
        email[strlen(email) - 1] = '\0';
    }
    if (endereco[strlen(endereco) - 1] == '\n')
    {
        endereco[strlen(endereco) - 1] = '\0';
    }

    // faz o backup dos dados
    strcpy(backup_nome, nome_completo);
    strcpy(backup_email, email);
    strcpy(backup_endereco, endereco);

    printf("Backup realizado com sucesso:\n");
    printf("Nome completo: %s\n", backup_nome);
    printf("E-mail: %s\n", backup_email);
    printf("Endereco: %s\n", backup_endereco);

    return 0;
}
