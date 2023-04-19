#include <stdio.h>

float celsius_para_fahrenheit(float celsius) { return (9 * celsius/5) + 32; }
float fahrenheit_para_celsius(float fahrenheit) { return (fahrenheit - 32) * 5/9; }
float celsius_para_kelvin(float celsius) { return celsius + 273.15; }
float kelvin_para_celsius(float kelvin) { return kelvin - 273.15; }
float celsius_para_reaumur(float celsius) { return celsius * 4/5; }
float reaumur_para_celsius(float reaumur) { return reaumur * 5/4; }
float kelvin_para_rankine(float kelvin) { return kelvin * 1.8; }
float rankine_para_kelvin(float rankine) { return rankine/1.8; }

int main() {
    int opcao;
    float valor;

    printf("Escolha uma das opcao:\n");
    printf("1 - Celsius para Fahrenheit\n");
    printf("2 - Fahrenheit para Celsius\n");
    printf("3 - Celsius para Kelvin\n");
    printf("4 - Kelvin para Celsius\n");
    printf("5 - Celsius para Reaumur\n");
    printf("6 - Reaumur para Celsius\n");
    printf("7 - Kelvin para Rankine\n");
    printf("8 - Rankine para Kelvin:");

    scanf("%d", &opcao);

    printf("Digite o valor a ser convertido:\n");
    scanf("%f", &valor);

    switch (opcao) {
        case 1:
            printf("%.2f C = %.2f F\n", valor, celsius_para_fahrenheit(valor));
            break;
        case 2:
            printf("%.2f F = %.2f C\n", valor, fahrenheit_para_celsius(valor));
            break;
        case 3:
            printf("%.2f C = %.2f K\n", valor, celsius_para_kelvin(valor));
            break;
        case 4:
            printf("%.2f K = %.2f C\n", valor, kelvin_para_celsius(valor));
            break;
        case 5:
            printf("%.2f C = %.2f Re\n", valor, celsius_para_reaumur(valor));
            break;
        case 6:
            printf("%.2f Re = %.2f C\n", valor, reaumur_para_celsius(valor));
            break;
        case 7:
            printf("%.2f K = %.2f R\n", valor, kelvin_para_rankine(valor));
            break;
        case 8:
            printf("%.2f R = %.2f K\n", valor, rankine_para_kelvin(valor));
            break;
        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}