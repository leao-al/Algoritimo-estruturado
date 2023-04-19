/*Escreva funções que calculem a conversão entre diferentes escalas de temperatura. Considere as fórmulas de conversão abaixo:

• De graus Celsius(C) para graus Fahrenheit(F):  ok
F = (9 ∗ C/5) + 32)

• De graus Fahrenheit (F) para graus Celsius (C): ok
C = (F − 32) ∗ 5/9

• De graus Celsius (C) para graus Kelvin (K): K = C + 273.15 

• De graus Kelvin (K) para graus Celsius (C): C = K − 273.15

• De graus Celsius (C) para graus Réaumur (Re): Re = C ∗ 4/5

• De graus Réaumur (Re) para graus Celsius (C): C = Re ∗ 5/4

• De graus Kelvin (K) para graus Rankine (R): R = K ∗ 1.8

• De graus Rankine (R) para graus Kelvin (K): K = R/1.8

Solicite o usuário para escolher a função desejada e apresente o resultado a partir da chamada da função escolhida.*/


#include<stdlib.h>
#include<stdio.h>


double Fahrenheitcelsius (float F){ // aqui e onde fica a função.
    float C;
    C = ((F - 32) * 5/9);
    return C;
}

double Fahrenheitcelsius (float C){ // aqui e onde fica a função.
    float K;
    K = C + 273.15;
    return C;
}


int main(){

    float F, C, K;
    scanf("%lf", &C);
    F =  celsiusFahrenheit(C);
    float F, C;
    scanf("%lf", &F);
    F =  celsiusFahrenheit(F);



    return 0;
}