#include<stdlib.h>
#include<stdio.h>

/*Faça um programa que some dois numero e mostre se e impar ou par*/
int main(){
    int n1[5], n2[5], media[5];
    

    for (int i=0; i<5; i++){
        printf("Digite o primeiro numero:");
        scanf("%d%d", &n1[i], &n2[i]);
        media[i] = (n1[i] + n2[i]); 
    }

    for (int i=0; i<5; i++){
        if(media[i]%2==0)
            printf("%d + %d = %d - Par\n", n1[i], n2[i], media[i]);
            else  printf("%d + %d = %d - Impar\n", n1[i], n2[i], media[i]);

    }
   


    return 0;
}