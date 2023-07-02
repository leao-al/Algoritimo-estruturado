#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[30], endereco[30], email[30], sexo[10];
    char vacina[10];
    double altura;
    struct no* proximo;
} No;

No* inicializar() {
    return NULL;
}

int validarEmail(const char* email) {
    if (strchr(email, '@') == NULL) {
        return 0; // email inválido
    }
    return 1; // email válido
}

No* inserir(No* cadastroUsuario) {
    No* novo = (No*)malloc(sizeof(No));

    printf("Digite seu nome: ");
    fgets(novo->nome, 30, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("Digite o endereco do usuario: ");
    fgets(novo->endereco, 30, stdin);
    novo->endereco[strcspn(novo->endereco, "\n")] = '\0';

    do {
        printf("Digite o e-mail do usuario: ");
        fgets(novo->email, 30, stdin);
        novo->email[strcspn(novo->email, "\n")] = '\0';

        if (!validarEmail(novo->email)) {
            printf("E-mail invalido. Informe novamente.\n");
        }
    } while (!validarEmail(novo->email));

    printf("Digite o sexo do usuario (Masculino ou Feminino): ");
    fgets(novo->sexo, 10, stdin);
    novo->sexo[strcspn(novo->sexo, "\n")] = '\0';

    while (strcmp(novo->sexo, "Masculino") != 0 && strcmp(novo->sexo, "Feminino") != 0) {
        printf("Sexo invalido. Informe novamente (Masculino ou Feminino): ");
        fgets(novo->sexo, 10, stdin);
        novo->sexo[strcspn(novo->sexo, "\n")] = '\0';
    }

    printf("Qual sua altura? (1) ou (2): ");
    scanf("%lf", &(novo->altura));

    while (novo->altura != 1 && novo->altura != 2) {
        printf("Altura invalida. Informe novamente (1 ou 2): ");
        scanf("%lf", &(novo->altura));
    }

    printf("Ja foi vacinado? (sim ou nao): ");
    fflush(stdin);
    fgets(novo->vacina, 10, stdin);
    novo->vacina[strcspn(novo->vacina, "\n")] = '\0';

    while (strcmp(novo->vacina, "sim") != 0 && strcmp(novo->vacina, "nao") != 0) {
        printf("Resposta invalida. Informe novamente (sim ou nao): ");
        fgets(novo->vacina, 10, stdin);
        novo->vacina[strcspn(novo->vacina, "\n")] = '\0';
    }

    novo->proximo = cadastroUsuario;
    return novo;
}

No* backupUsuario(No* cadastroUsuario) {
    No* backup = NULL;
    No* temp = cadastroUsuario; // variavel temp ponteiro da estrutura Nó, recebo o valor do cadastroUsuario

    while (temp != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        strcpy(novo->nome, temp->nome);
        strcpy(novo->endereco, temp->endereco);
        strcpy(novo->email, temp->email);
        strcpy(novo->sexo, temp->sexo);
        novo->altura = temp->altura;
        strcpy(novo->vacina, temp->vacina); 
        novo->proximo = backup;
        backup = novo;
        temp = temp->proximo;
    }

    printf("\n\nBackup realizado com sucesso.\n\n");
    return backup;
}

No* buscarUsuarioPorEmail(No* listaUsuarios, const char* email) {
    No* temp = listaUsuarios;

    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            return temp; // Usuário encontrado
        }
        temp = temp->proximo;
    }
// == 0 indica que as strings sao iguais/ 
    return NULL; // Usuário não encontrado
}

void listarUsuariosCadastrados(No* listaUsuarios) {
    No* temp = listaUsuarios;

    if (temp == NULL) {
        printf("\n\n----------Nenhum usuario cadastrado----------\n\n");
        return;
    }

    printf("\n\n----------------Usuario cadastrado--------------:\n\n");

    while (temp != NULL) {
        printf("Nome: %s\n", temp->nome);
        printf("Endereco: %s\n", temp->endereco);
        printf("Email: %s\n", temp->email);
        printf("Sexo: %s\n", temp->sexo);
        printf("Altura: %.2lf\n", temp->altura);
        printf("Vacinado: %s\n", strcmp(temp->vacina, "sim") == 0 ? "sim" : "nao");
        printf("\n");
        temp = temp->proximo;
    }
}

No* remover(No** lista, const char* nome) {
    No* aux = NULL;
    No* remover = NULL;

    if (*lista != NULL) {// nesse momento o if esta percorrendo a lista e verificando se ela esta vazia
        if (strcmp((*lista)->nome, nome) == 0) {
            remover = *lista;
            *lista = remover->proximo;
            free(remover); // libera o espaco na memoria
        } else {
            aux = *lista;
            while (aux->proximo != NULL && strcmp(aux->proximo->nome, nome) != 0) {
                aux = aux->proximo;
            }
            if (aux->proximo != NULL) {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                free(remover);
            }
        }
    }

    return remover;
}

No* editarUsuario(No* listaUsuarios, const char* email) {
    No* temp = listaUsuarios;

    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            printf("Digite o novo nome do usuario: ");
            fgets(temp->nome, 30, stdin);
            temp->nome[strcspn(temp->nome, "\n")] = '\0';

            printf("Digite o novo endereço do usuario: ");
            fgets(temp->endereco, 30, stdin);
            temp->endereco[strcspn(temp->endereco, "\n")] = '\0';

            printf("Digite o novo email do usuario: ");
            fgets(temp->email, 30, stdin);
            temp->email[strcspn(temp->email, "\n")] = '\0';

            printf("Digite o novo sexo do usuario: ");
            fgets(temp->sexo, 10, stdin);
            temp->sexo[strcspn(temp->sexo, "\n")] = '\0';// foi ultilizado os strcspn para obter a posicao do primeiro caractere da nova linha "("\n")"

            printf("Digite a nova altura do usuario: ");// foi usado o & para obter o endereco da variavel "altura"
            scanf("%lf", &(temp->altura));// passa o endereco da memoria da variavel para o scanf
            getchar();// Sem o getchar(), a próxima leitura de uma string usando fgets poderia capturar o caractere de nova linha deixado anteriormente e não aguardar a entrada do usuário 

            printf("O usuario foi editado com sucesso.\n");
            break;
        }
        temp = temp->proximo;
    }

    return listaUsuarios;
}

int main() {
    int opcao;
    char email[30];
    char nome[30];
    No* cadastroUsuario = inicializar();

    do {
        printf("----------Selecione uma opcao---------\n");
        printf("1 - Cadastrar usuarios\n");
        printf("2 - Backup usuario\n");
        printf("3 - Listar usuarios cadastrados\n");
        printf("4 - Buscar usuario por email\n");
        printf("5 - Excluir usuario\n");
        printf("0 - Sair\n");
        printf("-----------------Opcao------------------:");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastroUsuario = inserir(cadastroUsuario);
                break;
            case 2:
                cadastroUsuario = backupUsuario(cadastroUsuario);
                break;
            case 3:
                listarUsuariosCadastrados(cadastroUsuario);
                break;
            case 4: {
                printf("Digite o email do usuario a ser buscado: ");
                fgets(email, 30, stdin);
                email[strcspn(email, "\n")] = '\0';
                No* usuarioEncontrado = buscarUsuarioPorEmail(cadastroUsuario, email);
                if (usuarioEncontrado != NULL) {
                    printf("Usuario encontrado:\n");
                    printf("Nome: %s\n", usuarioEncontrado->nome);
                    printf("Endereco: %s\n", usuarioEncontrado->endereco);
                    printf("Email: %s\n", usuarioEncontrado->email);
                    printf("Sexo: %s\n", usuarioEncontrado->sexo);
                    printf("Altura: %.2lf\n", usuarioEncontrado->altura);
                    printf("Vacinado: %s\n", strcmp(usuarioEncontrado->vacina, "sim") == 0 ? "sim" : "nao");
                } else {
                    printf("Usuario nao encontrado.\n");
                }
                break;
            }
            case 5: {  
                printf("Digite o nome do usuario a ser excluido: ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                No* usuarioRemovido = remover(&cadastroUsuario, nome);
                if (usuarioRemovido != NULL) {
                    printf("\n\nUsuario removido com sucesso.\n\n");
                    free(usuarioRemovido);
                } else {
                    printf("\n\nUsuario nao encontrado.\n\n");
                }
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
