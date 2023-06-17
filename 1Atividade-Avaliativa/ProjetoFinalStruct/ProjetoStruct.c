#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 1000
#define MAX_NOME 100
#define MAX_EMAIL 100
#define MAX_SEXO 10
#define MAX_ENDERECO 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char sexo[MAX_SEXO];
    char endereco[MAX_ENDERECO];
    double altura;
    int vacina;
} Usuario;

int validarEmail(const char *email) {
    if (strchr(email, '@') == NULL) {
        return 0; // email invalido
    }
    return 1; // email valido
}

void listarUsuarios(const Usuario usuarios[], int quantidadeUsuarios) {
    if (quantidadeUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        for (int i = 0; i < quantidadeUsuarios; i++) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
            printf("--------------------\n");
        }
    }
}

void cadastrarUsuario(Usuario usuarios[], int *quantidadeUsuarios) {
    if (*quantidadeUsuarios == MAX_USUARIOS) {
        printf("Numero maximo de usuarios atingido.\n");
        return;
    }

    Usuario novoUsuario;

    printf("Digite seu nome: ");
    fgets(novoUsuario.nome, MAX_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    do {
        printf("Digite seu email: ");
        fgets(novoUsuario.email, MAX_EMAIL, stdin);
        novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';
        if (!validarEmail(novoUsuario.email)) {
            printf("Email invalido\n");
        }
    } while (!validarEmail(novoUsuario.email));

    printf("Digite seu endereco: ");
    fgets(novoUsuario.endereco, MAX_ENDERECO, stdin);
    novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0';

    do {
        printf("Qual seu sexo? Masculino (M) ou Feminino (F)? ");
        fgets(novoUsuario.sexo, MAX_SEXO, stdin);
        novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';
        if (strcasecmp(novoUsuario.sexo, "M") != 0 && strcasecmp(novoUsuario.sexo, "F") != 0) {
            printf("Sexo invalido. Digite M ou F.\n");
        }
    } while (strcasecmp(novoUsuario.sexo, "M") != 0 && strcasecmp(novoUsuario.sexo, "F") != 0);

    do {
        printf("Digite sua altura 1 ou 2: ");
        scanf("%lf", &novoUsuario.altura);
        getchar();
        if (novoUsuario.altura > 2.0 || novoUsuario.altura < 1.0) {
            printf("Altura invalida\n");
        }
    } while (novoUsuario.altura > 2.0 || novoUsuario.altura < 1.0);

    do {
        printf("Vacina: Sim (1) ou Nao (0): ");
        scanf("%d", &novoUsuario.vacina);
        getchar();
        if (novoUsuario.vacina != 0 && novoUsuario.vacina != 1) {
            printf("Opcao invalida\n");
        }
    } while (novoUsuario.vacina != 0 && novoUsuario.vacina != 1);

    novoUsuario.id = *quantidadeUsuarios + 1;

    usuarios[*quantidadeUsuarios] = novoUsuario;
    (*quantidadeUsuarios)++;

    printf("Usuario cadastrado com sucesso.\n");
}

void excluirUsuario(Usuario usuarios[], int *quantidadeUsuarios, int id) {
    int encontrado = 0;

    for (int i = 0; i < *quantidadeUsuarios; i++) {
        if (usuarios[i].id == id) {
            encontrado = 1;
            // Move todos os usuários posteriores para uma posição anterior
            for (int j = i; j < *quantidadeUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            (*quantidadeUsuarios)--;
            printf("Usuario removido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void buscarUsuarioPorEmail(const Usuario usuarios[], int quantidadeUsuarios, const char *email) {
    int encontrado = 0;

    for (int i = 0; i < quantidadeUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            encontrado = 1;
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
            printf("--------------------\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void fazerBackup(const Usuario usuarios[], int quantidadeUsuarios, Usuario backup[]) {
    for (int i = 0; i < quantidadeUsuarios; i++) {
        backup[i] = usuarios[i];
    }

    printf("Backup criado com sucesso.\n");
}

void fazerRestauracao(Usuario usuarios[], int *quantidadeUsuarios, const Usuario backup[], int quantidadeBackup) {
    for (int i = 0; i < quantidadeBackup; i++) {
        usuarios[i] = backup[i];
    }

    *quantidadeUsuarios = quantidadeBackup;

    printf("Restauracao concluida.\n");
}

void listarUsuariosdoBackup(const Usuario backup[], int quantidadeBackup) {
    if (quantidadeBackup == 0) {
        printf("Nenhum usuario no backup.\n");
    } else {
        for (int i = 0; i < quantidadeBackup; i++) {
            printf("ID: %d\n", backup[i].id);
            printf("Nome: %s\n", backup[i].nome);
            printf("Email: %s\n", backup[i].email);
            printf("Sexo: %s\n", backup[i].sexo);
            printf("Endereco: %s\n", backup[i].endereco);
            printf("Altura: %.2lf\n", backup[i].altura);
            printf("Vacina: %s\n", backup[i].vacina ? "Sim" : "Nao");
            printf("--------------------\n");
        }
    }
}

int main() {
    Usuario usuarios[MAX_USUARIOS];
    Usuario backup[MAX_USUARIOS];
    int quantidadeUsuarios = 0;
    int quantidadeBackup = 0;

    int opcao;

    do {
        printf("Selecione uma opcao:\n");
        printf("1 - Listar usuarios\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Buscar usuario por email\n");
        printf("5 - Fazer backup\n");
        printf("6 - Fazer restauracao\n");
        printf("7 - Listar usuarios do backup\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                listarUsuarios(usuarios, quantidadeUsuarios);
                break;
            case 2:
                cadastrarUsuario(usuarios, &quantidadeUsuarios);
                break;
            case 3:
                printf("Digite o ID do usuario que deseja excluir: ");
                int idExcluir;
                scanf("%d", &idExcluir);
                getchar();
                excluirUsuario(usuarios, &quantidadeUsuarios, idExcluir);
                break;
            case 4:
                printf("Digite o email do usuario que deseja buscar: ");
                char emailBuscar[MAX_EMAIL];
                fgets(emailBuscar, MAX_EMAIL, stdin);
                emailBuscar[strcspn(emailBuscar, "\n")] = '\0';
                buscarUsuarioPorEmail(usuarios, quantidadeUsuarios, emailBuscar);
                break;
            case 5:
                fazerBackup(usuarios, quantidadeUsuarios, backup);
                quantidadeBackup = quantidadeUsuarios;
                break;
            case 6:
                fazerRestauracao(usuarios, &quantidadeUsuarios, backup, quantidadeBackup);
                break;
            case 7:
                listarUsuariosdoBackup(backup, quantidadeBackup);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
