#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main (){

char nome [30], sobrenome[30];
int resposta;

printf("Digite o nome:");
scanf("%s", &nome);
fgets(nome, 100, stdin);
fflush(stdin);

printf("Digite o sobrenome:");
scanf("%s", &sobrenome);
fgets(sobrenome, 100, stdin); //fgets conta os espaços!!  substitui o scanf para ler a variavel, o "100" e a quantidade de caracteres lidos, o stdin serve como fflush, limpando a memoria.
fflush(stdin);

if(strlen(nome) == strlen(sobrenome))
    printf("iguais");
    else if (strlen(nome) > strlen(sobrenome))
        printf("nome e maior: ");
        else 
        printf("nome e menor ");




printf("");

    return 0;
}