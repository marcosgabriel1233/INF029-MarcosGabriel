#include<stdio.h>
int main(void)
{
    float soma(void);

    float resultado = soma();
    printf("A soma eh: %f", resultado);

    return 0;
}

    float soma()
    {
        float a, b;

        printf("Digite o primeiro numero: ");
        scanf("%f", &a);
        printf("Digite o segundo numero: ");
        scanf("%f", &b);

        float resultado = a + b;

        return resultado;
    }
