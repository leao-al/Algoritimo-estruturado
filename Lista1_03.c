


/*Faça um algoritmo que leia um numero inteiro, dois números reais (um float, com 3
casas depois da vírgua, e um double), um caracter (uma única letra), uma string
(conjunto de caracteres) e um endereço de memória, em hexadecimal. Na
sequência, imprima todos com a formatação abaixo.
Numero inteiro: “valor”
Numeros reais:
“valor”
“valor”
Letra: “valor”
String: “valor”
Endereço: “valor” */



#include<stdio.h>
#include<stdlib.h>

int main (){

int numeroInteiros;
float numeroRealFloat;
double numeroRealDouble;
char umaLetra;
char umaString[100];


scanf("%d",&numeroInteiros); // não vai ace
scanf("%d",&numeroRealFloat);
scanf("%d",&numeroRealDouble);
scanf("%d",&umaLetra);
scanf("%d",&umaString);


scanf("%s", &umaString);
gets (umaString); // vai funcionar, receber o texto, 
fgets (umaString, 100, stdin); // função mais completa, passa os dados. 

printf("%3d: Inteiros:\n", numeroInteiros);
printf("Float:%3.f \n", numeroRealFloat);
printf("Double:\n %.1lf ", numeroRealDouble);
printf("Char: \n%c", umaLetra);
printf("String: \n%s", umaString);
printf("Endereco do inteiro: \n%s", &numeroInteiros);
    return 0;
}