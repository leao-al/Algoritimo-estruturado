#include<stdio.h>
#include<stdlib.h>



struct Aluno
{
    char nome[50];
    char telefone[20];
    char cpf [20];
    double todoDinheiroDisponivel;
    int idade;
};
struct Professor
{
    char nome[50];
    char telefone[20];
    char cpf [20];
    double todoDinheiroDisponivelpMin;
};

int main (){
    struct Aluno aluno1;
    struct Professor Professor1;
    
    int vetor[50];
    struct Aluno listaAlunos[50];// [50 posições]..

    struct Aluno listaAlunosMatriz[2][2];
    struct Aluno listaAlunosVetor[4];
    
    

    printf("Digite o nome do aluno:");
    scanf("%s", &aluno1.nome);

    printf("Digite o cpf do aluno:");
    fgets(aluno1.cpf, 11, stdin);

    printf("Digite o telefone do aluno:");
    gets(aluno1.telefone);

    printf("Digite o valor disponivel:");
    scanf("%lf", &aluno1.todoDinheiroDisponivel);



    printf("Digite o nome do professor:");
    fgets(Professor1.nome, 20, stdin);

    printf("Digite o CPF:");
    scanf("%s", &Professor1.cpf);

    printf("Digite o telefone do aluno:");
    gets(Professor1.telefone);

    printf("Digite o valor disponivel:");
    scanf("%lf", &Professor1.todoDinheiroDisponivelpMin);



  for(int i=0; i<50; i++){
        printf("Digite o nome do aluno");
        fgets(listaAlunos[i].nome, 20, stdin);
        printf("igite a idade");
        scanf("%d", &listaAlunos[i].idade);
    }


    for(int i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("Digite o nome do aluno:");
            fgets(listaAlunosMatriz[i][j].nome);
        }
    }
    
}

