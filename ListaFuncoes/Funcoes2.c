#include<stdio.h>
int main(void)
{
    float a, b, c;
    float subtrai (float a, float b, float c);

    printf("Digite os 3 numeros para serem subtraidos: ");
    scanf("%f %f %f", &a, &b, &c);

    float resultado =  subtrai (a, b, c);

    printf("O resultado eh: %f", resultado);

    return 0;
}

    float subtrai (float a, float b, float c)
    {
        float sub = a - b - c;

        return sub;
    }
