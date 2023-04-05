#include<stdio.h>
#include<stdlib.h>
// faça um programa que leia apenas numeros impares 

int main(){

int i;

printf("Digite um valor:");
scanf("%d", &i);

for(i=11; i<100; i+=2){

    printf("%d", i);
}


    return 0;
}