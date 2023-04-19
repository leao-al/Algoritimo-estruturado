#include<stdlib.h>
#include<stdio.h>

float celsiusFahrenheit (float C){ // aqui e onde fica a função.
    float F;
    F = ((9 * C/5) + 32);
    return F;
}

float Fahrenheitcelsius (float F){ // aqui e onde fica a função.
    float C;
    C = ((F - 32) * 5/9);
    return C;
}


int main(){

    float F, C;
    scanf("%f", &C);
    F =  celsiusFahrenheit(C);



    return 0;
}