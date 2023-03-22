#include<stdio.h>
#include<stdlib.h>

int main (){

float A;
float B;
int soma;

printf("Digite o primeiro %2.f numero:");
scanf("%f", &A);
fflush(stdin);
printf("Digite o segundo %2.f numero:");
scanf("%f", &B);
fflush(stdin);

soma = A + B;

printf("A soma das duas variaveis e:", soma);

    return 0;
}