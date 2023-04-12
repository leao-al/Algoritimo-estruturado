#include <stdio.h>

int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;

    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &n);

    // caso especial para o termo de ordem 0
    if (n == 0) {
        printf("%d\n", t1);
        return 0;
    }

    // caso especial para o termo de ordem 1
    if (n == 1) {
        printf("%d\n", t2);
        return 0;
    }

    // calcular e imprimir o enésimo termo da sequência de Fibonacci
    for (i = 2; i <= n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("%d\n", nextTerm);
    return 0;
}
