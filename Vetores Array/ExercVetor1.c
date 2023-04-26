#include<stdio.h>
#include<stdlib.h>

/*Somar cinco numeros em vetores*/

int main(){
    int n2[5], n1[5], soma[5];

    for(int i=0; i<5; i++){
        printf("Digite o Numero:");
        scanf("%d%d",&n1[i], &n2[i]);
        soma[i] = n1[i] + n2[i];
        printf("a soma %d e:", soma[i]);

    }


    return 0;
}