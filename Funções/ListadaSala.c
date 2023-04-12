#include <stdio.h>

int main() {
   int escolha;
   float temperatura, resultado;

   printf("Qual conversao de temperatura deseja realizar?\n");
   printf("1. Celsius para Fahrenheit\n");
   printf("2. Fahrenheit para Celsius\n");
   scanf("%d", &escolha);

   if (escolha == 1) {
      printf("Digite a temperatura em graus Celsius: ");
      scanf("%f", &temperatura);

      resultado = (9.0 / 5.0) * temperatura + 32.0;

      printf("%.2f graus Celsius equivalem a %.2f graus Fahrenheit.\n", temperatura, resultado);
   }
   else if (escolha == 2) {
      printf("Digite a temperatura em graus Fahrenheit: ");
      scanf("%f", &temperatura);

      resultado = (temperatura - 32) * 5.0 / 9.0;

      printf("%.2f graus Fahrenheit equivalem a %.2f graus Celsius.\n", temperatura, resultado);
   }
   else {
      printf("Opcao invalida.\n");
   }

   return 0;
}
