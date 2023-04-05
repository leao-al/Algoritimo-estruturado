#include <stdio.h>

int main() {
    int num, i, count = 0;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Os 5 primeiros multiplos impares de %d sao:\n", num);
    for (i = 1; count < 5; i++) {
        int multiple = num * i;
        if (multiple % 2 != 0) {
            printf("%d\n", multiple);
            count++;
        }
    }

    return 0;
}
