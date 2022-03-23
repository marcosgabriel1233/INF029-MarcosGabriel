#include<stdio.h>

float soma(float a, float b);

int main()
{
    float a, b;
  
    printf("Digite o primeiro numero: ");
    scanf("%f", &a);
    printf("Digite o segundo numero: ");
    scanf("%f", &b);


    float resultado = soma(a, b);
    
    printf("A soma eh: %.2f", resultado);

    return 0;
}

    float soma(float a, float b)
    {
        float resultado = a + b;

        return resultado;
    }