#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int validarEmail(const char *email){
    if (strchr(email, '@') == NULL)  
    {
        return 0; //email invalido
    }
    return 1; // email valido
}


#define MAX_USUARIOS 1000 //definicao de constante
#define MAX_NOME 100
#define MAX_SEXO 100
#define MAX_ENDERECO 100
#define MAX_EMAIL 100

//variaveis de escopo global
// Dados do usuário
int numeroUsuarios = 0; // controla a quantidade de cadastros
int quantidadeBackup = 0; //controla a quantidade de cadastros do backup
int totalID[MAX_USUARIOS];
char totalNomeCompleto[MAX_USUARIOS][50];
char totalEmail[MAX_USUARIOS][50];
char totalSexo[MAX_USUARIOS][10];
char totalEndereco[MAX_USUARIOS][50];
double totalAltura[MAX_USUARIOS];
int totalVacina[MAX_USUARIOS];


// Backup
int backupID[MAX_USUARIOS];
char backupNomeCompleto[MAX_USUARIOS][100];
char backupEmail[MAX_USUARIOS][100];
char backupSexo[MAX_USUARIOS][10];
char backupEndereco[MAX_USUARIOS][100];
double backupAltura[MAX_USUARIOS];
int backupVacina[MAX_USUARIOS];


// Função para listar todos os usuários cadastrados
void listarUsuarios() {
	int i;
    // Verifica se há usuários cadastrados
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        // Imprime o id e o nome de cada usuário
        for (i = 0; i < numeroUsuarios; i++) {
            printf("ID: %d\n", totalID[i]);
            printf("Nome: %s\n", totalNomeCompleto[i]);
            printf("Email: %s\n", totalEmail[i]);
            printf("Sexo: %s\n", totalSexo[i]);
            printf("Endereco: %s\n", totalEndereco[i]);
            printf("Altura: %.2lf\n", totalAltura[i]);
            printf("Vacina: %s\n", totalVacina[i] ? "Sim" : "Nao");
            printf("--------------------\n");
        }
    }
}

// Função para listar todos os usuários cadastrados
void listarUsuariosBackup() {
	int i;
    // Verifica se há usuários cadastrados
    if (quantidadeBackup == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        // Imprime o id e o nome de cada usuário
        for (i = 0; i < quantidadeBackup; i++) {
            printf("ID: %d\n", backupID[i]);
            printf("Nome: %s\n", backupNomeCompleto[i]);
            printf("Email: %s\n", backupEmail[i]);
            printf("Sexo: %s\n", backupSexo[i]);
            printf("Endereco: %s\n", backupEndereco[i]);
            printf("Altura: %.2lf\n", backupAltura[i]);
            printf("Vacina: %s\n", backupVacina[i] ? "Sim" : "Nao");
            printf("--------------------\n");
        }
    }
}

// Função para cadastrar um novo usuário
void cadastrarUsuario() {
    double altura;


    // Verifica se o número máximo de usuários foi atingido
    if (numeroUsuarios == MAX_USUARIOS) {
        printf("Numero maximo de usuarios atingido.\n");
        return;
    }

    // Solicita os dados do usuário
    printf("Digite seu nome: ");
    fgets(totalNomeCompleto[numeroUsuarios], 50, stdin);
    totalNomeCompleto[numeroUsuarios][strlen(totalNomeCompleto[numeroUsuarios]) - 1] = '\0'; // Remove o caractere de nova linha

    do{
    printf("Digite seu email: ");
    fgets(totalEmail[numeroUsuarios], 50, stdin);
    totalEmail[numeroUsuarios][strlen(totalEmail[numeroUsuarios]) - 1] = '\0';
    if (!validarEmail(totalEmail[numeroUsuarios])){
        printf("Email invalido\n");
        //return;
    }
    }while(!validarEmail(totalEmail[numeroUsuarios]));

    printf("Qual seu sexo? Masculino ou Feminino? ");
    fgets(totalSexo[numeroUsuarios], 10, stdin);
    totalSexo[numeroUsuarios][strlen(totalSexo[numeroUsuarios]) - 1] = '\0';

    

    printf("Digite seu endereco: ");
    fgets(totalEndereco[numeroUsuarios], 50, stdin);
    totalEndereco[numeroUsuarios][strlen(totalEndereco[numeroUsuarios]) - 1] = '\0'; // Remove o caractere de nova linha

    // printf("Digite sua altura 1 ou 2:");
    // scanf("%lf", &altura);
    // getchar();// limpar o buffer  de entrada
    // while(altura > 2.0 || altura < 1.0){
    //         printf("Altura invalida\n");
    //         printf("Tente novamente: ");
    //         scanf("%lf", &altura);
    // }

    do{
    printf("Digite sua altura 1 ou 2:");
    scanf("%lf", &altura);
    if (altura > 2.0 || altura < 1.0)
        printf("Altura invalida\n");
    }while (altura > 2.0 || altura < 1.0);



    do{
    printf("Vacina: 1 para sim || 2 para nao:\n");
    scanf("%d", &totalVacina[numeroUsuarios]);
    if (totalVacina < 1 || totalVacina > 2 )
        printf("Vacina e invalida!\n");
    } while (totalVacina < 1 || totalVacina > 2);
    
    

    totalID[numeroUsuarios] = numeroUsuarios + 1;
    totalAltura[numeroUsuarios] = altura;
    numeroUsuarios++;
    quantidadeBackup++;

    printf("Usuario cadastrado.\n");
}

// Função para excluir um usuário
void excluirUsuario() {
    int i;
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int idUsuario;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &idUsuario);

    int indiceUsuario = -1; /*Ao atribuir -1 à variável indiceUsuario, estamos definindo um valor inicial que indica que o usuário com o ID procurado ainda não foi encontrado. Durante a busca no array de IDs, se o valor de indiceUsuario permanecer -1 após o loop, significa que nenhum usuário foi encontrado com o ID especificado. */
    for (i = 0; i < numeroUsuarios; i++) {
        if (totalID[i] == idUsuario) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("Usuario com ID %d nao encontrado.\n", idUsuario);
    } else {
        // Realiza a exclusão do usuário
        for (i = indiceUsuario; i < numeroUsuarios - 1; i++) {
            totalID[i] = totalID[i + 1];
            strcpy(totalNomeCompleto[i], totalNomeCompleto[i + 1]);
            strcpy(totalEmail[i], totalEmail[i + 1]);
            strcpy(totalSexo[i], totalSexo[i + 1]);
            strcpy(totalEndereco[i], totalEndereco[i + 1]);
            totalAltura[i] = totalAltura[i + 1];
            totalVacina[i] = totalVacina[i + 1];
        }

        numeroUsuarios--;
        printf("Usuario com ID %d excluido com sucesso.\n", idUsuario);
    }
}


// Função para buscar um usuário pelo email
void buscarUsuarioPorEmail() {
    int i;
    // Verifica se há usuários cadastrados
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    char email[50];
    printf("Digite o email do usuario que deseja buscar: ");
    scanf("%s", email);

    int indiceUsuario = -1;
    for (i = 0; i < numeroUsuarios; i++) {
        if (strcmp(totalEmail[i], email) == 0) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("Usuario com email %s nao encontrado.\n", email);
    } else {
        printf("Usuario encontrado:\n");
        printf("ID: %d\n", totalID[indiceUsuario]);
        printf("Nome: %s\n", totalNomeCompleto[indiceUsuario]);
        printf("Email: %s\n", totalEmail[indiceUsuario]);
        printf("Sexo: %s\n", totalSexo[indiceUsuario]);
        printf("Endereco: %s\n", totalEndereco[indiceUsuario]);
        printf("Altura: %.2lf\n", totalAltura[indiceUsuario]);
        printf("Vacina: %s\n", totalVacina[indiceUsuario] ? "Sim" : "Não");
    }
}

// Função para fazer backup dos usuários cadastrados
void fazerBackup() {
    int i;
    // Copia os dados dos usuários para o backup
    for (i = 0; i < quantidadeBackup; i++) {
        backupID[i] = totalID[i];
        strcpy(backupNomeCompleto[i], totalNomeCompleto[i]);
        strcpy(backupEmail[i], totalEmail[i]);
        strcpy(backupSexo[i], totalSexo[i]);
        strcpy(backupEndereco[i], totalEndereco[i]);
        backupAltura[i] = totalAltura[i];
        backupVacina[i] = totalVacina[i];
    }

    printf("Backup realizado com sucesso.\n");
}

// Função para fazer a restauração dos dados a partir do backup
void fazerRestauracao() {
    int i;
    // Copia os dados do backup de volta para os usuários cadastrados
    for (i = 0; i < quantidadeBackup; i++) {
        totalID[i] = backupID[i];
        strcpy(totalNomeCompleto[i], backupNomeCompleto[i]);
        strcpy(totalEmail[i], backupEmail[i]);
        strcpy(totalSexo[i], backupSexo[i]);
        strcpy(totalEndereco[i], backupEndereco[i]);
        totalAltura[i] = backupAltura[i];
        totalVacina[i] = backupVacina[i];
      //quantidadeBackup = 0; /*Dessa forma, o controle adequado dos backups será mantido e não ocorrerão duplicações de registros durante a restauração.*/

    }

   numeroUsuarios = quantidadeBackup; // Atualiza a quantidade de usuarios cadastrados com a quantidade restaurada.

    printf("Restaurado com sucesso.\n");
}

// Função para editar um usuário
void editarUsuario() {
    int i;
    // Verifica se há usuários cadastrados
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int idUsuario;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &idUsuario);

    int indiceUsuario = -1;
    for (i = 0; i < numeroUsuarios; i++) {
        if (totalID[i] == idUsuario) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("Usuario com ID %d nao encontrado.\n", idUsuario);
    } else {
        char nome[100], email[100], sexo[10], endereco[100];
        double altura;
        int vacina;

        printf("Digite o novo nome do usuario: ");
        scanf("%s", nome);
        strcpy(totalNomeCompleto[indiceUsuario], nome);

        printf("Digite o novo email do usuario: ");
        scanf("%s", email);
        strcpy(totalEmail[indiceUsuario], email);

        printf("Digite o novo sexo do usuario (Masculino ou Feminino): ");
        scanf("%s", sexo);
        strcpy(totalSexo[indiceUsuario], sexo);

        printf("Digite o novo endereco do usuario: ");
        scanf("%s", endereco);
        strcpy(totalEndereco[indiceUsuario], endereco);

        printf("Digite a nova altura do usuario: ");
        scanf("%lf", &altura);
        totalAltura[indiceUsuario] = altura;

        printf("Digite a nova opcao de vacina do usuario (1 para sim, 2 para nao): ");
        scanf("%d", &vacina);
        totalVacina[indiceUsuario] = vacina;

        printf("Usuario com ID %d editado com sucesso.\n", idUsuario);
    }
}

int main() {
    int opcao;

    do {
        // Exibe o menu de opções
        printf("-----------------MENU-------------------\n\n");
        printf("1. Listar usuarios\n");
        printf("2. Cadastrar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Fazer backup dos usuarios cadastrados\n");
        printf("6. Restaurar dados do backup\n");
        printf("7. Editar Usuario\n");
        printf("8. Listar usuarios backup\n");
        printf("0. Sair\n");
        printf("----------------------------------------\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                listarUsuarios();
                break;
            case 2:
                cadastrarUsuario();
                break;
            case 3:
                excluirUsuario();
                break;
            case 4:
                buscarUsuarioPorEmail();
                break;
            case 5:
                fazerBackup();
                break;
            case 6:
                fazerRestauracao();
                break;
            case 7: 
                 editarUsuario();
                 break;
            case 8: 
                listarUsuariosBackup(); 
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
