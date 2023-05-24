#include<stdio.h>
#include<stdlib.h>
#include<string.h> // biblioteca para manipulação de strings

 // crie uma variavel string, peça uma variavel e conte ela.
int main(){
 
char dado [30];

printf("Digite um dado com ate 30 caracteres:\n");
scanf("%s", &dado);

printf("A quantidade de caracteres e: %s\n", dado);
printf("A quantidade de caracteres e: %d", strlen(dado));
 //  variavel nunca vai entre "" pois so usa em texto.



    return 0;
}
