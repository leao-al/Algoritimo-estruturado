#include <stdio.h>
#include <stdlib.h>

/* faça um programa que o usuario digite um numero e o imprima apenas os numeros impares.*/
/* % = modolo, representa o resto da divisão.*/
int main() {
    int i, numeroInicial, numeroFinal;

    printf("Digite um numero:");
    scanf("%d", &numeroInicial);

    printf("Digite um numero:");
    scanf("%d", &numeroFinal);

    for (i = numeroInicial; i <= numeroFinal; i++) {
        if (i % 2 != 0)/*mostra apenas um numeros impares i dividido por 2. o resto da divisao eh diferente de 0*/ { 
            printf("%d\n", i);
        }
    }

    return 0;
}
