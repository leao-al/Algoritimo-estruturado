#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main (){

char nome [30], sobrenome[30];
int resposta;

printf("Digite o nome:");
scanf("%s", &nome);
fflush(stdin);

printf("Digite o sobrenome:");
scanf("%s", &sobrenome);
fflush(stdin);

if(strlen(nome) == strlen(sobrenome))
    printf("iguais");
    else if (strlen(nome) > strlen(sobrenome))
        printf("nome e maior: ");
        else printf("nome e menor ");




printf("");

    return 0;
}