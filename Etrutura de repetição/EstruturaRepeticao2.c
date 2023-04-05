#include<stdio.h>
#include<stdlib.h>



int main (){

int i;

printf("Digite um numero:");
scanf("%d", &i);

for(i=10; i<100; i+=2){
printf("%d\n", i);

}// o i=10 e para começar do numero 10, o i<100 quer dizer que ele vai parar em 100, o i+=2 sginifica que ele ira pular de dois em dois.

    return 0;
}